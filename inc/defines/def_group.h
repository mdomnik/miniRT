/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_group.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:37:11 by mdomnik           #+#    #+#             */
/*   Updated: 2025/01/17 18:13:28 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_GROUP_H
# define DEF_GROUP_H

void add_child(t_shape *group, t_shape *child);
t_point3 world_to_object(t_shape *shape, t_point3 *point);
t_vec3 normal_to_world(t_shape *shape, t_vec3 *normal);

t_bounds group_bounds(t_shape *shape);
t_bounds transform_bounds(t_bounds bounds, t_matrix *transform);
bool 	intersect_bounds(t_bounds bounds, t_ray *ray);
t_bounds bounds_unit(struct s_shape *shape);
t_bounds bounds_inf(struct s_shape *shape);
t_bounds bounds_cap(struct s_shape *shape);
t_bounds bounds_triangle(struct s_shape *shape);


void inherit_material(t_shape *group);
t_shape *objgroups_to_group(t_group *g);


t_shape *ice_cream_cone(void);
t_shape *hexagon(void);


#endif

