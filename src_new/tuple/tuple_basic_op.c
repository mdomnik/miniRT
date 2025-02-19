/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_basic_op.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:37:37 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/19 13:02:28 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

//adds two tuples together (cant add 2 points)
t_tuple	add_tuple(t_tuple a, t_tuple b)
{
	t_tuple	result;

	result.x = a.x + b.x;
	result.y = a.y + b.y;
	result.z = a.z + b.z;
	result.w = a.w + b.w;
	return (result);
}

//subtracts two tuples
// point - point = vector
// point - vector = point
// vector - vector = vector
t_tuple	sub_tuple(t_tuple a, t_tuple b)
{
	t_vec3	result;

	result.x = a.x - b.x;
	result.y = a.y - b.y;
	result.z = a.z - b.z;
	result.w = a.w - b.w;
	return (result);
}

//multiplies a tuple by a scalar
t_tuple	mult_tuple(t_tuple a, float scalar)
{
	t_tuple	result;
	
	result.x = a.x * scalar;
	result.y = a.y * scalar;
	result.z = a.z * scalar;
	result.w = a.w * scalar;
	return (result);
}

//divides a tuple by a scalar
t_tuple	div_tuple(t_tuple a, float scalar)
{
	t_tuple	result;

	result.x = a.x / scalar;
	result.y = a.y / scalar;
	result.z = a.z / scalar;
	return (result);
}

//negates a tuple
t_tuple	neg_tuple(t_tuple a)
{
	t_tuple	result;

	result.x = -a.x;
	result.y = -a.y;
	result.z = -a.z;
	result.w = -a.w;
	return (result);
}
