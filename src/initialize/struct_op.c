/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:57:37 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/21 16:43:09 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

void	add_light(t_light_p **lights, t_light_p *new_light)
{
	t_light_p	*tmp;

	if (!*lights)
	{
		*lights = new_light;
		return ;
	}
	tmp = *lights;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_light;
}

void	add_shape(t_shape **shapes, t_shape *new_shape)
{
	t_shape	*temp;

	if (!*shapes)
	{
		if (!new_shape)
			return ;
		*shapes = new_shape;
		return ;
	}
	if (!new_shape)
		return ;
	temp = *shapes;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new_shape;
}

t_triangle	*triangle_new(t_point3 p1, t_point3 p2, t_point3 p3)
{
	t_triangle	*triangle;

	triangle = malloc(sizeof(t_triangle));
	triangle->p1 = p1;
	triangle->p2 = p2;
	triangle->p3 = p3;
	triangle->e1 = sub_tuple(p2, p1);
	triangle->e2 = sub_tuple(p3, p1);
	triangle->normal = normalize(cross_product(triangle->e2, triangle->e1));
	return (triangle);
}
