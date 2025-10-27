/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:45:21 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/14 02:30:24 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

//Creates new t_tuple tuple
t_tuple	new_tuple(float x, float y, float z, float w)
{
	t_tuple	tuple;

	tuple.x = x;
	tuple.y = y;
	tuple.z = z;
	tuple.w = w;
	return (tuple);
}

//Creates new t_point3(t_tuple) point
t_point3	new_point3(float x, float y, float z)
{
	t_point3	point;

	point.x = x;
	point.y = y;
	point.z = z;
	point.w = 1;
	return (point);
}

//Creates new t_vec3(t_tuple) vec
t_vec3	new_vec3(float x, float y, float z)
{
	t_vec3	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	vec.w = 0;
	return (vec);
}

//Creates new t_color3(t_tuple) color
t_color3	new_color3(float r, float g, float b)
{
	t_color3	c;

	c.r = r;
	c.g = g;
	c.b = b;
	c.al = 0;
	return (c);
}

t_color3	int_to_color(int color)
{
	t_color3	result;

	result.r = (color >> 16) & 0xFF;
	result.g = (color >> 8) & 0xFF;
	result.b = color & 0xFF;
	result.al = 1;
	return (result);
}
