/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_caps.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:43:14 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/19 14:06:15 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"


// Checks if the intersection point of a ray with a plane lies within a unit disk.
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

	if (cylinder->size_cap.cap == false || fabsf(ray->dir.y) < EPSILON)
		return (xs);
	t = (cylinder->size_cap.min - ray->orig.y) / ray->dir.y;
	if (check_cap(ray, t) == true)
		xs = add_intersection(xs, t, cylinder);
	t = (cylinder->size_cap.max - ray->orig.y) / ray->dir.y;
	if (check_cap(ray, t) == true)
		xs = add_intersection(xs, t, cylinder);
	return (xs);
}

// Checks of the intersection point of a ray with a plane lies within the scope of caps of a cone
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
	t = (cone->size_cap.min - ray->orig.y) / ray->dir.y;
	if (check_cap_cone(ray, t, fabsf(cone->size_cap.min)))
		xs = add_intersection(xs, t, cone);
	t = (cone->size_cap.max - ray->orig.y) / ray->dir.y;
	if (check_cap_cone(ray, t, fabsf(cone->size_cap.max)))
		xs = add_intersection(xs, t, cone);
	return (xs);
}
