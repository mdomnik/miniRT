/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_world.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:40:41 by mdomnik           #+#    #+#             */
/*   Updated: 2024/11/16 20:26:16 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_WORLD_H
# define DEF_WORLD_H

//operations/world/create.c
t_world *create_world(t_object *objects, t_light_p *light);
t_x		*intersect_world(t_world *world, t_ray *ray);
t_comp *prepare_computations(t_i *i, t_ray *ray);
t_color3 shade_hit(t_world *world, t_comp *comps);
t_color3 color_at(t_world *world, t_ray *ray);
t_matrix view_transformation(t_point3 from, t_point3 to, t_vec3 up);

#endif
