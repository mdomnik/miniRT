/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:24:17 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/19 22:24:20 by mdomnik          ###   ########.fr       */
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

bool is_near_zero(t_tuple v)
{
	return (fabs(v.x) < EPSILON &&
			fabs(v.y) < EPSILON &&
			fabs(v.z) < EPSILON);
}
