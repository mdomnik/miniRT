/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_complex_obj.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:56:28 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/19 14:24:10 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

// Determines if given ray hit a cone object
t_x	*intersect_cone(t_shape *cone, t_ray *ray)
{
	float	a;
	float	b;
	float	c;
	float	discriminant;
	float	t0;
	float	t1;
	float	temp;
	float	y0;
	float	y1;
	t_x		*xs;

	xs = malloc(sizeof(t_x));
	xs->count = 0;
	xs->i = malloc(sizeof(t_i) * 2);
	a = ray->dir.x * ray->dir.x - ray->dir.y
		* ray->dir.y + ray->dir.z * ray->dir.z;
	b = 2 * (ray->orig.x * ray->dir.x - ray->orig.y
			* ray->dir.y + ray->orig.z * ray->dir.z);
	c = ray->orig.x * ray->orig.x - ray->orig.y
		* ray->orig.y + ray->orig.z * ray->orig.z;
	if (fabs(a) < EPSILON)
	{
		if (fabs(b) < EPSILON)
		{
			free(xs->i);
			free(xs);
			return (NULL);
		}
		t0 = -c / (2 * b);
		xs = add_intersection(xs, t0, cone);
		return (xs);
	}
	discriminant = b * b - 4 * a * c;
	if (discriminant < -EPSILON)
	{
		free(xs->i);
		free(xs);
		return (NULL);
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
	if (cone->size_cap.min < y0 && y0 < cone->size_cap.max)
		xs = add_intersection(xs, t0, cone);
	y1 = ray->orig.y + t1 * ray->dir.y;
	if (cone->size_cap.min < y1 && y1 < cone->size_cap.max)
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

// Helper function that checks the intersection along a single axis of an AABB
static float	check_axis(float origin, float direction, bool ret, int min, int max)
{
	float	tmin_numerator;
	float	tmax_numerator;
	float	tmin;
	float	tmax;
	float	temp;

	tmin_numerator = (min - origin);
	tmax_numerator = (max - origin);
	if (fabsf(direction) >= EPSILON)
	{
		tmin = tmin_numerator / direction;
		tmax = tmax_numerator / direction;
	}
	else
	{
		tmin = tmin_numerator * INFINITY;
		tmax = tmax_numerator * INFINITY;
	}
	if (tmin > tmax)
	{
		temp = tmin;
		tmin = tmax;
		tmax = temp;
	}
	if (ret == false)
		return (tmin);
	else
		return (tmax);
}

// Determines if given ray hit an axis-alligned bounding box (AABB) object
t_x	*intersect_cube(t_shape *cube, t_ray *ray)
{
	float	xtmin;
	float	xtmax;
	float	ytmin;
	float	ytmax;
	float	ztmin;
	float	ztmax;
	float	tmin;
	float	tmax;
	t_i 	i1;
	t_i 	i2;
	t_x 	*xs;

	xtmin = check_axis(ray->orig.x, ray->dir.x, false, -1, 1);
	xtmax = check_axis(ray->orig.x, ray->dir.x, true, -1, 1);
	ytmin = check_axis(ray->orig.y, ray->dir.y, false, -1, 1);
	ytmax = check_axis(ray->orig.y, ray->dir.y, true, -1, 1);
	ztmin = check_axis(ray->orig.z, ray->dir.z, false, -1, 1);
	ztmax = check_axis(ray->orig.z, ray->dir.z, true, -1, 1);
	tmin = fmaxf(fmaxf(xtmin, ytmin), ztmin);
	tmax = fminf(fminf(xtmax, ytmax), ztmax);
	i1 = create_intersection(tmin, cube);
	i2 = create_intersection(tmax, cube);
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

// Determines if given ray hit a group bounding box object
t_x	*intersect_group(t_shape *group, t_ray *ray)
{
	t_bounds	group_bounds;
	t_x			*xs;
	t_shape		*child;
	t_x			*temp_xs;

	group_bounds = group->bounds(group);
	if (!intersect_bounds(group_bounds, ray))
		return (NULL);
	xs = NULL;
	child = group->children;
	while (child != NULL)
	{
		temp_xs = intersect(child, ray);
		if (temp_xs != NULL)
		{
			if (xs == NULL)
				xs = temp_xs;
			else
			{
				xs =join_intersections((xs->count + temp_xs->count), xs, temp_xs);
				free(temp_xs->i);
				free(temp_xs);
			}
		}
		child = child->next;
	}
	if (xs != NULL && xs->count > 1)
		sort_intersections(xs);
	return (xs);
}