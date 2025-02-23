/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_and_reflect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:52:36 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/23 02:10:46 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

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
	t_color3	effective_color;
	t_vec3		lightv;
	t_vec3		ambient;
	float		light_dot_normal;
	t_color3	diffuse;
	t_color3	specular;
	t_vec3		reflectv;
	float		reflect_dot_eye;
	float		factor;
	t_color3	result;
	t_color3	ambient_product;

	if (m->pattern)
		effective_color = mult_color(pattern_at_object(m->pattern, shape, point), light->intensity);
	else
		effective_color = mult_color(m->color, light->intensity);
	lightv = normalize(sub_tuple_p(&light->position, point));
	ambient_product = mult_color_scalar(global_color('a', (t_color3){0}), m->ambient);
	ambient = mult_tuple(add_tuple(effective_color, ambient_product), m->ambient);
	light_dot_normal = dot_product(lightv, normalv);
	if (light_dot_normal < 0)
	{
		diffuse = new_color3(0, 0, 0);
		specular = new_color3(0, 0, 0);
	}
	else
	{
		diffuse = mult_tuple(effective_color, (m->diffuse * light_dot_normal));
		reflectv = reflect(neg_vec3(lightv), normalv);
		reflect_dot_eye = dot_product(reflectv, eyev);
		if (reflect_dot_eye <= 0)
			specular = new_color3(0, 0, 0);
		else
		{
			factor = powf(reflect_dot_eye, m->shininess);
			specular = mult_tuple(light->intensity, (m->specular * factor));
		}
	}
	if (in_shadow == true)
		result = ambient;
	else
		result = add_tuple(add_tuple(ambient, diffuse), specular);
	return (result);
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
