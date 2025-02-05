/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:09:47 by mdomnik           #+#    #+#             */
/*   Updated: 2024/11/12 15:13:53 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

t_tuple		new_tuple(float x, float y, float z, float w)
{
	t_tuple	tuple;

	tuple.x = x;
	tuple.y = y;
	tuple.z = z;
	tuple.w = w;
	return (tuple);
}

t_point3	new_point3(float x, float y, float z)
{
	t_point3	point;

	point.x = x;
	point.y = y;
	point.z = z;
	point.w = 1;
	return (point);
}

t_vec3	new_vec3(float x, float y, float z)
{
	t_vec3	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	vec.w = 0;
	return (vec);
}

t_color3 new_color3(float r, float g, float b)
{
	t_color3 color;

	color.r = r;
	color.g = g;
	color.b = b;
	color.al = 1;
	return (color);
}
