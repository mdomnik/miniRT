/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:17:22 by mdomnik           #+#    #+#             */
/*   Updated: 2025/01/17 21:20:34 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

t_shape	*sphere(void)
{
	t_shape	*shape;

	shape = malloc(sizeof(t_shape));
	shape->type = SPHERE;
	shape->transform = *init_identity_matrix(4);
	shape->material = *default_material();
	shape->saved_ray = NULL;
	shape->children = NULL;
	shape->children_count = 0;
	shape->parent = NULL;
	shape->triangle = NULL;
	shape->bounds = bounds_unit;
	shape->next = NULL;
	return (shape);
}

t_shape	*plane(void)
{
	t_shape	*shape;

	shape = malloc(sizeof(t_shape));
	shape->type = PLANE;
	shape->transform = *init_identity_matrix(4);
	shape->material = *default_material();
	shape->saved_ray = NULL;
	shape->children = NULL;
	shape->children_count = 0;
	shape->parent = NULL;
	shape->triangle = NULL;
	shape->bounds = bounds_inf;
	shape->next = NULL;
	return (shape);
}

t_shape	*cube(void)
{
	t_shape	*shape;

	shape = malloc(sizeof(t_shape));
	shape->type = CUBE;
	shape->transform = *init_identity_matrix(4);
	shape->material = *default_material();
	shape->saved_ray = NULL;
	shape->children = NULL;
	shape->children_count = 0;
	shape->parent = NULL;
	shape->triangle = NULL;
	shape->bounds = bounds_unit;
	shape->next = NULL;
	return (shape);
}

t_shape	*cylinder(void)
{
	t_shape	*shape;

	shape = malloc(sizeof(t_shape));
	shape->type = CYLINDER;
	shape->transform = *init_identity_matrix(4);
	shape->material = *default_material();
	shape->size_cap = *default_size_cap();
	shape->saved_ray = NULL;
	shape->children = NULL;
	shape->children_count = 0;
	shape->parent = NULL;
	shape->triangle = NULL;
	shape->bounds = bounds_cap;
	shape->next = NULL;
	return (shape);
}

t_shape	*cone(void)
{
	t_shape	*shape;

	shape = malloc(sizeof(t_shape));
	shape->type = CONE;
	shape->transform = *init_identity_matrix(4);
	shape->material = *default_material();
	shape->size_cap = *default_size_cap();
	shape->saved_ray = NULL;
	shape->children = NULL;
	shape->children_count = 0;
	shape->parent = NULL;
	shape->triangle = NULL;
	shape->bounds = bounds_cap;
	shape->next = NULL;
	return (shape);
}

t_shape	*group(void)
{
	t_shape	*shape;

	shape = malloc(sizeof(t_shape));
	shape->type = GROUP;
	shape->transform = *init_identity_matrix(4);
	shape->material = *default_material();
	shape->saved_ray = NULL;
	shape->children = NULL;
	shape->children_count = 0;
	shape->parent = NULL;
	shape->triangle = NULL;
	shape->bounds = group_bounds;
	shape->next = NULL;
	return (shape);
}

t_shape	*triangle(t_point3 p1, t_point3 p2, t_point3 p3)
{
	t_shape	*shape;

	shape = malloc(sizeof(t_shape));
	shape->type = TRIANGLE;
	shape->material = *default_material();
	shape->transform = *init_identity_matrix(4);
	shape->saved_ray = NULL;
	shape->children = NULL;
	shape->children_count = 0;
	shape->parent = NULL;
	shape->triangle = triangle_new(p1, p2, p3);
	shape->bounds = bounds_triangle;
	shape->next = NULL;
	return (shape);
}
