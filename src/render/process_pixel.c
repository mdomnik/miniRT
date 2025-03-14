/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:15:22 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/14 02:20:17 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

void	process_pixel_aa(t_world *world, t_pixel *px, int samples)
{
	int			i;
	int			j;
	t_color3	accumulated_color;
	t_color3	sample_color;
	t_ray		*sample_ray[RECURSIVE_DEPTH + 1];
	t_comp		*sample_comp[RECURSIVE_DEPTH + 1];
	int			grid_size;
	float		step_size;
	float		half_step;

	accumulated_color = new_color3(0, 0, 0);
	for (i = 0; i <= RECURSIVE_DEPTH; i++)
	{
		sample_ray[i] = malloc(sizeof(t_ray));
		sample_comp[i] = malloc(sizeof(t_comp));
	}
	grid_size = sqrt(samples);
	step_size = 1.0f / grid_size;
	half_step = step_size / 2.0f;
	for (i = 0; i < grid_size; i++)
	{
		for (j = 0; j < grid_size; j++)
		{
			float sample_x = px->x + (i * step_size) + half_step;
			float sample_y = px->y + (j * step_size) + half_step;
			for (int k = 0; k <= RECURSIVE_DEPTH; k++)
				ft_memset(sample_ray[k], 0, sizeof(t_ray));
			ray_for_pixel(world->camera, sample_x, sample_y, sample_ray[0]);
			for (int k = 0; k <= RECURSIVE_DEPTH; k++)
				ft_memset(sample_comp[k], 0, sizeof(t_comp));
			sample_color = color_at(world, sample_ray, sample_comp, RECURSIVE_DEPTH);
			accumulated_color = add_tuple(accumulated_color, sample_color);
		}
	}
	accumulated_color = mult_color_scalar(accumulated_color, 1.0f / samples);
	px->color = color_to_int(accumulated_color);
	for (i = 0; i <= RECURSIVE_DEPTH; i++)
	{
		free(sample_ray[i]);
		free(sample_comp[i]);
	}
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
