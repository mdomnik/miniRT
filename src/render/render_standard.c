/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_standard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:16:45 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/15 09:52:04 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

int	*init_pixel_order(int total_pixels)
{
	int	*pixel_order;
	int	i;
	int	j;
	int	temp;

	pixel_order = malloc(total_pixels * sizeof(int));
	i = 0;
	while (i < total_pixels)
	{
		pixel_order[i] = i;
		i++;
	}
	ft_srand(42);
	i = total_pixels - 1;
	while (i > 0)
	{
		j = ft_rand() % (i + 1);
		temp = pixel_order[i];
		pixel_order[i] = pixel_order[j];
		pixel_order[j] = temp;
		i--;
	}
	return (pixel_order);
}

t_render_data	*init_render_data(t_world *world, t_loop *loop)
{
	t_render_data	*data;
	int				i;

	data = malloc(sizeof(t_render_data));
	if (!data)
		return (NULL);
	data->ray = malloc((RECURSIVE_DEPTH + 1) * sizeof(t_ray *));
	data->comp = malloc((RECURSIVE_DEPTH + 1) * sizeof(t_comp *));
	i = -1;
	while (++i <= RECURSIVE_DEPTH)
	{
		data->ray[i] = malloc(sizeof(t_ray));
		data->comp[i] = malloc(sizeof(t_comp));
	}
	data->cmped_buf = malloc(world->camera->vsize * sizeof(bool *));
	i = -1;
	while (++i < world->camera->vsize)
		data->cmped_buf[i] = ft_calloc(world->camera->hsize, sizeof(bool));
	data->total_pixels = world->camera->vsize * world->camera->hsize;
	data->pixel_order = init_pixel_order(data->total_pixels);
	data->width = world->camera->hsize;
	data->height = world->camera->vsize;
	data->img = loop->img;
	data->mlx = loop->mlx;
	return ((data->win = loop->win), data);
}

static t_world	*create_world(t_loop *l)
{
	t_world	*world;

	world = malloc(sizeof(t_world));
	if (!world)
		return (NULL);
	world->camera = NULL;
	world->light = NULL;
	world->shapes = NULL;
	if (create_objects(l->opts, world) == -1)
	{
		free_world(world);
		key_hook(ESCAPE, l);
		return (NULL);
	}
	return (world);
}

void	render_single(t_loop *l)
{
	t_world			*world;
	t_render_data	*data;
	int				step;

	world = create_world(l);
	if (!world)
		return ;
	data = init_render_data(world, l);
	if (!data && (free_world(world), 1))
		return ;
	step = 16;
	while (step >= 1)
	{
		process_step_pixels(data, world, step, l);
		step /= 2;
	}
	mlx_put_image_to_window(l->mlx, l->win, l->img->img, 0, 0);
	if (l->opts->opts_flags & OPT_SAVE && l->opts->values->filename != NULL)
		save_image(l->img, l->opts->values->filename);
	free_render_data(data);
	free_world(world);
}
