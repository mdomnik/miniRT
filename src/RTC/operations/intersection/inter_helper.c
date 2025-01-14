/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:43:14 by mdomnik           #+#    #+#             */
/*   Updated: 2024/12/03 22:43:07 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

float check_axis(float origin, float direction, bool ret)
{
	float tmin_numerator;
	float tmax_numerator;
	float tmin;
	float tmax;
	float temp;

	tmin_numerator = (-1 - origin);
	tmax_numerator = (1 - origin);
	
	if(fabsf(direction) >= EPSILON)
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

t_x *add_intersection(t_x *xs, float t, t_shape *shape)
{
	t_x		*xs_temp;
	t_i		i;

	xs_temp = malloc(sizeof(t_x));
	xs_temp->count = 1;
	xs_temp->i = malloc(sizeof(t_i));
	i = intersection(t, shape);
	xs_temp->i[0] = i;
	xs = intersections(xs->count + 1, xs, xs_temp);
	return (xs);
}

//check cap
static bool check_cap(t_ray *ray, float t)
{
	float x;
	float z;

	x = ray->orig.x + t * ray->dir.x;
	z = ray->orig.z + t * ray->dir.z;
	return (x * x + z * z <= 1);
}

static bool check_cap_cone(t_ray *ray, float t)
{
    float x, z, radius;

    x = ray->orig.x + t * ray->dir.x;
    z = ray->orig.z + t * ray->dir.z;

    // Calculate radius at this cap
    radius = fabs(CONE_MIN); // Assuming symmetrical cone for both MIN/MAX
    return (x * x + z * z <= radius * radius);
}



//intersect caps
t_x *intersect_caps(t_shape *cylinder, t_ray *ray, t_x *xs)
{
	float	t;

	if (CYL_CLOSED == false || fabsf(ray->dir.y) < EPSILON)
		return (xs);
	t = (CYL_MIN - ray->orig.y) / ray->dir.y;
	if (check_cap(ray, t) == true)
		xs = add_intersection(xs, t, cylinder);
	t = (CYL_MAX - ray->orig.y) / ray->dir.y;
	if (check_cap(ray, t) == true)
		xs = add_intersection(xs, t, cylinder);
	return (xs);
}

t_x *intersect_caps_cone(t_shape *cone, t_ray *ray, t_x *xs)
{
    float t;

    if (!CONE_CLOSED || fabsf(ray->dir.y) < EPSILON)
        return xs;

    // Check bottom cap (at CONE_MIN)
    t = (CONE_MIN - ray->orig.y) / ray->dir.y;
    if (check_cap_cone(ray, t))
        xs = add_intersection(xs, t, cone);

    // Check top cap (at CONE_MAX)
    t = (CONE_MAX - ray->orig.y) / ray->dir.y;
    if (check_cap_cone(ray, t))
        xs = add_intersection(xs, t, cone);

    return xs;
}



