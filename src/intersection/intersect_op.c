/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:17:34 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/22 00:59:41 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

// Creates an intersection from distance and shape
t_i	create_intersection(float t, t_shape *shape)
{
	t_i	i;

	i.t = t;
	i.shape = shape;
	return (i);
}

// Adds an intersection to a list of intersections
t_x	*add_intersection(t_x *xs, float t, t_shape *shape)
{
	t_x		*xs_temp;
	t_i		i;

	xs_temp = malloc(sizeof(t_x));
	xs_temp->count = 1;
	xs_temp->i = malloc(sizeof(t_i));
	i = create_intersection(t, shape);
	xs_temp->i[0] = i;
	xs =join_intersections(xs->count + 1, xs, xs_temp);
	return (xs);
}


// Joins 2 lists of intersections by passing the lists and a new total of intersections
t_x	*join_intersections(int num_x, t_x *xs, t_x *temp_xs)
{
	t_x		*new_xs;
	int		i;
	int		j;

	new_xs = malloc(sizeof(t_x));
	new_xs->count = num_x;
	new_xs->i = malloc(sizeof(t_i) * num_x);
	i = 0;
	while (i < xs->count)
	{
		new_xs->i[i].t = xs->i[i].t;
		new_xs->i[i].shape = xs->i[i].shape;
		i++;
	}
	j = 0;
	while (j < temp_xs->count)
	{
		new_xs->i[i].t = temp_xs->i[j].t;
		new_xs->i[i].shape = temp_xs->i[j].shape;
		i++;
		j++;
	}

	free(xs->i);
	free(xs);
	free(temp_xs->i);
	free(temp_xs);

	return (new_xs);
}

// Sorts intersections
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
