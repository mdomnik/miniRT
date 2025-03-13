/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_standard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artem <artem@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:16:45 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/13 21:32:05 by artem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

void	process_pixel(t_world *world, t_render_data *data, t_pixel *px,
	t_loop *loop)
{
	px->color = 0;
	if (loop->opts->opts_flags & OPT_ANTIALIAS)
	{
		if (loop->opts->values->aa_samples > 1)
			process_pixel_aa(world, px, loop->opts->values->aa_samples);
	}
	else
		process_pixel_color(world, data->ray, data->comp, px);
}

void	process_step_pixels(t_render_data *data, t_world *world, int step,
	t_loop *loop)
{
	t_pixel	px;
	int		i;
	int		index;

	i = 0;
	while (i < data->total_pixels)
	{
		index = data->pixel_order[i];
		px.x = index % data->width;
		px.y = index / data->width;
		if ((fmodf(px.x, step) == 0.0f) && (fmodf(px.y, step) == 0.0f)
			&& !data->cmped_buf[(int)px.y][(int)px.x])
		{
			process_pixel(world, data, &px, loop);
			data->cmped_buf[(int)px.y][(int)px.x] = true;
			put_pixel_to_img(data->img, (int)px.x, (int)px.y, px.color);
		}
		if (i % 500 == 0)
			mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
		i++;
	}
}

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

void	render_single(t_loop *l)
{
	t_world			*world;
	t_render_data	*data;
	int				step;

	world = malloc(sizeof(t_world));
	if (!world)
		return ;
	world->camera = NULL;
	world->light = NULL;
	world->shapes = NULL;
	create_objects(l->opts, world);
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
