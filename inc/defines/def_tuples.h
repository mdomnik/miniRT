/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_tuples.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:40:48 by mdomnik           #+#    #+#             */
/*   Updated: 2024/11/11 18:40:19 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_TUPLES_H
# define DEF_TUPLES_H

//operations/tuples/tuples_init.c
t_tuple		*new_tuple_p(float x, float y, float z, float w);
t_point3	*new_point3_p(float x, float y, float z);
t_vec3		*new_vec3_p(float x, float y, float z);

//operations/tuples/tuples_init.c
t_tuple		new_tuple(float x, float y, float z, float w);
t_point3	new_point3(float x, float y, float z);
t_vec3		new_vec3(float x, float y, float z);

//operations/tuples/tuples_ops_1.c
t_tuple		add_tuples(t_tuple a, t_tuple b);
t_tuple		sub_tuple(t_tuple a, t_tuple b);
t_tuple		neg_tuple(t_tuple a);
t_tuple		mult_tuple(t_tuple a, float scalar);

//operations/tuples/tuples_ops_2.c
bool		compare_tuples(t_tuple a, t_tuple b);
t_tuple		div_tuple(t_tuple a, float scalar);
float		magnitude(t_vec3 a);
float		dot_product(t_vec3 a, t_vec3 b);

//operations/tuples/tuples_ops_3.c
t_vec3		neg_vec3(t_vec3 a);
t_vec3		normalize(t_vec3 a);
t_vec3		cross_product(t_vec3 a, t_vec3 b);

#endif
