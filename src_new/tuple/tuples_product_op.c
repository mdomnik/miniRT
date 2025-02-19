/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples_product_op.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:31:22 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/19 12:59:09 by mdomnik          ###   ########.fr       */
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
t_vec3	cross_product(t_vec3 a, t_vec3 b)
{
	t_vec3	result;

	result.x = a.y * b.z - a.z * b.y;
	result.y = a.z * b.x - a.x * b.z;
	result.z = a.x * b.y - a.y * b.x;
	return (result);
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
	return (result);
}