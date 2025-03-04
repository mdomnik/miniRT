/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   groups.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:58:22 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/19 18:55:24 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GROUPS_H
# define GROUPS_H

//bound_op.c
t_bounds	group_bounds(t_shape *group);
t_bounds	transform_bounds(t_bounds bounds, t_matrix *transform);
bool		intersect_bounds(t_bounds bounds, t_ray *ray);

//bound_types.c
t_bounds	bounds_unit(struct s_shape *shape);
t_bounds	bounds_inf(struct s_shape *shape);
t_bounds	bounds_cap(struct s_shape *shape);
t_bounds	bounds_triangle(struct s_shape *shape);

//group_op.c
void		add_child(t_shape *group, t_shape *child);
void		add_shape_to_group(t_shape *group, t_shape *child);
t_point3	world_to_object(t_shape *shape, t_point3 *point);
t_vec3		normal_to_world(t_shape *shape, t_vec3 *normal);
t_shape		*object_group_to_group(t_group *g);

//inherit.c
void		inherit_material(t_shape *group);

#endif
