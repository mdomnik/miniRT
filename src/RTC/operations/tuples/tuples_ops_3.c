/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples_ops_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 23:56:53 by mdomnik           #+#    #+#             */
/*   Updated: 2024/11/14 19:30:49 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

//negates a vector
t_vec3 neg_vec3(t_vec3 a)
{
	t_tuple result;

	result.x = -a.x;
	result.y = -a.y;
	result.z = -a.z;
	return (result);
}

//normalize a vector
t_vec3 normalize(t_vec3 a)
{
	t_vec3 result;
	float mag;

	mag = magnitude(a);
	result.x = a.x / mag;
	result.y = a.y / mag;
	result.z = a.z / mag;
	result.w = a.w / mag;
	return (result);
}

//cross product of two vectors
t_vec3 cross_product(t_vec3 a, t_vec3 b)
{
	t_vec3 result;

	result.x = a.y * b.z - a.z * b.y;
	result.y = a.z * b.x - a.x * b.z;
	result.z = a.x * b.y - a.y * b.x;
	return (result);
}

t_color3 color_mult(t_color3 *a, t_color3 *b)
{
	t_color3 result;

	result.r = a->r * b->r;
	result.g = a->g * b->g;
	result.b = a->b * b->b;
	result.al = 1;
	return (result);
}

t_tuple sub_tuple_p(t_tuple *a, t_tuple *b)
{
	t_vec3 result;

	result.x = a->x - b->x;
	result.y = a->y - b->y;
	result.z = a->z - b->z;
	result.w = a->w - b->w;
	if (result.w < 0) //delete later
		printf("Warning: Tuple w value is less than 0\n");
	return (result);
}
