/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:52:39 by mdomnik           #+#    #+#             */
/*   Updated: 2024/11/19 20:12:03 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

void add_shape(t_shape **shapes, t_shape *new_shape)
{
	t_shape	*tmp;

	if (!*shapes)
	{
		*shapes = new_shape;
		return ;
	}
	tmp = *shapes;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_shape;
}
