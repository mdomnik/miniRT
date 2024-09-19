/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_basic_ops_ret.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:42:02 by astavrop          #+#    #+#             */
/*   Updated: 2024/08/27 16:38:13 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vec3.h"

/**
 * @brief Negates the components of a 3D vector.
 * 
 * @param v Pointer to the vector to be negated.
 * @return t_vec3* Pointer to a copy of a vector after negation
 */
t_vec3	*vec3_neg(t_vec3 *v)
{
	t_vec3	*ret;

	ret = vec3_new(-v->a[X], -v->a[Y], -v->a[Z]);
	return (ret);
}

/**
 * @brief Adds the components of one 3D vector to another.
 * 
 * @param n Pointer to the first vector, which will store the result.
 * @param m Pointer to the second vector to be added.
 * @return t_vec3* Pointer to a copy of n after addition
 */
t_vec3	*vec3_add(t_vec3 *n, t_vec3 *m)
{
	t_vec3	*ret;

	ret = vec3_new(n->a[X] + m->a[X], n->a[Y] + m->a[Y], n->a[Z] + m->a[Z]);
	return (ret);
}

/**
 * @brief Subtracts the components of one 3D vector from another.
 * 
 * @param n Pointer to the first vector, which will store the result.
 * @param m Pointer to the second vector to be subtracted.
 * @return t_vec3* Pointer to a copy of n after subtraction
 */
t_vec3	*vec3_sub(t_vec3 *n, t_vec3 *m)
{
	t_vec3	*ret;

	ret = vec3_new(n->a[X] - m->a[X], n->a[Y] - m->a[Y], n->a[Z] - m->a[Z]);
	return (ret);
}

/**
 * @brief Multiplies the components of a 3D vector by a scalar.
 * 
 * @param n Pointer to the vector to be scaled.
 * @param t The scalar value to multiply with.
 * @return t_vec3* Pointer to a copy of n after multiplication
 */
t_vec3	*vec3_mult(t_vec3 *n, double t)
{
	t_vec3	*ret;

	ret = vec3_new(n->a[X] * t, n->a[Y] * t, n->a[Z] * t);
	return (ret);
}

/**
 * @brief Divides the components of a 3D vector by a scalar.
 * 
 * @param n Pointer to the vector to be scaled.
 * @param t The scalar value to divide by.
 * @return t_vec3* Pointer to a copy of n after division
 *
 * @note This function uses `vec3_mult` internally
 *       by multiplying with the reciprocal of the scalar.
 */
t_vec3	*vec3_div(t_vec3 *n, double t)
{
	return (vec3_mult(n, 1 / t));
}
