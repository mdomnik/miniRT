/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 21:39:21 by astavrop          #+#    #+#             */
/*   Updated: 2024/08/27 17:55:44 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vec3.h"

/**
 * @brief Creates and returns a 3D vector with the specified components.
 * 
 * @param x The x component of the vector.
 * @param y The y component of the vector.
 * @param z The z component of the vector.
 * @return t_vec3 A new 3D vector with the given components.
 * 
 * @note This function returns a vector by value, not by pointer.
 */
t_vec3	vec3(double x, double y, double z)
{
	t_vec3	v;

	v.a[X] = x;
	v.a[Y] = y;
	v.a[Z] = z;
	return (v);
}

/**
 * @brief Creates and returns a 3D point with the specified coordinates.
 * 
 * @param x The x coordinate of the point.
 * @param y The y coordinate of the point.
 * @param z The z coordinate of the point.
 * @return t_point3 A new 3D point with the given coordinates.
 * 
 * @note This function returns a point by value, not by pointer.
 */
t_point3	point3(double x, double y, double z)
{
	t_point3	p;

	p.a[X] = x;
	p.a[Y] = y;
	p.a[Z] = z;
	return (p);
}
