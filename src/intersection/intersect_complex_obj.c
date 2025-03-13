/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_complex_obj.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:56:28 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/13 14:48:15 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

// Determines if given ray hit a cone object
t_x	*intersect_cone(t_shape *cone, t_ray *ray)
{
	float	v[8];

	v[A] = (ray->dir.x * ray->dir.x + ray->dir.z
			* ray->dir.z - ray->dir.y * ray->dir.y);
	v[LOCAL_B] = 2 * (ray->orig.x * ray->dir.x + ray->orig.z
			* ray->dir.z - ray->orig.y * ray->dir.y);
	v[C] = (ray->orig.x * ray->orig.x + ray->orig.z
			* ray->orig.z - ray->orig.y * ray->orig.y);
	if (fabsf(v[A]) < EPSILON)
		return (handle_zero_a(v, cone, ray));
	v[DISC] = v[LOCAL_B] * v[LOCAL_B] - 4 * v[A] * v[C];
	if (v[DISC] < 0)
		return (NULL);
	return (handle_discriminant(v, cone, ray));
}

// Determines if given ray hit an axis-alligned bounding box (AABB) object
t_x	*intersect_cube(t_shape *cube, t_ray *ray)
{
	int		bounds[2];
	float	t[2];
	float	axis_t[3][2];
	t_x		*xs;

	bounds[MIN] = -1;
	bounds[L_MAX] = 1;
	axis_t[X][TMIN] = check_axis(ray->orig.x, ray->dir.x, false, bounds);
	axis_t[X][TMAX] = check_axis(ray->orig.x, ray->dir.x, true, bounds);
	axis_t[Y][TMIN] = check_axis(ray->orig.y, ray->dir.y, false, bounds);
	axis_t[Y][TMAX] = check_axis(ray->orig.y, ray->dir.y, true, bounds);
	axis_t[Z][TMIN] = check_axis(ray->orig.z, ray->dir.z, false, bounds);
	axis_t[Z][TMAX] = check_axis(ray->orig.z, ray->dir.z, true, bounds);
	t[TMIN] = fmaxf(fmaxf(axis_t[X][TMIN], axis_t[Y][TMIN]), axis_t[Z][TMIN]);
	t[TMAX] = fminf(fminf(axis_t[X][TMAX], axis_t[Y][TMAX]), axis_t[Z][TMAX]);
	xs = ft_calloc(1, sizeof(t_x));
	if (t[TMIN] > t[TMAX])
		return (xs->count = 0, xs);
	xs->count = 2;
	xs->i = malloc(sizeof(t_i) * 2);
	xs->i[0] = create_intersection(t[TMIN], cube);
	xs->i[1] = create_intersection(t[TMAX], cube);
	return (xs);
}

// Determines if given ray hit a group bounding box object
t_x	*intersect_group(t_shape *group, t_ray *ray)
{
	t_x		*xs;
	t_shape	*child;
	t_x		*temp_xs;

	if (!intersect_bounds(group->bounds_cache, ray))
		return (NULL);
	xs = NULL;
	child = group->children;
	while (child != NULL)
	{
		temp_xs = intersect(child, ray);
		if (temp_xs != NULL)
			xs = handle_child_intersection(xs, temp_xs);
		child = child->next;
	}
	if (xs != NULL && xs->count > 1)
		sort_intersections(xs);
	return (xs);
}

t_x	*intersect_triangle(t_shape *shape, t_ray *ray)
{
	t_vec3	vec[3];
	float	v[5];
	t_x		*xs;

	vec[DIR_CROSS_E2] = cross_product(ray->dir, shape->triangle->e2);
	v[DET] = dot_product(shape->triangle->e1, vec[DIR_CROSS_E2]);
	if (fabsf(v[DET]) < EPSILON)
		return (NULL);
	v[F] = 1.0 / v[DET];
	vec[P1_TO_ORIGIN] = sub_tuple(ray->orig, shape->triangle->p1);
	v[U] = v[F] * dot_product(vec[P1_TO_ORIGIN], vec[DIR_CROSS_E2]);
	if (v[U] < 0 || v[U] > 1)
		return (NULL);
	vec[ORIGIN_CROSS_E1] = cross_product(vec[P1_TO_ORIGIN],
			shape->triangle->e1);
	v[V] = v[F] * dot_product(ray->dir, vec[ORIGIN_CROSS_E1]);
	if (v[V] < 0 || (v[U] + v[V]) > 1)
		return (NULL);
	v[T] = v[F] * dot_product(shape->triangle->e2, vec[ORIGIN_CROSS_E1]);
	xs = malloc(sizeof(t_x));
	xs->count = 1;
	xs->i = malloc(sizeof(t_i));
	xs->i[0] = create_intersection(v[T], shape);
	return (xs);
}
