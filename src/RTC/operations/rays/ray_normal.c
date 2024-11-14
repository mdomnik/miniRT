/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:19:48 by mdomnik           #+#    #+#             */
/*   Updated: 2024/11/13 18:44:50 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

static t_vec3 normal_at_sphere(t_sphere *sphere, t_point3 *world_point);

//normal at
t_vec3	normal_at(t_object *object, t_point3 point)
{
	if (object->type == SPHERE)
	{
		return(normal_at_sphere((t_sphere *)object->object, &point));
	}
	return (new_vec3(0, 0, 0));
}

//normal at sphere
t_vec3 normal_at_sphere(t_sphere *sphere, t_point3 *world_point)
{
	t_point3 object_point;
	t_vec3 object_normal;
	t_vec3 world_normal;
	
	object_point = multiply_matrix_tuple(inverse(sphere->transform), world_point);
	object_normal = sub_tuple(object_point, new_point3(0, 0, 0));
	world_normal = multiply_matrix_tuple(transpose_matrix(inverse(sphere->transform)), &object_normal);
	world_normal.w = 0;
	return (normalize(world_normal));
}
