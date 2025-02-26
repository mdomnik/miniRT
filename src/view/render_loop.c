/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:45:51 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/26 19:01:09 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

t_loop *loop_init(void)
{
	t_loop *loop;

	loop = malloc(sizeof(t_loop));
	loop->mlx = mlx_init();
	loop->win = mlx_new_window(loop->mlx, DEFAULT_WIDTH, DEFAULT_HEIGHT, "test");
	loop->img = malloc(sizeof(t_image));
	loop->img->img = mlx_new_image(loop->mlx, DEFAULT_WIDTH, DEFAULT_HEIGHT);
	loop->img->buffer = mlx_get_data_addr(loop->img->img, 
										  &loop->img->bits_per_pixel, 
										  &loop->img->size_line, 
										  &loop->img->endian);
	loop->img->width = DEFAULT_WIDTH;
	loop->img->height = DEFAULT_HEIGHT;
	loop->opts = malloc(sizeof(t_options));
	loop->opts->scene.scene_objects = NULL;
	loop->opts->scene.scene_file = NULL;
	loop->opts->values = NULL;
	return loop;
}


void put_pixel_to_img(t_image *img, int x, int y, int color)
{
	if (x < 0 || y < 0 || x >= img->width || y >= img->height)
		return;

	int pixel_index = (y * img->size_line) + (x * (img->bits_per_pixel / 8));
	*(int *)(img->buffer + pixel_index) = color;
}

#define NUM_THREADS 1  // Adjust as needed


pthread_mutex_t check_args_mutex = PTHREAD_MUTEX_INITIALIZER;

pthread_mutex_t mlx_mutex = PTHREAD_MUTEX_INITIALIZER;

pthread_mutex_t printf_mutex = PTHREAD_MUTEX_INITIALIZER;

void *render_worker(void *arg)
{
	t_thread_data *data = (t_thread_data *)arg;
	t_loop *loop = data->loop;
	int thread_id = data->thread_id;
	t_camera *camera;

	// Create a new world for this thread
	t_world *local_world = malloc(sizeof(t_world));
	if (!local_world)
	{
		fprintf(stderr, "Thread %d: Failed to allocate world\n", thread_id);
		pthread_exit(NULL);
	}

	// Lock check_args to prevent race conditions
	pthread_mutex_lock(&check_args_mutex);
	if (make_world(loop->opts, local_world) == -1)
	{
		pthread_mutex_unlock(&check_args_mutex);
		fprintf(stderr, "Thread %d: Failed to initialize world\n", thread_id);
		free(local_world);
		pthread_exit(NULL);
	}
	pthread_mutex_unlock(&check_args_mutex);

	camera = local_world->camera;

	t_ray *ray[RECURSIVE_DEPTH + 1];
	t_comp *comp[RECURSIVE_DEPTH + 1];
	t_color3 color;
	int color_int;

	// Allocate rays
	for (int i = 0; i < (RECURSIVE_DEPTH + 1); i++)
	{
		ray[i] = malloc(sizeof(t_ray));
		if (!ray[i])
		{
			fprintf(stderr, "Thread %d: Failed to allocate ray[%d]\n", thread_id, i);
			free(local_world);
			pthread_exit(NULL);
		}
	}

	// Allocate rays
	for (int i = 0; i < (RECURSIVE_DEPTH + 1); i++)
	{
		comp[i] = malloc(sizeof(t_comp));
		if (!comp[i])
		{
			fprintf(stderr, "Thread %d: Failed to allocate comp[%d]\n", thread_id, i);
			free(local_world);
			pthread_exit(NULL);
		}
	}

	// Progress tracking
	int last_printed_percent = -1;
	int total_rows = camera->vsize;
		
	// Iterate through assigned pixels
	for (int y = 0; y < total_rows; y++)
	{
		for (int x = thread_id; x < camera->hsize; x += NUM_THREADS)
		{
			ray_for_pixel(camera, x, y, ray[0]);
			for (int i = 0; i < (RECURSIVE_DEPTH + 1); i++)
				memset(comp[i], 0, sizeof(t_comp));
			color = color_at(local_world, ray, comp, RECURSIVE_DEPTH);
			color_int = color_to_int(color);
			put_pixel_to_img(loop->img, x, y, color_int);
		}

		// 🔒 Lock before updating the window
		pthread_mutex_lock(&mlx_mutex);
		mlx_put_image_to_window(loop->mlx, loop->win, loop->img->img, 0, 0);
		pthread_mutex_unlock(&mlx_mutex);  // 🔓 Unlock after update

		// Calculate and print progress
		int percent_complete = (y * 100) / total_rows;
		if (percent_complete != last_printed_percent) // Avoid duplicate prints
		{
			last_printed_percent = percent_complete;
			// pthread_mutex_lock(&printf_mutex);
			// printf("Thread %d: %d%% complete\n", thread_id, percent_complete);
			// pthread_mutex_unlock(&printf_mutex);
		}
	}

	// Free allocated memory
	for (int i = 0; i < (RECURSIVE_DEPTH + 1); i++)
		free(ray[i]);
	for (int i = 0; i < (RECURSIVE_DEPTH + 1); i++)
		free(comp[i]);
	

	// Free the new world safely
	free(local_world->camera);
	free(local_world->shapes);
	free(local_world->light);
	free(local_world);

	pthread_exit(NULL);
}



void render(t_loop *loop, int ac, char *av[])
{
    pthread_t threads[NUM_THREADS];
    t_thread_data thread_data[NUM_THREADS];

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++)
    {
        thread_data[i].loop = loop;
        thread_data[i].thread_id = i;
        thread_data[i].ac = ac;
        thread_data[i].av = av;

        if (pthread_create(&threads[i], NULL, render_worker, &thread_data[i]) != 0)
        {
            fprintf(stderr, "Failed to create thread %d\n", i);
            exit(EXIT_FAILURE);
        }
    }

    // Wait for threads to complete
    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    // Display the rendered image after all threads finish
    mlx_put_image_to_window(loop->mlx, loop->win, loop->img->img, 0, 0);
    printf("Rendering done\n");
}
