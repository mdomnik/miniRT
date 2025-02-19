/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:45:01 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/19 14:50:59 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLE_H
# define TUPLE_H

//tuple_basic_op.c
t_tuple		add_tuple(t_tuple a, t_tuple b);
t_tuple		sub_tuple(t_tuple a, t_tuple b);
t_tuple		mult_tuple(t_tuple a, float scalar);
t_tuple		div_tuple(t_tuple a, float scalar);
t_tuple		neg_tuple(t_tuple a);

//tuple_color.c
t_color3	mult_color(t_color3 a, t_color3 b);
t_color3	sub_color(t_tuple a, t_tuple b);
t_color3	mult_color_scalar(t_color3 a, float scalar);
t_tuple		sub_tuple_p(t_tuple *a, t_tuple *b); //replace

//tuple_init.c
t_tuple		new_tuple(float x, float y, float z, float w);
t_point3	new_point3(float x, float y, float z);
t_vec3		new_vec3(float x, float y, float z);
t_color3	new_color3(float r, float g, float b);

//tuple_product_op.c
float		magnitude(t_vec3 a);
float		dot_product(t_vec3 a, t_vec3 b);
t_vec3		cross_product(t_vec3 a, t_vec3 b);
t_vec3		normalize(t_vec3 a);
t_vec3		neg_vec3(t_vec3 a);

#endif
