/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:54:43 by mdomnik           #+#    #+#             */
/*   Updated: 2025/01/15 23:58:47 by mdomnik          ###   ########.fr       */
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

// int main(void)
// {
// 	// t_shape *s = test_shape();
// 	// set_transform(&s->transform, translation(2, 3, 4));
// 	// t_material *m = default_material();
// 	// m->ambient = 1;
// 	// s->material = *m;
// 	// printf("ambient: %f\n", s->material.ambient);
	
// 	// t_ray *r = ray_new(new_point3_p(0, 0, -5), new_vec3_p(0, 0, 1));
// 	// t_shape *s = test_shape();
// 	// set_transform(s, scaling(2, 2, 2));
// 	// t_x *xs = intersect(s, r);
// 	// print_tuple(s->saved_ray->orig);
// 	// print_tuple(s->saved_ray->dir);
// 	// printf("xs->count: %d\n", xs->count);

// 	// t_ray *r = ray_new(new_point3_p(0, 0, -5), new_vec3_p(0, 0, 1));
// 	// t_shape *s = test_shape();
// 	// set_transform(s, translation(5, 0, 0));
// 	// t_x *xs = intersect(s, r);
// 	// printf("xs->count: %d\n", xs->count);
// 	// print_tuple(s->saved_ray->orig);
// 	// print_tuple(s->saved_ray->dir);

// 	// t_shape *s = test_shape();
// 	// set_transform(s, translation(0, 1, 0));
// 	// t_vec3 n = normal_at(s, new_point3(0, 1.70711, -0.70711));
// 	// print_tuple(n);

// 	t_shape *s = test_shape();
// 	t_matrix *m = multiply_matrices(scaling(1, 0.5, 1), rotation_z(M_PI / 5));
// 	set_transform(s, m);
// 	t_vec3 n = normal_at(s, new_point3(0, sqrt(2) / 2, -sqrt(2) / 2));
// 	print_tuple(n);
// }


// void print_xs_intersections(t_x *xs)
// {
// 	int i = 0;
// 	if (xs == NULL)
// 	{
// 		printf("xs is NULL\n");
// 		return ;
// 	}
// 	if (xs->count == 0)
// 		printf("intersection count: 0\n");
// 	printf("xs->count: %d\n", xs->count);
// 	while (i < xs->count)
// 	{
// 		printf("xs->i[%d].t: %f\n", i, xs->i[i].t);
// 		printf("xs->i[%d].shape: %d\n", i, xs->i[i].shape->type);
// 		i++;
// 	}
// }

// int main (void)
// {
// 	t_shape *p = plane_new();
// 	t_ray *r = ray_new(new_point3_p(0, 10, 0), new_vec3_p(0, 0, 1));
// 	t_x *xs = intersect(p, r);
// 	print_xs_intersections(xs);
// }	


// patterns
// int main(void)
// {
// 	t_color3 *black = new_color3_p(0, 0, 0);
// 	t_color3 *white = new_color3_p(1, 1, 1);
// 	t_pattern p = stripe_pattern(black, white);
// 	t_color3 c1 = stripe_at(&p, new_point3_p(0, 0, 0));
// 	print_tuple(c1);
// 	t_color3 c2 = stripe_at(&p, new_point3_p(0.9, 0, 0));
// 	print_tuple(c2);
// 	t_color3 c3 = stripe_at(&p, new_point3_p(1, 0, 0));
// 	print_tuple(c3);
// 	t_color3 c4 = stripe_at(&p, new_point3_p(-0.1, 0, 0));
// 	print_tuple(c4);
// 	t_color3 c5 = stripe_at(&p, new_point3_p(-1, 0, 0));
// 	print_tuple(c5);
// 	t_color3 c6 = stripe_at(&p, new_point3_p(-1.1, 0, 0));
// 	print_tuple(c6);
// }

// int main (void)
// {
// 	t_material *m = default_material();
// 	m->pattern = stripe_pattern(new_color3_p(1, 1, 1), new_color3_p(0, 0, 0));
// 	m->ambient = 1;
// 	m->diffuse = 0;
// 	m->specular = 0;
// 	// m.shininess = 0;
// 	t_vec3 eyev = new_vec3(0, 0, -1);
// 	t_vec3 normalv = new_vec3(0, 0, -1);
// 	t_light_p light = *new_light(new_point3_p(0, 0, -10), new_color3_p(1, 1, 1));
// 	t_color3 c1 = lighting(m, &light, new_point3_p(0.9, 0, 0), eyev, normalv, false);
// 	print_tuple(c1);
// 	t_color3 c2 = lighting(m, &light, new_point3_p(1.1, 0, 0), eyev, normalv, false);
// 	print_tuple(c2);
// }

// int main (void)
// {
// 	t_shape *s = sphere_new();
// 	set_transform(s, scaling(2, 2, 2));
// 	t_pattern *p = stripe_pattern(new_color3_p(1, 1, 1), new_color3_p(0, 0, 0));
// 	set_pattern_transform(p, scaling(2, 2, 2));
// 	t_color3 *c = stripe_at_object(p, s, new_point3_p(1.5, 0, 0));
// 	print_tuple(*c);
// }

// int main (void)
// {
// 	t_pattern *p = new_pattern(GRADIENT, new_color3_p(1, 1, 1), new_color3_p(0, 0, 0));
// 	t_color3 *c1 = pattern_at(p, new_point3_p(0, 0, 0));
// 	print_tuple(*c1);
// 	t_color3 *c2 = pattern_at(p, new_point3_p(0.25, 0, 0));
// 	print_tuple(*c2);
// 	t_color3 *c3 = pattern_at(p, new_point3_p(0.5, 0, 0));
// 	print_tuple(*c3);
// 	t_color3 *c4 = pattern_at(p, new_point3_p(0.75, 0, 0));
// 	print_tuple(*c4);
// }




// int main (void)
// {
// 	t_pattern *p = new_pattern(CHECKERS, new_color3_p(1, 1, 1), new_color3_p(0, 0, 0));
// 	t_color3 *c1 = pattern_at(p, new_point3_p(0, 0, 0));
// 	print_tuple(*c1);
// 	t_color3 *c2 = pattern_at(p, new_point3_p(0.99, 0, 0));
// 	print_tuple(*c2);
// 	t_color3 *c3 = pattern_at(p, new_point3_p(1.01, 0, 0));
// 	print_tuple(*c3);
// 	printf("------------\n");
// 	t_color3 *c4 = pattern_at(p, new_point3_p(0, 0, 0));
// 	print_tuple(*c4);
// 	t_color3 *c5 = pattern_at(p, new_point3_p(0, 0.99, 0));
// 	print_tuple(*c5);
// 	t_color3 *c6 = pattern_at(p, new_point3_p(0, 1.01, 0));
// 	print_tuple(*c6);
// 	printf("------------\n");
// 	t_color3 *c7 = pattern_at(p, new_point3_p(0, 0, 0));
// 	print_tuple(*c7);
// 	t_color3 *c8 = pattern_at(p, new_point3_p(0, 0, 0.99));
// 	print_tuple(*c8);
// 	t_color3 *c9 = pattern_at(p, new_point3_p(0, 0, 1.01));
// 	print_tuple(*c9);
// }



// //print_world_shapes
// void print_world_shapes(t_world *world)
// {
// 	while (world->shapes)
// 	{
// 		printf("shape->type: %d\n", world->shapes->type);
// 		printf("shape->material.reflective: %f\n", world->shapes->material.reflective);
// 		world->shapes = world->shapes->next;
// 	}
// 	printf("end\n");
// }


// int main (void)
// {
	// t_material *m = default_material();
	// printf("reflective: %f\n", m->reflective);

	// t_shape *shape = plane_new();
	// t_ray *r = ray_new(new_point3_p(0, 1, -1), new_vec3_p(0, -sqrt(2) / 2, sqrt(2) / 2));
	// t_i i = intersection(sqrt(2), shape);
	// t_comp *comps = prepare_computations(&i, r);
	// print_tuple(comps->reflectv);

	// t_world *world = default_world();
	// t_ray *r = ray_new(new_point3_p(0, 0, 0), new_vec3_p(0, 0, 1));
	// t_shape *shape = world->shapes->next;
	// shape->material.ambient = 1;
	// t_i i = intersection(1, shape);
	// t_comp *comps = prepare_computations(&i, r);
	// t_color3 c = reflected_color(world, comps);
	// print_tuple(c);
	
	// t_world *world = default_world();
	// t_shape *shape = plane_new();
	// shape->material.reflective = 0.5;
	// set_transform(shape, translation(0, -1, 0));
	// add_shape(&world->shapes, shape);
	// // print_world_shapes(world);
	// t_ray *r = ray_new(new_point3_p(0, 0, -3), new_vec3_p(0, -sqrt(2) / 2, sqrt(2) / 2));
	// t_i i = intersection(sqrt(2), shape);
	// t_comp *comps = prepare_computations(&i, r);
	// t_color3 c = reflected_color(world, comps, 0);
	// print_tuple(c);

// 	t_world *world;
// 	world = malloc(sizeof(t_world));
// 	world->light = new_light(new_point3_p(0, 0, 0), new_color3_p(1, 1, 1));
// 	t_shape *lower = plane_new();
// 	lower->material.reflective = 1;
// 	set_transform(lower, translation(0, -1, 0));
// 	t_shape *upper = plane_new();
// 	upper->material.reflective = 1;
// 	set_transform(upper, translation(0, 1, 0));
// 	add_shape(&lower, upper);
// 	world->shapes = lower;
// 	t_ray *r = ray_new(new_point3_p(0, 0, 0), new_vec3_p(0, 1, 0));
// 	t_color3 c = color_at(world, r, 1);
// 	print_tuple(c);
	
// }


// void print_intersections(t_x *xs)
// {
// 	int i = 0;
// 	if (xs == NULL)
// 	{
// 		printf("xs is NULL\n");
// 		return ;
// 	}
// 	if (xs->count == 0)
// 		printf("intersection count: 0\n");
// 	printf("xs->count: %d\n", xs->count);
// 	while (i < xs->count)
// 	{
// 		printf("xs->i[%d].t: %f\n", i, xs->i[i].t);
// 		printf("xs->i[%d].shape->type: %d\n", i, xs->i[i].shape->type);
// 		i++;
// 	}
// }

// int main (void)
// {
// 	// t_material *m = default_material();
// 	// printf("transparency: %f\n", m->transparency);
// 	// printf("refractive_index: %f\n", m->refractive_index);
// 	// t_shape *s = glass_sphere();
// 	// print_matrix(s->transform);
// 	// printf("transparency %f\n", s->material.transparency);
// 	// printf("refractive_index %f\n", s->material.refractive_index);

// 	//finding n1 and n2 at various intersections
// 	// t_shape *a = glass_sphere();
// 	// set_transform(a, scaling(2, 2, 2));
// 	// a->material.refractive_index = 1.5;
// 	// t_shape *b = glass_sphere();
// 	// set_transform(b, translation(0, 0, -0.25));
// 	// b->material.refractive_index = 2.0;
	// t_shape *c = glass_sphere();
// 	// set_transform(c, translation(0, 0, 0.25));
// 	// c->material.refractive_index = 2.5;
// 	// t_ray *r = ray_new(new_point3_p(0, 0, -4), new_vec3_p(0, 0, 1));
// 	// t_i i1 = intersection(2, a);
// 	// t_i i2 = intersection(2.75, b);
// 	// t_i i3 = intersection(3.25, c);
// 	// t_i i4 = intersection(4.75, b);
// 	// t_i i5 = intersection(5.25, c);
// 	// t_i i6 = intersection(6, a);
// 	// t_x *xs = malloc(sizeof(t_x));
// 	// xs->count = 6;
// 	// xs->i = malloc(sizeof(t_i) * 6);
// 	// xs->i[0] = i1;
// 	// xs->i[1] = i2;
// 	// xs->i[2] = i3;
// 	// xs->i[3] = i4;
// 	// xs->i[4] = i5;
// 	// xs->i[5] = i6;
// 	// print_intersections(xs);
// 	// printf("xs_i[0].shape->next address: %p\n", (void *)xs->i[0].shape->next);
// 	// printf("xs_i[1].shape->next address: %p\n", (void *)xs->i[1].shape->next);
// 	// printf("xs_i[2].shape->next address: %p\n", (void *)xs->i[2].shape->next);
// 	// printf("xs_i[3].shape->next address: %p\n", (void *)xs->i[3].shape->next);
// 	// printf("xs_i[4].shape->next address: %p\n", (void *)xs->i[4].shape->next);
// 	// printf("xs_i[5].shape->next address: %p\n", (void *)xs->i[5].shape->next);
// 	// t_comp *comps1 = prepare_computations(&xs->i[0], r, xs);
// 	// printf("index[0] | n1:%f, n2:%f\n", comps1->n1, comps1->n2);
// 	// printf("-----------------\n");
// 	// t_comp *comps2 = prepare_computations(&xs->i[1], r, xs);
// 	// printf("index[1] | n1:%f, n2:%f\n", comps2->n1, comps2->n2);
// 	// printf("-----------------\n");
// 	// t_comp *comps3 = prepare_computations(&xs->i[2], r, xs);
// 	// printf("index[2] | n1:%f, n2:%f\n", comps3->n1, comps3->n2);
// 	// printf("-----------------\n");
// 	// t_comp *comps4 = prepare_computations(&xs->i[3], r, xs);
// 	// printf("index[3] | n1:%f, n2:%f\n", comps4->n1, comps4->n2);
// 	// printf("-----------------\n");
// 	// t_comp *comps5 = prepare_computations(&xs->i[4], r, xs);
// 	// printf("index[4] | n1:%f, n2:%f\n", comps5->n1, comps5->n2);
// 	// printf("-----------------\n");
// 	// t_comp *comps6 = prepare_computations(&xs->i[5], r, xs);
// 	// printf("index[5] | n1:%f, n2:%f\n", comps6->n1, comps6->n2);
// 	// printf("-----------------\n");
// 	// (void)comps1;
// 	// (void)comps2;
// 	// (void)comps3;
// 	// (void)comps4;
// 	// (void)comps5;
// 	// (void)comps6; //POTENTIAL ERROR
	
	
// }

// t_x *create_intersections(int count, ...)
// {
//     t_x *xs = malloc(sizeof(t_x));
//     xs->count = count;
//     xs->i = malloc(sizeof(t_i) * count);
//     va_list args;
//     va_start(args, count);
//     for (int i = 0; i < count; i++)
//         xs->i[i] = va_arg(args, t_i);
//     va_end(args);
//     return xs;
// }

// void print_comps_data(t_comp *comps)
// {
// 	print_tuple(comps->eyev);
// 	print_tuple(comps->normalv);
// 	print_tuple(comps->reflectv);
// 	printf("comps->inside: %d\n", comps->inside);	
// 	printf("comps->n1: %f\n", comps->n1);
// 	printf("comps->n2: %f\n", comps->n2);
// 	printf("comps->under_point.z: %f\n", comps->under_point.z);
// 	printf("comps->point.z: %f\n", comps->point.z);
	
// }

// int main (void)
// {
	// t_ray *r = ray_new(new_point3_p(0, 0, -5), new_vec3_p(0, 0, 1));
	// t_shape *shape = glass_sphere();
	// set_transform(shape, translation(0, 0, 1));
	// t_i i = intersection(5, shape);
	// t_x *xs = malloc(sizeof(t_x));
	// xs->count = 1;
	// xs->i = malloc(sizeof(t_i) * 1);
	// xs->i[0] = i;
	// t_comp *comps = prepare_computations(&xs->i[0], r, xs);
	// if (comps->under_point.z > EPSILON / 2)
	// 	printf("SUCCESS: comps->under_point.z: %f\n", comps->under_point.z);
	// else
	// 	printf("FAIL:   comps->under_point.z: %f\n", comps->under_point.z);
	// if (comps->point.z < comps->under_point.z)
	// 	printf("SUCCESS: comps->point.z: %f\n", comps->point.z);
	// else
	// 	printf("FAIL:   comps->point.z: %f\n", comps->point.z);

	// t_world *world = default_world();
	// t_shape *shape = world->shapes;
	// shape->material.transparency = 1.0;
	// shape->material.refractive_index = 1.5;
	// t_ray *r = ray_new(new_point3_p(0, 0, sqrt(2) / 2), new_vec3_p(0, 1, 0));
	// t_i i1 = intersection(-sqrt(2) / 2, shape);
	// t_i i2 = intersection(sqrt(2) / 2, shape);
	// t_x *xs = malloc(sizeof(t_x));
	// xs->count = 2;
	// xs->i = malloc(sizeof(t_i) * 2);
	// xs->i[0] = i1;
	// xs->i[1] = i2;
	// t_comp *comps = prepare_computations(&xs->i[1], r, xs);
	// t_color3 c = refracted_color(world, comps, 5);
	// print_tuple(c);

// 	t_world *world = default_world();
// 	t_shape *a = world->shapes;
// 	a->material.ambient = 1;
// 	a->material.pattern = test_pattern();
// 	// printf("%f\n", world->shapes->material.ambient);
// 	t_shape *b = world->shapes->next;
// 	b->material.transparency = 1;
// 	b->material.refractive_index = 1.5;
// 	t_ray *r = ray_new(new_point3_p(0, 0, 0.1), new_vec3_p(0, 1, 0));
// 	t_i i1 = intersection(-0.9899, a);
// 	t_i i2 = intersection(-0.4899, b);
// 	t_i i3 = intersection(0.4899, b);
// 	t_i i4 = intersection(0.9899, a);
// 	t_x *xs = create_intersections(4, i1, i2, i3, i4);
// 	printf("xs->i[2].t: %f\n", xs->i[2].t);
	
// 	t_comp *comps = prepare_computations(&xs->i[2], r, xs);
// 	// print_comps_data(comps);
// 	t_color3 c = refracted_color(world, comps, 5);
// 	print_tuple(c);
// }


// void print_xs_intersections(t_x *xs)
// {
// 	int i = 0;
// 	if (xs == NULL)
// 	{
// 		printf("xs is NULL\n");
// 		return ;
// 	}
// 	if (xs->count == 0)
// 		printf("intersection count: 0\n");
// 	printf("xs->count: %d\n", xs->count);
// 	while (i < xs->count)
// 	{
// 		printf("xs->i[%d].t: %f\n", i, xs->i[i].t);
// 		i++;
// 	}
// 	printf("-----------------\n");
// }


// int main(void)
// {
// 	// t_shape *c = cube();

// 	// t_ray *r1 = ray_new(new_point3_p(5, 0.5, 0), new_vec3_p(-1, 0, 0));
// 	// t_x *xs1 = intersect(c, r1);
// 	// print_xs_intersections(xs1);
// 	// t_ray *r2 = ray_new(new_point3_p(-5, 0.5, 0), new_vec3_p(1, 0, 0));
// 	// t_x *xs2 = intersect(c, r2);
// 	// print_xs_intersections(xs2);
// 	// t_ray *r3 = ray_new(new_point3_p(0.5, 5, 0), new_vec3_p(0, -1, 0));
// 	// t_x *xs3 = intersect(c, r3);
// 	// print_xs_intersections(xs3);
// 	// t_ray *r4 = ray_new(new_point3_p(0.5, -5, 0), new_vec3_p(0, 1, 0));
// 	// t_x *xs4 = intersect(c, r4);
// 	// print_xs_intersections(xs4);
// 	// t_ray *r5 = ray_new(new_point3_p(0.5, 0, 5), new_vec3_p(0, 0, -1));
// 	// t_x *xs5 = intersect(c, r5);
// 	// print_xs_intersections(xs5);
// 	// t_ray *r6 = ray_new(new_point3_p(0.5, 0, -5), new_vec3_p(0, 0, 1));
// 	// t_x *xs6 = intersect(c, r6);
// 	// print_xs_intersections(xs6);
// 	// t_ray *r7 = ray_new(new_point3_p(0, 0.5, 0), new_vec3_p(0, 0, 1));
// 	// t_x *xs7 = intersect(c, r7);
// 	// print_xs_intersections(xs7);

// 	// t_ray *r1 = ray_new(new_point3_p(-2, 0, 0), new_vec3_p(0.2673, 0.5345, 0.8018));
// 	// t_x *xs1 = intersect(c, r1);
// 	// print_xs_intersections(xs1);
// 	// t_ray *r2 = ray_new(new_point3_p(0, -2, 0), new_vec3_p(0.8018, 0.2673, 0.5345));
// 	// t_x *xs2 = intersect(c, r2);
// 	// print_xs_intersections(xs2);
// 	// t_ray *r3 = ray_new(new_point3_p(0, 0, -2), new_vec3_p(0.5345, 0.8018, 0.2673));
// 	// t_x *xs3 = intersect(c, r3);
// 	// print_xs_intersections(xs3);
// 	// t_ray *r4 = ray_new(new_point3_p(2, 0, 2), new_vec3_p(0, 0, -1));
// 	// t_x *xs4 = intersect(c, r4);
// 	// print_xs_intersections(xs4);
// 	// t_ray *r5 = ray_new(new_point3_p(0, 2, 2), new_vec3_p(0, -1, 0));
// 	// t_x *xs5 = intersect(c, r5);
// 	// print_xs_intersections(xs5);
// 	// t_ray *r6 = ray_new(new_point3_p(2, 2, 0), new_vec3_p(-1, 0, 0));
// 	// t_x *xs6 = intersect(c, r6);
// 	// print_xs_intersections(xs6);

	
// 	t_shape *c = cube();
	
// 	t_vec3 n1 = local_normal_at(c, new_point3_p(1, 0.5, -0.8));
// 	print_tuple(n1);
// 	t_vec3 n2 = local_normal_at(c, new_point3_p(-1, -0.2, 0.9));
// 	print_tuple(n2);
// 	t_vec3 n3 = local_normal_at(c, new_point3_p(-0.4, 1, -0.1));
// 	print_tuple(n3);
// 	t_vec3 n4 = local_normal_at(c, new_point3_p(0.3, -1, -0.7));
// 	print_tuple(n4);
// 	t_vec3 n5 = local_normal_at(c, new_point3_p(-0.6, 0.3, 1));
// 	print_tuple(n5);
// 	t_vec3 n6 = local_normal_at(c, new_point3_p(0.4, 0.4, -1));
// 	print_tuple(n6);
// 	t_vec3 n7 = local_normal_at(c, new_point3_p(1, 1, 1));
// 	print_tuple(n7);
// 	t_vec3 n8 = local_normal_at(c, new_point3_p(-1, -1, -1));
// 	print_tuple(n8);
// }



// void print_xs_intersections(t_x *xs)
// {
// 	int i = 0;
// 	if (xs == NULL)
// 	{
// 		printf("xs is NULL\n");
// 		return ;
// 	}
// 	if (xs->count == 0)
// 		printf("intersection count: 0\n");
// 	printf("xs->count: %d\n", xs->count);
// 	while (i < xs->count)
// 	{
// 		printf("xs->i[%d].t: %f\n", i, xs->i[i].t);
// 		i++;
// 	}
// 	printf("-----------------\n");
// }

// int main(void)
// {
// 	// t_shape *cyl = cylinder();
// 	// t_vec3 dir1 = normalize(new_vec3(0, 0, 1));
// 	// t_ray *r1 = ray_new(new_point3_p(1, 0, -5), &dir1);
// 	// t_x *xs1 = intersect(cyl, r1);
// 	// print_xs_intersections(xs1);
// 	// t_vec3 dir2 = normalize(new_vec3(0, 0, 1));
// 	// t_ray *r2 = ray_new(new_point3_p(0, 0, -5), &dir2);
	// t_x *xs2 = intersect(cyl, r2);
// 	// print_xs_intersections(xs2);
// 	// t_vec3 dir3 = normalize(new_vec3(0.1, 1, 1));
// 	// t_ray *r3 = ray_new(new_point3_p(0.5, 0, -5), &dir3);
// 	// t_x *xs3 = intersect(cyl, r3);
// 	// print_xs_intersections(xs3);

// 	t_shape *cyl = cylinder();
// 	t_vec3 n1 = local_normal_at(cyl, new_point3_p(1, 0, 0));
// 	print_tuple(n1);
// 	t_vec3 n2 = local_normal_at(cyl, new_point3_p(0, 5, -1));
// 	print_tuple(n2);
// 	t_vec3 n3 = local_normal_at(cyl, new_point3_p(0, -2, 1));
// 	print_tuple(n3);
// 	t_vec3 n4 = local_normal_at(cyl, new_point3_p(-1, 1, 0));
// 	print_tuple(n4);
	
// }

// int main(void)
// {
// 	// t_shape *cyl = cylinder();
// 	// t_vec3 dir1 = normalize(new_vec3(0, -1, 0));
// 	// t_ray *r1 = ray_new(new_point3_p(0, 3, 0), &dir1);
// 	// t_x *xs1 = intersect(cyl, r1);
// 	// print_xs_intersections(xs1);
// 	// t_vec3 dir2 = normalize(new_vec3(0, -1, 2));
// 	// t_ray *r2 = ray_new(new_point3_p(0, 3, -2), &dir2);
// 	// t_x *xs2 = intersect(cyl, r2);
// 	// print_xs_intersections(xs2);
// 	// t_vec3 dir3 = normalize(new_vec3(0, -1, 1));
// 	// t_ray *r3 = ray_new(new_point3_p(0, 4, -2), &dir3);
// 	// t_x *xs3 = intersect(cyl, r3);
// 	// print_xs_intersections(xs3);
// 	// t_vec3 dir4 = normalize(new_vec3(0, 1, 2));
// 	// t_ray *r4 = ray_new(new_point3_p(0, 0, -2), &dir4);
// 	// t_x *xs4 = intersect(cyl, r4);
// 	// print_xs_intersections(xs4);
// 	// t_vec3 dir5 = normalize(new_vec3(0, 1, 1));
// 	// t_ray *r5 = ray_new(new_point3_p(0, 1, -2), &dir5);
// 	// t_x *xs5 = intersect(cyl, r5);
// 	// print_xs_intersections(xs5);

// 	t_shape *cyl = cylinder();
// 	t_vec3 n1 = local_normal_at(cyl, new_point3_p(0, 1, 0));
// 	print_tuple(n1);
// 	t_vec3 n2 = local_normal_at(cyl, new_point3_p(0.5, 1, 0));
// 	print_tuple(n2);
// 	t_vec3 n3 = local_normal_at(cyl, new_point3_p(0, 1, 0.5));
// 	print_tuple(n3);
// 	t_vec3 n4 = local_normal_at(cyl, new_point3_p(0, 2, 0));
// 	print_tuple(n4);
// 	t_vec3 n5 = local_normal_at(cyl, new_point3_p(0.5, 2, 0));
// 	print_tuple(n5);
// 	t_vec3 n6 = local_normal_at(cyl, new_point3_p(0, 2, 0.5));
// 	print_tuple(n6);
	
// }

// int main(void)
// {
// 	// t_shape *c = cone();
	
// 	// t_vec3 dir1 = normalize(new_vec3(0, 0, 1));
// 	// t_ray *r1 = ray_new(new_point3_p(0, 0, -5), &dir1);
// 	// t_x *xs1 = intersect(c, r1);
// 	// print_xs_intersections(xs1);
// 	// t_vec3 dir2 = normalize(new_vec3(1, 1, 1));
// 	// t_ray *r2 = ray_new(new_point3_p(0, 0, -5), &dir2);
// 	// t_x *xs2 = intersect(c, r2);
// 	// print_xs_intersections(xs2);
// 	// t_vec3 dir3 = normalize(new_vec3(-0.5, -1, 1));
// 	// t_ray *r3 = ray_new(new_point3_p(1, 1, -5), &dir3);
// 	// t_x *xs3 = intersect(c, r3);
// 	// print_xs_intersections(xs3);

// 	// t_shape *c = cone();
// 	// t_vec3 dir1 = normalize(new_vec3(0, 1, 1));
// 	// t_ray *r1 = ray_new(new_point3_p(0, 0, -1), &dir1);
// 	// t_x *xs1 = intersect(c, r1);
// 	// print_xs_intersections(xs1);

// 	// t_shape *c = cone();
	
// 	// t_vec3 dir1 = normalize(new_vec3(0, 1, 0));
// 	// t_ray *r1 = ray_new(new_point3_p(0, 0, -5), &dir1);
// 	// t_x *xs1 = intersect(c, r1);
// 	// print_xs_intersections(xs1);
// 	// t_vec3 dir2 = normalize(new_vec3(0, 1, 1));
// 	// t_ray *r2 = ray_new(new_point3_p(0, 0, -0.25), &dir2);
// 	// t_x *xs2 = intersect(c, r2);
// 	// print_xs_intersections(xs2);
// 	// t_vec3 dir3 = normalize(new_vec3(0, 1, 0));
// 	// t_ray *r3 = ray_new(new_point3_p(0, 0, -0.25), &dir3);
// 	// t_x *xs3 = intersect(c, r3);
// 	// print_xs_intersections(xs3);

// 	t_shape *c = cone();
// 	t_vec3 n1 = local_normal_at(c, new_point3_p(0, 0, 0));
// 	print_tuple(n1);
// 	t_vec3 n2 = local_normal_at(c, new_point3_p(1, 1, 1));
// 	print_tuple(n2);
// 	t_vec3 n3 = local_normal_at(c, new_point3_p(-1, -1, 0));
// 	print_tuple(n3);
// }

void assert_color_equal(t_color3 actual, t_color3 expected) {
    if (fabs(actual.r - expected.r) > 1e-6 ||
        fabs(actual.g - expected.g) > 1e-6 ||
        fabs(actual.b - expected.b) > 1e-6) {
        fprintf(stderr, "Assertion failed: Color mismatch.\n");
        exit(EXIT_FAILURE);
    }
	else
		printf("A SUCCESS\n");
}



// void test_uv_checkers()
// {
// 	t_color3 black = new_color3(0, 0, 0);
// 	t_color3 white = new_color3(1, 1, 1);

//     t_uv *checkers = uv_checkers(2, 2, black, white);

//     t_color3 color = uv_pattern_at(checkers, 0.0f, 0.0f);
//     assert_color_equal(color, black);

//     color = uv_pattern_at(checkers, 0.5f, 0.0f);
//     assert_color_equal(color, white);

//     color = uv_pattern_at(checkers, 0.0f, 0.5f);
//     assert_color_equal(color, white);

//     color = uv_pattern_at(checkers, 0.5f, 0.5f);
//     assert_color_equal(color, black);

//     color = uv_pattern_at(checkers, 1.0f, 1.0f);
//     assert_color_equal(color, black);

//     free(checkers); // Clean up memory.
// }

// void test_spherical_map() {
//     // Define test points
//     t_point3 p1 = new_point3(0, 0, -1);
//     t_point3 p2 = new_point3(1, 0, 0);
//     t_point3 p3 = new_point3(0, 0, 1);
//     t_point3 p4 = new_point3(-1, 0, 0);
//     t_point3 p5 = new_point3(0, 1, 0);
//     t_point3 p6 = new_point3(0, -1, 0);
//     t_point3 p7 = new_point3(sqrt(2) / 2, sqrt(2) / 2, 0);

//     // Compute UV coordinates for each point
//     t_uv_val uv1 = spherical_map(p1);
//     t_uv_val uv2 = spherical_map(p2);
//     t_uv_val uv3 = spherical_map(p3);
//     t_uv_val uv4 = spherical_map(p4);
//     t_uv_val uv5 = spherical_map(p5);
//     t_uv_val uv6 = spherical_map(p6);
//     t_uv_val uv7 = spherical_map(p7);

//     // Expected results
//     t_uv_val expected[] = {
//         {0.0f, 0.5f}, {0.25f, 0.5f}, {0.5f, 0.5f}, {0.75f, 0.5f},
//         {0.5f, 1.0f}, {0.5f, 0.0f}, {0.25f, 0.75f}
//     };

//     // Print results
//     printf("Test results:\n");
//     printf("P1: (u, v) = (%f, %f) | Expected: (%f, %f)\n", uv1.u, uv1.v, expected[0].u, expected[0].v);
//     printf("P2: (u, v) = (%f, %f) | Expected: (%f, %f)\n", uv2.u, uv2.v, expected[1].u, expected[1].v);
//     printf("P3: (u, v) = (%f, %f) | Expected: (%f, %f)\n", uv3.u, uv3.v, expected[2].u, expected[2].v);
//     printf("P4: (u, v) = (%f, %f) | Expected: (%f, %f)\n", uv4.u, uv4.v, expected[3].u, expected[3].v);
//     printf("P5: (u, v) = (%f, %f) | Expected: (%f, %f)\n", uv5.u, uv5.v, expected[4].u, expected[4].v);
//     printf("P6: (u, v) = (%f, %f) | Expected: (%f, %f)\n", uv6.u, uv6.v, expected[5].u, expected[5].v);
//     printf("P7: (u, v) = (%f, %f) | Expected: (%f, %f)\n", uv7.u, uv7.v, expected[6].u, expected[6].v);
// }

// void test_texture_map_integration() {
//     t_color3 black = new_color3(0, 0, 0);
//     t_color3 white = new_color3(1, 1, 1);

//     // Create UV pattern and texture map
//     t_uv *checkers = uv_checkers(16, 8, black, white);
//     t_pattern *pattern = new_texture_map(checkers, spherical_map);

//     // Test points
//     t_point3 points[] = {
//         new_point3(0.4315, 0.4670, 0.7719),
//         new_point3(-0.9654, 0.2552, -0.0534),
//         new_point3(0.1039, 0.7090, 0.6975),
//         new_point3(-0.4986, -0.7856, -0.3663),
//         new_point3(-0.0317, -0.9395, 0.3411),
//         new_point3(0.4809, -0.7721, 0.4154),
//         new_point3(0.0285, -0.9612, -0.2745),
//         new_point3(-0.5734, -0.2162, -0.7903),
//         new_point3(0.7688, -0.1470, 0.6223),
//         new_point3(-0.7652, 0.2175, 0.6060),
//     };

//     t_color3 expected[] = {
//         white, black, white, black, black, black, black, white, black, black
//     };

//     // Check results
//     for (int i = 0; i < 10; i++) {
//         t_color3 *color = pattern_at(pattern, &points[i]);
//         assert_color_equal(*color, expected[i]);
//     }

//     // Cleanup
//     free(checkers);
//     free(pattern);

//     printf("All texture map integration tests passed.\n");
// }

// int main (void)
// {
// 	// t_uv *checkers = uv_checkers(2, 2, new_color3(1, 1, 1), new_color3(0, 0, 0));
// 	// t_color3 color = uv_pattern_at(*checkers, 1, 1);
// 	// print_tuple(color);

// // 	t_point3 p = new_point3(sqrt(2)/2, sqrt(2)/2, 0);
// // 	float u = spherical_map(p, false);
// // 	float v = spherical_map(p, true);
// // 	printf("u %f\n", u);
// // 	printf("v %f\n", v);
// 	test_uv_checkers();
// 	test_spherical_map();
// 	test_texture_map_integration();

// }


// void test_planar_map() {
//     t_point3 points[] = {
//         new_point3(0.25, 0, 0.5),
//         new_point3(0.25, 0, -0.25),
//         new_point3(0.25, 0.5, -0.25),
//         new_point3(1.25, 0, 0.5),
//         new_point3(0.25, 0, -1.75),
//         new_point3(1, 0, -1),
//         new_point3(0, 0, 0)
//     };

//     t_uv_val expected[] = {
//         {0.25, 0.5}, {0.25, 0.75}, {0.25, 0.75},
//         {0.25, 0.5}, {0.25, 0.25}, {0.0, 0.0}, {0.0, 0.0}
//     };

//     for (int i = 0; i < 7; i++) {
//         t_uv_val uv = planar_map(points[i]);
//         printf("Point: (%f, %f, %f) -> (u, v): (%f, %f) | Expected: (%f, %f)\n",
//                points[i].x, points[i].y, points[i].z,
//                uv.u, uv.v, expected[i].u, expected[i].v);

//         // Validate results
//         if (fabs(uv.u - expected[i].u) > 1e-6 || fabs(uv.v - expected[i].v) > 1e-6) {
//             fprintf(stderr, "Test failed for point (%f, %f, %f)\n",
//                     points[i].x, points[i].y, points[i].z);
//             exit(EXIT_FAILURE);
//         }
//     }

//     printf("All planar_map tests passed successfully.\n");
// }

// int main(void)
// {
// 	test_planar_map();
// 	return 0;
// }

// void test_cylindrical_map() {
//     t_point3 points[] = {
//         new_point3(0, 0, -1),
//         new_point3(0, 0.5, -1),
//         new_point3(0, 1, -1),
//         new_point3(0.70711, 0.5, -0.70711),
//         new_point3(1, 0.5, 0),
//         new_point3(0.70711, 0.5, 0.70711),
//         new_point3(0, -0.25, 1),
//         new_point3(-0.70711, 0.5, 0.70711),
//         new_point3(-1, 1.25, 0),
//         new_point3(-0.70711, 0.5, -0.70711),
//     };

//     t_uv_val expected[] = {
//         {0.0, 0.0}, {0.0, 0.5}, {0.0, 0.0}, {0.125, 0.5},
//         {0.25, 0.5}, {0.375, 0.5}, {0.5, 0.75}, {0.625, 0.5},
//         {0.75, 0.25}, {0.875, 0.5}
//     };

//     for (int i = 0; i < 10; i++) {
//         t_uv_val uv = cylindrical_map(points[i]);
//         printf("Point: (%f, %f, %f) -> (u, v): (%f, %f) | Expected: (%f, %f)\n",
//                points[i].x, points[i].y, points[i].z,
//                uv.u, uv.v, expected[i].u, expected[i].v);

//         // Validate results
//         if (fabs(uv.u - expected[i].u) > 1e-6 || fabs(uv.v - expected[i].v) > 1e-6) {
//             fprintf(stderr, "Test failed for point (%f, %f, %f)\n",
//                     points[i].x, points[i].y, points[i].z);
//             exit(EXIT_FAILURE);
//         }
//     }

//     printf("All cylindrical_map tests passed successfully.\n");
// }

// int main (void)
// {
// 	test_cylindrical_map();
// 	return 0;
// }








// void test_uv_align_check() {
//     t_color3 main = new_color3(1, 1, 1);
//     t_color3 ul = new_color3(1, 0, 0);
//     t_color3 ur = new_color3(1, 1, 0);
//     t_color3 bl = new_color3(0, 1, 0);
//     t_color3 br = new_color3(0, 1, 1);

//     t_pattern *pattern = new_uv_align_check(main, ul, ur, bl, br);

//     struct {
//         float u, v;
//         t_color3 expected;
//     } cases[] = {
//         {0.5, 0.5, main},
//         {0.1, 0.9, ul},
//         {0.9, 0.9, ur},
//         {0.1, 0.1, bl},
//         {0.9, 0.1, br},
//     };

//     for (int i = 0; i < 5; i++) {
//         t_color3 result = uv_pattern_at(pattern, cases[i].u, cases[i].v);
//         if (fabs(result.r - cases[i].expected.r) > 1e-6 ||
//             fabs(result.g - cases[i].expected.g) > 1e-6 ||
//             fabs(result.b - cases[i].expected.b) > 1e-6) {
//             printf("Test failed for u = %f, v = %f\n", cases[i].u, cases[i].v);
//             printf("Expected: (%f, %f, %f), Got: (%f, %f, %f)\n",
//                    cases[i].expected.r, cases[i].expected.g, cases[i].expected.b,
//                    result.r, result.g, result.b);
//             exit(EXIT_FAILURE);
//         }
//     }

//     printf("All uv_align_check tests passed!\n");
//     free(pattern->uv_pattern);
//     free(pattern);
// }

// int main (void)
// {
// 	test_uv_align_check();
// 	return 0;
// }

#include <assert.h>

void test_uv_checkers() {
    t_color3 black = new_color3(0, 0, 0);
    t_color3 white = new_color3(1, 1, 1);

    t_uv *checkers = uv_checkers(2, 2, black, white);

    assert_color_equal(uv_pattern_at(checkers, 0.0f, 0.0f), black);
    assert_color_equal(uv_pattern_at(checkers, 0.5f, 0.0f), white);
    assert_color_equal(uv_pattern_at(checkers, 0.0f, 0.5f), white);
    assert_color_equal(uv_pattern_at(checkers, 0.5f, 0.5f), black);
    assert_color_equal(uv_pattern_at(checkers, 1.0f, 1.0f), black);

    free(checkers);
}



void assert_uv_equal(t_uv_val actual, t_uv_val expected, const char *test_name) {
    printf("%s: (u, v) = (%f, %f) | Expected: (%f, %f)\n",
           test_name, actual.u, actual.v, expected.u, expected.v);

    assert(fabs(actual.u - expected.u) < 1e-6);
    assert(fabs(actual.v - expected.v) < 1e-6);
    printf("%s: SUCCESS\n", test_name);
}

void test_spherical_map() {
    // Test 1
    t_point3 p1 = new_point3(0, 0, -1);
    t_uv_val expected1 = {0.0, 0.5};
    assert_uv_equal(spherical_map(p1), expected1, "Test 1: point(0, 0, -1)");

    // Test 2
    t_point3 p2 = new_point3(1, 0, 0);
    t_uv_val expected2 = {0.25, 0.5};
    assert_uv_equal(spherical_map(p2), expected2, "Test 2: point(1, 0, 0)");

    // Test 3
    t_point3 p3 = new_point3(0, 0, 1);
    t_uv_val expected3 = {0.5, 0.5};
    assert_uv_equal(spherical_map(p3), expected3, "Test 3: point(0, 0, 1)");

    // Test 4
    t_point3 p4 = new_point3(-1, 0, 0);
    t_uv_val expected4 = {0.75, 0.5};
    assert_uv_equal(spherical_map(p4), expected4, "Test 4: point(-1, 0, 0)");

    // Test 5
    t_point3 p5 = new_point3(0, 1, 0);
    t_uv_val expected5 = {0.5, 1.0};
    assert_uv_equal(spherical_map(p5), expected5, "Test 5: point(0, 1, 0)");

    // Test 6
    t_point3 p6 = new_point3(0, -1, 0);
    t_uv_val expected6 = {0.5, 0.0};
    assert_uv_equal(spherical_map(p6), expected6, "Test 6: point(0, -1, 0)");

    // Test 7
    t_point3 p7 = new_point3(sqrtf(2) / 2, sqrtf(2) / 2, 0);
    t_uv_val expected7 = {0.25, 0.75};
    assert_uv_equal(spherical_map(p7), expected7, "Test 7: point(√2/2, √2/2, 0)");
}

void test_texture_map() {
    t_color3 black = new_color3(0, 0, 0);
    t_color3 white = new_color3(1, 1, 1);

    // Create a UV checkers pattern
    t_uv *checkers = uv_checkers(16, 8, black, white);

    // Create a texture map pattern with spherical mapping
    t_pattern *pattern = texture_map(checkers, spherical_map);

    // Define test points and expected colors
    struct {
        t_point3 point;
        t_color3 expected_color;
    } tests[] = {
        {new_point3(0.4315, 0.4670, 0.7719), white},
        {new_point3(-0.9654, 0.2552, -0.0534), black},
        {new_point3(0.1039, 0.7090, 0.6975), white},
        {new_point3(-0.4986, -0.7856, -0.3663), black},
        {new_point3(-0.0317, -0.9395, 0.3411), black},
        {new_point3(0.4809, -0.7721, 0.4154), black},
        {new_point3(0.0285, -0.9612, -0.2745), black},
        {new_point3(-0.5734, -0.2162, -0.7903), white},
        {new_point3(0.7688, -0.1470, 0.6223), black},
        {new_point3(-0.7652, 0.2175, 0.6060), black},
    };

    // Run the tests
    for (int i = 0; i < 10; i++) {
        t_color3 *result = pattern_at(pattern, &tests[i].point);
        assert_color_equal(*result, tests[i].expected_color);
        printf("Test %d passed!\n", i + 1);
        free(result);
    }

    // Clean up
    free(checkers);
    free(pattern);
}

void test_planar_map() {
    printf("Testing planar_map...\n");

    // Test cases
    t_point3 p1 = new_point3(0.25, 0, 0.5);
    t_uv_val expected1 = {0.25, 0.5};
    assert_uv_equal(planar_map(p1), expected1, "Test 1: point(0.25, 0, 0.5)");

    t_point3 p2 = new_point3(0.25, 0, -0.25);
    t_uv_val expected2 = {0.25, 0.75};
    assert_uv_equal(planar_map(p2), expected2, "Test 2: point(0.25, 0, -0.25)");

    t_point3 p3 = new_point3(0.25, 0.5, -0.25);
    t_uv_val expected3 = {0.25, 0.75};
    assert_uv_equal(planar_map(p3), expected3, "Test 3: point(0.25, 0.5, -0.25)");

    t_point3 p4 = new_point3(1.25, 0, 0.5);
    t_uv_val expected4 = {0.25, 0.5};
    assert_uv_equal(planar_map(p4), expected4, "Test 4: point(1.25, 0, 0.5)");

    t_point3 p5 = new_point3(0.25, 0, -1.75);
    t_uv_val expected5 = {0.25, 0.25};
    assert_uv_equal(planar_map(p5), expected5, "Test 5: point(0.25, 0, -1.75)");

    t_point3 p6 = new_point3(1, 0, -1);
    t_uv_val expected6 = {0.0, 0.0};
    assert_uv_equal(planar_map(p6), expected6, "Test 6: point(1, 0, -1)");

    t_point3 p7 = new_point3(0, 0, 0);
    t_uv_val expected7 = {0.0, 0.0};
    assert_uv_equal(planar_map(p7), expected7, "Test 7: point(0, 0, 0)");

    printf("All planar_map tests passed!\n");
}

void test_cylindrical_map() {
    printf("Testing cylindrical_map...\n");

    // Test 1
    t_point3 p1 = new_point3(0, 0, -1);
    t_uv_val expected1 = {0.0, 0.0};
    assert_uv_equal(cylindrical_map(p1), expected1, "Test 1: point(0, 0, -1)");

    // Test 2
    t_point3 p2 = new_point3(0, 0.5, -1);
    t_uv_val expected2 = {0.0, 0.5};
    assert_uv_equal(cylindrical_map(p2), expected2, "Test 2: point(0, 0.5, -1)");

    // Test 3
    t_point3 p3 = new_point3(0, 1, -1);
    t_uv_val expected3 = {0.0, 0.0};
    assert_uv_equal(cylindrical_map(p3), expected3, "Test 3: point(0, 1, -1)");

    // Test 4
    t_point3 p4 = new_point3(0.70711, 0.5, -0.70711);
    t_uv_val expected4 = {0.125, 0.5};
    assert_uv_equal(cylindrical_map(p4), expected4, "Test 4: point(0.70711, 0.5, -0.70711)");

    // Test 5
    t_point3 p5 = new_point3(1, 0.5, 0);
    t_uv_val expected5 = {0.25, 0.5};
    assert_uv_equal(cylindrical_map(p5), expected5, "Test 5: point(1, 0.5, 0)");

    // Test 6
    t_point3 p6 = new_point3(0.70711, 0.5, 0.70711);
    t_uv_val expected6 = {0.375, 0.5};
    assert_uv_equal(cylindrical_map(p6), expected6, "Test 6: point(0.70711, 0.5, 0.70711)");

    // Test 7
    t_point3 p7 = new_point3(0, -0.25, 1);
    t_uv_val expected7 = {0.5, 0.75};
    assert_uv_equal(cylindrical_map(p7), expected7, "Test 7: point(0, -0.25, 1)");

    // Test 8
    t_point3 p8 = new_point3(-0.70711, 0.5, 0.70711);
    t_uv_val expected8 = {0.625, 0.5};
    assert_uv_equal(cylindrical_map(p8), expected8, "Test 8: point(-0.70711, 0.5, 0.70711)");

    // Test 9
    t_point3 p9 = new_point3(-1, 1.25, 0);
    t_uv_val expected9 = {0.75, 0.25};
    assert_uv_equal(cylindrical_map(p9), expected9, "Test 9: point(-1, 1.25, 0)");

    // Test 10
    t_point3 p10 = new_point3(-0.70711, 0.5, -0.70711);
    t_uv_val expected10 = {0.875, 0.5};
    assert_uv_equal(cylindrical_map(p10), expected10, "Test 10: point(-0.70711, 0.5, -0.70711)");

    printf("All cylindrical_map tests passed!\n");
}

void test_uv_align_check() {
    printf("Testing uv_align_check...\n");

    t_uv_align_check *pattern = uv_align_check(
        new_color3(1, 1, 1), // Main (white)
        new_color3(1, 0, 0), // Upper left (red)
        new_color3(1, 1, 0), // Upper right (yellow)
        new_color3(0, 1, 0), // Bottom left (green)
        new_color3(0, 1, 1)  // Bottom right (cyan)
    );

    // Test cases
    assert_color_equal(uv_pattern_at_align_check(pattern, 0.5, 0.5), new_color3(1, 1, 1));
    assert_color_equal(uv_pattern_at_align_check(pattern, 0.1, 0.9), new_color3(1, 0, 0));
    assert_color_equal(uv_pattern_at_align_check(pattern, 0.9, 0.9), new_color3(1, 1, 0));
    assert_color_equal(uv_pattern_at_align_check(pattern, 0.1, 0.1), new_color3(0, 1, 0));
    assert_color_equal(uv_pattern_at_align_check(pattern, 0.9, 0.1), new_color3(0, 1, 1));

    printf("All uv_align_check tests passed!\n");
}

void test_face_from_point() {
    struct {
        t_point3 point;
        t_directions expected_face;
    } test_cases[] = {
        {new_point3(-1, 0.5, -0.25), LEFT},
        {new_point3(1.1, -0.75, 0.8), RIGHT},
        {new_point3(0.1, 0.6, 0.9), FRONT},
        {new_point3(-0.7, 0, -2), BACK},
        {new_point3(0.5, 1, 0.9), UP},
        {new_point3(-0.2, -1.3, 1.1), DOWN}
    };

    for (int i = 0; (unsigned long)i < sizeof(test_cases) / sizeof(test_cases[0]); ++i) {
        t_directions result = face_from_point(test_cases[i].point);
        if (result != test_cases[i].expected_face) {
            fprintf(stderr, "Test %d failed: Expected %d, got %d\n",
                    i + 1, test_cases[i].expected_face, result);
            exit(EXIT_FAILURE);
        } else {
            printf("Test %d passed.\n", i + 1);
        }
    }
}


#include <assert.h>
#include <stdio.h>

// Helper function for comparing colors
int color_equals(t_color3 a, t_color3 b) {
    float epsilon = 1e-6;  // Adjust as needed
    return fabs(a.r - b.r) < epsilon && fabs(a.g - b.g) < epsilon && fabs(a.b - b.b) < epsilon;
}

void test_left_face_uv() {
    t_point3 points[] = {
        new_point3(-1, 0, 0),      // Center of left face
        new_point3(-1, 0.9, -0.9), // Top-left corner
        new_point3(-1, 0.9, 0.9),  // Top-right corner
        new_point3(-1, -0.9, -0.9),// Bottom-left corner
        new_point3(-1, -0.9, 0.9)  // Bottom-right corner
    };

    t_uv_val expected[] = {
        {0.5, 0.5}, {0.05, 0.95}, {0.95, 0.95}, {0.05, 0.05}, {0.95, 0.05}
    };

    for (int i = 0; i < 5; i++) {
        t_uv_val uv = cube_uv_left(points[i]);
        printf("Left Face: Point (%f, %f, %f) -> UV: u = %f, v = %f (Expected: u = %f, v = %f)\n",
               points[i].x, points[i].y, points[i].z, uv.u, uv.v, expected[i].u, expected[i].v);
        assert(fabs(uv.u - expected[i].u) < 1e-6 && fabs(uv.v - expected[i].v) < 1e-6);
    }
}

void test_right_face_uv() {
    t_point3 points[] = {
        new_point3(1, 0, 0),       // Center of right face
        new_point3(1, 0.9, 0.9),   // Top-right corner
        new_point3(1, 0.9, -0.9),  // Top-left corner
        new_point3(1, -0.9, 0.9),  // Bottom-right corner
        new_point3(1, -0.9, -0.9),  // Bottom-left corner
    };

    t_uv_val expected[] = {
        {0.5, 0.5}, {0.95, 0.95}, {0.05, 0.95}, {0.95, 0.05}, {0.05, 0.05}
    };

    for (int i = 0; i < 5; i++) {
        t_uv_val uv = cube_uv_right(points[i]);
        printf("Right Face: Point (%f, %f, %f) -> UV: u = %f, v = %f (Expected: u = %f, v = %f)\n",
               points[i].x, points[i].y, points[i].z, uv.u, uv.v, expected[i].u, expected[i].v);
        assert(fabs(uv.u - expected[i].u) < 1e-6 && fabs(uv.v - expected[i].v) < 1e-6);
    }
}



void test_cube_mapped_colors() {
    // Define colors
    t_color3 red = new_color3(1, 0, 0);
    t_color3 yellow = new_color3(1, 1, 0);
    t_color3 brown = new_color3(1, 0.5, 0);
    t_color3 green = new_color3(0, 1, 0);
    t_color3 cyan = new_color3(0, 1, 1);
    t_color3 blue = new_color3(0, 0, 1);
    t_color3 purple = new_color3(1, 0, 1);
    t_color3 white = new_color3(1, 1, 1);

    // Create align check patterns for each face
    t_pattern *left = align_check_map(uv_align_check(yellow, cyan, red, blue, brown), cube_uv_left);
    t_pattern *front = align_check_map(uv_align_check(cyan, red, yellow, brown, green), cube_uv_front);
    t_pattern *right = align_check_map(uv_align_check(red, yellow, purple, green, white), cube_uv_right);
    t_pattern *back = align_check_map(uv_align_check(green, purple, cyan, white, blue), cube_uv_back);
    t_pattern *up = align_check_map(uv_align_check(brown, cyan, purple, red, yellow), cube_uv_up);
    t_pattern *down = align_check_map(uv_align_check(purple, brown, green, blue, white), cube_uv_down);

    // Create cube map pattern
    t_pattern *cube_pattern = new_cube_map(left, front, right, back, up, down);

    // Define test cases
    typedef struct {
        t_point3 point;
        t_color3 expected_color;
        const char *description;
    } t_test_case;

    t_test_case test_cases[] = {
        {new_point3(-1, 0, 0), yellow, "Left face, center"},
        {new_point3(-1, 0.9, -0.9), cyan, "Left face, top-left"},
        {new_point3(-1, 0.9, 0.9), red, "Left face, top-right"},
        {new_point3(-1, -0.9, -0.9), blue, "Left face, bottom-left"},
        {new_point3(-1, -0.9, 0.9), brown, "Left face, bottom-right"},
        {new_point3(0, 0, 1), cyan, "Front face, center"},
        {new_point3(-0.9, 0.9, 1), red, "Front face, top-left"},
        {new_point3(0.9, 0.9, 1), yellow, "Front face, top-right"},
        {new_point3(-0.9, -0.9, 1), brown, "Front face, bottom-left"},
        {new_point3(0.9, -0.9, 1), green, "Front face, bottom-right"},
        {new_point3(1, 0, 0), red, "Right face, center"},
        {new_point3(1, 0.9, 0.9), yellow, "Right face, top-left"},
        {new_point3(1, 0.9, -0.9), purple, "Right face, top-right"},
        {new_point3(1, -0.9, 0.9), green, "Right face, bottom-left"},
        {new_point3(1, -0.9, -0.9), white, "Right face, bottom-right"},
        {new_point3(0, 0, -1), green, "Back face, center"},
        {new_point3(0.9, 0.9, -1), purple, "Back face, top-left"},
        {new_point3(-0.9, 0.9, -1), cyan, "Back face, top-right"},
        {new_point3(0.9, -0.9, -1), white, "Back face, bottom-left"},
        {new_point3(-0.9, -0.9, -1), blue, "Back face, bottom-right"},
        {new_point3(0, 1, 0), brown, "Up face, center"},
        {new_point3(-0.9, 1, -0.9), cyan, "Up face, top-left"},
        {new_point3(0.9, 1, -0.9), purple, "Up face, top-right"},
        {new_point3(-0.9, 1, 0.9), red, "Up face, bottom-left"},
        {new_point3(0.9, 1, 0.9), yellow, "Up face, bottom-right"},
        {new_point3(0, -1, 0), purple, "Down face, center"},
        {new_point3(-0.9, -1, 0.9), brown, "Down face, top-left"},
        {new_point3(0.9, -1, 0.9), green, "Down face, top-right"},
        {new_point3(-0.9, -1, -0.9), blue, "Down face, bottom-left"},
        {new_point3(0.9, -1, -0.9), white, "Down face, bottom-right"}
    };

    // Run test cases
    for (size_t i = 0; i < sizeof(test_cases) / sizeof(t_test_case); i++) {
        t_color3 *actual_color = pattern_at(cube_pattern, &test_cases[i].point);
        printf("%s: Point (%f, %f, %f) -> Expected Color (%f, %f, %f), Actual Color (%f, %f, %f)\n",
               test_cases[i].description,
               test_cases[i].point.x, test_cases[i].point.y, test_cases[i].point.z,
               test_cases[i].expected_color.r, test_cases[i].expected_color.g, test_cases[i].expected_color.b,
               actual_color->r, actual_color->g, actual_color->b);
        assert(color_equals(*actual_color, test_cases[i].expected_color) && "Test failed!");
    }
}
void test_uv_image_pattern() {
    // Create a test canvas
    t_canvas *canvas = canvas_from_ppm("test.ppm");

    // Create a UV image pattern
    t_pattern *pattern = uv_image(canvas);

    // Test cases
    double test_uvs[4][2] = {
        {0, 0},
        {0.3, 0},
        {0.6, 0.3},
        {1, 1}
    };
    t_color3 expected_colors[4] = {
        new_color3(0.9, 0.9, 0.9),
        new_color3(0.2, 0.2, 0.2),
        new_color3(0.1, 0.1, 0.1),
        new_color3(0.9, 0.9, 0.9)
    };

    for (int i = 0; i < 4; i++) {
        double u = test_uvs[i][0];
        double v = test_uvs[i][1];
        t_color3 actual = uv_pattern_at_image(pattern, u, v);
        assert(color_equals(actual, expected_colors[i]) && "UV Image Pattern Test Failed!");
    }

    printf("All UV image pattern tests passed!\n");
}


// int main(void)
// {
// 	test_uv_checkers();
// 	printf("test_uv_checkers passed\n");
// 	test_spherical_map();
// 	printf("test_spherical_map passed\n");
// 	test_texture_map();
// 	printf("test_texture_map passed\n");
// 	test_planar_map();
// 	printf("test_planar_map passed\n");
// 	test_cylindrical_map();
// 	printf("test_cylindrical_map passed\n");
// 	test_uv_align_check();
// 	printf("test\n");
// 	test_face_from_point();
//     printf("test_face_from_point passed\n");
//     test_cube_mapped_colors();
//     printf("test_cube_colors_passed\n");
//     test_uv_image_pattern();
//     printf("test_uv_image_pattern passed\n");
//     // test_left_face_uv();
//     // test_right_face_uv();
//     return 0;
// }

// int main(void)
// {
//     t_canvas *canvas = canvas_from_ppm("test.ppm");
//     printf("width: %d\n", canvas->width);
//     printf("height: %d\n", canvas->height);
//     print_tuple(canvas->pixels[1][0]);
// }



// int main (void)
// {
//     t_canvas *canvas = canvas_new(800, 800);
//     t_world	*world = setup_cube_scene();
// 	t_camera *camera = camera_new(800, 400, 0.8);
// 	camera->transform = view_transformation(new_point3(0, 0, -20), new_point3(0, 0, 0), new_vec3(0, 1, 0));
//     int x, y;
//     t_ray *ray;
//     t_color3 color;

//     y = 0;
// 	while(y < canvas->height)
// 	{
// 		x = 0;
// 		while(x < canvas->width)
// 		{
// 			ray = ray_for_pixel(camera, x, y);			
// 			color = color_at(world, ray, RECURSIVE_DEPTH);
// 			write_pixel(canvas, x, y, color);
// 			x++;
// 		}
// 		y++;
// 	}
//     canvas_to_ppm(canvas, "test.ppm");
//     printf("done\n");
// }

// int main(void)
// {
// 	t_shape *g = group();
// 	t_shape *s1 = sphere();
// 	t_shape *s2 = sphere();
// 	set_transform(s2, translation(0, 0, -3));
// 	t_shape *s3 = sphere();
// 	set_transform(s3, translation(5, 0, 0));
// 	add_child(g, s1);
// 	add_child(g, s2);
// 	add_child(g, s3);
// 	t_ray *r = ray_new(new_point3_p(0, 0, -5), new_vec3_p(0, 0, 1));
// 	printf("group->children->count: %d\n", g->children_count);
// 	t_x *xs = intersect(g, r);
// 	printf("xs->count: %d\n", xs->count);
// 	int i = 0;
// 	printf("shape 1 address: %p\n", (void *)s1);
// 	printf("shape 2 address: %p\n", (void *)s2);
// 	printf("shape 3 address: %p\n", (void *)s3);
// 	while (i < xs->count)
// 	{
// 		printf("xs->xs[%d]->t: %p\n", i, (void *)xs->i[i].shape);
// 		i++;
// 	}
// }

// int main (void)
// {
// 	t_shape *g = group();
// 	set_transform(g, scaling(2, 2, 2));
// 	t_shape *s = sphere();
// 	set_transform(s, translation(5, 0, 0));
// 	add_child(g, s);
// 	t_ray *r = ray_new(new_point3_p(10, 0, -10), new_vec3_p(0, 0, 1));
// 	t_x *xs = intersect(g, r);
// 	printf("xs->count: %d\n", xs->count);
// }


// int main (void)
// {
// 	t_shape *g1 = group();
// 	set_transform(g1, rotation_y(M_PI / 2));
// 	t_shape *g2 = group();
// 	set_transform(g2, scaling(1, 2, 3));
// 	add_child(g1, g2);
// 	t_shape *s = sphere();
// 	set_transform(s, translation(5, 0, 0));
// 	add_child(g2, s);
// 	t_vec3 n = normal_at(s, new_point3(1.7321, 1.1547, -5.5774));
// 	// t_point3 p = world_to_object(s, new_point3_p(-2, 0, -10));
// 	print_tuple(n);


// }


int main (void)
{
	mlx_t *mlx = mlx_init(800, 400, "test", 1);
	t_world	*world = test_groups_scene();
	// (void)world;
	t_camera *camera = camera_new(800, 400, 0.8);
	camera->transform = view_transformation(new_point3(1, 7, -9), new_point3(0, 1.1, 0), new_vec3(0, 1, 0));
    mlx_image_t *image = render(mlx, camera, world);
	mlx_image_to_window(mlx, image, 0, 0);
	printf("done\n");
	mlx_loop(mlx);
	return(0);
}


// // // // CAMERA TEST !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// int main (void)
// {
// 	// mlx_t *mlx = mlx_init(800, 400, "test", 1);
// 	t_world	*world = test_groups_scene();
// 	(void)world;
// 	// t_camera *camera = camera_new(800, 400, 0.8);
// 	// camera->transform = view_transformation(new_point3(1, 2, -15), new_point3(0, 1.1, 0), new_vec3(0, 1, 0));
//     // mlx_image_t *image = render(mlx, camera, world);
// 	// mlx_image_to_window(mlx, image, 0, 0);
// 	// printf("done\n");
// 	// mlx_loop(mlx);
// 	return(0);
// }
