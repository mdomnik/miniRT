/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 20:47:13 by astavrop          #+#    #+#             */
/*   Updated: 2024/08/27 16:39:44 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vec3.h"

#include <stdio.h>

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
