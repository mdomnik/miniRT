/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patterns.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:11:21 by mdomnik           #+#    #+#             */
/*   Updated: 2024/11/26 18:14:50 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

//stripe pattern
t_pattern *stripe_pattern(t_color3 *a, t_color3 *b)
{
	t_pattern *pattern;

	pattern = malloc(sizeof(t_pattern));
	pattern->a = a;
	pattern->b = b;
	pattern->transform = *init_identity_matrix(4);
	return (pattern);
}

//stripe at
t_color3 *stripe_at(t_pattern *pattern, t_point3 *point)
{
	if ((int)floor(point->x) % 2 == 0)
		return (pattern->a);
	return (pattern->b);
}

//stripe at object
t_color3 *stripe_at_object(t_pattern *pattern, t_shape *shape, t_point3 *point)
{
	t_point3 object_space;
	t_point3 pattern_space;
	t_color3 *c;

	object_space = multiply_matrix_tuple(inverse(shape->transform), point);
	pattern_space = multiply_matrix_tuple(inverse(pattern->transform), &object_space);
	c = stripe_at(pattern, &pattern_space);
	return (c);
}
void	set_pattern_transform(t_pattern *pattern, t_matrix *new_transform)
{
	int	i;
	int	j;
	t_matrix *transform;

	transform = &pattern->transform;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			transform->a[i][j] = new_transform->a[i][j];
			j++;
		}
		i++;
	}
}
