/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:29:52 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/19 18:57:25 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

float	current_ambient(int flag, float value)
{
	static float	ambient = 0.3;

	if (flag == 's')
		ambient = value;
	return (ambient);
}

t_color3	global_color(int flag, t_color3 color)
{
	static t_color3	global;

	if (flag == 's')
		global = color;
	return (global);
}
