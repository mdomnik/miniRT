/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 20:47:13 by astavrop          #+#    #+#             */
/*   Updated: 2024/08/22 20:50:08 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vec3.h"

#include <stdio.h>

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
