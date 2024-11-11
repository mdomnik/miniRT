/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples_ops_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:37:37 by mdomnik           #+#    #+#             */
/*   Updated: 2024/11/11 18:41:09 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

//adds two tuples together (cant add 2 points)
t_tuple add_tuples(t_tuple a, t_tuple b)
{
	t_tuple result;

	result.x = a.x + b.x;
	result.y = a.y + b.y;
	result.z = a.z + b.z;
	result.w = a.w + b.w;
	if (result.w > 1) //delete later
		printf("Warning: Tuple w value is greater than 1\n");
	return (result);
}

//subtracts two tuples
// point - point = vector
// point - vector = point
// vector - vector = vector
// rest is undefined
t_tuple sub_tuple(t_tuple a, t_tuple b)
{
	t_vec3 result;

	result.x = a.x - b.x;
	result.y = a.y - b.y;
	result.z = a.z - b.z;
	result.w = a.w - b.w;
	if (result.w < 0) //delete later
		printf("Warning: Tuple w value is less than 0\n");
	return (result);
}

//negates a tuple
t_tuple neg_tuple(t_tuple a)
{
	t_tuple result;

	result.x = -a.x;
	result.y = -a.y;
	result.z = -a.z;
	result.w = -a.w;
	return (result);
}

//multiplies a tuple by a scalar
t_tuple mult_tuple(t_tuple a, float scalar)
{
	t_tuple result;

	result.x = a.x * scalar;
	result.y = a.y * scalar;
	result.z = a.z * scalar;
	result.w = a.w * scalar;
	return (result);
}
