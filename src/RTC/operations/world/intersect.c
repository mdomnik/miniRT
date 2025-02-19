/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:36:41 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/19 14:49:52 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

void	print_xs(t_x *xs)
{
	int	i;

	i = 0;
	printf("a\n");
	printf("xs->count: %d\n", xs->count);
	printf("b\n");
	while (i < xs->count)
	{
		printf("c\n");
		printf("xs->t[%d]: %f\n", i, xs->i[i].t);
		printf("d\n");
		i++;
	}
	printf("e\n");
}

//intersect world
t_x	*intersect_world(t_world *world, t_ray *ray)
{
	t_x		*xs;
	t_x		*xs_temp;
	t_shape	*shape_temp;

	xs = malloc(sizeof(t_x));
	shape_temp = world->shapes;
	xs->count = 0;
	xs = intersect(world->shapes, ray);
	world->shapes = world->shapes->next;
	while (world->shapes)
	{
		xs_temp = intersect(world->shapes, ray);
		if (xs_temp != NULL)
		{
			if (xs == NULL)
				xs = xs_temp;
			else
				xs = join_intersections((xs->count + xs_temp->count), xs, xs_temp);
		}
		world->shapes = world->shapes->next;
	}
	world->shapes = shape_temp;
	sort_intersections(xs);
	return (xs);
}

void	sort_intersections(t_x *xs)
{
	int	i;
	int	j;
	t_i	temp;

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
