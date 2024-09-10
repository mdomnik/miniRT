/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 21:39:21 by astavrop          #+#    #+#             */
/*   Updated: 2024/08/22 21:41:17 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vec3.h"

t_vec3	vec3(double x, double y, double z)
{
	t_vec3	v;

	v.a[X] = x;
	v.a[Y] = y;
	v.a[Z] = z;
	return (v);
}

t_point3	point3(double x, double y, double z)
{
	t_point3	p;

	p.a[X] = x;
	p.a[Y] = y;
	p.a[Z] = z;
	return (p);
}
