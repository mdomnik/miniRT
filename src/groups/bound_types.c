/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bound_types.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:59:26 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/15 10:38:01 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

t_bounds	bounds_unit(struct s_shape *shape)
{
	t_bounds	bounds;

	(void)shape;
	bounds.min = new_point3(-1, -1, -1);
	bounds.max = new_point3(1, 1, 1);
	bounds.initialized = false;
	return (bounds);
}

t_bounds	bounds_inf(struct s_shape *shape)
{
	t_bounds	bounds;

	(void)shape;
	bounds.min = new_point3(-INFINITY, 0, -INFINITY);
	bounds.max = new_point3(INFINITY, 0, INFINITY);
	bounds.initialized = false;
	return (bounds);
}

t_bounds	bounds_cap(struct s_shape *shape)
{
	t_bounds	bounds;

	bounds.min = new_point3(-1, shape->size_cap.min, -1);
	bounds.max = new_point3(1, shape->size_cap.max, 1);
	bounds.initialized = false;
	return (bounds);
}

t_bounds	bounds_triangle(struct s_shape *shape)
{
	t_bounds	bounds;
	t_point3	p1;
	t_point3	p2;
	t_point3	p3;

	p1 = shape->triangle->p1;
	p2 = shape->triangle->p2;
	p3 = shape->triangle->p3;
	bounds.min.x = fmin(fmin(p1.x, p2.x), p3.x);
	bounds.min.y = fmin(fmin(p1.y, p2.y), p3.y);
	bounds.min.z = fmin(fmin(p1.z, p2.z), p3.z);
	bounds.max.x = fmax(fmax(p1.x, p2.x), p3.x);
	bounds.max.y = fmax(fmax(p1.y, p2.y), p3.y);
	bounds.max.z = fmax(fmax(p1.z, p2.z), p3.z);
	bounds.initialized = false;
	return (bounds);
}
