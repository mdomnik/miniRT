/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_and_reflect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:52:36 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/09 12:48:47 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

#define VEC_LIGHT 0
#define VEC_AMBIENT 1
#define VEC_REFLECT 2
#define VEC_COUNT 3

#define COL_EFFECTIVE 0
#define COL_DIFFUSE 1
#define COL_SPECULAR 2
#define COL_RESULT 3
#define COL_AMBIENT_PROD 4
#define COL_COUNT 5

#define DOT_LIGHT_NORMAL 0
#define DOT_REFLECT_EYE 1
#define DOT_FACTOR 2
#define DOT_COUNT 3

t_vec3	reflect(t_vec3 in, t_vec3 normal)
{
	float	dot;
	t_vec3	reflect;

	dot = dot_product(in, normal);
	reflect = sub_tuple(in, mult_tuple(normal, 2 * dot));
	return (reflect);
}

t_color3	lighting(t_material *m, t_shape *shape, t_light_p *light,
	t_point3 *point, t_vec3 eyev, t_vec3 normalv, bool in_shadow)
{
	t_vec3		vec[VEC_COUNT];
	t_color3	col[COL_COUNT];
	float		dot[DOT_COUNT];

	if (m->pattern)
		col[COL_EFFECTIVE] = mult_color(pattern_at_object(m->pattern,
					shape, point), light->intensity);
	else if (is_near_zero(light->intensity))
		return (mult_color_scalar(m->color, m->ambient));
	else
	{
		col[COL_EFFECTIVE] = mult_color(m->color, light->intensity);
	}
	vec[VEC_LIGHT] = normalize(sub_tuple_p(&light->position, point));
	if (shape->type != SKYBOX)
	{
		col[COL_AMBIENT_PROD] = mult_color_scalar(global_color('a',
					(t_color3){0}), m->ambient);
		vec[VEC_AMBIENT] = mult_tuple(add_tuple(col[COL_EFFECTIVE],
					col[COL_AMBIENT_PROD]), m->ambient);
	}
	else
	{
		col[COL_EFFECTIVE] = m->color;
		vec[VEC_AMBIENT] = mult_tuple(col[COL_EFFECTIVE], m->ambient);
	}
	dot[DOT_LIGHT_NORMAL] = dot_product(vec[VEC_LIGHT], normalv);
	if (dot[DOT_LIGHT_NORMAL] < 0)
	{
		col[COL_DIFFUSE] = new_color3(0, 0, 0);
		col[COL_SPECULAR] = new_color3(0, 0, 0);
	}
	else
	{
		col[COL_DIFFUSE] = mult_tuple(col[COL_EFFECTIVE],
				(m->diffuse * dot[DOT_LIGHT_NORMAL]));
		vec[VEC_REFLECT] = reflect(neg_vec3(vec[VEC_LIGHT]), normalv);
		dot[DOT_REFLECT_EYE] = dot_product(vec[VEC_REFLECT], eyev);
		if (dot[DOT_REFLECT_EYE] <= 0)
			col[COL_SPECULAR] = new_color3(0, 0, 0);
		else
		{
			dot[DOT_FACTOR] = powf(dot[DOT_REFLECT_EYE], m->shininess);
			col[COL_SPECULAR] = mult_tuple(light->intensity,
					(m->specular * dot[DOT_FACTOR]));
		}
	}
	if (in_shadow == true)
		col[COL_RESULT] = vec[VEC_AMBIENT];
	else
		col[COL_RESULT] = add_tuple(add_tuple(vec[VEC_AMBIENT],
					col[COL_DIFFUSE]), col[COL_SPECULAR]);
	return (col[COL_RESULT]);
}

// t_color3	lighting(t_material *m, t_shape *shape, t_light_p *light,
// 	t_point3 *point, t_vec3 eyev, t_vec3 normalv, bool in_shadow)
// {
// 	t_color3	effective_color;
// 	t_vec3		lightv;
// 	t_vec3		ambient;
// 	float		light_dot_normal;
// 	t_color3	diffuse;
// 	t_color3	specular;
// 	t_vec3		reflectv;
// 	float		reflect_dot_eye;
// 	float		factor;
// 	t_color3	result;

// 	if (m->pattern)
// 		effective_color = mult_color(pattern_at_object(m->pattern, shape, point), light->intensity);
// 	else
// 		effective_color = mult_color(m->color, light->intensity);
// 	if (shape->type == SPHERE)
// 	{
// 		printf("light: ");
// 		print_tuple(light->intensity);
// 		printf("color: ");
// 		print_tuple(m->color);
// 		printf("effective: ");
// 		print_tuple(effective_color);
// 	}
// 	lightv = normalize(sub_tuple_p(&light->position, point));
// 	ambient = mult_tuple(effective_color, m->ambient);
// 	light_dot_normal = dot_product(lightv, normalv);
// 	if (light_dot_normal < 0)
// 	{
// 		diffuse = new_color3(0, 0, 0);
// 		specular = new_color3(0, 0, 0);
// 	}
// 	else
// 	{
// 		diffuse = mult_tuple(effective_color, (m->diffuse * light_dot_normal));
// 		reflectv = reflect(neg_vec3(lightv), normalv);
// 		reflect_dot_eye = dot_product(reflectv, eyev);
// 		if (reflect_dot_eye <= 0)
// 			specular = new_color3(0, 0, 0);
// 		else
// 		{
// 			factor = powf(reflect_dot_eye, m->shininess);
// 			specular = mult_tuple(light->intensity, (m->specular * factor));
// 		}
// 	}
// 	if (in_shadow == true)
// 		result = ambient;
// 	else
// 		result = add_tuple(add_tuple(ambient, diffuse), specular);
// 	return (result);
// }
