/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:22:56 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/14 16:11:12 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

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
	pthread_mutex_lock(&loop->mutexes->mlx);
	mlx_put_image_to_window(loop->mlx, loop->win, loop->img->img, 0, 0);
	pthread_mutex_unlock(&loop->mutexes->mlx);
}

// Function to initialize memory for rays and computation buffers
bool	init_worker_memory(t_ray **ray, t_comp **comp)
{
	int	i;

	i = 0;
	while (i <= RECURSIVE_DEPTH)
	{
		ray[i] = ft_calloc(1, sizeof(t_ray));
		comp[i] = ft_calloc(1, sizeof(t_comp));
		if (!ray[i] || !comp[i])
			return (false);
		i++;
	}
	return (true);
}

// Function to free allocated memory
void	free_worker_memory(t_ray **ray, t_comp **comp)
{
	int	i;

	i = 0;
	while (i <= RECURSIVE_DEPTH)
	{
		free(ray[i]);
		free(comp[i]);
		i++;
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
	pthread_mutex_lock(&data->loop->mutexes->world);
	if (make_world(data->loop->opts, local_world) == -1)
	{
		pthread_mutex_unlock(&data->loop->mutexes->world);
		free(local_world);
		return (NULL);
	}
	pthread_mutex_unlock(&data->loop->mutexes->world);
	return (local_world);
}
