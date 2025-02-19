/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_and_hit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 05:02:00 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/19 15:56:51 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

// Finds all intersections between a ray and a given shape
t_x	*intersect(t_shape *shape, t_ray *ray)
{
	t_ray	*local_ray;
	t_x		*xs;

	local_ray = ray_transform(ray, inverse(shape->transform));
	shape->saved_ray = local_ray;
	xs = local_intersect(shape, local_ray);
	return (xs);
}

// Function router based on object type
t_x	*local_intersect(t_shape *shape, t_ray *ray)
{
	if (shape->type == SPHERE)
		return (intersect_sphere(shape, ray));
	if (shape->type == PLANE)
		return (intersect_plane(shape, ray));
	if (shape->type == CUBE)
		return (intersect_cube(shape, ray));
	if (shape->type == CYLINDER)
		return (intersect_cylinder(shape, ray));
	if (shape->type == CONE)
		return (intersect_cone(shape, ray));
	if (shape->type == GROUP)
		return (intersect_group(shape, ray));
	if (shape->type == TRIANGLE)
		return (intersect_triangle(shape, ray));
	return (NULL);
}

// Determines the 'hit'; lowest positive distance in intersections
t_i	hit(t_x *xs)
{
	t_i	i;
	int	j;
	int	count;

	count = xs->count;
	i.t = -1;
	i.shape = NULL;
	j = 0;
	while (j < count)
	{
		if (xs->i[j].t > 0)
		{
			if (i.shape == NULL || xs->i[j].t < i.t)
				i = xs->i[j];
		}
		j++;
	}
	return (i);
}

//intersect world
t_x	*intersect_world(t_world *world, t_ray *ray)
{
	t_x		*xs;
	t_x		*xs_temp;
	t_shape	*shape_temp;

	xs = malloc(sizeof(t_x));
	shape_temp = world->shapes;
	xs->count = 0;
	xs = intersect(world->shapes, ray);
	world->shapes = world->shapes->next;
	while (world->shapes)
	{
		xs_temp = intersect(world->shapes, ray);
		if (xs_temp != NULL)
		{
			if (xs == NULL)
				xs = xs_temp;
			else
				xs = join_intersections((xs->count + xs_temp->count), xs, xs_temp);
		}
		world->shapes = world->shapes->next;
	}
	world->shapes = shape_temp;
	sort_intersections(xs);
	return (xs);
}
