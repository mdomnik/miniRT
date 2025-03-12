/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:22:56 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/12 20:30:57 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

pthread_mutex_t	g_check_args_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t	g_world_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t	g_mlx_mutex = PTHREAD_MUTEX_INITIALIZER;

void	put_pixel_to_img(t_image *img, int x, int y, int color)
{
	int	pixel_index;

	if (x < 0 || y < 0 || x >= img->width || y >= img->height)
		return ;
	pixel_index = (y * img->size_line) + (x * (img->bits_per_pixel / 8));
	*(int *)(img->buffer + pixel_index) = color;
}

// Function to update the display safely
void	update_display(t_loop *loop)
{
	pthread_mutex_lock(&g_mlx_mutex);
	mlx_put_image_to_window(loop->mlx, loop->win, loop->img->img, 0, 0);
	pthread_mutex_unlock(&g_mlx_mutex);
}

// Function to initialize memory for rays and computation buffers
bool	init_worker_memory(t_ray **ray, t_comp **comp)
{
	for (int i = 0; i <= RECURSIVE_DEPTH; i++)
	{
		ray[i] = malloc(sizeof(t_ray));
		comp[i] = malloc(sizeof(t_comp));
		if (!ray[i] || !comp[i])
			return (false);
	}
	return (true);
}

// Function to free allocated memory
void	free_worker_memory(t_ray **ray, t_comp **comp)
{
	for (int i = 0; i <= RECURSIVE_DEPTH; i++)
	{
		free(ray[i]);
		free(comp[i]);
	}
}

t_world	*init_local_world(t_thread_data *data)
{
	t_world	*local_world;

	local_world = malloc(sizeof(t_world));
	if (!local_world)
		return (NULL);
	local_world->camera = NULL;
	local_world->light = NULL;
	local_world->shapes = NULL;
	pthread_mutex_lock(&g_world_mutex);
	if (make_world(data->loop->opts, local_world) == -1)
	{
		pthread_mutex_unlock(&g_world_mutex);
		free(local_world);
		return (NULL);
	}
	pthread_mutex_unlock(&g_world_mutex);
	return (local_world);
}
