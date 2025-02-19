/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 21:15:13 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/19 14:13:25 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

t_triangle	*triangle_new(t_point3 p1, t_point3 p2, t_point3 p3)
{
	t_triangle	*triangle;

	triangle = malloc(sizeof(t_triangle));
	triangle->p1 = p1;
	triangle->p2 = p2;
	triangle->p3 = p3;
	triangle->e1 = sub_tuple(p2, p1);
	triangle->e2 = sub_tuple(p3, p1);
	triangle->normal = normalize(cross_product(triangle->e2, triangle->e1));
	return (triangle);
}

t_x	*intersect_triangle(t_shape *shape, t_ray *ray)
{
	t_x		*xs;
	t_vec3	dir_cross_e2;
	float	det;
	float	f;
	t_vec3	p1_to_origin;
	float	u;
	t_vec3	origin_cross_e1;
	float	v;
	float	t;

	dir_cross_e2 = cross_product(ray->dir, shape->triangle->e2);
	det = dot_product(shape->triangle->e1, dir_cross_e2);
	if (fabsf(det) < EPSILON)
		return (NULL);
	f = 1.0 / det;
	p1_to_origin = sub_tuple(ray->orig, shape->triangle->p1);
	u = f * dot_product(p1_to_origin, dir_cross_e2);
	if (u < 0 || u > 1)
		return (NULL);
	origin_cross_e1 = cross_product(p1_to_origin, shape->triangle->e1);
	v = f * dot_product(ray->dir, origin_cross_e1);
	if (v < 0 || (u + v) > 1)
		return (NULL);
	t = f * dot_product(shape->triangle->e2, origin_cross_e1);
	xs = malloc(sizeof(t_x));
	xs->count = 1;
	xs->i = malloc(sizeof(t_i));
	xs->i[0] = create_intersection(t, shape);
	return (xs);
}
