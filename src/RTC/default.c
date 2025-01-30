/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:35:59 by mdomnik           #+#    #+#             */
/*   Updated: 2025/01/20 21:56:59 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

t_material *default_material(void)
{
	t_material *material;

	material = gc_malloc(sizeof(t_material));
	material->color = add_tuples(new_color3(1, 1, 1), global_color('g', new_color3(0, 0, 0)));
	material->pattern = NULL;
	material->ambient = current_ambient('g', 0);
	material->diffuse = 0.9;
	material->specular = 0.9;
	material->shininess = 200.0;
	material->reflective = 0.0;
	material->transparency = 0.0;
	material->refractive_index = 1.0;
    material->bump_map = NULL;
	return (material);
}

float	current_ambient(int flag, float value)
{
	static float	ambient = 0.3;

	if (flag == 's')
		ambient = value;
	return (ambient);
}

t_color3	global_color(int flag, t_color3 color)
{
	static t_color3	global;

	if (flag == 's')
		global = color;
	return (global);
}

t_size_cap *default_size_cap(void)
{
    t_size_cap *size_cap;

    size_cap = gc_malloc(sizeof(t_size_cap));
    size_cap->min = -1;
    size_cap->max = 0;
    size_cap->cap = 1;
    return (size_cap);
}

//default world
// t_world	*default_world(void)
// {
// 	t_world	*world;
// 
// 	world = malloc(sizeof(t_world));
// 	world->shapes = NULL;
// 	world->light = NULL;
// 	t_light_p *l1 = new_light(new_point3_p(0, 0, 0), new_color3_p(1, 1, 1));
// 	// t_light_p *l2 = new_light(new_point3_p(10, -10, -10), new_color3_p(0.1, 0.8, 0.1));
// 	t_shape  *s1 = sphere();
//     t_matrix *m = translation(0, 2, 0);
//     m = multiply_matrices(m, scaling(0.5, 0.5, 0.5));
//     set_transform(s1, m);
// 	s1->material.color = new_color3_p(1, 0, 0);
// 	// s1->material.diffuse = 0.7;
// 	// s1->material.specular = 0.2;
// 	// t_shape  *s2 = sphere();
// 	// set_transform(s2, scaling(0.5, 0.5, 0.5));
// 	// add_shape(&s1, s2);
// 	world->shapes = s1;
// 	// add_light(&world->light, l1);
// 	world->light = l1;
// 	return (world);
// }
// 
// t_world *test_world(void)
// {
// 		t_world	*world;
// 
// 	world = malloc(sizeof(t_world));
// 	world->shapes = NULL;
// 	world->light = NULL;
// 	t_light_p *l1 = new_light(new_point3_p(-10, 10, -10), new_color3_p(1, 1, 1));
// 	t_shape  *floor = sphere();
// 	set_transform(floor, scaling(10, 0.01, 10));
// 	floor->material.color = new_color3_p(1, 0.9, 0.9);
// 	floor->material.specular = 0;
// 	t_shape  *left_wall = sphere();
// 	set_transform(left_wall, multiply_matrices(multiply_matrices(translation(0, 0, 5), rotation_y(-M_PI / 4)), multiply_matrices(rotation_x(M_PI / 2), scaling(10, 0.3, 10))));
// 	left_wall->material = floor->material;
// 	t_shape  *right_wall = sphere();
// 	set_transform(right_wall, multiply_matrices(multiply_matrices(translation(0, 0, 5), rotation_y(M_PI / 4)), multiply_matrices(rotation_x(M_PI / 2), scaling(10, 0.3, 10))));
// 	right_wall->material = floor->material;
// 	t_shape  *middle = sphere();
// 	set_transform(middle, translation(-0.5, 1, 0.5));
// 	middle->material.color = new_color3_p(0.1, 1, 0.5);
// 	middle->material.diffuse = 0.7;
// 	middle->material.specular = 0.3;
// 	t_shape  *right = sphere();
// 	set_transform(right, multiply_matrices(translation(1.5, 0.5, -0.5), scaling(0.5, 0.5, 0.5)));
// 	right->material.color = new_color3_p(0.5, 1, 0.1);
// 	right->material.diffuse = 0.7;
// 	right->material.specular = 0.3;
// 	t_shape  *left = sphere();
// 	set_transform(left, multiply_matrices(translation(-1.5, 0.33, -0.75), scaling(0.33, 0.33, 0.33)));
// 	left->material.color = new_color3_p(1, 0.8, 0.1);
// 	left->material.diffuse = 0.7;
// 	left->material.specular = 0.3;
// 	add_shape(&floor, left_wall);
// t_world	*default_world(void)
// {
// 	t_world	*world;
// 
// 	world = malloc(sizeof(t_world));
// 	world->shapes = NULL;
// 	world->light = NULL;
// 	t_light_p *l1 = new_light(new_point3_p(0, 0, 0), new_color3_p(1, 1, 1));
// 	// t_light_p *l2 = new_light(new_point3_p(10, -10, -10), new_color3_p(0.1, 0.8, 0.1));
// 	t_shape  *s1 = sphere();
//     t_matrix *m = translation(0, 2, 0);
//     m = multiply_matrices(m, scaling(0.5, 0.5, 0.5));
//     set_transform(s1, m);
// 	s1->material.color = new_color3_p(1, 0, 0);
// 	// s1->material.diffuse = 0.7;
// 	// s1->material.specular = 0.2;
// 	// t_shape  *s2 = sphere();
// 	// set_transform(s2, scaling(0.5, 0.5, 0.5));
// 	// add_shape(&s1, s2);
// 	world->shapes = s1;
// 	// add_light(&world->light, l1);
// 	world->light = l1;
// 	return (world);
// }
// 
// t_world *test_world(void)
// {
// 		t_world	*world;
// 
// 	world = malloc(sizeof(t_world));
// 	world->shapes = NULL;
// 	world->light = NULL;
// 	t_light_p *l1 = new_light(new_point3_p(-10, 10, -10), new_color3_p(1, 1, 1));
// 	t_shape  *floor = sphere();
// 	set_transform(floor, scaling(10, 0.01, 10));
// 	floor->material.color = new_color3_p(1, 0.9, 0.9);
// 	floor->material.specular = 0;
// 	t_shape  *left_wall = sphere();
// 	set_transform(left_wall, multiply_matrices(multiply_matrices(translation(0, 0, 5), rotation_y(-M_PI / 4)), multiply_matrices(rotation_x(M_PI / 2), scaling(10, 0.3, 10))));
// 	left_wall->material = floor->material;
// 	t_shape  *right_wall = sphere();
// 	set_transform(right_wall, multiply_matrices(multiply_matrices(translation(0, 0, 5), rotation_y(M_PI / 4)), multiply_matrices(rotation_x(M_PI / 2), scaling(10, 0.3, 10))));
// 	right_wall->material = floor->material;
// 	t_shape  *middle = sphere();
// 	set_transform(middle, translation(-0.5, 1, 0.5));
// 	middle->material.color = new_color3_p(0.1, 1, 0.5);
// 	middle->material.diffuse = 0.7;
// 	middle->material.specular = 0.3;
// 	t_shape  *right = sphere();
// 	set_transform(right, multiply_matrices(translation(1.5, 0.5, -0.5), scaling(0.5, 0.5, 0.5)));
// 	right->material.color = new_color3_p(0.5, 1, 0.1);
// 	right->material.diffuse = 0.7;
// 	right->material.specular = 0.3;
// 	t_shape  *left = sphere();
// 	set_transform(left, multiply_matrices(translation(-1.5, 0.33, -0.75), scaling(0.33, 0.33, 0.33)));
// 	left->material.color = new_color3_p(1, 0.8, 0.1);
// 	left->material.diffuse = 0.7;
// 	left->material.specular = 0.3;
// 	add_shape(&floor, left_wall);
// 	add_shape(&floor, right_wall);
// 	add_shape(&floor, middle);
// 	add_shape(&floor, right);
// 	add_shape(&floor, left);
// 	world->shapes = floor;
// 	add_light(&world->light, l1);
// 	return (world);
// }
// 
// 	add_shape(&floor, right_wall);
// 	add_shape(&floor, middle);
// 	add_shape(&floor, right);
// 	add_shape(&floor, left);
// 	world->shapes = floor;
// 	add_light(&world->light, l1);
// 	return (world);
// }
// 
// t_world *test_world_plane(void)
// {
// 		t_world	*world;
// 
// 	world = malloc(sizeof(t_world));
// 	world->shapes = NULL;
// 	world->light = NULL;
// 	t_light_p *l1 = new_light(new_point3_p(-10, 10, -10), new_color3_p(1, 1, 1));
// 	t_shape  *floor = plane();
// 	floor->material.pattern = new_pattern(CHECKERS, new_color3_p(0.8, 0.2, 0.2), new_color3_p(0.2, 1, 0.2));
// 	set_pattern_transform(floor->material.pattern, multiply_matrices(rotation_y(M_PI / 4), scaling(0.1, 0.1, 0.1)));
// 	floor->material.reflective = 0.2;
// 	floor->material.color = new_color3_p(1, 0.9, 0.9);
// 	floor->material.specular = 0;
// 	t_shape *wall = plane();
// 	set_transform(wall, multiply_matrices(translation(0, 0, 3), rotation_x(M_PI / 2)));
// 	wall->material.pattern = new_pattern(CHECKERS, new_color3_p(0.8, 0.2, 0.2), new_color3_p(0.2, 1, 0.2));
// 	set_pattern_transform(wall->material.pattern, multiply_matrices(rotation_y(M_PI / 2), scaling(0.5, 0.5, 0.5)));
// 	wall->material.color = new_color3_p(1, 0.9, 0.9);
// 	wall->material.reflective = 0;
// 	wall->material.specular = 0;
// 	t_shape  *middle = sphere();
// 	set_transform(middle, translation(-0.5, 1, 0.5));
// 	middle->material.pattern = new_pattern(RING, new_color3_p(0.5, 0.3, 0.9), new_color3_p(0.1, 0.5, 0.8));
// 	set_pattern_transform(middle->material.pattern, multiply_matrices(scaling(0.1, 0.1, 0.1), rotation_x(M_PI / 2)));
// 	middle->material.reflective = 0.3;
// 	middle->material.color = new_color3_p(0.1, 1, 0.5);
// 	middle->material.diffuse = 0.7;
// 	middle->material.specular = 0.3;
// 	t_shape  *right = cylinder();
// 	set_transform(right, multiply_matrices(translation(3.5, 0.5, -0.5), rotation_z(M_PI / 2)));
// 	// right->material.pattern = new_pattern(GRADIENT, new_color3_p(0.8, 0.1, 0.1), new_color3_p(0.1, 1, 0.8));
// 	// set_pattern_transform(right->material.pattern, multiply_matrices(translation(-1, 0, 0), scaling(2, 2, 2)));
// 	right->material.color = new_color3_p(0.5, 1, 0.1);
// 	right->material.diffuse = 0.7;
// 	right->material.specular = 0.3;
// 	t_shape  *left = cube();
// 	set_transform(left, multiply_matrices(translation(-1.5, 0.33, -0.75), scaling(0.33, 0.33, 0.33)));
// 	left->material.pattern = new_pattern(CHECKERS, new_color3_p(0.8, 0.2, 0.2), new_color3_p(0.2, 1, 0.2));
// 	left->material.color = new_color3_p(1, 0.8, 0.1);
// 	left->material.diffuse = 0.7;
// 	left->material.specular = 0.3;
// 	t_shape *con = cone();
// 	set_transform(con, multiply_matrices(translation(0, 0.8, -0.75), scaling(0.5, 0.5, 0.5)));
// 	con->material.color = new_color3_p(0.5, 1, 0.1);
// 	add_shape(&floor, wall);
// 	add_shape(&floor, middle);
// 	add_shape(&floor, right);
// 	add_shape(&floor, left);
// 	add_shape(&floor, con);
// 	world->shapes = floor;
// 	add_light(&world->light, l1);
// 	return (world);
// }
// 
// t_world *test_textures(void) {
//     t_world *world = malloc(sizeof(t_world));
//     if (!world) {
//         fprintf(stderr, "Error: Could not allocate memory for world.\n");
//         exit(EXIT_FAILURE);
//     }
//     world->shapes = NULL;
//     world->light = NULL;
// 
//     // Add light
//     t_light_p *light = new_light(new_point3_p(-10, 10, -10), new_color3_p(1, 1, 1));
//     add_light(&world->light, light);
// 
//     // Add sphere with a checker texture map
//     t_shape *s = sphere();
//     t_uv *sphere_checkers = uv_checkers(20, 10, new_color3(0, 0.5, 0), new_color3(1, 1, 1));
//     t_pattern *sphere_texture = texture_map(sphere_checkers, spherical_map);
//     s->material.pattern = sphere_texture;
//     s->material.ambient = 0.1;
//     s->material.specular = 0.4;
//     s->material.shininess = 10;
//     s->material.diffuse = 0.6;
// 
//     // Add plane for context
//     t_shape *p = plane();
//     p->material.color = new_color3_p(0.9, 0.9, 0.9);
//     p->material.specular = 0;
//     set_transform(p, translation(0, -1, 0)); // Position the plane as the floor
// 
//     // Add shapes to world
//     add_shape(&p, s); // Add sphere to plane's linked list
//     world->shapes = p;
// 
//     return world;
// }
// 
// t_world *test_planar_mapping_scene(void) {
//     t_world *w = malloc(sizeof(t_world));
//     if (!w) {
//         fprintf(stderr, "Error: Could not allocate memory for world.\n");
//         exit(EXIT_FAILURE);
//     }
//     w->shapes = NULL;
//     w->light = NULL;
// 
//     // Add light
//     t_light_p *l = new_light(new_point3_p(-10, 10, -10), new_color3_p(1, 1, 1));
//     add_light(&w->light, l);
// 
//     // Add sphere with a checker texture map
//     t_shape *s = sphere();
//     t_uv *sphere_checkers = uv_checkers(20, 10, new_color3(0, 0.5, 0), new_color3(1, 1, 1));
//     t_pattern *sphere_texture = texture_map(sphere_checkers, spherical_map);
//     s->material.pattern = sphere_texture;
//     s->material.ambient = 0.1;
//     s->material.specular = 0.4;
//     s->material.shininess = 10;
//     s->material.diffuse = 0.6;
// 
// 
// 	t_pattern *align_check_texture = texture_map(
//     uv_align_check(
//         new_color3(1, 1, 1), // Main (white)
//         new_color3(1, 0, 0), // Upper left (red)
//         new_color3(1, 1, 0), // Upper right (yellow)
//         new_color3(0, 1, 0), // Bottom left (green)
//         new_color3(0, 1, 1)  // Bottom right (cyan)
//     ),
//     planar_map
// 	);
// 	t_shape *p = plane();
// 	p->material.pattern = align_check_texture;
// 	p->material.ambient = 0.1;
// 	p->material.diffuse = 0.8;
// 
// 	add_shape(&p, s); // Add sphere to plane's linked list
//     w->shapes = p;
// 
//     return w;
// }
// 
// 
// t_world *test_cylindrical_mapping_scene(void) {
//     t_world *w = malloc(sizeof(t_world));
//     if (!w) {
//         fprintf(stderr, "Error: Could not allocate memory for world.\n");
//         exit(EXIT_FAILURE);
//     }
//     w->shapes = NULL;
//     w->light = NULL;
// 
//     // Add light
//     t_light_p *l = new_light(new_point3_p(-10, 10, -10), new_color3_p(1, 1, 1));
//     add_light(&w->light, l);
// 
//     // Add cylinder with cylindrical mapping
//     t_shape *c = cylinder();
//     t_uv *cp = uv_checkers(16, 8, new_color3(0, 0.5, 0), new_color3(1, 1, 1));
//     t_pattern *pt = texture_map(cp, cylindrical_map);
// 
//     c->material.pattern = pt;
//     c->material.ambient = 0.1;
//     c->material.specular = 0.6;
//     c->material.shininess = 15;
//     c->material.diffuse = 0.8;
// 
// 	t_shape *s = sphere();
//     t_uv *sphere_checkers = uv_checkers(20, 10, new_color3(0, 0.5, 0), new_color3(1, 1, 1));
//     t_pattern *sphere_texture = texture_map(sphere_checkers, spherical_map);
//     s->material.pattern = sphere_texture;
//     s->material.ambient = 0.1;
//     s->material.specular = 0.4;
//     s->material.shininess = 10;
//     s->material.diffuse = 0.6;
// 
//     set_transform(c, multiply_matrices(rotation_x(5 * (M_PI / 6)), scaling(1, M_PI, 1)));
// 	set_transform(s, translation(0, 0, 100));
//     add_shape(&c, s); // Add sphere to cylinder's linked list
// 	w->shapes = c;
// 
//     return w;
// }
// 
// t_world *test_uv_align_check_scene(void) {
//     t_world *world = malloc(sizeof(t_world));
//     if (!world) {
//         fprintf(stderr, "Error: Could not allocate memory for world.\n");
//         exit(EXIT_FAILURE);
//     }
//     world->shapes = NULL;
//     world->light = NULL;
// 
//     // Add light
//     t_light_p *light = new_light(new_point3_p(-10, 10, -10), new_color3_p(1, 1, 1));
//     add_light(&world->light, light);
// 
//     // Add align check pattern to a plane
//     t_shape *p = plane();
//     t_uv_align_check *align_pattern = uv_align_check(
//         new_color3(1, 1, 1), // Main (white)
//         new_color3(1, 0, 0), // Upper left (red)
//         new_color3(1, 1, 0), // Upper right (yellow)
//         new_color3(0, 1, 0), // Bottom left (green)
//         new_color3(0, 1, 1)  // Bottom right (cyan)
//     );
//     t_pattern *plane_pattern = align_check_map(align_pattern, planar_map);
//     p->material.pattern = plane_pattern;
//     p->material.ambient = 0.1;
//     p->material.diffuse = 0.8;
// 
// 		t_shape *s = sphere();
//     t_uv *sphere_checkers = uv_checkers(20, 10, new_color3(0, 0.5, 0), new_color3(1, 1, 1));
//     t_pattern *sphere_texture = texture_map(sphere_checkers, spherical_map);
//     s->material.pattern = sphere_texture;
//     s->material.ambient = 0.1;
//     s->material.specular = 0.4;
//     s->material.shininess = 10;
//     s->material.diffuse = 0.6;
// 
//     // Add plane to world
// 	add_shape(&p, s); // Add sphere to plane's linked list
//     world->shapes = p;
// 
//     return world;
// }
// 
// t_world *setup_cube_scene() 
// {
//     t_world *world = malloc(sizeof(t_world));
//     world->shapes = NULL;
//     world->light = NULL;
// 
//     // Add lights
//     add_light(&world->light, new_light(new_point3_p(0, 100, -100), new_color3_p(0.25, 0.25, 0.25)));
//     add_light(&world->light, new_light(new_point3_p(0, -100, -100), new_color3_p(0.25, 0.25, 0.25)));
//     add_light(&world->light, new_light(new_point3_p(-100, 0, -100), new_color3_p(0.25, 0.25, 0.25)));
//     add_light(&world->light, new_light(new_point3_p(100, 0, -100), new_color3_p(0.25, 0.25, 0.25)));
// 
//     // Create and transform mapped cubes
//     float rotations[][3] = {
//         {0.7854, 0.7854, -6}, {2.3562, 0.7854, -2}, {3.927, 0.7854, 2}, {5.4978, 0.7854, 6},
//         {0.7854, -0.7854, -6}, {2.3562, -0.7854, -2}, {3.927, -0.7854, 2}, {5.4978, -0.7854, 6}
//     };
// 
//     for (int i = 0; i < 8; i++) {
//         t_shape *cube = create_mapped_cube();
//         cube->transform = *multiply_matrices(
//             multiply_matrices(translation(rotations[i][2], (i < 4 ? 2 : -2), 0),
//                               rotation_y(rotations[i][0])),
//             rotation_x(rotations[i][1])
//         );
//         add_shape(&world->shapes, cube);
//     }
// 
//     return world;
// }
// 
// t_world *create_earth_scene(void) {
//     t_world *world = malloc(sizeof(t_world));
//     if (!world) {
//         fprintf(stderr, "Failed to allocate world.\n");
//         exit(EXIT_FAILURE);
//     }
//     world->shapes = NULL;
//     world->light = NULL;
// 
//     // Add light source
//     t_light_p *light = new_light(new_point3_p(-100, 100, -100), new_color3_p(1, 1, 1));
//     world->light = light;
// 
//     // Add plane
//     t_shape *p = plane();
//     p->material.color = new_color3_p(1, 1, 1);
//     p->material.diffuse = 0.1;
//     p->material.specular = 0;
//     p->material.ambient = 0;
//     p->material.reflective = 0.4;
// 
//     // Add cylinder
//     t_shape *c = cylinder();
//     c->material.color = new_color3_p(1, 1, 1);
//     c->material.diffuse = 0.2;
//     c->material.specular = 0;
//     c->material.ambient = 0;
//     c->material.reflective = 0.1;
//     add_shape(&p, c);
// 
//     // Add sphere with image map
//     t_canvas *earth_canvas = canvas_from_ppm("earthmap1k.ppm");
//     t_pattern *earth_pattern = uv_image(earth_canvas);
//     t_pattern *sphere_texture = texture_map(earth_pattern, spherical_map);
// 
//     t_shape *s = sphere();
//     s->material.pattern = sphere_texture;
//     s->material.diffuse = 0.9;
//     s->material.specular = 0.1;
//     s->material.shininess = 10;
//     s->material.ambient = 0.1;
// 
//     // Apply transformations
//     t_matrix *rotation = rotation_y(1.9);
//     t_matrix *trans = translation(0, 1.1, 0);
//     set_transform(s, multiply_matrices(trans, rotation));
// 
//     add_shape(&p, s);
// 	world->shapes = p;
//     return world;
// }
// 
// t_world *create_skybox_scene(void) {
//     t_world *world = malloc(sizeof(t_world));
//     if (!world) {
//         fprintf(stderr, "Failed to allocate world.\n");
//         exit(EXIT_FAILURE);
//     }
//     world->shapes = NULL;
//     world->light = NULL;
// 
//     // Add light source
//     t_light_p *light = new_light(new_point3_p(0, 100, 0), new_color3_p(1, 1, 1));
//     world->light = light;
// 
//     // Add reflective sphere
//     t_shape *s = sphere();
//     set_transform(s, multiply_matrices(translation(0, 0, 5), scaling(1.75, 1.75, 1.75)));
//     s->material.diffuse = 0.4;
//     s->material.specular = 0.6;
//     s->material.shininess = 20;
//     s->material.reflective = 0.6;
//     s->material.ambient = 0;
// 
//     // Add skybox cube
//     t_shape *skybox = create_mapped_cube();
// 	set_transform(skybox, scaling(500, 500, 500));
//     skybox->material.diffuse = 0;
//     skybox->material.specular = 0;
//     skybox->material.ambient = 1;
// 
// 	// https://www.humus.name/index.php?page=Textures&start=24
// 	t_pattern *uv_left = texture_map(uv_image(canvas_from_ppm("z_hdri/negx.ppm")), planar_map);
// 	t_pattern *uv_front = texture_map(uv_image(canvas_from_ppm("z_hdri/posz.ppm")), planar_map);
// 	t_pattern *uv_right = texture_map(uv_image(canvas_from_ppm("z_hdri/posx.ppm")), planar_map);
// 	t_pattern *uv_back = texture_map(uv_image(canvas_from_ppm("z_hdri/negz.ppm")), planar_map);
// 	t_pattern *uv_up = texture_map(uv_image(canvas_from_ppm("z_hdri/posy.ppm")), planar_map);
// 	t_pattern *uv_down = texture_map(uv_image(canvas_from_ppm("z_hdri/negy.ppm")), planar_map);
// 
// 	t_pattern *cube_map = new_cube_map(uv_left, uv_front, uv_right, uv_back, uv_up, uv_down);
//     // Cube map pattern
//     skybox->material.pattern = cube_map;
// 
//     // Add objects to the world
//     add_shape(&skybox, s);
// 	world->shapes = skybox;
// 
// 	// t_shape *p = plane();
// 	// t_canvas *cnegx = canvas_from_ppm("Tenerife4/negx.ppm");
// 	// t_pattern *uv_left = uv_image(cnegx);
// 	// t_pattern *uv_left_map = texture_map(uv_left, planar_map);
// 	// p->material.pattern = uv_left_map;
// 
// 	// set_transform(p, scaling(10, 10, 10));
// 	
// 	// add_shape(&p, s);
// 	// world->shapes = p;	
// 
// 
//     return world;
// }
// 
// 
// t_world *create_bump_map_scene(void)
// {
//     t_world *world = malloc(sizeof(t_world));
//     if (!world) {
//         fprintf(stderr, "Failed to allocate world.\n");
//         exit(EXIT_FAILURE);
//     }
//     world->shapes = NULL;
//     world->light = NULL;
// 
//     // Add light source
//     t_light_p *light2 = new_light(new_point3_p(100, -100, -100), new_color3_p(1, 1, 1));
//     t_light_p *light = new_light(new_point3_p(-100, 100, -100), new_color3_p(1, 0.5, 1));
//     add_light(&light, light2);
//     world->light = light;
// 
//     // Add plane
//     t_shape *p = plane();
//     p->material.color = new_color3_p(1, 1, 1);
//     p->material.diffuse = 0.1;
//     p->material.specular = 0;
//     p->material.ambient = 0;
//     p->material.reflective = 0.4;
// 
//     // Add cylinder
//     // t_shape *c = cylinder();
//     // c->material.color = new_color3_p(1, 1, 1);
//     // c->material.diffuse = 0.2;
//     // c->material.specular = 0;
//     // c->material.ambient = 0;
//     // c->material.reflective = 0.1;
//     // add_shape(&p, c);
// 
// 
//     t_shape *sph = sphere();
//     set_transform(sph, translation(100, 0, 0));
//     // t_canvas *earth_canvas = canvas_from_ppm("earthmap1k.ppm");
//     // t_pattern *earth_pattern = uv_image(earth_canvas);
//     // t_pattern *sphere_texture = texture_map(earth_pattern, spherical_map);
// 
//     t_shape *s = plane();
//     // s->material.pattern = sphere_texture;
//     s->material.bump_map = bump_map_from_ppm("Bass1.ppm", 10, planar_map);
//     s->material.diffuse = 0.9;
//     s->material.color = new_color3_p(0.42, 0.42, 0.42);
//     s->material.specular = 0.1;
//     s->material.shininess = 10;
//     s->material.ambient = 0.1;
// 
//     // // Apply transformations
//     t_matrix *rotation = rotation_y(3);
//     t_matrix *trans = translation(0, 1.2, 0);
//     set_transform(s, multiply_matrices(trans, rotation));
// 
//     add_shape(&p, s);
//     add_shape(&p, sph);
// 	world->shapes = p;
//     return world;
// }
// 
// 
// 
// t_world *test_groups_scene(void)
// {
// 		t_world	*world;
// 
// 	world = malloc(sizeof(t_world));
// 	world->shapes = NULL;
// 	world->light = NULL;
// 	t_light_p *l1 = new_light(new_point3_p(-5, 10, -5), new_color3_p(1, 1, 1));
// 	t_shape  *floor = plane();
//     t_pattern *wood_floor = texture_map(uv_image(canvas_from_ppm("textures/planks.ppm")), planar_map);
//     set_pattern_transform(wood_floor, scaling(10, 10, 10));
// 	floor->material.color = new_color3_p(1, 0.9, 0.9);
//     floor->material.pattern = wood_floor;
//     floor->material.bump_map = bump_map_from_ppm("textures/planks_bump.ppm", 10, planar_map);
// 	floor->material.specular = 0;
//     floor->material.ambient = 0.5;
// 	// t_shape  *left_wall = sphere();
// 	// set_transform(left_wall, multiply_matrices(multiply_matrices(translation(0, 0, 5), rotation_y(-M_PI / 4)), multiply_matrices(rotation_x(M_PI / 2), scaling(10, 0.3, 10))));
// 	// left_wall->material = floor->material;
// 	// t_shape  *right_wall = sphere();
// 	// set_transform(right_wall, multiply_matrices(multiply_matrices(translation(0, 0, 5), rotation_y(M_PI / 4)), multiply_matrices(rotation_x(M_PI / 2), scaling(10, 0.3, 10))));
// 	// right_wall->material = floor->material;
// 	t_shape *icecream = ice_cream_cone();
//     // set_transform(icecream, multiply_matrices(translation(0, 1, 0), scaling(0.5, 0.5, 0.5)));
//     // print_matrix(c->transform);
//     // printf("cone min: %f\n", c->size_cap->min);
//     // printf("cone max: %f\n", c->size_cap->max);
// 	// icecream->material.color = new_color3_p(1, 0.5, 0.5);
// 	// icecream->material.diffuse = 0.7;
// 	// icecream->material.specular = 0.3;
// 	// icecream->material.shininess = 200.0;
// 	// icecream->material.reflective = 0.2;
// 	// icecream->material.transparency = 0.0;
// 	// icecream->material.refractive_index = 1.0;
//     // set_transform(icecream, translation(0, 1, 0));
// 	// add_shape(&floor, left_wall);
// 	// add_shape(&floor, right_wall);
// 	add_shape(&floor, icecream);
// 	world->shapes = floor;
// 	world->light = l1;
// 	return (world);
// }
// 
// 
// t_world *try_hexagon_scene(void)
// {
// 	t_world	*world;
// 
// 	world = malloc(sizeof(t_world));
// 	world->shapes = NULL;
// 	world->light = NULL;
// 
// 	t_light_p *l1 = new_light(new_point3_p(-5, 10, -5), new_color3_p(1, 1, 1));
// 	world->light = l1;
// 
// 
// 	t_shape  *floor = plane();
//     t_pattern *wood_floor = texture_map(uv_image(canvas_from_ppm("textures/planks.ppm")), planar_map);
//     set_pattern_transform(wood_floor, scaling(10, 10, 10));
// 	floor->material.color = new_color3_p(1, 0.9, 0.9);
//     floor->material.pattern = wood_floor;
//     floor->material.bump_map = bump_map_from_ppm("textures/planks_bump.ppm", 10, planar_map);
// 	floor->material.specular = 0;
//     floor->material.ambient = 0.5;
// 
// 	t_shape *s = sphere();
// 
// 	t_shape *hex = hexagon();
// 	set_transform(hex, multiply_matrices(translation(0, 2, 0), scaling(3, 3, 3)));
//     hex->material.diffuse = 0.4;
//     hex->material.specular = 0.6;
//     hex->material.shininess = 20;
//     hex->material.reflective = 0.6;
//     hex->material.ambient = 0;
// 	inherit_material(hex);
// 	add_shape(&floor, hex);
// 	add_shape(&floor, s);
// 	world->shapes = floor;
// 	return (world);
// }
// 
// // t_world *try_huge_scene(void)
// // {
// // 		t_world	*world;
// 
// // 	world = malloc(sizeof(t_world));
// // 	world->shapes = NULL;
// // 	world->light = NULL;
// 
// // 	t_light_p *l1 = new_light(new_point3_p(-5, 10, -5), new_color3_p(1, 1, 1));
// // 	world->light = l1;
// 
// 
// // 	t_shape  *floor = plane();
// //     t_pattern *wood_floor = texture_map(uv_image(canvas_from_ppm("textures/planks.ppm")), planar_map);
// //     set_pattern_transform(wood_floor, scaling(10, 10, 10));
// // 	floor->material.color = new_color3_p(1, 0.9, 0.9);
// //     floor->material.pattern = wood_floor;
// //     floor->material.bump_map = bump_map_from_ppm("textures/planks_bump.ppm", 10, planar_map);
// // 	floor->material.specular = 0;
// //     floor->material.ambient = 0.5;
// 
// // 	for(int i = 0; i < 50; i++)
// // 	{
// // 		t_shape *s = sphere();
// // 		set_transform(s, translation(0, (1 + (0.1 * i)), 0));
// // 		add_shape(&floor, s);
// // 	}
// 	
// // 	world->shapes = floor;
// // 	return (world);
// // }
// 
// t_world *triangle_scene(void)
// {
// 		t_world	*world;
// 
// 	world = malloc(sizeof(t_world));
// 	world->shapes = NULL;
// 	world->light = NULL;
// 
// 	t_light_p *l1 = new_light(new_point3_p(-5, 10, -5), new_color3_p(1, 1, 1));
// 	world->light = l1;
// 
// 
// 	t_shape  *floor = plane();
//     t_pattern *wood_floor = texture_map(uv_image(canvas_from_ppm("textures/planks.ppm")), planar_map);
//     set_pattern_transform(wood_floor, scaling(10, 10, 10));
// 	floor->material.color = new_color3_p(1, 0.9, 0.9);
//     floor->material.pattern = wood_floor;
//     floor->material.bump_map = bump_map_from_ppm("textures/planks_bump.ppm", 10, planar_map);
// 	floor->material.specular = 0;
//     floor->material.ambient = 0.5;
// 
// 	t_obj_file *obj = parse_obj_file("teapot.obj");
//     t_group *g = obj->default_group;
// 	// int i = 0;
// 	// while(g)
// 	// {
// 	// 	printf("group_name = %s\n", g->name);
// 	// 	printf("group->children->count = %d\n", g->group->children_count);
// 	// 	i = 0;
// 	// 	while(i < g->group->children_count)
// 	// 	{
// 	// 		printf("Triangle\n");
// 	// 		print_tuple(g->group->children->triangle->p1);
// 	// 		print_tuple(g->group->children->triangle->p2);
// 	// 		print_tuple(g->group->children->triangle->p3);
// 	// 		g->group->children = g->group->children->next;
// 	// 		i++;
// 	// 	}
// 	// 	g = g->next;
// 	// }
// 	t_shape *gr = objgroups_to_group(g);
// 	add_shape(&floor, gr);
// 	
// 	world->shapes = floor;
// 	return (world);
// }
// 
t_world *night_box(void)
{
	t_world	*world;

	world = malloc(sizeof(t_world));
	world->shapes = NULL;
	world->light = NULL;
	t_light_p *l1 = new_light(new_point3(60, 60, 0), new_color3(1, 1, 1));
	t_canvas *earth_canvas = canvas_from_ppm("textures/earth.ppm");
    t_pattern *earth_pattern = uv_image(earth_canvas);
    t_pattern *sphere_texture = texture_map(earth_pattern, spherical_map);

	t_canvas *moon_canvas = canvas_from_ppm("textures/moon2.ppm");
    t_pattern *moon_pattern = uv_image(moon_canvas);
    t_pattern *moon_texture = texture_map(moon_pattern, spherical_map);

    t_shape *moon = sphere();
    set_transform(moon, multiply_matrices(translation(-8, 8, 0), scaling(2, 2, 2)));
    moon->material.pattern = moon_texture;
    moon->material.diffuse = 0.4;
    moon->material.specular = 0.6;
    moon->material.shininess = 10;
    moon->material.reflective = 0.05;
    moon->material.ambient = 0.1;

    t_shape *s = sphere();
    s->material.pattern = sphere_texture;
    s->material.diffuse = 0.9;
    s->material.specular = 0.1;
    s->material.shininess = 10;
    s->material.ambient = 0.1;
    set_transform(s, multiply_matrices(translation(0, 0, 0), scaling(4, 4, 4)));
    
    t_shape  *skybox = cube();
    set_transform(skybox, scaling(500, 500, 500));
	t_pattern *uv_left = texture_map(uv_image(canvas_from_ppm("textures/night/nx.ppm")), planar_map);
	t_pattern *uv_front = texture_map(uv_image(canvas_from_ppm("textures/night/pz.ppm")), planar_map);
	t_pattern *uv_right = texture_map(uv_image(canvas_from_ppm("textures/night/px.ppm")), planar_map);
	t_pattern *uv_back = texture_map(uv_image(canvas_from_ppm("textures/night/nz.ppm")), planar_map);
	t_pattern *uv_up = texture_map(uv_image(canvas_from_ppm("textures/night/py.ppm")), planar_map);
	t_pattern *uv_down = texture_map(uv_image(canvas_from_ppm("textures/night/ny.ppm")), planar_map);

	t_pattern *cube_map = new_cube_map(uv_left, uv_front, uv_right, uv_back, uv_up, uv_down);
    // Cube map pattern
    skybox->material.pattern = cube_map;
    skybox->material.diffuse = 0;
    skybox->material.specular = 0;
    skybox->material.ambient = 1;
    add_shape(&world->shapes, moon);
	add_shape(&world->shapes, s);
    add_shape(&world->shapes, skybox);
	add_light(&world->light, l1);
	return (world);
}

// t_world *benchmark_1(void)
// {
// 	t_world	*world;
// 
// 	world = malloc(sizeof(t_world));
// 	world->shapes = NULL;
// 	world->light = NULL;
// 	t_light_p *l1 = new_light(new_point3_p(0, 2, -2), new_color3_p(1, 1, 1));
// 	t_shape  *s1 = sphere();
// 	s1->material.color = new_color3_p(1, 0, 0);
// 	add_shape(&world->shapes, s1);
// 	add_light(&world->light, l1);
// 	return (world);
// }
// 
t_world *benchmark_2(void)
{
    t_world	*world;

	world = malloc(sizeof(t_world));
	world->shapes = NULL;
	world->light = NULL;
	t_light_p *l1 = new_light(new_point3(-10, 10, -10), new_color3(1, 1, 1));
	t_shape  *floor = plane();
	floor->material.color = new_color3(1, 0.9, 0.9);
	floor->material.specular = 0;
	t_shape  *left_wall = sphere();
	set_transform(left_wall, multiply_matrices(multiply_matrices(translation(0, 0, 5), rotation_y(-M_PI / 4)), multiply_matrices(rotation_x(M_PI / 2), scaling(10, 0.3, 10))));
	left_wall->material = floor->material;
	t_shape  *right_wall = sphere();
	set_transform(right_wall, multiply_matrices(multiply_matrices(translation(0, 0, 5), rotation_y(M_PI / 4)), multiply_matrices(rotation_x(M_PI / 2), scaling(10, 0.3, 10))));
	right_wall->material = floor->material;
	t_shape  *middle = sphere();
	set_transform(middle, translation(-0.5, 1, 0.5));
	middle->material.color = new_color3(0.1, 1, 0.5);
	middle->material.diffuse = 0.7;
	middle->material.specular = 0.3;
	t_shape  *right = sphere();
	set_transform(right, multiply_matrices(translation(1.5, 0.5, -0.5), scaling(0.5, 0.5, 0.5)));
	right->material.color = new_color3(0.5, 1, 0.1);
	right->material.diffuse = 0.7;
	right->material.specular = 0.3;
	t_shape  *left = sphere();
	set_transform(left, multiply_matrices(translation(-1.5, 0.33, -0.75), scaling(0.33, 0.33, 0.33)));
	left->material.color = new_color3(1, 0.8, 0.1);
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

// t_world *benchmark_3(void)
// {
//     t_world	*world;
// 
//     world = malloc(sizeof(t_world));
//     world->shapes = NULL;
//     world->light = NULL;
//     t_light_p *l1 = new_light(new_point3_p(-10, 10, -10), new_color3_p(1, 0.5, 1));
//     t_light_p *l2 = new_light(new_point3_p(10, 10, -10), new_color3_p(0.5, 0.8, 0.3));
//     t_shape  *floor = plane();
//     floor->material.color = new_color3_p(1, 0.9, 0.9);
//     floor->material.diffuse = 0.4;
//     floor->material.specular = 0.6;
//     floor->material.shininess = 20;
//     floor->material.reflective = 0.6;
//     floor->material.ambient = 0;
// 
//     t_shape *wall = plane();
//     set_transform(wall, multiply_matrices(translation(0, 0, 3), rotation_x(M_PI / 2)));
//     wall->material.color = new_color3_p(1, 0.9, 0.9);
//     wall->material.specular = 0;
//     t_shape  *middle = sphere();
//     set_transform(middle, translation(-0.5, 1, 0.5));
//     t_uv *sphere_checkers = uv_checkers(20, 10, new_color3(0, 0.5, 0), new_color3(1, 1, 1));
//     t_pattern *sphere_texture = texture_map(sphere_checkers, spherical_map);
//     middle->material.pattern = sphere_texture;
//     middle->material.color = new_color3_p(0.1, 1, 0.5);
//     middle->material.diffuse = 0.7;
//     middle->material.specular = 0.3;
//     t_shape  *right = cylinder();
//     set_transform(right, multiply_matrices(translation(1, 0.5, -0.5), rotation_z(M_PI / 2)));
//     t_pattern *tile = texture_map(uv_image(canvas_from_ppm("Tile.ppm")), cylindrical_map);
//     set_pattern_transform(tile, scaling(3, 3, 3));
//     right->material.pattern = tile;
//     right->material.color = new_color3_p(0.5, 1, 0.1);
//     right->material.diffuse = 0.7;
//     right->material.specular = 0.3;
//     t_shape  *left = cube();
//     set_transform(left, multiply_matrices(translation(-1.5, 0.33, -0.75), scaling(0.33, 0.33, 0.33)));
// 	t_pattern *uv_left = texture_map(uv_image(canvas_from_ppm("z_hdri/negx.ppm")), planar_map);
// 	t_pattern *uv_front = texture_map(uv_image(canvas_from_ppm("z_hdri/posz.ppm")), planar_map);
// 	t_pattern *uv_right = texture_map(uv_image(canvas_from_ppm("z_hdri/posx.ppm")), planar_map);
// 	t_pattern *uv_back = texture_map(uv_image(canvas_from_ppm("z_hdri/negz.ppm")), planar_map);
// 	t_pattern *uv_up = texture_map(uv_image(canvas_from_ppm("z_hdri/posy.ppm")), planar_map);
// 	t_pattern *uv_down = texture_map(uv_image(canvas_from_ppm("z_hdri/negy.ppm")), planar_map);
// 
// 	t_pattern *cube_map = new_cube_map(uv_left, uv_front, uv_right, uv_back, uv_up, uv_down);
//     // Cube map pattern
//     left->material.pattern = cube_map;
//     left->material.color = new_color3_p(1, 0.8, 0.1);
//     left->material.diffuse = 0.7;
//     left->material.specular = 0.3;
//     t_shape *con = cone();
//     set_transform(con, multiply_matrices(translation(0, 0.8, -0.75), scaling(0.5, 0.5, 0.5)));
//     con->material.color = new_color3_p(0.5, 1, 0.1);
//     add_shape(&floor, wall);
//     add_shape(&floor, middle);
//     add_shape(&floor, right);
//     add_shape(&floor, left);
//     add_shape(&floor, con);
//     world->shapes = floor;
//     add_light(&world->light, l1);
//     add_light(&world->light, l2);
//     return (world);
// }
// 
// t_world *benchmark_4(void)
// {
// 	t_world	*world;
// 
// 	world = malloc(sizeof(t_world));
// 	world->shapes = NULL;
// 	world->light = NULL;
// 
// 	t_light_p *l1 = new_light(new_point3_p(-5, 10, -5), new_color3_p(1, 1, 1));
// 	world->light = l1;
// 
// 	t_shape  *floor = plane();
//     t_pattern *wood_floor = texture_map(uv_image(canvas_from_ppm("textures/planks.ppm")), planar_map);
//     set_pattern_transform(wood_floor, scaling(10, 10, 10));
// 	floor->material.color = new_color3_p(1, 0.9, 0.9);
//     floor->material.pattern = wood_floor;
//     floor->material.bump_map = bump_map_from_ppm("textures/planks_bump.ppm", 10, planar_map);
// 	floor->material.specular = 0;
//     floor->material.ambient = 0.5;
// 
// 	t_shape *s = sphere();
// 
// 	t_shape *hex = hexagon();
// 	set_transform(hex, multiply_matrices(translation(-0.5, 2, -0.5), scaling(2, 2, 2)));
//     hex->material.color = new_color3_p(0.9, 0.5, 0.5);
//     hex->material.diffuse = 0.4;
//     hex->material.specular = 0.6;
//     hex->material.shininess = 20;
//     hex->material.reflective = 0.6;
//     hex->material.ambient = 0;
// 	inherit_material(hex);
//     t_shape *hex2 = hexagon();
//     set_transform(hex2, multiply_matrices(translation(0.1, 2, 0.1), scaling(2, 2, 2)));
//     hex2->material.color = new_color3_p(0.5, 0.9, 0.5);
//     hex2->material.diffuse = 0.4;
//     hex2->material.specular = 0.6;
//     hex2->material.shininess = 20;
//     hex2->material.reflective = 0.6;
//     hex2->material.ambient = 0;
//     inherit_material(hex2);
// 	add_shape(&floor, hex);
//     add_shape(&floor, hex2);
// 	add_shape(&floor, s);
// 	world->shapes = floor;
// 	return (world);
// }
// 
// t_world *benchmark_5(void)
// {
// 	t_world	*world;
// 
// 	world = malloc(sizeof(t_world));
// 	world->shapes = NULL;
// 	world->light = NULL;
// 
// 	t_light_p *l1 = new_light(new_point3_p(-5, 10, -5), new_color3_p(1, 0.8, 0.8));
//     t_light_p *l2 = new_light(new_point3_p(5, 10, -5), new_color3_p(0.8, 0.8, 1));
//     add_light(&world->light, l1);
//     add_light(&world->light, l2);
// 
// 	t_shape  *floor = plane();
//     t_pattern *wood_floor = texture_map(uv_image(canvas_from_ppm("textures/planks.ppm")), planar_map);
//     set_pattern_transform(wood_floor, scaling(10, 10, 10));
// 	floor->material.color = new_color3_p(1, 0.9, 0.9);
//     floor->material.pattern = wood_floor;
//     floor->material.bump_map = bump_map_from_ppm("textures/planks_bump.ppm", 10, planar_map);
// 	floor->material.specular = 0;
//     floor->material.ambient = 0.5;
// 
// 	t_shape *s = sphere();
// 
// 	t_shape *hex = hexagon();
// 	set_transform(hex, multiply_matrices(translation(0, 2, 0), scaling(0.5, 0.5, 0.5)));
//     hex->material.color = new_color3_p(0.9, 0.5, 0.5);
//     hex->material.diffuse = 0.4;
//     hex->material.specular = 0.6;
//     hex->material.shininess = 20;
//     hex->material.reflective = 0.6;
//     hex->material.ambient = 0;
// 	inherit_material(hex);
//     t_shape *hex2 = hexagon();
//     set_transform(hex2, multiply_matrices(translation(1, 2, 1), scaling(0.25, 0.25, 0.25)));
//     hex2->material.color = new_color3_p(0.5, 0.9, 0.5);
//     hex2->material.diffuse = 0.4;
//     hex2->material.specular = 0.6;
//     hex2->material.shininess = 20;
//     hex2->material.reflective = 0.6;
//     hex2->material.ambient = 0;
//     inherit_material(hex2);
// 	add_shape(&floor, hex);
//     add_shape(&floor, hex2);
// 	add_shape(&floor, s);
// 	world->shapes = floor;
// 	return (world);
// }
