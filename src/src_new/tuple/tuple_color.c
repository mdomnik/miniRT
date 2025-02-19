/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 23:56:53 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/19 15:07:35 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

//multiplies two colors
t_color3	mult_color(t_color3 a, t_color3 b)
{
	t_color3	result;

	result.r = a.r * b.r;
	result.g = a.g * b.g;
	result.b = a.b * b.b;
	result.al = 1;
	return (result);
}

//subtracts two colors
t_color3	sub_color(t_tuple a, t_tuple b)
{
	t_color3	result;
	
	result.x = a.x - b.x;
	result.y = a.y - b.y;
	result.z = a.z - b.z;
	result.w = 2;
	return (result);
}

//multiplies color by a scalar
t_color3	mult_color_scalar(t_color3 a, float scalar)
{
	t_color3	result;
	
	result.x = a.x * scalar;
	result.y = a.y * scalar;
	result.z = a.z * scalar;
	result.w = 2;
	return (result);
}

//subtracts tuple b from tuple a and returns a pointer to the result
t_tuple	sub_tuple_p(t_tuple *a, t_tuple *b) //replace
{
	t_vec3	result;

	result.x = a->x - b->x;
	result.y = a->y - b->y;
	result.z = a->z - b->z;
	result.w = a->w - b->w;
	return (result);
}
