/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 05:02:00 by mdomnik           #+#    #+#             */
/*   Updated: 2025/01/16 23:01:13 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

t_x *intersect(t_shape *shape, t_ray *ray)
{
	t_ray	*local_ray;
	t_x		*xs;
	local_ray = ray_transform(ray, inverse(shape->transform));
	shape->saved_ray = local_ray;
	xs = local_intersect(shape, local_ray);
	return(xs);
}

t_x *local_intersect(t_shape *shape, t_ray *ray)
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

//intersect a ray with an object
t_i	intersection(float t, t_shape *shape)
{
	t_i	i;

	i.t = t;
	i.shape = shape;
	return (i);
}

t_x *intersections(int num_x, t_x *xs, t_x *temp_xs)
{
	t_x		*new_xs;
	int		i;
	int		j;

	new_xs = malloc(sizeof(t_x));
	new_xs->count = num_x;
	new_xs->i = malloc(sizeof(t_i) * num_x);
	i = 0;
	while (i < xs->count)
	{
		new_xs->i[i].t = xs->i[i].t;
		new_xs->i[i].shape = xs->i[i].shape;
		i++;
	}
	j = 0;
	while (j < temp_xs->count)
	{
		new_xs->i[i].t = temp_xs->i[j].t;
		new_xs->i[i].shape = temp_xs->i[j].shape;
		i++;
		j++;
	}
	
	return (new_xs);
}

t_i hit(t_x *xs)
{
	t_i	i;
	int j;
	int		count;

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
