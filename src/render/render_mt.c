/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_worker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:45:51 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/26 19:01:09 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

// Function executed by each worker thread
void *render_worker(void *arg)
{
	t_thread_data *data = (t_thread_data *)arg;
	t_world *world = init_local_world(data);
	if (!world) {
		 ft_dprintf(2, "Thread %d failed to initialize world.\n", data->thread_id);
		pthread_exit(NULL);
	}

	t_ray *ray[RECURSIVE_DEPTH + 1] = {NULL};
	t_comp *comp[RECURSIVE_DEPTH + 1] = {NULL};
	if (!init_worker_memory(ray, comp)) {
		free_worker_memory(ray, comp);
		pthread_exit(NULL);
	}

	int hsize = world->camera->hsize;
	int vsize = world->camera->vsize;

	// Create computed buffer to track rendered pixels
	bool **computed_buffer = malloc(vsize * sizeof(bool *));
	for (int i = 0; i < vsize; i++) computed_buffer[i] = ft_calloc(hsize, sizeof(bool));

	// Progressive refinement: render in decreasing block sizes
	for (int step = 16; step >= 1; step /= 2) {
		for (int y = data->thread_id; y < vsize; y += data->total_threads) {
			for (int x = 0; x < hsize; x++) {
				if ((x % step == 0) && (y % step == 0) && !computed_buffer[y][x]) {
					t_pixel px;
					px.x = x;
					px.y = y;

					if (data->loop->opts->opts_flags & OPT_ANTIALIAS)
					{
						if (data->loop->opts->values->aa_samples > 1)
							process_pixel_aa(world, &px, data->loop->opts->values->aa_samples);
					}
					else
						process_pixel_color(world, ray, comp, &px);

					computed_buffer[y][x] = true;
					put_pixel_to_img(data->loop->img, px.x, px.y, px.color);
				}
			}
			// Periodically update the display
			if (y % 10 == 0) {
				update_display(data->loop);
			}
		}
	}

	for (int i = 0; i < vsize; i++) free(computed_buffer[i]);
	free(computed_buffer);
	free_worker_memory(ray, comp);
	pthread_exit(NULL);
}

// Function to join all threads after rendering
void join_threads(pthread_t *threads, int thread_count)
{
	for (int i = 0; i < thread_count; i++) {
		pthread_join(threads[i], NULL);
	}
}

// Multi-threaded render function
void render_multithreaded(t_loop *loop)
{
	int thread_count = loop->opts->values->threads;
	if (thread_count < 1) thread_count = 1;

	pthread_t *threads = malloc(thread_count * sizeof(pthread_t));
	t_thread_data *thread_data = malloc(thread_count * sizeof(t_thread_data));

	if (!threads || !thread_data) {
		 ft_dprintf(2, "Memory allocation failed.\n");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < thread_count; i++) {
		thread_data[i].loop = loop;
		thread_data[i].thread_id = i;
		thread_data[i].total_threads = thread_count;

		if (pthread_create(&threads[i], NULL, render_worker, &thread_data[i]) != 0) {
			 ft_dprintf(2, "Failed to create thread %d\n", i);
			exit(EXIT_FAILURE);
		}
	}
	join_threads(threads, thread_count);
	mlx_put_image_to_window(loop->mlx, loop->win, loop->img->img, 0, 0);
	if (loop->opts->opts_flags & OPT_SAVE) {
		printf("Saving image to '%s'\n", loop->opts->values->filename);
		save_image(loop->img, loop->opts->values->filename);
	}
	free(threads);
	free(thread_data);
}
