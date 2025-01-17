/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:54:43 by mdomnik           #+#    #+#             */
/*   Updated: 2025/01/17 23:42:24 by mdomnik          ###   ########.fr       */
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

int	main(void)
{
	mlx_t		*mlx;
	t_world		*world;
	t_camera	*camera;
	mlx_image_t	*image;

	mlx = mlx_init(800, 400, "test", 1);
	world = default_world();
	camera = camera_new(800, 400, 0.8);
	camera->transform = view_transformation(new_point3(0, 0, 0),
			new_point3(0, 2, 0), new_vec3(0, 1, 0));
	image = render(mlx, camera, world);
	mlx_image_to_window(mlx, image, 0, 0);
	printf("done\n");
	mlx_loop(mlx);
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
