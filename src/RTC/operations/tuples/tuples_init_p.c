/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples_init_p.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:06:47 by mdomnik           #+#    #+#             */
/*   Updated: 2024/11/12 16:02:06 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

t_tuple		*new_tuple_p(float x, float y, float z, float w)
{
	t_tuple	*tuple;
	
	tuple = malloc(sizeof(t_tuple));
	tuple->x = x;
	tuple->y = y;
	tuple->z = z;
	tuple->w = w;
	return (tuple);
}

t_point3	*new_point3_p(float x, float y, float z)
{
	t_point3	*point;

	point = malloc(sizeof(t_point3));
	point->x = x;
	point->y = y;
	point->z = z;
	point->w = 1;
	return (point);
}

t_vec3	*new_vec3_p(float x, float y, float z)
{
	t_vec3	*vec;

	vec = malloc(sizeof(t_vec3));
	vec->x = x;
	vec->y = y;
	vec->z = z;
	vec->w = 0;
	return (vec);
}

t_color3 *new_color3_p(float x, float y, float z)
{
	t_color3 *color;

	color = malloc(sizeof(t_color3));
	color->r = x;
	color->g = y;
	color->b = z;
	color->al = 1;
	return (color);
}
