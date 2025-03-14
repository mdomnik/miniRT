/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_worker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 02:32:53 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/14 02:37:33 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

void	*render_worker(void *arg)
{
	t_thread_data	*data;
	t_world			*world;
	t_ray			*ray[RECURSIVE_DEPTH + 1] = {NULL};
	t_comp			*comp[RECURSIVE_DEPTH + 1] = {NULL};
	int				hsize;
	int				vsize;
	bool			**computed_buffer;

	data = (t_thread_data *)arg;
	world = init_local_world(data);
	if (!world)
	{
		fprintf(stderr, "Thread %d failed to initialize world.\n",
			data->thread_id);
		pthread_exit(NULL);
	}
	if (!init_worker_memory(ray, comp))
	{
		free_world(world);
		pthread_exit(NULL);
	}
	hsize = world->camera->hsize;
	vsize = world->camera->vsize;
	computed_buffer = malloc(vsize * sizeof(bool *));
	if (!computed_buffer)
	{
		free_worker_memory(ray, comp);
		free_world(world);
		pthread_exit(NULL);
	}
	for (int i = 0; i < vsize; i++)
	{
		computed_buffer[i] = calloc(hsize, sizeof(bool));
		if (!computed_buffer[i])
		{
			for (int j = 0; j < i; j++)
				free(computed_buffer[j]);
			free(computed_buffer);
			free_worker_memory(ray, comp);
			free_world(world);
			pthread_exit(NULL);
		}
	}
	for (int step = 16; step >= 1; step /= 2)
	{
		for (int y = data->thread_id; y < vsize; y += data->total_threads)
		{
			for (int x = 0; x < hsize; x++)
			{
				if ((x % step == 0) && (y % step == 0)
					&& !computed_buffer[y][x])
				{
					t_pixel px;
					px.x = x;
					px.y = y;
					if (data->loop->opts->opts_flags & OPT_ANTIALIAS)
					{
						if (data->loop->opts->values->aa_samples > 1)
							process_pixel_aa(world, &px,
								data->loop->opts->values->aa_samples);
					}
					else
						process_pixel_color(world, ray, comp, &px);
					computed_buffer[y][x] = true;
					put_pixel_to_img(data->loop->img, px.x, px.y, px.color);
				}
			}
			if (y % 10 == 0)
				update_display(data->loop);
		}
	}
	for (int i = 0; i < vsize; i++)
		free(computed_buffer[i]);
	free(computed_buffer);
	free_worker_memory(ray, comp);
	free_world(world);
	pthread_exit(NULL);
}
