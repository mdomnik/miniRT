/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:54:43 by mdomnik           #+#    #+#             */
/*   Updated: 2025/01/20 20:57:02 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

// //triangle tests
// int main(void)
// {
//     //test_1
//     // t_point3 p1 = new_point3(0, 1, 0);
//     // t_point3 p2 = new_point3(-1, 0, 0);
//     // t_point3 p3 = new_point3(1, 0, 0);
//     // t_shape *t = triangle(p1, p2, p3);
//     // print_tuple(t->triangle->p1);
//     // print_tuple(t->triangle->p2);
//     // print_tuple(t->triangle->p3);
//     // print_tuple(t->triangle->e1);
//     // print_tuple(t->triangle->e2);
//     // print_tuple(t->triangle->normal);
//     //test_2
//     // t_shape *t = triangle(new_point3(0, 1, 0),
		// new_point3(-1, 0, 0), new_point3(1, 0, 0));
//     // t_vec3 n1 = local_normal_at(t, new_point3_p(0, 0.5, 0));
//     // t_vec3 n2 = local_normal_at(t, new_point3_p(-0.5, 0.75, 0));
//     // t_vec3 n3 = local_normal_at(t, new_point3_p(0.5, 0.25, 0));
//     // print_tuple(t->triangle->normal);
//     // print_tuple(n1);
//     // print_tuple(n2);
//     // print_tuple(n3);

//     //test_3
//     // t_shape *t = triangle(new_point3(0, 1, 0),
		// new_point3(-1, 0, 0), new_point3(1, 0, 0));
//     // t_ray *r = ray_new(new_point3_p(0, -1, -2), new_vec3_p(0, 1, 0));
//     // t_x *xs = intersect_triangle(t, r);
//     // if (xs) {
//     //     printf("Intersections found: %d\n", xs->count);
//     //     for (int i = 0; i < xs->count; i++) {
//     //         printf("t[%d]: %f\n", i, xs->i[i].t);
//     //     }
//     //     free(xs->i);
//     //     free(xs);
//     // } else {
//     //     printf("No intersections found.\n");
//     // }
//     //test_4
//     // t_shape *t = triangle(new_point3(0, 1, 0), 
			// new_point3(-1, 0, 0), new_point3(1, 0, 0));
//     // t_ray *r = ray_new(new_point3_p(1, 1, -2), new_vec3_p(0, 0, 1));
//     // t_x *xs = intersect_triangle(t, r);
//     // if (xs) {
//     //     printf("Intersections found: %d\n", xs->count);
//     //     for (int i = 0; i < xs->count; i++) {
//     //         printf("t[%d]: %f\n", i, xs->i[i].t);
//     //     }
//     //     free(xs->i);
//     //     free(xs);
//     // } else {
//     //     printf("No intersections found.\n");
//     // }

//     //test_5
//     // t_shape *t = triangle(new_point3(0, 1, 0),
			// new_point3(-1, 0, 0), new_point3(1, 0, 0));
//     // t_ray *r = ray_new(new_point3_p(-1, 1, -2), new_vec3_p(0, 0, 1));
//     // t_x *xs = intersect_triangle(t, r);
//     // if (xs) {
//     //     printf("Intersections found: %d\n", xs->count);
//     //     for (int i = 0; i < xs->count; i++) {
//     //         printf("t[%d]: %f\n", i, xs->i[i].t);
//     //     }
//     //     free(xs->i);
//     //     free(xs);
//     // } else {
//     //     printf("No intersections found.\n");
//     // }

//     //test_6
//     // t_shape *t = triangle(new_point3(0, 1, 0),
// 			new_point3(-1, 0, 0), new_point3(1, 0, 0));
//     // t_ray *r = ray_new(new_point3_p(0, -1, -2), new_vec3_p(0, 0, 1));
//     // t_x *xs = intersect_triangle(t, r);
//     // if (xs) {
//     //     printf("Intersections found: %d\n", xs->count);
//     //     for (int i = 0; i < xs->count; i++) {
//     //         printf("t[%d]: %f\n", i, xs->i[i].t);
//     //     }
//     //     free(xs->i);
//     //     free(xs);
//     // } else {
//     //     printf("No intersections found.\n");
//     // }

//     //test_7
//     // t_shape *t = triangle(new_point3(0, 1, 0),
		// new_point3(-1, 0, 0), new_point3(1, 0, 0));
//     // t_ray *r = ray_new(new_point3_p(0, 0.5, -2), new_vec3_p(0, 0, 1));
//     // t_x *xs = intersect_triangle(t, r);
//     // if (xs) {
//     //     printf("Intersections found: %d\n", xs->count);
//     //     for (int i = 0; i < xs->count; i++) {
//     //         printf("t[%d]: %f\n", i, xs->i[i].t);
//     //     }
//     //     free(xs->i);
//     //     free(xs);
//     // } else {
//     //     printf("No intersections found.\n");
//     // }

//     //test_8
//     // t_obj_file *obj = parse_obj_file("gibberish.obj");
//     // printf("Ignored lines: %d\n", obj->ignored_lines);
//     //test_9
//     // t_obj_file *obj = parse_obj_file("test1.obj");
//     // printf("Vertices: %d\n", obj->vertex_count);
//     // print_tuple(obj->vertices[0]);
//     // print_tuple(obj->vertices[1]);
//     // print_tuple(obj->vertices[2]);
//     // print_tuple(obj->vertices[3]);
//     // print_tuple(obj->vertices[4]);
//     // print_tuple(obj->vertices[5]);

//     //test_10
//     t_obj_file *obj = parse_obj_file("teapot.obj");
//     t_group *g = obj->default_group;
// 	t_shape *g = objgroups_to_group(g);
// 	int i = 0;
// 	while(g)
// 	{
// 		printf("group_name = %s\n", g->name);
// 		printf("group->children->count = %d\n", g->group->children_count);
// 		i = 0;
// 		while(i < g->group->children_count)
// 		{
// 			printf("Triangle\n");
// 			print_tuple(g->group->children->triangle->p1);
// 			print_tuple(g->group->children->triangle->p2);
// 			print_tuple(g->group->children->triangle->p3);
// 			g->group->children = g->group->children->next;
// 			i++;
// 		}
// 		g = g->next;
// 	}
// }
t_world *benchmark_1(void)
{
	t_world	*world;

	world = malloc(sizeof(t_world));
	world->shapes = NULL;
	world->light = NULL;
	t_light_p *l1 = new_light(new_point3(0, 2, -2), new_color3(1, 1, 1));
	t_shape  *s1 = sphere();
	s1->material.reflective = 0.9;
	s1->material.color = new_color3(1, 0, 0);
	add_shape(&world->shapes, s1);
	add_light(&world->light, l1);
	return (world);
}

t_world *benchmark_4(void)
{
	t_world	*world;

	world = malloc(sizeof(t_world));
	world->shapes = NULL;
	world->light = NULL;

	t_light_p *l1 = new_light(new_point3(-5, 10, -5), new_color3(1, 1, 1));
	world->light = l1;

	t_shape  *floor = plane();
	t_pattern *wood_floor = texture_map(uv_image(canvas_from_ppm("textures/planks.ppm")), planar_map);
	set_pattern_transform(wood_floor, scaling(10, 10, 10));
	floor->material.color = new_color3(1, 0.9, 0.9);
	floor->material.pattern = wood_floor;
	floor->material.bump_map = bump_map_from_ppm("textures/planks_bump.ppm", 10, planar_map);
	floor->material.specular = 0;
	floor->material.ambient = 0.5;

	t_shape *s = sphere();

	t_shape *hex = hexagon();
	set_transform(hex, multiply_matrices(translation(-0.5, 2, -0.5), scaling(2, 2, 2)));
	hex->material.color = new_color3(0.9, 0.5, 0.5);
	hex->material.diffuse = 0.4;
	hex->material.specular = 0.6;
	hex->material.shininess = 20;
	hex->material.reflective = 0.6;
	hex->material.ambient = 0;
	inherit_material(hex);
	t_shape *hex2 = hexagon();
	set_transform(hex2, multiply_matrices(translation(0.1, 2, 0.1), scaling(2, 2, 2)));
	hex2->material.color = new_color3(0.5, 0.9, 0.5);
	hex2->material.diffuse = 0.4;
	hex2->material.specular = 0.6;
	hex2->material.shininess = 20;
	hex2->material.reflective = 0.6;
	hex2->material.ambient = 0;
	inherit_material(hex2);
	add_shape(&floor, hex);
	add_shape(&floor, hex2);
	add_shape(&floor, s);
	world->shapes = floor;
	return (world);
}

t_world *triangle_scene(void)
{
		t_world	*world;

	world = malloc(sizeof(t_world));
	world->shapes = NULL;
	world->light = NULL;

	t_light_p *l1 = new_light(new_point3(-10, 20, -10), new_color3(1, 1, 1));
	world->light = l1;


	t_shape  *floor = plane();
    t_pattern *wood_floor = texture_map(uv_image(canvas_from_ppm("textures/planks.ppm")), planar_map);
    set_pattern_transform(wood_floor, scaling(10, 10, 10));
	floor->material.color = new_color3(1, 0.9, 0.9);
    floor->material.pattern = wood_floor;
    floor->material.bump_map = bump_map_from_ppm("textures/planks_bump.ppm", 10, planar_map);
	floor->material.specular = 0;
    floor->material.ambient = 0.5;

	t_obj_file *obj = parse_obj_file("teapot.obj");
    t_group *g = obj->default_group;
	// int i = 0;
	// while(g)
	// {
	// 	printf("group_name = %s\n", g->name);
	// 	printf("group->children->count = %d\n", g->group->children_count);
	// 	i = 0;
	// 	while(i < g->group->children_count)
	// 	{
	// 		printf("Triangle\n");
	// 		print_tuple(g->group->children->triangle->p1);
	// 		print_tuple(g->group->children->triangle->p2);
	// 		print_tuple(g->group->children->triangle->p3);
	// 		g->group->children = g->group->children->next;
	// 		i++;
	// 	}
	// 	g = g->next;
	// }
	t_shape *gr = objgroups_to_group(g);
	t_matrix *m = rotation_x(-(M_PI / 2));
	multiply_matrices(m, scaling(0.1, 0.1, 0.1));
	set_transform(gr, m);
	add_shape(&floor, gr);
	
	world->shapes = floor;
	return (world);
}

void my_keyhook(mlx_key_data_t keydata, void* param)
{
	t_loop	*loop;

	loop = (t_loop *)param;
	// If we PRESS the 'J' key, print "Hello".
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		loop->camera->transform.a[0][3] += 0.1;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		loop->camera->transform.a[0][3] -= 0.1;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		loop->camera->transform.a[2][3] -= 0.1;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		loop->camera->transform.a[2][3] += 0.1;
	if (keydata.key == MLX_KEY_1 && keydata.action == MLX_PRESS)
		quality(1, LOW);
	if (keydata.key == MLX_KEY_2 && keydata.action == MLX_PRESS)
		quality(1, MEDIUM);
	if (keydata.key == MLX_KEY_I && keydata.action == MLX_PRESS)
		downscale_setting(1, FULL);
	if (keydata.key == MLX_KEY_O && keydata.action == MLX_PRESS)
		downscale_setting(1, HALF);
	if (keydata.key == MLX_KEY_P && keydata.action == MLX_PRESS)
		downscale_setting(1, QUARTER);
	if (keydata.key == MLX_KEY_L && keydata.action == MLX_PRESS)
		downscale_setting(1, EIGHTH);
	if (keydata.key == MLX_KEY_K && keydata.action == MLX_PRESS)
		downscale_setting(1, SIXTEENTH);
	if (keydata.key == MLX_KEY_V && keydata.action == MLX_PRESS)
		supersampling_setting(1, SS_OFF);
	if (keydata.key == MLX_KEY_B && keydata.action == MLX_PRESS)
		supersampling_setting(1, SS_2X);
	if (keydata.key == MLX_KEY_N && keydata.action == MLX_PRESS)
		supersampling_setting(1, SS_4X);
	if (keydata.key == MLX_KEY_M && keydata.action == MLX_PRESS)
		supersampling_setting(1, SS_8X);
	if (keydata.key == MLX_KEY_COMMA && keydata.action == MLX_PRESS)
		supersampling_setting(1, SS_16X);
	
}

int	main(void)
{
	t_loop	*loop;

	// downscale_setting(1, SIXTEENTH);
	loop = loop_init();
	mlx_key_hook(loop->mlx, &my_keyhook, loop);
	mlx_loop_hook(loop->mlx, render_loop, loop);
	mlx_loop(loop->mlx);
	return (0);
}


// int main (void)
// {
// 	t_shape *shape = sphere();
// 	t_matrix *m = init_identity_matrix(4);
	
// 	m = multiply_matrices(m, translation(2, 3, 4));
// 	m = multiply_matrices(m, scaling(2, 2, 2));
// 	set_transform(shape, m);
// 	print_matrix(shape->transform);
// }
