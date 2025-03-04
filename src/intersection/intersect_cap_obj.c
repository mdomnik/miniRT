/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cap_obj.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:43:14 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/23 18:18:45 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

// Checks if the intersection point of a ray with a plane lies within
// a unit disk.
static bool	check_cap(t_ray *ray, float t)
{
	float	x;
	float	z;

	x = ray->orig.x + t * ray->dir.x;
	z = ray->orig.z + t * ray->dir.z;
	return (x * x + z * z <= 1);
}

// Finds the intersections between ray and caps of a cylinder
t_x	*intersect_caps(t_shape *cylinder, t_ray *ray, t_x *xs)
{
	float	t;

	if (!cylinder->size_cap.cap)
		return (xs);
	if (fabsf(ray->dir.y) > EPSILON)
	{
		t = (cylinder->size_cap.min - ray->orig.y) / ray->dir.y;
		if (check_cap(ray, t))
			xs = add_intersection(xs, t, cylinder);
		t = (cylinder->size_cap.max - ray->orig.y) / ray->dir.y;
		if (check_cap(ray, t))
			xs = add_intersection(xs, t, cylinder);
	}
	return (xs);
}

// Checks of the intersection point of a ray with a plane lies within
// the scope of caps of a cone
static bool	check_cap_cone(t_ray *ray, float t, float cap_radius)
{
	float	x;
	float	z;

	x = ray->orig.x + t * ray->dir.x;
	z = ray->orig.z + t * ray->dir.z;
	return (x * x + z * z <= cap_radius * cap_radius);
}

// Finds the intersections between ray and caps of a cone
t_x	*intersect_caps_cone(t_shape *cone, t_ray *ray, t_x *xs)
{
	float	t;

	if (!cone->size_cap.cap || fabsf(ray->dir.y) < EPSILON)
		return (xs);
	// **Fix: Use correct radius for min/max caps**
	t = (cone->size_cap.min - ray->orig.y) / ray->dir.y;
	// Fix: should check max radius
	if (check_cap_cone(ray, t, fabsf(cone->size_cap.max)))
		xs = add_intersection(xs, t, cone);
	t = (cone->size_cap.max - ray->orig.y) / ray->dir.y;
	if (check_cap_cone(ray, t, fabsf(cone->size_cap.max)))
		xs = add_intersection(xs, t, cone);
	return (xs);
}

//makes ends of the cylinder
//makes ends of the cylinder
void	apply_cap_transformation(t_shape *cone, t_matrix *transform)
{
	float	translate_y;
	float	scale_y;

	translate_y = transform->a[1][3];
	scale_y = transform->a[1][1];
	cone->size_cap.min = translate_y - 1;
	cone->size_cap.max = translate_y + (1.0 * scale_y) - 1;
}
