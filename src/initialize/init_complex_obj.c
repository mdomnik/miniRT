/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_complex_obj.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:35:20 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/21 18:02:23 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

t_shape	*cube(void)
{
	t_shape	*shape;

	shape = malloc(sizeof(t_shape));
	shape->type = CUBE;
	shape->transform = init_identity_matrix(4);
	shape->material = default_material();
	shape->saved_ray = NULL;
	shape->children = NULL;
	shape->children_count = 0;
	shape->parent = NULL;
	shape->triangle = NULL;
	shape->bounds = bounds_unit;
	shape->next = NULL;
	return (shape);
}

t_shape	*cone(void)
{
	t_shape	*shape;

	shape = malloc(sizeof(t_shape));
	shape->type = CONE;
	shape->transform = init_identity_matrix(4);
	shape->material = default_material();
	shape->size_cap = default_size_cap();
	shape->saved_ray = NULL;
	shape->children = NULL;
	shape->children_count = 0;
	shape->parent = NULL;
	shape->triangle = NULL;
	shape->bounds = bounds_cap;
	shape->next = NULL;
	return (shape);
}

t_shape	*triangle(t_point3 p1, t_point3 p2, t_point3 p3)
{
	t_shape	*shape;

	shape = malloc(sizeof(t_shape));
	shape->type = TRIANGLE;
	shape->material = default_material();
	shape->transform = init_identity_matrix(4);
	shape->saved_ray = NULL;
	shape->children = NULL;
	shape->children_count = 0;
	shape->parent = NULL;
	shape->triangle = triangle_new(p1, p2, p3);
	shape->bounds = bounds_triangle;
	shape->next = NULL;
	return (shape);
}

t_shape	*group(void)
{
	t_shape	*shape;

	shape = malloc(sizeof(t_shape));
	shape->type = GROUP;
	shape->transform = init_identity_matrix(4);
	shape->material = default_material();
	shape->saved_ray = NULL;
	shape->children = NULL;
	shape->children_count = 0;
	shape->parent = NULL;
	shape->triangle = NULL;
	shape->bounds = group_bounds;
	shape->next = NULL;
	return (shape);
}
