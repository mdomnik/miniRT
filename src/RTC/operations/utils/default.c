/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:35:59 by mdomnik           #+#    #+#             */
/*   Updated: 2024/12/08 18:59:18 by mdomnik          ###   ########.fr       */
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

t_world *test_textures(void) {
    t_world *world = malloc(sizeof(t_world));
    if (!world) {
        fprintf(stderr, "Error: Could not allocate memory for world.\n");
        exit(EXIT_FAILURE);
    }
    world->shapes = NULL;
    world->light = NULL;

    // Add light
    t_light_p *light = new_light(new_point3_p(-10, 10, -10), new_color3_p(1, 1, 1));
    add_light(&world->light, light);

    // Add sphere with a checker texture map
    t_shape *s = sphere();
    t_uv *sphere_checkers = uv_checkers(20, 10, new_color3(0, 0.5, 0), new_color3(1, 1, 1));
    t_pattern *sphere_texture = texture_map(sphere_checkers, spherical_map);
    s->material.pattern = sphere_texture;
    s->material.ambient = 0.1;
    s->material.specular = 0.4;
    s->material.shininess = 10;
    s->material.diffuse = 0.6;

    // Add plane for context
    t_shape *p = plane();
    p->material.color = new_color3_p(0.9, 0.9, 0.9);
    p->material.specular = 0;
    set_transform(p, translation(0, -1, 0)); // Position the plane as the floor

    // Add shapes to world
    add_shape(&p, s); // Add sphere to plane's linked list
    world->shapes = p;

    return world;
}

t_world *test_planar_mapping_scene(void) {
    t_world *w = malloc(sizeof(t_world));
    if (!w) {
        fprintf(stderr, "Error: Could not allocate memory for world.\n");
        exit(EXIT_FAILURE);
    }
    w->shapes = NULL;
    w->light = NULL;

    // Add light
    t_light_p *l = new_light(new_point3_p(-10, 10, -10), new_color3_p(1, 1, 1));
    add_light(&w->light, l);

    // Add sphere with a checker texture map
    t_shape *s = sphere();
    t_uv *sphere_checkers = uv_checkers(20, 10, new_color3(0, 0.5, 0), new_color3(1, 1, 1));
    t_pattern *sphere_texture = texture_map(sphere_checkers, spherical_map);
    s->material.pattern = sphere_texture;
    s->material.ambient = 0.1;
    s->material.specular = 0.4;
    s->material.shininess = 10;
    s->material.diffuse = 0.6;


	t_pattern *align_check_texture = texture_map(
    uv_align_check(
        new_color3(1, 1, 1), // Main (white)
        new_color3(1, 0, 0), // Upper left (red)
        new_color3(1, 1, 0), // Upper right (yellow)
        new_color3(0, 1, 0), // Bottom left (green)
        new_color3(0, 1, 1)  // Bottom right (cyan)
    ),
    planar_map
	);
	t_shape *p = plane();
	p->material.pattern = align_check_texture;
	p->material.ambient = 0.1;
	p->material.diffuse = 0.8;

	add_shape(&p, s); // Add sphere to plane's linked list
    w->shapes = p;

    return w;
}


t_world *test_cylindrical_mapping_scene(void) {
    t_world *w = malloc(sizeof(t_world));
    if (!w) {
        fprintf(stderr, "Error: Could not allocate memory for world.\n");
        exit(EXIT_FAILURE);
    }
    w->shapes = NULL;
    w->light = NULL;

    // Add light
    t_light_p *l = new_light(new_point3_p(-10, 10, -10), new_color3_p(1, 1, 1));
    add_light(&w->light, l);

    // Add cylinder with cylindrical mapping
    t_shape *c = cylinder();
    t_uv *cp = uv_checkers(16, 8, new_color3(0, 0.5, 0), new_color3(1, 1, 1));
    t_pattern *pt = texture_map(cp, cylindrical_map);

    c->material.pattern = pt;
    c->material.ambient = 0.1;
    c->material.specular = 0.6;
    c->material.shininess = 15;
    c->material.diffuse = 0.8;

	t_shape *s = sphere();
    t_uv *sphere_checkers = uv_checkers(20, 10, new_color3(0, 0.5, 0), new_color3(1, 1, 1));
    t_pattern *sphere_texture = texture_map(sphere_checkers, spherical_map);
    s->material.pattern = sphere_texture;
    s->material.ambient = 0.1;
    s->material.specular = 0.4;
    s->material.shininess = 10;
    s->material.diffuse = 0.6;

    set_transform(c, multiply_matrices(rotation_x(5 * (M_PI / 6)), scaling(1, M_PI, 1)));
	set_transform(s, translation(0, 0, 100));
    add_shape(&c, s); // Add sphere to cylinder's linked list
	w->shapes = c;

    return w;
}

t_world *test_uv_align_check_scene(void) {
    t_world *world = malloc(sizeof(t_world));
    if (!world) {
        fprintf(stderr, "Error: Could not allocate memory for world.\n");
        exit(EXIT_FAILURE);
    }
    world->shapes = NULL;
    world->light = NULL;

    // Add light
    t_light_p *light = new_light(new_point3_p(-10, 10, -10), new_color3_p(1, 1, 1));
    add_light(&world->light, light);

    // Add align check pattern to a plane
    t_shape *p = plane();
    t_uv_align_check *align_pattern = uv_align_check(
        new_color3(1, 1, 1), // Main (white)
        new_color3(1, 0, 0), // Upper left (red)
        new_color3(1, 1, 0), // Upper right (yellow)
        new_color3(0, 1, 0), // Bottom left (green)
        new_color3(0, 1, 1)  // Bottom right (cyan)
    );
    t_pattern *plane_pattern = align_check_map(align_pattern, planar_map);
    p->material.pattern = plane_pattern;
    p->material.ambient = 0.1;
    p->material.diffuse = 0.8;

		t_shape *s = sphere();
    t_uv *sphere_checkers = uv_checkers(20, 10, new_color3(0, 0.5, 0), new_color3(1, 1, 1));
    t_pattern *sphere_texture = texture_map(sphere_checkers, spherical_map);
    s->material.pattern = sphere_texture;
    s->material.ambient = 0.1;
    s->material.specular = 0.4;
    s->material.shininess = 10;
    s->material.diffuse = 0.6;

    // Add plane to world
	add_shape(&p, s); // Add sphere to plane's linked list
    world->shapes = p;

    return world;
}





