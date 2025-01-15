/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_objects.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:52:07 by mdomnik           #+#    #+#             */
/*   Updated: 2025/01/15 22:00:48 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_OBJECTS_H
# define DEF_OBJECTS_H


void 		add_shape(t_shape **shapes, t_shape *new_shape);
void 		add_light(t_light_p **lights, t_light_p *new_light);
void		apply_cap_transformation(t_shape *cone, t_matrix *transform);
t_shape 	*test_shape(void);
t_shape *glass_sphere(void);
t_shape *create_mapped_cube(void);
t_shape *create_texture_cube(void);

t_shape	*sphere(void);
t_shape *plane(void);
t_shape *cube(void);
t_shape *cylinder(void);
t_shape *cone(void);
t_shape *group(void);

#endif
