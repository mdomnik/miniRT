/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection_and_refraction.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:53:38 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/19 18:57:37 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

t_color3	reflected_color(t_world *world, t_comp *comps, int remaining)
{
	t_ray		*reflect_ray;
	t_color3	color;

	if (remaining < 1)
		return (new_color3(0, 0, 0));
	if (comps->shape->material.reflective == 0) //maybe should be world
		return (new_color3(0, 0, 0));
	reflect_ray = ray_new(&comps->over_point, &comps->reflectv);
	color = color_at(world, reflect_ray, remaining - 1);
	return (mult_tuple(color, comps->shape->material.reflective));
}

//refracted color
t_color3	refracted_color(t_world *world, t_comp *comps, int remaining)
{
	float		n_ratio;
	float		cos_i;
	float		sin2_t;
	float		cos_t;
	t_vec3		direction;
	t_ray		*refract_ray;
	t_color3	color;

	if (remaining <= 0)
		return (new_color3(0, 0, 0));
	if (comps->shape->material.transparency == 0)
		return (new_color3(0, 0, 0));
	n_ratio = comps->n1 / comps->n2;
	cos_i = dot_product(comps->eyev, comps->normalv);
	print_tuple(comps->eyev);
	print_tuple(comps->normalv);
	sin2_t = (n_ratio * n_ratio) * (1 - (cos_i * cos_i));
	if (sin2_t > 1.0)
		return (new_color3(0, 0, 0));
	cos_t = sqrt(1.0 - sin2_t);
	direction = add_tuple(mult_tuple(comps->normalv,
				(n_ratio * cos_i - cos_t)), mult_tuple(comps->eyev, n_ratio));
	refract_ray = ray_new(&comps->under_point, &direction);
	color = mult_tuple(color_at(world, refract_ray, remaining - 1),
			comps->shape->material.transparency);
	return (color);
}
