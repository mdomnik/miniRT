/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_basic_obj.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:54:28 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/19 14:22:03 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

// Determines if given ray hit a sphere object
t_x	*intersect_sphere(t_shape *sphere, t_ray *ray)
{
	t_x		*xs;
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

// Determines if given ray hit a plane object
t_x	*intersect_plane(t_shape *plane, t_ray *ray)
{
	t_x		*xs;
	t_i		i;
	float	t;

	xs = malloc(sizeof(t_x));
	if (fabsf(ray->dir.y) < EPSILON)
		return (NULL);
	t = -ray->orig.y / ray->dir.y;
	i = create_intersection(t, plane);
	xs->count = 1;
	xs->i = malloc(sizeof(t_i));
	xs->i[0] = i;
	return (xs);
}

// Determines if given ray hit a cylinder object
t_x	*intersect_cylinder(t_shape *cylinder, t_ray *ray)
{
	float	a;
	float	b;
	float	c;
	float	discriminant;
	float	t0;
	float	t1;
	t_x		*xs;
	float	temp;
	float	y0;
	float	y1;

	a = ray->dir.x * ray->dir.x + ray->dir.z * ray->dir.z;
	if (a < EPSILON && cylinder->size_cap.cap == false)
		return (NULL);
	b = (2 * ray->orig.x * ray->dir.x) + (2 * ray->orig.z * ray->dir.z);
	c = ray->orig.x * ray->orig.x + ray->orig.z * ray->orig.z - 1;
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (NULL);
	t0 = (-b - sqrt(discriminant)) / (2 * a);
	t1 = (-b + sqrt(discriminant)) / (2 * a);
	if (t0 > t1)
	{
		temp = t0;
		t0 = t1;
		t1 = temp;
	}
	xs = malloc(sizeof(t_x));
	xs->count = 0;
	xs->i = malloc(sizeof(t_i) * 2);
	y0 = ray->orig.y + t0 * ray->dir.y;
	if (cylinder->size_cap.min < y0 && y0 < cylinder->size_cap.max)
		xs = add_intersection(xs, t0, cylinder);
	y1 = ray->orig.y + t1 * ray->dir.y;
	if (cylinder->size_cap.min < y1 && y1 < cylinder->size_cap.max)
		xs = add_intersection(xs, t1, cylinder);
	xs = intersect_caps(cylinder, ray, xs);
	return (xs);
}