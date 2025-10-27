/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:15:22 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/14 14:35:04 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

#define PP_STEP_SIZE 0
#define PP_HALF_STEP 1
#define PP_SAMPLE_X 2
#define PP_SAMPLE_Y 3
#define PP_I 0
#define PP_J 1
#define PP_K 2

void	process_pixel_aa(t_world *world, t_pixel *px, int samples)
{
	t_color3	accumulated_color;
	int			grid_size;
	float		a[4];

	accumulated_color = new_color3(0, 0, 0);
	grid_size = sqrt(samples);
	a[PP_STEP_SIZE] = 1.0f / grid_size;
	a[PP_HALF_STEP] = a[PP_STEP_SIZE] / 2.0f;
	accumulated_color = ray_shooter(grid_size, a, px, world);
	accumulated_color = mult_color_scalar(accumulated_color, 1.0f / samples);
	px->color = color_to_int(accumulated_color);
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
