/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_standard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:16:45 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/13 13:17:58 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

void	render_single(t_loop *loop)
{
	t_world	*world;
	t_ray	*ray[RECURSIVE_DEPTH + 1] = {NULL};
	t_comp	*comp[RECURSIVE_DEPTH + 1] = {NULL};
	t_pixel	px;
	int		i, step, total_pixels;
	int		*pixel_order;
	bool	**computed_buffer;

	world = malloc(sizeof(t_world));
	if (!world)
		return ;
	world->camera = NULL;
	world->light = NULL;
	world->shapes = NULL;
	create_objects(loop->opts, world);
	for (i = 0; i <= RECURSIVE_DEPTH; i++)
	{
		ray[i] = malloc(sizeof(t_ray));
		comp[i] = malloc(sizeof(t_comp));
	}
	computed_buffer = malloc(world->camera->vsize * sizeof(bool *));
	for (i = 0; i < world->camera->vsize; i++)
		computed_buffer[i] = ft_calloc(world->camera->hsize, sizeof(bool));
	total_pixels = world->camera->vsize * world->camera->hsize;
	pixel_order = malloc(total_pixels * sizeof(int));
	for (i = 0; i < total_pixels; i++)
		pixel_order[i] = i;
	ft_srand(42);
	for (i = total_pixels - 1; i > 0; i--)
	{
		int j = ft_rand() % (i + 1);
		int temp = pixel_order[i];
		pixel_order[i] = pixel_order[j];
		pixel_order[j] = temp;
	}
	for (step = 16; step >= 1; step /= 2)
	{
		for (i = 0; i < total_pixels; i++)
		{
			int index = pixel_order[i];
			px.x = index % world->camera->hsize;
			px.y = index / world->camera->hsize;
			if ((fmodf(px.x, step) == 0.0f) && (fmodf(px.y, step) == 0.0f) && !computed_buffer[(int)px.y][(int)px.x])
			{
				px.color = 0;
				if (loop->opts->opts_flags & OPT_ANTIALIAS)
				{
					if (loop->opts->values->aa_samples > 1)
						process_pixel_aa(world, &px, loop->opts->values->aa_samples);
				}
				else
					process_pixel_color(world, ray, comp, &px);
				computed_buffer[(int)px.y][(int)px.x] = true;
				put_pixel_to_img(loop->img, (int)px.x, (int)px.y, px.color);
			}
			if (i % 500 == 0)
				mlx_put_image_to_window(loop->mlx, loop->win, loop->img->img, 0, 0);
		}
	}
	mlx_put_image_to_window(loop->mlx, loop->win, loop->img->img, 0, 0);
	free(pixel_order);
	for (i = 0; i < world->camera->vsize; i++)
		free(computed_buffer[i]);
	free(computed_buffer);
	for (i = 0; i <= RECURSIVE_DEPTH; i++)
	{
		free(ray[i]);
		free(comp[i]);
	}
	if (loop->opts->opts_flags & OPT_SAVE)
	{
		if (loop->opts->values->filename != NULL)
			save_image(loop->img, loop->opts->values->filename);
	}
	free_world(world);
}
