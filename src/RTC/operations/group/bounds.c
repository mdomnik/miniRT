/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bounds.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:41:02 by mdomnik           #+#    #+#             */
/*   Updated: 2025/01/17 18:37:18 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

t_bounds group_bounds(t_shape *group)
{
    t_bounds group_bounds;
    group_bounds.min = new_point3(INFINITY, INFINITY, INFINITY);
    group_bounds.max = new_point3(-INFINITY, -INFINITY, -INFINITY);

    t_shape *child = group->children;

    while (child != NULL) {
        // Compute child bounds in its local space
        t_bounds child_bounds = child->bounds(child);

        // Transform the child bounds to group space
        t_bounds transformed_bounds = transform_bounds(child_bounds, &child->transform);

        // Update the group bounds to include the transformed bounds
        group_bounds.min.x = fminf(group_bounds.min.x, transformed_bounds.min.x);
        group_bounds.min.y = fminf(group_bounds.min.y, transformed_bounds.min.y);
        group_bounds.min.z = fminf(group_bounds.min.z, transformed_bounds.min.z);

        group_bounds.max.x = fmaxf(group_bounds.max.x, transformed_bounds.max.x);
        group_bounds.max.y = fmaxf(group_bounds.max.y, transformed_bounds.max.y);
        group_bounds.max.z = fmaxf(group_bounds.max.z, transformed_bounds.max.z);

        child = child->next;
    }
    return group_bounds;
}


t_bounds transform_bounds(t_bounds bounds, t_matrix *transform)
{
	t_bounds transformed_bounds;
	
	transformed_bounds.min = new_point3(INFINITY, INFINITY, INFINITY);
	transformed_bounds.max = new_point3(-INFINITY, -INFINITY, -INFINITY);

	t_point3 corners[8] = {
		new_point3(bounds.min.x, bounds.min.y, bounds.min.z),
		new_point3(bounds.min.x, bounds.min.y, bounds.max.z),
		new_point3(bounds.min.x, bounds.max.y, bounds.min.z),
		new_point3(bounds.min.x, bounds.max.y, bounds.max.z),
		new_point3(bounds.max.x, bounds.min.y, bounds.min.z),
		new_point3(bounds.max.x, bounds.min.y, bounds.max.z),
		new_point3(bounds.max.x, bounds.max.y, bounds.min.z),
		new_point3(bounds.max.x, bounds.max.y, bounds.max.z),
	};

	int i;
	i = 0;
	while (i < 8)
	{
		t_point3 transformed = multiply_matrix_tuple(transform, &corners[i]);
		if (isnan(transformed.x) || isnan(transformed.y) || isnan(transformed.z))
		{
			printf("Invalid transformation detected.\n");
			continue;
		}

		transformed_bounds.min.x = fminf(transformed_bounds.min.x, transformed.x);
		transformed_bounds.min.y = fminf(transformed_bounds.min.y, transformed.y);
		transformed_bounds.min.z = fminf(transformed_bounds.min.z, transformed.z);

		transformed_bounds.max.x = fmaxf(transformed_bounds.max.x, transformed.x);
		transformed_bounds.max.y = fmaxf(transformed_bounds.max.y, transformed.y);
		transformed_bounds.max.z = fmaxf(transformed_bounds.max.z, transformed.z);
		i++;
	}

	return transformed_bounds;
}

t_bounds bounds_unit(struct s_shape *shape)
{
	t_bounds bounds;

	(void)shape;
	bounds.min = new_point3(-1, -1, -1);
	bounds.max = new_point3(1, 1, 1);
	return bounds;
}

t_bounds bounds_inf(struct s_shape *shape)
{
	t_bounds bounds;

	(void)shape;
	bounds.min = new_point3(-INFINITY, 0, -INFINITY);
	bounds.max = new_point3(INFINITY, 0, INFINITY);
	return bounds;
}

t_bounds bounds_cap(struct s_shape *shape)
{
	t_bounds bounds;

	bounds.min = new_point3(-1, shape->size_cap.min, -1);
	bounds.max = new_point3(1, shape->size_cap.max, 1);
	return bounds;
}

t_bounds bounds_triangle(struct s_shape *shape)
{
    t_bounds bounds;
    t_point3 p1 = shape->triangle->p1;
    t_point3 p2 = shape->triangle->p2;
    t_point3 p3 = shape->triangle->p3;

    // Calculate min bounds
    bounds.min.x = fmin(fmin(p1.x, p2.x), p3.x);
    bounds.min.y = fmin(fmin(p1.y, p2.y), p3.y);
    bounds.min.z = fmin(fmin(p1.z, p2.z), p3.z);

    // Calculate max bounds
    bounds.max.x = fmax(fmax(p1.x, p2.x), p3.x);
    bounds.max.y = fmax(fmax(p1.y, p2.y), p3.y);
    bounds.max.z = fmax(fmax(p1.z, p2.z), p3.z);

    return bounds;
}


bool intersect_bounds(t_bounds bounds, t_ray *ray)
{
	float t_min = -INFINITY;
	float t_max = INFINITY;

	for (int i = 0; i < 3; i++) {
		float inv_dir = 1.0f / ray->dir.a[i];
		float t0 = (bounds.min.a[i] - ray->orig.a[i]) * inv_dir;
		float t1 = (bounds.max.a[i] - ray->orig.a[i]) * inv_dir;
		if (inv_dir < 0.0f) {
			float temp = t0;
			t0 = t1;
			t1 = temp;
		}
		t_min = fmaxf(t_min, t0);
		t_max = fminf(t_max, t1);
		if (t_min > t_max) {
			return false;
		}
	}
	return true;
}





