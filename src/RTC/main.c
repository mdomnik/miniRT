/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:54:43 by mdomnik           #+#    #+#             */
/*   Updated: 2024/11/19 20:20:39 by mdomnik          ###   ########.fr       */
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
	// t_toremove	object;
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
	// t_toremove	o;
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
	
	// t_toremove	o;
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




// int main(void)
// {
// 	// t_toremove	o;
// 	// o.object = sphere_new();
// 	// o.type = SPHERE;
// 	// t_sphere *s = (t_sphere *)o.object;
// 	// t_matrix *m = translation(0, 1, 0);
// 	// set_transform(&s->transform, m);
// 	// print_matrix(s->transform);
// 	// t_sphere *s2 = (t_sphere *)o.object;
// 	// printf("-----------------\n");
// 	// print_matrix(s2->transform);
// 	// t_vec3 n = normal_at(&o, new_point3(0, 1.70711, -0.70711));
// 	// print_tuple(n);

// 	t_toremove	o;
// 	o.object = sphere_new();
// 	o.type = SPHERE;
// 	t_sphere *s = (t_sphere *)o.object;
// 	t_matrix *m = multiply_matrices(scaling(1, 0.5, 1), rotation_z(M_PI / 5));
// 	set_transform(&s->transform, m);
// 	t_vec3 n = normal_at(&o, new_point3(0, sqrt(2) / 2, -sqrt(2) / 2));
// 	print_tuple(n);

// }



// CHAPTER 6
// int main(void)
// {
// 	// t_vec3 v = new_vec3(0, -1, 0);
// 	// t_vec3 n = new_vec3(sqrt(2) / 2, sqrt(2) / 2, 0);
// 	// t_vec3 r = reflect(v, n);
// 	// print_tuple(r);

// 	// t_point3 p = new_point3(0, 0, 0);
// 	// t_color3 c = new_color3(1, 1, 1);

// 	// t_light_p *light = new_light(&p, &c);
// 	// print_tuple(*light->position);
// 	// print_tuple(*light->intensity);

// 	// t_sphere *s = sphere_new();
// 	// t_material *m = default_material();
// 	// m->ambient = 1;
// 	// s->material = m;
// 	// print_tuple(s->material->color);
// 	// printf("ambient: %f\n", s->material->ambient);
// 	// printf("diffuse: %f\n", s->material->diffuse);
// 	// printf("specular: %f\n", s->material->specular);
// 	// printf("shininess: %f\n", s->material->shininess);
	
// 	t_material *m = default_material();
// 	t_point3 *position = new_point3_p(0, 0, 0);

// 	// t_vec3 eyev = new_vec3(0, 0, -1);
// 	// t_vec3 normalv = new_vec3(0, 0, -1);
// 	// t_light_p *light = new_light(new_point3_p(0, 0, -10), new_color3_p(1, 1, 1));
// 	// t_color3 result = lighting(m, light, position, eyev, normalv);
// 	// print_tuple(result);


// 	// t_vec3 eyev = new_vec3(0, sqrt(2) / 2, -(sqrt(2) / 2));
// 	// t_vec3 normalv = new_vec3(0, 0, -1);
// 	// t_light_p *light = new_light(new_point3_p(0, 0, -10), new_color3_p(1, 1, 1));
// 	// t_color3 result = lighting(m, light, position, eyev, normalv);
// 	// print_tuple(result);

// 	// t_vec3 eyev = new_vec3(0, 0, -1);
// 	// t_vec3 normalv = new_vec3(0, 0, -1);
// 	// t_light_p *light = new_light(new_point3_p(0, 10, -10), new_color3_p(1, 1, 1));
// 	// t_color3 result = lighting(m, light, position, eyev, normalv);
// 	// print_tuple(result);

// 	// t_vec3 eyev = new_vec3(0, -sqrt(2) / 2, -(sqrt(2) / 2));
// 	// t_vec3 normalv = new_vec3(0, 0, -1);
// 	// t_light_p *light = new_light(new_point3_p(0, 10, -10), new_color3_p(1, 1, 1));
// 	// t_color3 result = lighting(m, light, position, eyev, normalv);
// 	// print_tuple(result);

// 	// t_vec3 eyev = new_vec3(0, 0, -1);
// 	// t_vec3 normalv = new_vec3(0, 0, -1);
// 	// t_light_p *light = new_light(new_point3_p(0, 0, 10), new_color3_p(1, 1, 1));
// 	// t_color3 result = lighting(m, light, position, eyev, normalv);
// 	// print_tuple(result);
// }











// // //WORKING SPHERE LIGHTING
// int main(void)
// {
// 	mlx_t *mlx = mlx_init(500, 500, "test", 1);
// 	mlx_image_t *image = mlx_new_image(mlx, 500, 500);

// 	t_point3	origin = new_point3(0, 0, 0);
// 	float wall_z = 10;
// 	float wall_size = 7;
// 	int canvas_width = (int)image->width;
// 	int canvas_height = (int)image->height;
// 	float pixel_size = wall_size / canvas_width;
// 	float half = wall_size / 2;
// 	t_world	*world = default_world();
// 	for (int y = 0; y < canvas_height; y++)
// 	{
// 		float world_y = half - pixel_size * y;
// 		for (int x = 0; x < canvas_width; x++)
// 		{
// 			float world_x = -half + pixel_size * x;
// 			t_point3 position = new_point3(world_x, world_y, wall_z);
// 			t_vec3 direction = normalize(sub_tuple(position, origin));
// 			t_ray *ray = ray_new(&origin, &direction);
// 			t_color3 color = color_at(world, ray);
// 			int color_int = color_to_int(color);
// 			mlx_put_pixel(image, x, y, color_int);
// 		}
// 	}
// 	printf("done\n");
// 	mlx_image_to_window(mlx, image, 0, 0);
// 	mlx_loop(mlx);
// 	return(0);
// }

// int main(void)
// {
// 	t_light_p *light = new_light(new_point3_p(-10, 10, -10), new_color3_p(1, 1, 1));	
// 	t_sphere  *s1 = sphere_new();
// 	s1->material->color = new_color3_p(0.8, 1.0, 0.6);
// 	s1->material->diffuse = 0.7;
// 	s1->material->specular = 0.2;
// 	t_sphere  *s2 = sphere_new();
// 	set_transform(&s2->transform, scaling(0.5, 0.5, 0.5));
// 	t_toremove  *o1 = object_new(s1, SPHERE);
// 	t_toremove  *o2 = object_new(s2, SPHERE);
// 	add_object(&o1, o2);
// 	t_world	*world = create_world(o1, light);
// 	// if (world->light == NULL)
// 	// 	printf("light is NULL\n");
// 	// else
// 	// {
// 	// 	printf("light is not NULL\n");
// 	// 	printf("light->position: %f, %f, %f\n", world->light->position->x, world->light->position->y, world->light->position->z);
// 	// 	printf("light->intensity: %f, %f, %f\n", world->light->intensity->x, world->light->intensity->y, world->light->intensity->z);
// 	// }
// 	// if (world->objects == NULL)
// 	// 	printf("objects is NULL\n");
// 	// else
// 	// 	{
// 	// 		while (world->objects != NULL)
// 	// 		{
// 	// 			printf("object->type: %d\n", world->objects->type);
// 	// 			if (world->objects->type == SPHERE)
// 	// 			{
// 	// 				t_sphere *s = (t_sphere *)world->objects->object;
// 	// 				print_matrix(s->transform);
// 	// 				print_tuple(*s->material->color);
// 	// 				printf("diffuse: %f\n", s->material->diffuse);
// 	// 				printf("specular: %f\n", s->material->specular);
// 	// 				printf("-----------------\n");
// 	// 			}
// 	// 			world->objects = world->objects->next;
// 	// 		}
// 	// 	}
// 	t_ray *r = ray_new(new_point3_p(0, 0, -5), new_vec3_p(0, 0, 1));
// 	t_x *xs = intersect_world(world, r);
// 	int i = 0;
// 	printf("xs_count: %d\n", xs->count);
// 	while (i < xs->count)
// 	{
// 		printf("xs->i[%d].t: %f\n", i, xs->i[i].t);
// 		i++;
// 	}
// }

// int main(void)
// {
// 	//p.94
// 	// t_ray *r = ray_new(new_point3_p(0, 0, 0), new_vec3_p(0, 0, 1));
// 	// t_sphere *s = sphere_new();
// 	// t_toremove	*o;
// 	// o = object_new(s, SPHERE);
// 	// t_i i = intersection(1, o);
// 	// printf("sphere: %p\n", (void *)o);
// 	// t_comp *comps = prepare_computations(&i, r);
// 	// printf("comps->t: %f\n", comps->t);
// 	// printf("comps->object: %p\n", (void *)comps->object);
// 	// print_tuple(comps->point);
// 	// print_tuple(comps->eyev);
// 	// print_tuple(comps->normalv);
// 	// printf("comps->inside: %d\n", comps->inside);

// 	//p.95

// 	// t_world	*world = default_world();
// 	// t_ray *r = ray_new(new_point3_p(0, 0, -5), new_vec3_p(0, 0, 1));
// 	// t_toremove	*shape = world->objects;
// 	// t_i i = intersection(4, shape);
// 	// t_comp *comps = prepare_computations(&i, r);
// 	// t_color3 c = shade_hit(world, comps);
// 	// print_tuple(c);

// 	// t_world	*world = default_world();
// 	// world->light = new_light(new_point3_p(0, 0.25, 0), new_color3_p(1, 1, 1));
// 	// t_ray *r = ray_new(new_point3_p(0, 0, 0), new_vec3_p(0, 0, 1));
// 	// world->objects = world->objects->next;
// 	// t_toremove	*shape = world->objects;
// 	// t_i i = intersection(0.5, shape);
// 	// t_comp *comps = prepare_computations(&i, r);
// 	// t_color3 c = shade_hit(world, comps);
// 	// print_tuple(c);
	
// 	//MULTIPLE LIGHTS
// 	// t_world *world = default_world();
// 	// t_ray *r = ray_new(new_point3_p(0, 0, -5), new_vec3_p(0, 0, 1));
// 	// t_color3 c = color_at(world, r);
// 	// print_tuple(c);

// 	t_world	*world = default_world();
// 	t_ray *r = ray_new(new_point3_p(0, 0, 0.75), new_vec3_p(0, 0, -1));
// 	t_color3 c = color_at(world, r);
// 	print_tuple(c);
// }

// // // //WORKING SPHERE LIGHTING
// int main(void)
// {
// 	mlx_t *mlx = mlx_init(500, 500, "test", 1);
// 	mlx_image_t *image = mlx_new_image(mlx, 500, 500);

// 	t_point3	origin = new_point3(0, 0, 0);
// 	float wall_z = 10;
// 	float wall_size = 7;
// 	int canvas_width = (int)image->width;
// 	int canvas_height = (int)image->height;
// 	float pixel_size = wall_size / canvas_width;
// 	float half = wall_size / 2;
// 	t_world	*world = default_world();
// 	for (int y = 0; y < canvas_height; y++)
// 	{
// 		float world_y = half - pixel_size * y;
// 		for (int x = 0; x < canvas_width; x++)
// 		{
// 			float world_x = -half + pixel_size * x;
// 			t_point3 position = new_point3(world_x, world_y, wall_z);
// 			t_vec3 direction = normalize(sub_tuple(position, origin));
// 			t_ray *ray = ray_new(&origin, &direction);
// 			t_color3 color = color_at(world, ray);
// 			int color_int = color_to_int(color);
// 			mlx_put_pixel(image, x, y, color_int);
// 		}
// 	}
// 	printf("done\n");
// 	mlx_image_to_window(mlx, image, 0, 0);
// 	mlx_loop(mlx);
// 	return(0);
// }


// int main (void)
// {
// 	t_point3 from = new_point3(1, 3, 2);
// 	t_point3 to = new_vec3(4, -2, 8);
// 	t_vec3 up = new_vec3(1, 1, 0);
// 	t_matrix t = view_transformation(from, to, up);
// 	print_matrix(t);
// }

//CAMERA TEST
int main (void)
{
	mlx_t *mlx = mlx_init(800, 400, "test", 1);
	t_world	*world = test_world();
	t_camera *camera = camera_new(800, 400, M_PI / 3);
	camera->transform = view_transformation(new_point3(0, 1.5, -5), new_point3(0, 1, 0), new_vec3(0, 1, 0));
	mlx_image_t *image = render(mlx, camera, world);
	mlx_image_to_window(mlx, image, 0, 0);
	printf("done\n");
	mlx_loop(mlx);
	return(0);
}

// // CHAPTER 9
// int main (void)
// {
// 	// t_vec3 eyev = new_vec3(0, 0, -1);
// 	// t_vec3 normalv = new_vec3(0, 0, -1);
// 	// t_light_p *light = new_light(new_point3_p(0, 0, -10), new_color3_p(1, 1, 1));
// 	// bool in_shadow = false;
// 	// t_color3 result = lighting(default_material(), light, new_point3_p(0, 0, 0), eyev, normalv, in_shadow);
// 	// print_tuple(result);

// 	// t_world *world = default_world();
// 	// t_point3 *point = new_point3_p(-20, 20, -20);
// 	// bool shadowed = is_shadowed(world, point);
// 	// printf("shadowed: %d\n", shadowed);

// 	// t_world *world = default_world();
// 	// t_point3 *point = new_point3_p(-2, 2, -2);
// 	// bool shadowed = is_shadowed(world, point);
// 	// printf("shadowed: %d\n", shadowed);

// 	// t_world *world = default_world();
// 	// t_ray *r = ray_new(new_point3_p(0, 0, 5), new_vec3_p(0, 0, 1));
// 	// t_i i = intersection(4, world->objects->next);
// 	// t_comp *comps = prepare_computations(&i, r);
	// t_color3 c = shade_hit(world, comps);
// 	// print_tuple(c);
	
// 	// t_ray *r = ray_new(new_point3_p(0, 0, -5), new_vec3_p(0, 0, 1));
// 	// t_sphere *s = sphere_new();
// 	// set_transform(&s->transform, translation(0, 0, 1));
// 	// t_i i = intersection(5, s);
// 	// t_comp *comps = prepare_computations(&i, r);
// 	// printf("comps->over_point.z: %f\n", comps->over_point.z);
// 	// printf("comps->point.z: %f\n", comps->point.z);
	
// }

