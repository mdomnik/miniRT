/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patterns.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:11:21 by mdomnik           #+#    #+#             */
/*   Updated: 2024/11/26 23:14:04 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

t_pattern *new_pattern(t_pattern_type pattern, t_color3 *a, t_color3 *b)
{
	t_pattern *p;

	p = malloc(sizeof(t_pattern));
	p->type = pattern;
	p->a = a;
	p->b = b;
	p->transform = *init_identity_matrix(4);
	return (p);
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

//pattern at object
t_color3 *pattern_at_object(t_pattern *pattern, t_shape *shape, t_point3 *point)
{
	t_point3 object_space;
	t_point3 pattern_space;
	t_color3 *c;

	object_space = multiply_matrix_tuple(inverse(shape->transform), point);
	pattern_space = multiply_matrix_tuple(inverse(pattern->transform), &object_space);
	c = pattern_at(pattern, &pattern_space);
	return (c);
}

//pattern at
t_color3 *pattern_at(t_pattern *pattern, t_point3 *point)
{
	if (pattern->type == STRIPE)
		return(stripe_at(pattern, point));
	if (pattern->type == GRADIENT)
		return(gradient_at(pattern, point));
	if (pattern->type == RING)
		return(ring_at(pattern, point));
	if (pattern->type == CHECKERS)
		return(checkers_at(pattern, point));
	return (NULL);
}
