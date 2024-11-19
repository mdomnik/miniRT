/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_objects.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:52:07 by mdomnik           #+#    #+#             */
/*   Updated: 2024/11/19 21:15:05 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_OBJECTS_H
# define DEF_OBJECTS_H


void 		add_shape(t_shape **shapes, t_shape *new_shape);
void 		add_light(t_light_p **lights, t_light_p *new_light);
t_shape 	*test_shape(void);

#endif
