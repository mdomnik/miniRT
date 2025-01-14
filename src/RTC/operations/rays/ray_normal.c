/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:19:48 by mdomnik           #+#    #+#             */
/*   Updated: 2024/12/03 22:50:51 by mdomnik          ###   ########.fr       */
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

static t_vec3 cube_normal_at(t_point3 *local_point)
{
	float maxc;
	
	maxc = fmaxf(fabsf(local_point->x), fmaxf(fabsf(local_point->y), fabsf(local_point->z)));
	if (maxc == fabsf(local_point->x))
		return (new_vec3(local_point->x, 0, 0));
	else if (maxc == fabsf(local_point->y))
		return (new_vec3(0, local_point->y, 0));
	return (new_vec3(0, 0, local_point->z));
}

static t_vec3 cyl_normal_at(t_point3 *local_point)
{
	float dist;
	
	dist = local_point->x * local_point->x + local_point->z * local_point->z;
	if (dist < 1 && local_point->y >= CYL_MAX - EPSILON)
		return (new_vec3(0, 1, 0));
	else if (dist < 1 && local_point->y <= CYL_MIN + EPSILON)
		return (new_vec3(0, -1, 0));
	else
		return (new_vec3(local_point->x, 0, local_point->z));
}

static t_vec3 cone_normal_at(t_point3 *local_point)
{
	float dist;
	float y;
	
	dist = local_point->x * local_point->x + local_point->z * local_point->z;
	y = sqrt(dist);
	if (local_point->y > 0)
		y = -y;
	if (dist < 1 && local_point->y >= CONE_MAX - EPSILON)
		return (new_vec3(0, 1, 0));
	else if (dist < 1 && local_point->y <= CONE_MIN + EPSILON)
		return (new_vec3(0, -1, 0));
	else
		return (new_vec3(local_point->x, y, local_point->z));
}

t_vec3	local_normal_at(t_shape *shape, t_point3 *local_point)
{
	t_vec3 local_normal;
	
	local_normal = new_vec3(0, 0, 0);
	if (shape->type == SPHERE)
		local_normal = sub_tuple(*local_point, new_point3(0, 0, 0));
	else if (shape->type == PLANE)
		local_normal = new_vec3(0, 1, 0); //???? maybe weird
	else if (shape->type == CUBE)
		local_normal = cube_normal_at(local_point);
	else if (shape->type == CYLINDER)
		local_normal = cyl_normal_at(local_point);
	else if (shape->type == CONE)
		local_normal = cone_normal_at(local_point);
	return (local_normal);
}
