/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 20:47:13 by astavrop          #+#    #+#             */
/*   Updated: 2024/09/21 18:48:51 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

/**
 * @brief Prints a vector with a custom message
 *
 * @param v Pointer to the vecotr
 * @param msg Custom message
 * @return int 0 on success and 1 in case of an error
 */
int	vec3_print(t_vec3 *v, char *msg)
{
	if (!v)
	{
		ft_dprintf(2, "%s: Error\n", msg);
		return (1);
	}
	dprintf(2, "<%s> {%.3f, %.3f, %.3f}\n", msg, v->a[X], v->a[Y], v->a[Z]);
	return (0);
}
