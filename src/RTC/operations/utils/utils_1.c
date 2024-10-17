/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:24:27 by mdomnik           #+#    #+#             */
/*   Updated: 2024/10/15 02:35:59 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

bool		is_equal(float a, float b)
{
	if (fabs(a - b) < EPSILON)
		return (true);
	return (false);
}

float		deg_to_rad(float deg)
{
	return (deg * M_PI / 180);
}