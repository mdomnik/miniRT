/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bound_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:41:02 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/24 20:27:31 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

static void	update_group_bounds(t_bounds *group_bounds, t_bounds *child_bounds)
{
	group_bounds->min.x = fminf(group_bounds->min.x, child_bounds->min.x);
	group_bounds->min.y = fminf(group_bounds->min.y, child_bounds->min.y);
	group_bounds->min.z = fminf(group_bounds->min.z, child_bounds->min.z);
	group_bounds->max.x = fmaxf(group_bounds->max.x, child_bounds->max.x);
	group_bounds->max.y = fmaxf(group_bounds->max.y, child_bounds->max.y);
	group_bounds->max.z = fmaxf(group_bounds->max.z, child_bounds->max.z);
}

t_bounds	group_bounds(t_shape *group)
{
	t_bounds	group_bounds;
	t_shape		*child;

	group_bounds.min = new_point3(INFINITY, INFINITY, INFINITY);
	group_bounds.max = new_point3(-INFINITY, -INFINITY, -INFINITY);
	child = group->children;
	while (child != NULL)
	{
		if (!child->bounds_cache.initialized)
		{
			child->bounds_cache = child->bounds(child);
			child->transformed_bounds_cache = transform_bounds(
					child->bounds_cache, &child->transform);
			child->bounds_cache.initialized = true;
			update_group_bounds(&group_bounds,
				&child->transformed_bounds_cache);
		}
		child = child->next;
	}
	return (group_bounds);
}

static void	update_transformed_bounds(t_bounds *bounds, t_point3 transformed)
{
	if (isnan(transformed.x) || isnan(transformed.y) || isnan(transformed.z))
	{
		printf("Invalid transformation detected.\n");
		return ;
	}
	bounds->min.x = fminf(bounds->min.x, transformed.x);
	bounds->min.y = fminf(bounds->min.y, transformed.y);
	bounds->min.z = fminf(bounds->min.z, transformed.z);
	bounds->max.x = fmaxf(bounds->max.x, transformed.x);
	bounds->max.y = fmaxf(bounds->max.y, transformed.y);
	bounds->max.z = fmaxf(bounds->max.z, transformed.z);
}

t_bounds	transform_bounds(t_bounds bounds, t_matrix *transform)
{
	t_bounds	transformed_bounds;
	int			i;
	t_point3	transformed;
	t_point3	corners[8];

	transformed_bounds.min = new_point3(INFINITY, INFINITY, INFINITY);
	transformed_bounds.max = new_point3(-INFINITY, -INFINITY, -INFINITY);
	corners[0] = new_point3(bounds.min.x, bounds.min.y, bounds.min.z);
	corners[1] = new_point3(bounds.min.x, bounds.min.y, bounds.max.z);
	corners[2] = new_point3(bounds.min.x, bounds.max.y, bounds.min.z);
	corners[3] = new_point3(bounds.min.x, bounds.max.y, bounds.max.z);
	corners[4] = new_point3(bounds.max.x, bounds.min.y, bounds.min.z);
	corners[5] = new_point3(bounds.max.x, bounds.min.y, bounds.max.z);
	corners[6] = new_point3(bounds.max.x, bounds.max.y, bounds.min.z);
	corners[7] = new_point3(bounds.max.x, bounds.max.y, bounds.max.z);
	i = 0;
	while (i < 8)
	{
		transformed = multiply_matrix_tuple(*transform, corners[i]);
		update_transformed_bounds(&transformed_bounds, transformed);
		i++;
	}
	return (transformed_bounds);
}

#define BO_TMIN 0
#define BO_TMAX 1
#define BO_INV_DIR 2
#define BO_T0 3
#define BO_T1 4

bool	intersect_bounds(t_bounds bounds, t_ray *ray)
{
	float	v[5];
	int		i;

	v[BO_TMIN] = -INFINITY;
	v[BO_TMAX] = INFINITY;
	i = 0;
	while (i < 3)
	{
		v[BO_INV_DIR] = 1.0f / ray->dir.a[i];
		v[BO_T0] = (bounds.min.a[i] - ray->orig.a[i]) * v[BO_INV_DIR];
		v[BO_T1] = (bounds.max.a[i] - ray->orig.a[i]) * v[BO_INV_DIR];
		if (v[BO_INV_DIR] < 0.0f)
			ft_swap(&v[BO_T0], &v[BO_T1]);
		v[BO_TMIN] = fmaxf(v[BO_TMIN], v[BO_T0]);
		v[BO_TMAX] = fminf(v[BO_TMAX], v[BO_T1]);
		if (v[BO_TMIN] > v[BO_TMAX])
			return (false);
		i++;
	}
	return (true);
}
