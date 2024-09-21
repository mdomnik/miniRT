/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_basic_ops.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 21:26:28 by astavrop          #+#    #+#             */
/*   Updated: 2024/09/21 18:48:47 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

/**
 * @brief Negates the components of a 3D vector.
 * 
 * @param v Pointer to the vector to be negated.
 * 
 * @note The original vector is modified in place.
 */
void	v_vec3_neg(t_vec3 *v)
{
	v->a[X] = -v->a[X];
	v->a[Y] = -v->a[Y];
	v->a[Z] = -v->a[Z];
}

/**
 * @brief Adds the components of one 3D vector to another.
 * 
 * @param n Pointer to the first vector, which will store the result.
 * @param m Pointer to the second vector to be added.
 * 
 * @note The original vector n is modified in place.
 */
void	v_vec3_add(t_vec3 *n, t_vec3 *m)
{
	n->a[X] += m->a[X];
	n->a[Y] += m->a[Y];
	n->a[Z] += m->a[Z];
}

/**
 * @brief Subtracts the components of one 3D vector from another.
 * 
 * @param n Pointer to the first vector, which will store the result.
 * @param m Pointer to the second vector to be subtracted. 
 *
 * @note The original vector n is modified in place.
 */
void	v_vec3_sub(t_vec3 *n, t_vec3 *m)
{
	n->a[X] -= m->a[X];
	n->a[Y] -= m->a[Y];
	n->a[Z] -= m->a[Z];
}

/**
 * @brief Multiplies the components of a 3D vector by a scalar.
 * 
 * @param n Pointer to the vector to be scaled.
 * @param t The scalar value to multiply with. 
 *
 * @note The original vector n is modified in place.
 */
void	v_vec3_mult(t_vec3 *n, double t)
{
	n->a[X] *= t;
	n->a[Y] *= t;
	n->a[Z] *= t;
}

/**
 * @brief Divides the components of a 3D vector by a scalar.
 * 
 * @param n Pointer to the vector to be scaled.
 * @param t The scalar value to divide by.
 *  
 * @note The original vector n is modified in place.
 *
 * @note This function uses `v_vec3_mult` internally
 *       by multiplying with the reciprocal of the scalar.
 */
void	v_vec3_div(t_vec3 *n, double t)
{
	v_vec3_mult(n, 1 / t);
}
