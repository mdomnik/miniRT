/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:02:16 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/24 16:47:02 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITIALIZE_H
# define INITIALIZE_H

//init_basic_obj.c
t_shape		*sphere(void);
t_shape		*plane(void);
t_shape		*cylinder(void);
t_light_p	*light(t_point3 position, t_color3 intensity);

//init_complex_obj.c
t_shape		*cube(void);
t_shape		*cone(void);
t_shape		*hourglass(void);
t_shape		*triangle(t_point3 p1, t_point3 p2, t_point3 p3);
t_shape		*group(void);

//init_else.c
t_material	default_material(void);
t_size_cap	default_size_cap(void);

//struct_op.c
void		add_light(t_light_p **lights, t_light_p *new_light);
void		add_shape(t_shape **shapes, t_shape *new_shape);
t_triangle	*triangle_new(t_point3 p1, t_point3 p2, t_point3 p3);

#endif
