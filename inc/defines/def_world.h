/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_world.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:40:41 by mdomnik           #+#    #+#             */
/*   Updated: 2024/11/13 14:50:03 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_WORLD_H
# define DEF_WORLD_H

//operations/world/create.c
t_world *create_world(t_object *objects, t_light_p *light);
t_x		*intersect_world(t_world *world, t_ray *ray);

#endif
