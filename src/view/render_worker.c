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

static bool	init_worker_memory(t_ray **ray, t_comp **comp)
{
	int	i;

	i = -1;
	while (++i < (RECURSIVE_DEPTH + 1))
	{
		ray[i] = malloc(sizeof(t_ray));
		if (!ray[i])
			return (false);
	}
	i = -1;
	while (++i < (RECURSIVE_DEPTH + 1))
	{
		comp[i] = malloc(sizeof(t_comp));
		if (!comp[i])
			return (false);
	}
	return (true);
}

static void	free_worker_memory(t_ray **ray, t_comp **comp, t_world *world)
{
	int	i;

	i = -1;
	while (++i < (RECURSIVE_DEPTH + 1))
		free(ray[i]);
	i = -1;
	while (++i < (RECURSIVE_DEPTH + 1))
		free(comp[i]);
	free_world(world);
}

void	process_pixel_color(t_world *world, t_ray **ray,
			t_comp **comp, t_pixel *px)
{
	int			i;
	t_color3	color;

	i = -1;
	ray_for_pixel(world->camera, px->x, px->y, ray[0]);
	while (++i < (RECURSIVE_DEPTH + 1))
		ft_memset(comp[i], 0, sizeof(t_comp));
	color = color_at(world, ray, comp, RECURSIVE_DEPTH);
	px->color = color_to_int(color);
}

static void	process_rows(t_world *world, t_thread_data *data,
			t_ray **ray, t_comp **comp)
{
	int		x;
	t_pixel	px;

	px.y = -1;
	while (++px.y < world->camera->vsize)
	{
		x = data->thread_id - 1;
		x += NUM_THREADS;
		while (x < world->camera->hsize)
		{
			px.x = x;
			process_pixel_color(world, ray, comp, &px);
			put_pixel_to_img(data->loop->img, px.x, px.y, px.color);
			x += NUM_THREADS;
		}
		update_display(data->loop);
	}
}

void	*render_worker(void *arg)
{
	t_thread_data	*data;
	t_world			*world;
	t_ray			*ray[RECURSIVE_DEPTH + 1];
	t_comp			*comp[RECURSIVE_DEPTH + 1];

	data = (t_thread_data *)arg;
	world = init_local_world(data);
	if (!world || !init_worker_memory(ray, comp))
	{
		free_worker_memory(ray, comp, world);
		pthread_exit(NULL);
	}
	process_rows(world, data, ray, comp);
	free_worker_memory(ray, comp, world);
	pthread_exit(NULL);
}
