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

t_bounds    group_bounds(t_shape *group)
{
    t_bounds    group_bounds;
    t_shape     *child;

    group_bounds.min = new_point3(INFINITY, INFINITY, INFINITY);
    group_bounds.max = new_point3(-INFINITY, -INFINITY, -INFINITY);
    child = group->children;
    while (child != NULL)
    {
        // Use cached bounds if available, otherwise compute and cache them
        if (!child->bounds_cache.initialized)
        {
            child->bounds_cache = child->bounds(child);
			child->transformed_bounds_cache = transform_bounds(child->bounds_cache, &child->transform);
            child->bounds_cache.initialized = true;
			group_bounds.min.x = fminf(group_bounds.min.x, child->transformed_bounds_cache.min.x);
			group_bounds.min.y = fminf(group_bounds.min.y, child->transformed_bounds_cache.min.y);
			group_bounds.min.z = fminf(group_bounds.min.z, child->transformed_bounds_cache.min.z);
			group_bounds.max.x = fmaxf(group_bounds.max.x, child->transformed_bounds_cache.max.x);
			group_bounds.max.y = fmaxf(group_bounds.max.y, child->transformed_bounds_cache.max.y);
			group_bounds.max.z = fmaxf(group_bounds.max.z, child->transformed_bounds_cache.max.z);
        }
        child = child->next;
    }
    return (group_bounds);
}


t_bounds	transform_bounds(t_bounds bounds, t_matrix *transform)
{
	t_bounds	transformed_bounds;
	int			i;
	t_point3	transformed;

	transformed_bounds.min = new_point3(INFINITY, INFINITY, INFINITY);
	transformed_bounds.max = new_point3(-INFINITY, -INFINITY, -INFINITY);
	t_point3	corners[8] = {
		new_point3(bounds.min.x, bounds.min.y, bounds.min.z),
		new_point3(bounds.min.x, bounds.min.y, bounds.max.z),
		new_point3(bounds.min.x, bounds.max.y, bounds.min.z),
		new_point3(bounds.min.x, bounds.max.y, bounds.max.z),
		new_point3(bounds.max.x, bounds.min.y, bounds.min.z),
		new_point3(bounds.max.x, bounds.min.y, bounds.max.z),
		new_point3(bounds.max.x, bounds.max.y, bounds.min.z),
		new_point3(bounds.max.x, bounds.max.y, bounds.max.z),
	};
	i = 0;
	while (i < 8)
	{
		transformed = multiply_matrix_tuple(*transform, corners[i]);
		if (isnan(transformed.x)
			|| isnan(transformed.y) || isnan(transformed.z))
		{
			printf("Invalid transformation detected.\n");
			continue ;
		}
		transformed_bounds.min.x = fminf(
				transformed_bounds.min.x, transformed.x);
		transformed_bounds.min.y = fminf(
				transformed_bounds.min.y, transformed.y);
		transformed_bounds.min.z = fminf(
				transformed_bounds.min.z, transformed.z);
		transformed_bounds.max.x = fmaxf(
				transformed_bounds.max.x, transformed.x);
		transformed_bounds.max.y = fmaxf(
				transformed_bounds.max.y, transformed.y);
		transformed_bounds.max.z = fmaxf(
				transformed_bounds.max.z, transformed.z);
		i++;
	}
	return (transformed_bounds);
}

bool	intersect_bounds(t_bounds bounds, t_ray *ray)
{
	float	t_min;
	float	t_max;
	float	inv_dir;
	float	t0;
	float	t1;
	float	temp;
	int		i;

	t_min = -INFINITY;
	t_max = INFINITY;
	i = 0;
	while (i < 3)
	{
		inv_dir = 1.0f / ray->dir.a[i];
		t0 = (bounds.min.a[i] - ray->orig.a[i]) * inv_dir;
		t1 = (bounds.max.a[i] - ray->orig.a[i]) * inv_dir;
		if (inv_dir < 0.0f)
		{
			temp = t0;
			t0 = t1;
			t1 = temp;
		}
		t_min = fmaxf(t_min, t0);
		t_max = fminf(t_max, t1);
		if (t_min > t_max)
			return (false);
		i++;
	}
	return (true);
}
