/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:03:26 by astavrop          #+#    #+#             */
/*   Updated: 2024/08/22 20:00:30 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vec3.h"

void	v_vec3_unit(t_vec3 *v)
{
	v_vec3_div(v, vec3_len(v));
}

t_vec3	*vec3_unit(t_vec3 *v)
{
	return (vec3_div(vec3_copy(v), vec3_len(v)));
}

t_vec3	*vec3_copy(t_vec3 *orig)
{
	t_vec3	*copy;

	copy = vec3_new(orig->a[X], orig->a[Y], orig->a[Z]);
	if (!copy)
		return (NULL);
	return (copy);
}
