/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:38:49 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/21 18:41:11 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

//matrix_basic_op.c
t_matrix	init_identity_matrix(int size);
t_matrix	*init_identity_matrix_p(int size);
t_matrix	multiply_matrices(t_matrix mat1, t_matrix mat2);
t_tuple		multiply_matrix_tuple(t_matrix mat, t_tuple tuple);
t_matrix	transpose_matrix(t_matrix mat);

//matrix_basic_transform.c
t_matrix	translation(float x, float y, float z);
t_matrix	scaling(float x, float y, float z);
t_matrix	rotation_x(float rad);
t_matrix	rotation_y(float rad);
t_matrix	rotation_z(float rad);

//matrix_inverse.c
t_matrix	inverse(t_matrix mat);

//matrix_shear_transform.c
t_matrix	shearing_x(float y, float z);
t_matrix	shearing_y(float x, float z);
t_matrix	shearing_z(float x, float y);
void		set_transform(t_shape *shape, t_matrix new_transform);

#endif
