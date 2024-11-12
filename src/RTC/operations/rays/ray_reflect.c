/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_reflect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 20:33:08 by mdomnik           #+#    #+#             */
/*   Updated: 2024/11/12 18:07:10 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

t_vec3 reflect(t_vec3 in, t_vec3 normal)
{
	float	dot;
	t_vec3	reflect;

	dot = dot_product(in, normal);
	reflect = sub_tuple(in, mult_tuple(normal, 2 * dot));
	return (reflect);
}

t_light_p *new_light(t_point3 *position, t_color3 *intensity)
{
	t_light_p *light;

	light = malloc(sizeof(t_light));
	if (!light)
		return (NULL);
	light->position = position;
	light->intensity = intensity;
	return (light);
}

t_material *default_material()
{
	t_material *material;

	material = malloc(sizeof(t_material));
	material->color = new_color3_p(1, 1, 1);
	material->ambient = 0.1;
	material->diffuse = 0.9;
	material->specular = 0.9;
	material->shininess = 200.0;
	return (material);
}

t_color3 lighting(t_material *m, t_light_p *light, t_point3 *point, t_vec3 eyev, t_vec3 normalv)
{
	t_color3	effective_color;
	t_vec3 		lightv;
	t_vec3 		ambient;
	float	light_dot_normal;
	t_color3	diffuse;
	t_color3	specular;
	t_vec3		reflectv;
	float		reflect_dot_eye;
	float		factor;
	t_color3	result;

	
	effective_color = color_mult(m->color, light->intensity);
	lightv = normalize(sub_tuple_p(light->position, point));
	ambient = mult_tuple(effective_color, m->ambient);
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
			specular = mult_tuple(*light->intensity, (m->specular * factor));
			print_tuple(specular);
		}
	}
	result = (add_tuples(add_tuples(ambient, diffuse), specular));
	return (result);
}

