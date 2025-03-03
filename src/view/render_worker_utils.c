/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_worker_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:45:51 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/26 19:01:09 by mdomnik          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "forward.h"
#include "mrt.h"

pthread_mutex_t	g_check_args_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t	g_mlx_mutex = PTHREAD_MUTEX_INITIALIZER;

t_world	*init_local_world(t_thread_data *data)
{
	t_world	*local_world;

	local_world = malloc(sizeof(t_world));
	if (!local_world)
		return (NULL);
	local_world->camera = NULL;
	local_world->light = NULL;
	local_world->shapes = NULL;
	pthread_mutex_lock(&g_check_args_mutex);
	if (make_world(data->loop->opts, local_world) == -1)
	{
		pthread_mutex_unlock(&g_check_args_mutex);
		free(local_world);
		return (NULL);
	}
	pthread_mutex_unlock(&g_check_args_mutex);
	return (local_world);
}

void	process_row(t_thread_data *data, t_world *world,
	int y, t_ray **ray, t_comp **comp)
{
	int	x;

	x = data->thread_id - 1;
	x += NUM_THREADS;
	while (x < world->camera->hsize)
	{
		process_pixel(data, world,
			(int [2]){x, y}, ray, comp);
		x += NUM_THREADS;
	}
}

void	update_display(t_loop *loop)
{
	pthread_mutex_lock(&g_mlx_mutex);
	mlx_put_image_to_window(loop->mlx, loop->win, loop->img->img, 0, 0);
	pthread_mutex_unlock(&g_mlx_mutex);
}

void	join_threads(pthread_t *threads)
{
	int	i;

	i = -1;
	while (++i < NUM_THREADS)
		pthread_join(threads[i], NULL);
}

void	process_pixel(t_thread_data *data, t_world *world,
	int coords[2], t_ray **ray, t_comp **comp)
{
	t_pixel	px;

	px.x = coords[0];
	px.y = coords[1];
	process_pixel_color(world, ray, comp, &px);
	put_pixel_to_img(data->loop->img, px.x, px.y, px.color);
}
