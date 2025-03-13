/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_xyz.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 20:09:23 by astavrop         #+#    #+#             */
/*   Updated: 2025/03/13 20:09:23 by astavrop        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

t_vec3	rotate_x(t_vec3 v, double angle)
{
	double	cos_a;
	double	sin_a;

	cos_a = cos(angle);
	sin_a = sin(angle);
	return (new_vec3(v.x, v.y * cos_a - v.z
			* sin_a, v.y * sin_a + v.z * cos_a));
}

t_vec3	rotate_y(t_vec3 v, double angle)
{
	double	cos_a;
	double	sin_a;

	cos_a = cos(angle);
	sin_a = sin(angle);
	return (new_vec3(v.x * cos_a + v.z * sin_a, v.y,
			-v.x * sin_a + v.z * cos_a));
}

t_vec3	rotate_z(t_vec3 v, double angle)
{
	double	cos_a;
	double	sin_a;

	cos_a = cos(angle);
	sin_a = sin(angle);
	return (new_vec3(v.x * cos_a - v.y * sin_a,
			v.x * sin_a + v.y * cos_a, v.z));
}
