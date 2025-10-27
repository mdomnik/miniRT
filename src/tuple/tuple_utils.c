/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:24:17 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/13 20:34:01 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

bool	is_equal(float a, float b)
{
	if (fabs(a - b) < EPSILON)
		return (true);
	return (false);
}

float	deg_to_rad(float deg)
{
	return (deg * M_PI / 180);
}

bool	is_near_zero(t_tuple v)
{
	return (fabs(v.x) < EPSILON
		&& fabs(v.y) < EPSILON
		&& fabs(v.z) < EPSILON);
}

t_color3	div_color(t_color3 c)
{
	return ((t_color3){.r = (c.r / 255),
		.g = (c.g / 255), .b = (c.b / 255)});
}
