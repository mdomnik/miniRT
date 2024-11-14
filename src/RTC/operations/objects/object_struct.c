/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:47:10 by mdomnik           #+#    #+#             */
/*   Updated: 2024/11/13 17:45:04 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

t_object	*object_new(void *object, t_object_type type)
{
	t_object	*new_object;

	new_object = malloc(sizeof(t_object));
	if (!new_object)
		return (NULL);
	new_object->object = object;
	new_object->type = type;
	new_object->next = NULL;
	return (new_object);
}

//object next add
void add_object(t_object **objects, t_object *new_object)
{
	t_object	*tmp;

	if (!*objects)
	{
		*objects = new_object;
		return ;
	}
	tmp = *objects;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_object;
}
