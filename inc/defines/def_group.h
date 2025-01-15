/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_group.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:37:11 by mdomnik           #+#    #+#             */
/*   Updated: 2025/01/15 18:36:41 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_GROUP_H
# define DEF_GROUP_H

void add_child(t_shape *group, t_shape *child);
t_point3 world_to_object(t_shape *shape, t_point3 *point);
t_vec3 normal_to_world(t_shape *shape, t_vec3 *normal);


t_shape *ice_cream_cone(void);

#endif

