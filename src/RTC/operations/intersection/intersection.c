/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 05:02:00 by mdomnik           #+#    #+#             */
/*   Updated: 2024/11/27 13:31:39 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"


static t_x *intersect_sphere(t_shape *sphere, t_ray *ray)
{
	t_x	*xs;
	t_vec3	sphere_to_ray;
	float	a;
	float	b;
	float	c;
	float	discriminant;

	xs = malloc(sizeof(t_x));
	xs->count = 0;
	xs->i = malloc(sizeof(t_i) * 2);
	sphere_to_ray = sub_tuple(ray->orig, new_point3(0, 0, 0));
	a = dot_product(ray->dir, ray->dir);
	b = 2 * dot_product(ray->dir, sphere_to_ray);
	c = dot_product(sphere_to_ray, sphere_to_ray) - 1;
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
	{
		xs->i[0].t = 0;
		xs->i[1].t = 0;
		xs->i[0].shape = NULL;
		xs->i[1].shape = NULL;
	}
	else
	{
		xs->count = 2;
		xs->i[0].t = (-b - sqrt(discriminant)) / (2 * a);
		xs->i[1].t = (-b + sqrt(discriminant)) / (2 * a);
		xs->i[0].shape = sphere;
		xs->i[1].shape = sphere;
	}
	return (xs);
}

static t_x *intersect_plane(t_shape *plane, t_ray *ray)
{
	t_x		*xs;
	t_i		i;
	float	t;
	
	xs = malloc(sizeof(t_x));
	if (fabsf(ray->dir.y) < EPSILON)
		return (NULL);
	t = -ray->orig.y / ray->dir.y;
	i = intersection(t, plane);
	xs->count = 1;
	xs->i = malloc(sizeof(t_i));
	xs->i[0] = i;
	return (xs);
}

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
