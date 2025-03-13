/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_and_reflect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:52:36 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/13 21:12:06 by mdomnik          ###   ########.fr       */
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

t_color3	get_effective_color(t_lighting l)
{
	if (l.m->pattern)
	{
		if (l.shape->type != SKYBOX)
			return mult_color(pattern_at_object(l.m->pattern, l.shape, l.point),
					l.light->intensity);
		else
			return pattern_at_object(l.m->pattern, l.shape, l.point);
	}
	else if (is_near_zero(l.light->intensity))
		return mult_color_scalar(l.m->color, l.m->ambient);
	return mult_color(l.m->color, l.light->intensity);
}

t_color3	get_ambient_component(t_lighting l, t_color3 effective_color)
{
	t_color3 ambient_prod;
	t_color3 ambient;

	if (l.shape->type != SKYBOX)
	{
		ambient_prod = mult_color_scalar(global_color('a', (t_color3){0}),
				l.m->ambient);
		ambient = mult_tuple(add_tuple(effective_color, ambient_prod),
				l.m->ambient);
	}
	else
	{
		if (!l.m->pattern)
			effective_color = l.m->color;
		ambient = mult_tuple(effective_color, l.m->ambient);
	}
	return ambient;
}

void	calculate_diffuse_specular(t_lighting l, t_vec3 *vec,
			t_color3 *col, float *dot)
{
	if (dot[DOT_LIGHT_NORMAL] < 0)
	{
		col[COL_DIFFUSE] = new_color3(0, 0, 0);
		col[COL_SPECULAR] = new_color3(0, 0, 0);
	}
	else
	{
		col[COL_DIFFUSE] = mult_tuple(col[COL_EFFECTIVE],
				(l.m->diffuse * dot[DOT_LIGHT_NORMAL]));
		vec[VEC_REFLECT] = reflect(neg_vec3(vec[VEC_LIGHT]), l.normalv);
		dot[DOT_REFLECT_EYE] = dot_product(vec[VEC_REFLECT], l.eyev);
		if (dot[DOT_REFLECT_EYE] <= 0)
			col[COL_SPECULAR] = new_color3(0, 0, 0);
		else
		{
			dot[DOT_FACTOR] = powf(dot[DOT_REFLECT_EYE], l.m->shininess);
			col[COL_SPECULAR] = mult_tuple(l.light->intensity,
					(l.m->specular * dot[DOT_FACTOR]));
		}
	}
}

t_color3	lighting(t_lighting l)
{
	t_vec3		vec[VEC_COUNT];
	t_color3	col[COL_COUNT];
	float		dot[DOT_COUNT];

	col[COL_EFFECTIVE] = get_effective_color(l);
	vec[VEC_LIGHT] = normalize(sub_tuple_p(&l.light->position, l.point));
	vec[VEC_AMBIENT] = get_ambient_component(l, col[COL_EFFECTIVE]);
	dot[DOT_LIGHT_NORMAL] = dot_product(vec[VEC_LIGHT], l.normalv);
	calculate_diffuse_specular(l, vec, col, dot);
	if (l.in_shadow == true)
		col[COL_RESULT] = vec[VEC_AMBIENT];
	else
		col[COL_RESULT] = add_tuple(add_tuple(vec[VEC_AMBIENT],
					col[COL_DIFFUSE]), col[COL_SPECULAR]);
	return (col[COL_RESULT]);
}
