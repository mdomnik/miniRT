/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:45:36 by mdomnik           #+#    #+#             */
/*   Updated: 2024/11/27 15:04:09 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

t_color3	reflected_color(t_world *world, t_comp *comps, int remaining)
{
	t_ray	*reflect_ray;
	t_color3	color;

	if (remaining < 1)
		return (new_color3(0, 0, 0));
	if (comps->shape->material.reflective == 0) //maybe should be world
		return (new_color3(0, 0, 0));
	reflect_ray = ray_new(&comps->over_point, &comps->reflectv);
	color = color_at(world, reflect_ray, remaining - 1);
	return (mult_tuple(color, comps->shape->material.reflective));
}
