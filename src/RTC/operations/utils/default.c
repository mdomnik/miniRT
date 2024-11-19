/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:35:59 by mdomnik           #+#    #+#             */
/*   Updated: 2024/11/19 18:26:28 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

t_material *default_material(void)
{
	t_material *material;

	material = malloc(sizeof(t_material));
	material->color = new_color3_p(1, 1, 1);
	material->ambient = 0.1;
	material->diffuse = 0.9;
	material->specular = 0.9;
	material->shininess = 200.0;
	return (material);
}
//default world
t_world	*default_world(void)
{
	t_world	*world;

	world = malloc(sizeof(t_world));
	world->objects = NULL;
	world->light = NULL;
	t_light_p *l1 = new_light(new_point3_p(0, 0, -10), new_color3_p(1, 1, 1));
	// t_light_p *l2 = new_light(new_point3_p(10, -10, -10), new_color3_p(0.1, 0.8, 0.1));
	t_sphere  *s1 = sphere_new();
	// s1->material->color = new_color3_p(0.8, 1.0, 0.6);
	// s1->material->diffuse = 0.7;
	// s1->material->specular = 0.2;
	t_sphere  *s2 = sphere_new();
	set_transform(&s2->transform, translation(0, 0, 10));
	t_object  *o1 = object_new(s1, SPHERE);
	t_object  *o2 = object_new(s2, SPHERE);
	add_object(&o1, o2);
	// add_light(&l1, l2);
	world = create_world(o1, l1);
	return (world);
}

t_world *test_world(void)
{
		t_world	*world;

	world = malloc(sizeof(t_world));
	world->objects = NULL;
	world->light = NULL;
	t_light_p *l1 = new_light(new_point3_p(-10, 10, -10), new_color3_p(1, 1, 1));
	t_sphere  *floor = sphere_new();
	set_transform(&floor->transform, scaling(10, 0.01, 10));
	floor->material->color = new_color3_p(1, 0.9, 0.9);
	floor->material->specular = 0;
	t_sphere  *left_wall = sphere_new();
	set_transform(&left_wall->transform, multiply_matrices(multiply_matrices(translation(0, 0, 5), rotation_y(-M_PI / 4)), multiply_matrices(rotation_x(M_PI / 2), scaling(10, 0.3, 10))));
	left_wall->material = floor->material;
	t_sphere  *right_wall = sphere_new();
	set_transform(&right_wall->transform, multiply_matrices(multiply_matrices(translation(0, 0, 5), rotation_y(M_PI / 4)), multiply_matrices(rotation_x(M_PI / 2), scaling(10, 0.3, 10))));
	right_wall->material = floor->material;
	t_sphere  *middle = sphere_new();
	set_transform(&middle->transform, translation(-0.5, 1, 0.5));
	middle->material->color = new_color3_p(0.1, 1, 0.5);
	middle->material->diffuse = 0.7;
	middle->material->specular = 0.3;
	t_sphere  *right = sphere_new();
	set_transform(&right->transform, multiply_matrices(translation(1.5, 0.5, -0.5), scaling(0.5, 0.5, 0.5)));
	right->material->color = new_color3_p(0.5, 1, 0.1);
	right->material->diffuse = 0.7;
	right->material->specular = 0.3;
	t_sphere  *left = sphere_new();
	set_transform(&left->transform, multiply_matrices(translation(-1.5, 0.33, -0.75), scaling(0.33, 0.33, 0.33)));
	left->material->color = new_color3_p(1, 0.8, 0.1);
	left->material->diffuse = 0.7;
	left->material->specular = 0.3;
	t_object  *o1 = object_new(floor, SPHERE);
	t_object  *o2 = object_new(left_wall, SPHERE);
	t_object  *o3 = object_new(right_wall, SPHERE);
	t_object  *o4 = object_new(middle, SPHERE);
	t_object  *o5 = object_new(right, SPHERE);
	t_object  *o6 = object_new(left, SPHERE);
	add_object(&o1, o2);
	add_object(&o1, o3);
	add_object(&o1, o4);
	add_object(&o1, o5);
	add_object(&o1, o6);
	// add_light(&l1, l2);
	world = create_world(o1, l1);
	return (world);
}
