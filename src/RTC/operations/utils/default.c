/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:35:59 by mdomnik           #+#    #+#             */
/*   Updated: 2024/12/03 22:58:47 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

t_material *default_material(void)
{
	t_material *material;

	material = malloc(sizeof(t_material));
	material->color = new_color3_p(1, 1, 1);
	material->pattern = NULL;
	material->ambient = 0.1;
	material->diffuse = 0.9;
	material->specular = 0.9;
	material->shininess = 200.0;
	material->reflective = 0.0;
	material->transparency = 0.0;
	material->refractive_index = 1.0;
	return (material);
}
//default world
t_world	*default_world(void)
{
	t_world	*world;

	world = malloc(sizeof(t_world));
	world->shapes = NULL;
	world->light = NULL;
	t_light_p *l1 = new_light(new_point3_p(-10, 10, -10), new_color3_p(1, 1, 1));
	// t_light_p *l2 = new_light(new_point3_p(10, -10, -10), new_color3_p(0.1, 0.8, 0.1));
	t_shape  *s1 = sphere();
	s1->material.color = new_color3_p(0.8, 1.0, 0.6);
	s1->material.diffuse = 0.7;
	s1->material.specular = 0.2;
	t_shape  *s2 = sphere();
	set_transform(s2, scaling(0.5, 0.5, 0.5));
	add_shape(&s1, s2);
	world->shapes = s1;
	// add_light(&world->light, l1);
	world->light = l1;
	return (world);
}

t_world *test_world(void)
{
		t_world	*world;

	world = malloc(sizeof(t_world));
	world->shapes = NULL;
	world->light = NULL;
	t_light_p *l1 = new_light(new_point3_p(-10, 10, -10), new_color3_p(1, 1, 1));
	t_shape  *floor = sphere();
	set_transform(floor, scaling(10, 0.01, 10));
	floor->material.color = new_color3_p(1, 0.9, 0.9);
	floor->material.specular = 0;
	t_shape  *left_wall = sphere();
	set_transform(left_wall, multiply_matrices(multiply_matrices(translation(0, 0, 5), rotation_y(-M_PI / 4)), multiply_matrices(rotation_x(M_PI / 2), scaling(10, 0.3, 10))));
	left_wall->material = floor->material;
	t_shape  *right_wall = sphere();
	set_transform(right_wall, multiply_matrices(multiply_matrices(translation(0, 0, 5), rotation_y(M_PI / 4)), multiply_matrices(rotation_x(M_PI / 2), scaling(10, 0.3, 10))));
	right_wall->material = floor->material;
	t_shape  *middle = sphere();
	set_transform(middle, translation(-0.5, 1, 0.5));
	middle->material.color = new_color3_p(0.1, 1, 0.5);
	middle->material.diffuse = 0.7;
	middle->material.specular = 0.3;
	t_shape  *right = sphere();
	set_transform(right, multiply_matrices(translation(1.5, 0.5, -0.5), scaling(0.5, 0.5, 0.5)));
	right->material.color = new_color3_p(0.5, 1, 0.1);
	right->material.diffuse = 0.7;
	right->material.specular = 0.3;
	t_shape  *left = sphere();
	set_transform(left, multiply_matrices(translation(-1.5, 0.33, -0.75), scaling(0.33, 0.33, 0.33)));
	left->material.color = new_color3_p(1, 0.8, 0.1);
	left->material.diffuse = 0.7;
	left->material.specular = 0.3;
	add_shape(&floor, left_wall);
	add_shape(&floor, right_wall);
	add_shape(&floor, middle);
	add_shape(&floor, right);
	add_shape(&floor, left);
	world->shapes = floor;
	add_light(&world->light, l1);
	return (world);
}

t_world *test_world_plane(void)
{
		t_world	*world;

	world = malloc(sizeof(t_world));
	world->shapes = NULL;
	world->light = NULL;
	t_light_p *l1 = new_light(new_point3_p(-10, 10, -10), new_color3_p(1, 1, 1));
	t_shape  *floor = plane();
	floor->material.pattern = new_pattern(CHECKERS, new_color3_p(0.8, 0.2, 0.2), new_color3_p(0.2, 1, 0.2));
	set_pattern_transform(floor->material.pattern, multiply_matrices(rotation_y(M_PI / 4), scaling(0.1, 0.1, 0.1)));
	floor->material.reflective = 0.5;
	floor->material.color = new_color3_p(1, 0.9, 0.9);
	floor->material.specular = 0;
	t_shape *wall = plane();
	set_transform(wall, multiply_matrices(translation(0, 0, 3), rotation_x(M_PI / 2)));
	wall->material.pattern = new_pattern(CHECKERS, new_color3_p(0.8, 0.2, 0.2), new_color3_p(0.2, 1, 0.2));
	set_pattern_transform(wall->material.pattern, multiply_matrices(rotation_y(M_PI / 2), scaling(0.5, 0.5, 0.5)));
	wall->material.color = new_color3_p(1, 0.9, 0.9);
	wall->material.reflective = 0.5;
	wall->material.specular = 0;
	t_shape  *middle = sphere();
	set_transform(middle, translation(-0.5, 1, 0.5));
	middle->material.pattern = new_pattern(RING, new_color3_p(0.5, 0.3, 0.9), new_color3_p(0.1, 0.5, 0.8));
	set_pattern_transform(middle->material.pattern, multiply_matrices(scaling(0.1, 0.1, 0.1), rotation_x(M_PI / 2)));
	middle->material.reflective = 0.3;
	middle->material.color = new_color3_p(0.1, 1, 0.5);
	middle->material.diffuse = 0.7;
	middle->material.specular = 0.3;
	t_shape  *right = cylinder();
	set_transform(right, multiply_matrices(translation(3.5, 0.5, -0.5), rotation_z(M_PI / 2)));
	// right->material.pattern = new_pattern(GRADIENT, new_color3_p(0.8, 0.1, 0.1), new_color3_p(0.1, 1, 0.8));
	// set_pattern_transform(right->material.pattern, multiply_matrices(translation(-1, 0, 0), scaling(2, 2, 2)));
	right->material.color = new_color3_p(0.5, 1, 0.1);
	right->material.diffuse = 0.7;
	right->material.specular = 0.3;
	t_shape  *left = cube();
	set_transform(left, multiply_matrices(translation(-1.5, 0.33, -0.75), scaling(0.33, 0.33, 0.33)));
	left->material.pattern = new_pattern(CHECKERS, new_color3_p(0.8, 0.2, 0.2), new_color3_p(0.2, 1, 0.2));
	left->material.color = new_color3_p(1, 0.8, 0.1);
	left->material.diffuse = 0.7;
	left->material.specular = 0.3;
	t_shape *con = cone();
	set_transform(con, multiply_matrices(translation(0, 0.8, -0.75), scaling(0.5, 0.5, 0.5)));
	con->material.color = new_color3_p(0.5, 1, 0.1);
	add_shape(&floor, wall);
	add_shape(&floor, middle);
	add_shape(&floor, right);
	add_shape(&floor, left);
	add_shape(&floor, con);
	world->shapes = floor;
	add_light(&world->light, l1);
	return (world);
}
