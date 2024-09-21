/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:22:28 by astavrop          #+#    #+#             */
/*   Updated: 2024/09/21 18:49:03 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

/**
 * @brief Allocates and initializes a new 3D vector with given components.
 * 
 * @param x The x component of the vector.
 * @param y The y component of the vector.
 * @param z The z component of the vector.
 * @return t_vec3* Pointer to the vector or NULL in case of error
 */
t_vec3	*vec3_new(double x, double y, double z)
{
	t_vec3	*v;

	v = malloc(sizeof(*v));
	if (!v)
		return (NULL);
	v->a[X] = x;
	v->a[Y] = y;
	v->a[Z] = z;
	return (v);
}

/**
 * @brief Computes the squared length of a 3D vector.
 * 
 * @param v Pointer to the vector.
 * @return double The squared length of the vector.
 */
double	vec3_len_sq(t_vec3 *v)
{
	return (
		v->a[X] * v->a[X]
		+ v->a[Y] * v->a[Y]
		+ v->a[Z] * v->a[Z]
	);
}

/**
 * @brief Computes the length (magnitude) of a 3D vector.
 * 
 * @param v Pointer to the vector.
 * @return double The length of the vector.
 */
double	vec3_len(t_vec3 *v)
{
	return (sqrt(vec3_len_sq(v)));
}

/**
 * @brief Computes the dot product of two 3D vectors.
 * 
 * @param u Pointer to the first vector.
 * @param v Pointer to the second vector.
 * @return double The dot product of the two vectors.
 */
double	dot(t_vec3 *u, t_vec3 *v)
{
	return (
		u->a[X] * v->a[X]
		+ u->a[Y] * v->a[Y]
		+ u->a[Z] * v->a[Z]
	);
}

/**
 * @brief Computes the cross product of two 3D vectors.
 * 
 * @param u Pointer to the first vector.
 * @param v Pointer to the second vector.
 * @return t_vec3* Pointer to the vector cross product or NULL in case of error.
 */
t_vec3	*cross(t_vec3 *u, t_vec3 *v)
{
	t_vec3	*ret;

	ret = vec3_new(0, 0, 0);
	if (!ret)
		return (NULL);
	ret->a[X] = u->a[Y] * v->a[Z] - u->a[Z] * v->a[Y];
	ret->a[Y] = u->a[Z] * v->a[X] - u->a[X] * v->a[Z];
	ret->a[Z] = u->a[X] * v->a[Y] - u->a[Y] * v->a[X];
	return (ret);
}
