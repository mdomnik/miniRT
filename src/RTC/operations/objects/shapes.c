/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:52:39 by mdomnik           #+#    #+#             */
/*   Updated: 2024/11/19 21:58:34 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

//add shape
void add_shape(t_shape **shapes, t_shape *new_shape)
{
	t_shape *temp;

	if (!new_shape)
		return ;
	if (!*shapes)
	{
		*shapes = new_shape;
		return ;
	}
	temp = *shapes;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new_shape;
}

//test_shape
t_shape *test_shape(void)
{
	t_shape *shape;

	shape = malloc(sizeof(t_shape));
	shape->type = SPHERE;
	shape->transform = *init_identity_matrix(4);
	shape->material = *default_material();
	shape->next = NULL;
	return (shape);
}
