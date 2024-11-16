/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:36:41 by mdomnik           #+#    #+#             */
/*   Updated: 2024/11/16 19:44:07 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

static void sort_intersections(t_x *xs);

//intersect world
t_x	*intersect_world(t_world *world, t_ray *ray)
{
	t_x *xs;
	t_x *xs_temp;
	t_object *obj_temp;
	
	xs = malloc(sizeof(t_x));
	obj_temp = world->objects;
	xs->count = 0;
	xs = intersect(world->objects, ray);
	world->objects = world->objects->next;
	while (world->objects)
	{
		xs_temp = intersect(world->objects, ray);
		xs = intersections(xs->count + xs_temp->count,xs, xs_temp);
		world->objects = world->objects->next;
	}
	world->objects = obj_temp;
	sort_intersections(xs);
	return (xs);
}

void sort_intersections(t_x *xs)
{
	int i;
	int j;
	t_i temp;

	i = 0;
	while (i < xs->count)
	{
		j = i + 1;
		while (j < xs->count)
		{
			if (xs->i[i].t > xs->i[j].t)
			{
				temp = xs->i[i];
				xs->i[i] = xs->i[j];
				xs->i[j] = temp;
			}
			j++;
		}
		i++;
	}
}
