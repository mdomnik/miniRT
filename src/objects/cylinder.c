/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:41:55 by astavrop          #+#    #+#             */
/*   Updated: 2024/09/17 18:30:15 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/objects.h"
#include "../../lib/libft/libft.h"

t_cylinder	cylinder(t_vec3 center, t_vec3 axis, float radius, float height)
{
	t_cylinder	c;

	c.coords = center;
	c.normal = axis;
	v_vec3_unit(&c.normal);
	c.radius = radius;
	c.height = height;
	return (c);
}

bool	hit_cylinder(t_cylinder *cy, t_ray *r)
{
	t_vec3	*ro_cpy;
	double	di[4];
	double	sec[3];
	double	x[4];
	double	discr;

	ft_memmove(x, &(double []){-1, -1, -1, -1}, sizeof(double) * 4);
	ro_cpy = vec3_copy(&r->orig);
	v_vec3_sub(ro_cpy, &cy->coords);
	di[0] = dot(&r->dir, &cy->normal);
	di[1] = dot(&r->dir, ro_cpy);
	di[2] = dot(ro_cpy, &cy->normal);
	di[3] = vec3_len_sq(&r->dir) - 2;
	sec[0] = vec3_len_sq(&r->dir) + di[0] * di[0] * di[3];
	sec[1] = 2 * (di[1] + di[0] * di[2] * di[3]);
	sec[2] = vec3_len_sq(ro_cpy) - cy->radius * cy->radius + di[2] * di[2] * di[3];
	discr = sec[1] * sec[1] - 4 * sec[0] * sec[2];
	if (discr < 0)
		return (false);
	return (true);
}
