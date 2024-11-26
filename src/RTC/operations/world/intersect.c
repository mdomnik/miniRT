/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:36:41 by mdomnik           #+#    #+#             */
/*   Updated: 2024/11/26 16:25:29 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

static void sort_intersections(t_x *xs);

//intersect world
t_x	*intersect_world(t_world *world, t_ray *ray)
{
	t_x *xs;
	t_x *xs_temp;
	t_shape *shape_temp;
	
	xs = malloc(sizeof(t_x));
	shape_temp = world->shapes;
	xs->count = 0;
	xs = intersect(world->shapes, ray);
	world->shapes = world->shapes->next;
	while (world->shapes)
	{
		xs_temp = intersect(world->shapes, ray);
		xs = intersections((xs->count + xs_temp->count), xs, xs_temp);
		world->shapes = world->shapes->next;
	}
	world->shapes = shape_temp;
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
