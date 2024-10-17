/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:54:43 by mdomnik           #+#    #+#             */
/*   Updated: 2024/10/17 17:46:52 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

// int main(int argc, char **argv)
// {
// 	t_project project;
// 	if (check_args(argc, argv, &project) != 0)
// 		printf("failed\n");
	
// 	int i = 0;
// 	while(project.objects[i].type != NONE)
// 	{
// 		printf("project->objects->type: %d\n", project.objects[i].type);
// 		i++;
// 	}
// 	// t_ray		*ray = ray_new(new_point3_p(0, 1, 0), new_vec3_p(0, 0, 1));
// 	// t_sphere	*sphere = sphere_new();
// 	// t_x xs = intersect_sphere(ray, sphere);
// 	// printf("xs.t1: %f\n", xs.t[0]);
// 	// printf("xs.t2: %f\n", xs.t[1]);
// 	return(0);
// }

// int main(void)
// {
	// t_object	object;
	// object.object = sphere_new();
	// object.type = SPHERE;
	// t_i i1 = intersection(1, &object);
	// t_i i2 = intersection(2, &object);
	// t_i i3 = intersection(3, &object);
	// t_i i4 = intersection(4, &object);
	// t_x xs = intersections(4, i1, i2, i3, i4);
	// printf("xs.count: %d\n", xs.count);
	// printf("xs.t1: %f\n", xs.t[0]);
	// printf("xs.t2: %f\n", xs.t[1]);
	// printf("xs.t3: %f\n", xs.t[2]);
	// printf("xs.t4: %f\n", xs.t[3]);
	
	// t_i i;
	// i = intersection(3.5, &object);
	// t_ray *ray = ray_new(new_point3_p(0, 0, -5), new_vec3_p(0, 0, 1));
	// t_object	o;
	// o.object = sphere_new();
	// o.type = SPHERE;
	// t_i i1 = intersection(5, &o);
	// t_i i2 = intersection(7, &o);
	// t_i i3 = intersection(-3, &o);
	// t_i i4 = intersection(2, &o);
	// t_x *xs = intersections(4, i1, i2, i3, i4);
	// t_i h = hit(xs);
	// printf("h.t: %f\n", h.t);
	// printf("h.object: %p\n", (void *)h.object);

	// t_ray *r = ray_new(new_point3_p(1, 2, 3), new_vec3_p(0, 1, 0));
	// t_matrix m = scaling(2, 3, 4);
	// t_ray *r2 = ray_transform(r, &m);
	// print_tuple(r2->orig);
	// print_tuple(r2->dir);

	// print_matrix(s->transform);
	// t_matrix *m = translation(2, 3, 4);
	// set_transform(&s->transform, m);
	// print_matrix(s->transform);

	// t_ray *r = ray_new(new_point3_p(0, 0, -5), new_vec3_p(0, 0, 1));
	
	// t_object	o;
	// o.object = sphere_new();
	// o.type = SPHERE;

	// t_sphere *s = (t_sphere *)o.object;
	// set_transform(&s->transform, translation(5, 0, 0));
	// print_matrix(s->transform);
	// t_x *xs = intersect(&o, r);
	// printf("xs->count: %d\n", xs->count);
	// printf("xs->i[0].t: %f\n", xs->i[0].t);
	// printf("xs->i[1].t: %f\n", xs->i[1].t);
// }
int main(void)
{
	mlx_t *mlx = mlx_init(500, 500, "test", 1);
	mlx_image_t *image = mlx_new_image(mlx, 500, 500);

	t_point3	origin = new_point3(0, 0, -5);
	float wall_z = 10;
	float wall_size = 7;
	int canvas_width = (int)image->width;
	int canvas_height = (int)image->height;
	float pixel_size = wall_size / canvas_width;
	float half = wall_size / 2;
	t_object	o;
	o.object = sphere_new();
	o.type = SPHERE;
	t_sphere *s = (t_sphere *)o.object;
	set_transform(&s->transform, multiply_matrices(translation(0, 0, 5), scaling(1, 0.5, 1)));
	// set_transform(&s->transform, scaling(0.5, 1, 1));
	// set_transform(&s->transform, (multiply_matrices(rotation_z(M_PI / 4), scaling(0.5, 1, 1))));
	// set_transform(&s->transform, (multiply_matrices(shearing_x(1, 0), scaling(0.5, 1, 1))));
	for (int y = 0; y < canvas_height; y++)
	{
		float world_y = half - pixel_size * y;
		for (int x = 0; x < canvas_width; x++)
		{
			float world_x = -half + pixel_size * x;
			t_point3 position = new_point3(world_x, world_y, wall_z);
			t_vec3 direction = normalize(sub_tuple(position, origin));
			t_ray *ray = ray_new(&origin, &direction);
			t_x *xs = intersect(&o, ray);
			t_i h = hit(xs);
			if (h.object != NULL)
				mlx_put_pixel(image, x, y, 0xFF0000FF);
			else
				mlx_put_pixel(image, x, y, 0x000000FF);
		}
	}
	mlx_image_to_window(mlx, image, 0, 0);
	mlx_loop(mlx);
	return(0);
}



