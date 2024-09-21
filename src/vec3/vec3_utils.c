/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:03:26 by astavrop          #+#    #+#             */
/*   Updated: 2024/09/21 18:48:57 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

/**
 * @brief Normalizes the vector, making it a unit vector (length of 1).
 * 
 * @param v Pointer to the vector to be normalized.
 * 
 * @note The original vector is modified in place.
 */
void	v_vec3_unit(t_vec3 *v)
{
	v_vec3_div(v, vec3_len(v));
}

/**
 * @brief Creates and returns a new unit vector (normalized)
 *        based on the given vector.
 * 
 * @param v Pointer to the original vector to be normalized.
 * @return t_vec3* Pointer to the unit vector copy of v
 *                 or NULL in case of an error.
 */
t_vec3	*vec3_unit(t_vec3 *v)
{
	return (vec3_div(vec3_copy(v), vec3_len(v)));
}

/**
 * @brief Creates and returns a copy of the given vector.
 * 
 * @param orig Pointer to the original vector to be copied.
 * @return t_vec3* Pointer to the created copy of the vector.
 *                 Returns NULL if memory allocation fails.
 */
t_vec3	*vec3_copy(t_vec3 *orig)
{
	t_vec3	*copy;

	copy = vec3_new(orig->a[X], orig->a[Y], orig->a[Z]);
	if (!copy)
		return (NULL);
	return (copy);
}
