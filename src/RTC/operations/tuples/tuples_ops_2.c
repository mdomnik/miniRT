/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples_ops_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:31:22 by mdomnik           #+#    #+#             */
/*   Updated: 2024/11/13 18:43:02 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

bool	compare_tuples(t_tuple a, t_tuple b)
{
	if (is_equal(a.x, b.x) && is_equal(a.y, b.y) && is_equal(a.z, b.z) && is_equal(a.w, b.w))
		return (true);
	return (false);
}

//divides a tuple by a scalar
t_tuple div_tuple(t_tuple a, float scalar)
{
	t_tuple result;

	result.x = a.x / scalar;
	result.y = a.y / scalar;
	result.z = a.z / scalar;
	return (result);
}

//magnitude of a vector
float magnitude(t_vec3 a)
{
	return (sqrt(a.x * a.x + a.y * a.y + a.z * a.z));
}

//dot product of two vectors
float dot_product(t_vec3 a, t_vec3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}
