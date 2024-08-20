/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:22:28 by astavrop          #+#    #+#             */
/*   Updated: 2024/08/20 21:26:51 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rayft.h"
#include "../../libft/libft.h"

t_vec3	*new_vec3(double x, double y, double z)
{
	t_vec3	*v;

	v = gc_malloc(sizeof(*v));
	if (!v)
		return (NULL);
	v->a[X] = x;
	v->a[Y] = y;
	v->a[Z] = z;
	return (v);
}
