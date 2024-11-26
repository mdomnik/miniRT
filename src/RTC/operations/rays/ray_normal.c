/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:19:48 by mdomnik           #+#    #+#             */
/*   Updated: 2024/11/26 16:37:07 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

//normal at
t_vec3	normal_at(t_shape *shape, t_point3 point)
{
	t_point3 local_point;
	t_vec3 local_normal;
	t_vec3 world_normal;
	
	local_point = multiply_matrix_tuple(inverse(shape->transform), &point);
	local_normal = local_normal_at(shape, &local_point);
	world_normal = multiply_matrix_tuple(transpose_matrix(inverse(shape->transform)), &local_normal);
	world_normal.w = 0;
	return (normalize(world_normal));
}

t_vec3	local_normal_at(t_shape *shape, t_point3 *local_point)
{
	t_vec3 local_normal;
	
	local_normal = new_vec3(0, 0, 0);
	if (shape->type == SPHERE)
		local_normal = sub_tuple(*local_point, new_point3(0, 0, 0));
	else if (shape->type == PLANE)
		local_normal = new_vec3(0, 1, 0); //???? maybe weird
	return (local_normal);
}
