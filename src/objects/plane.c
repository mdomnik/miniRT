/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:30:40 by astavrop          #+#    #+#             */
/*   Updated: 2024/09/21 21:24:43 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

t_plane	plane(t_point3 center, t_vec3 norm)
{
	t_plane	p;

	p.coords = center;
	p.normal = norm;
	return (p);
}

/**
 * Equation of a plane:
 * `N \dot (P - P0) = 0`
 * where `P (x,y,z)` is any point on the plane
 *
 * Finding the intersection from an equation:
 * `N \dot C + t * N \dot D - N \dot P0 = 0`
 * Solve for t:
 * `t = [a](N \dot (P0 - C)) / [b](N \dot D)
 *
 * C = ray origin
 * D = ray direction
 * P and P0 = points on the plane
 * N = normal vector of the plane
 */
bool	hit_plane(t_plane *p, t_ray *r)
{
	float	a;
	float	b;
	float	t;

	v_vec3_sub((t_vec3 *) &p->coords, &r->orig);
	a = dot(&p->normal, &p->coords);
	b = dot(&p->normal, &r->dir);
	t = (float) a / b;
	if (t <= 0)
		return (false);
	return (true);
}
