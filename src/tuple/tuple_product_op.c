/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_product_op.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:31:22 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/15 15:45:46 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

//magnitude of a vector
float	magnitude(t_vec3 a)
{
	return (sqrt(a.x * a.x + a.y * a.y + a.z * a.z));
}

//dot product of two vectors
float	dot_product(t_vec3 a, t_vec3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

//cross product of two vectors
inline t_vec3	cross_product(t_vec3 a, t_vec3 b)
{
	return ((t_vec3){.x = (a.y * b.z - a.z * b.y),
		.y = (a.z * b.x - a.x * b.z), .z = (a.x * b.y - a.y * b.x), .w = 0});
}

//normalize a vector
t_vec3	normalize(t_vec3 a)
{
	t_vec3	result;
	float	mag;

	mag = magnitude(a);
	result.x = a.x / mag;
	result.y = a.y / mag;
	result.z = a.z / mag;
	result.w = a.w / mag;
	return (result);
}

//negates a vector
t_vec3	neg_vec3(t_vec3 a)
{
	t_tuple	result;

	result.x = -a.x;
	result.y = -a.y;
	result.z = -a.z;
	result.w = 0;
	return (result);
}
