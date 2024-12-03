/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transparency.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 18:21:30 by mdomnik           #+#    #+#             */
/*   Updated: 2024/11/30 18:22:30 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

t_shape *last_shape(t_shape *shapes)
{
	t_shape *temp;

	temp = shapes;
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}

//add shape
t_shape *add_shape_con(t_shape *shapes, t_shape *new_shape)
{
	t_shape *temp;

	if (!new_shape)
		return (shapes);
	if (shapes == NULL){
		shapes = new_shape;
		shapes->next = NULL;
		return (shapes);
	}
	temp = last_shape(shapes);
	temp->next = new_shape;
	return (shapes);
}

//remove shape
t_shape *remove_shape(t_shape *shapes, t_shape *to_remove)
{
	t_shape *temp;
	t_shape *prev;

	temp = shapes;
	prev = NULL;
	while (temp != NULL)
	{
		if (temp == to_remove)
		{
			if (prev == NULL)
				shapes = temp->next;
			else
				prev->next = temp->next;
			break;
		}
		prev = temp;
		temp = temp->next;
	}
	to_remove->next = NULL;
	return (shapes);
}


//contains
bool contains(t_shape *containers, t_shape *shape)
{
	t_shape *temp;

	temp = containers;
	while (temp != NULL)
	{
		if (temp == shape)
			return (true);
		temp = temp->next;
	}
	return (false);
}

void transparency_and_refraction(t_i *hit, t_comp *comp, t_x *xs)
{
	t_shape *containers = NULL;

	for (int i = 0; i < xs->count; i++)
	{
		t_i *x = &xs->i[i];

		if (x->t == hit->t)
		{
			if (containers == NULL)
				comp->n1 = 1.0;
			else
				comp->n1 = last_shape(containers)->material.refractive_index;
		}
		if (contains(containers, x->shape))
			containers = remove_shape(containers, x->shape);
		else
			containers = add_shape_con(containers, x->shape);
		if (x->t == hit->t)
		{
			if (containers == NULL)
				comp->n2 = 1.0;
			else
				comp->n2 = last_shape(containers)->material.refractive_index;
			break;
		}
	}
	// free(containers);
}
