/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_basic_obj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:34:15 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/15 10:37:15 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

t_shape	*sphere(void)
{
	t_shape	*shape;

	shape = malloc(sizeof(t_shape));
	shape->type = SPHERE;
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

t_shape	*plane(void)
{
	t_shape	*shape;

	shape = malloc(sizeof(t_shape));
	shape->type = PLANE;
	shape->transform = init_identity_matrix(4);
	shape->material = default_material();
	shape->saved_ray = NULL;
	shape->children = NULL;
	shape->children_count = 0;
	shape->parent = NULL;
	shape->triangle = NULL;
	shape->bounds = bounds_inf;
	shape->next = NULL;
	return (shape);
}

t_shape	*cylinder(void)
{
	t_shape	*shape;

	shape = malloc(sizeof(t_shape));
	shape->type = CYLINDER;
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

t_light_p	*light(t_point3 position, t_color3 intensity)
{
	t_light_p	*light;

	light = malloc(sizeof(t_light));
	if (!light)
		return (NULL);
	light->position = position;
	light->intensity = intensity;
	light->next = NULL;
	return (light);
}
