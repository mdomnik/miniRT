/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_inter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:28:44 by mdomnik           #+#    #+#             */
/*   Updated: 2024/12/03 22:51:12 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

t_x *intersect_sphere(t_shape *sphere, t_ray *ray)
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

t_x *intersect_plane(t_shape *plane, t_ray *ray)
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

//AABB axis-alligned bounding box
t_x *intersect_cube(t_shape *cube, t_ray *ray)
{
	float	xtmin;
	float	xtmax;
	float	ytmin;
	float	ytmax;
	float	ztmin;
	float	ztmax;
	float	tmin;
	float	tmax;
	t_i i1;
	t_i i2;
	t_x *xs;

	xtmin = check_axis(ray->orig.x, ray->dir.x, false);
	xtmax = check_axis(ray->orig.x, ray->dir.x, true);
	ytmin = check_axis(ray->orig.y, ray->dir.y, false);
	ytmax = check_axis(ray->orig.y, ray->dir.y, true);
	ztmin = check_axis(ray->orig.z, ray->dir.z, false);
	ztmax = check_axis(ray->orig.z, ray->dir.z, true);
	
	tmin = fmaxf(fmaxf(xtmin, ytmin), ztmin);
	tmax = fminf(fminf(xtmax, ytmax), ztmax);

	i1 = intersection(tmin, cube);
	i2 = intersection(tmax, cube);
	xs = malloc(sizeof(t_x));

	if (tmin > tmax)
	{
		xs->count = 0;
		return (xs);
	}
	xs->count = 2;
	xs->i = malloc(sizeof(t_i) * 2);
	xs->i[0] = i1;
	xs->i[1] = i2;
	return (xs);
}

t_x *intersect_cylinder(t_shape *cylinder, t_ray *ray)
{
	float	a;
	float	b;
	float	c;
	float	discriminant;
	float 	t0;
	float 	t1;
	t_x		*xs;
	
	a = ray->dir.x * ray->dir.x + ray->dir.z * ray->dir.z;
	if (a < EPSILON && CYL_CLOSED == false)
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
		float temp = t0;
		t0 = t1;
		t1 = temp;
	}
	xs = malloc(sizeof(t_x));
	xs->count = 0;
	xs->i = malloc(sizeof(t_i) * 2);
	float y0 = ray->orig.y + t0 * ray->dir.y;
	if (CYL_MIN < y0 && y0 < CYL_MAX)
		xs = add_intersection(xs, t0, cylinder);
	float y1 = ray->orig.y + t1 * ray->dir.y;
	if(CYL_MIN < y1 && y1 < CYL_MAX)
		xs = add_intersection(xs, t1, cylinder);
	xs = intersect_caps(cylinder, ray, xs);
	return (xs);
}

t_x *intersect_cone(t_shape *cone, t_ray *ray)
{
	float a, b, c, discriminant, t0, t1, temp, y0, y1;
	t_x *xs = malloc(sizeof(t_x));
	xs->count = 0;
	xs->i = malloc(sizeof(t_i) * 2);

	a = ray->dir.x * ray->dir.x - ray->dir.y * ray->dir.y + ray->dir.z * ray->dir.z;
	b = 2 * (ray->orig.x * ray->dir.x - ray->orig.y * ray->dir.y + ray->orig.z * ray->dir.z);
	c = ray->orig.x * ray->orig.x - ray->orig.y * ray->orig.y + ray->orig.z * ray->orig.z;


	if (fabs(a) < EPSILON)
	{
		if (fabs(b) < EPSILON)
		{
			free(xs->i);
			free(xs);
			return NULL;
		}
		t0 = -c / (2 * b);
		xs = add_intersection(xs, t0, cone);
		return xs;
	}
	discriminant = b * b - 4 * a * c;
	if (discriminant < -EPSILON)
	{
		free(xs->i);
		free(xs);
		return NULL;
	}
	else if (fabs(discriminant) < EPSILON)
		discriminant = 0.0f;
	t0 = (-b - sqrt(discriminant)) / (2 * a);
	t1 = (-b + sqrt(discriminant)) / (2 * a);
	if (t0 > t1)
	{
		temp = t0;
		t0 = t1;
		t1 = temp;
	}
	y0 = ray->orig.y + t0 * ray->dir.y;
	if (CONE_MIN < y0 && y0 < CONE_MAX)
		xs = add_intersection(xs, t0, cone);
	y1 = ray->orig.y + t1 * ray->dir.y;
	if (CONE_MIN < y1 && y1 < CONE_MAX)
		xs = add_intersection(xs, t1, cone);
	xs = intersect_caps_cone(cone, ray, xs);
	if (xs->count == 0)
	{
		free(xs->i);
		free(xs);
		return (NULL);
	}
	return (xs);
}

