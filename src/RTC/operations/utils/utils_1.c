/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:24:27 by mdomnik           #+#    #+#             */
/*   Updated: 2025/01/17 19:56:53 by mdomnik          ###   ########.fr       */
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

//color to int
int	color_to_int(t_color3 color)
{
	if (color.r > 1)
		color.r = 1;
	if (color.g > 1)
		color.g = 1;
	if (color.b > 1)
		color.b = 1;
	if (color.r < 0)
		color.r = 0;
	if (color.g < 0)
		color.g = 0;
	if (color.b < 0)
		color.b = 0;
	return ((int)(color.r * 255) << 24 |
	(int)(color.g * 255) << 16 | (int)(color.b * 255) << 8 | 0xFF);
}
