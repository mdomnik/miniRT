/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_matrix.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:42:27 by mdomnik           #+#    #+#             */
/*   Updated: 2025/01/19 20:24:25 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_MATRIX_H
# define DEF_MATRIX_H

//operations/matrix/matrix_ops_1.c
t_matrix	*multiply_matrices(t_matrix *mat1, t_matrix *mat2);
t_tuple		multiply_matrix_tuple(t_matrix mat, t_tuple tuple);
t_matrix	*init_identity_matrix(int size);
t_matrix	submatrix(t_matrix mat, int ex_row, int ex_col);

//operations/matrix/matrix_ops_2.c
float		cofactor(t_matrix mat, int row, int col);
float		minor(t_matrix mat, int row, int col);
t_matrix	transpose_matrix(t_matrix mat);
bool		compare_matrices(t_matrix mat1, t_matrix mat2);

//operations/matrix/matrix_ops_3.c
float		determinant(t_matrix mat);
t_matrix	inverse(t_matrix mat);

//operations/matrix/matrix_transform_1.c
t_matrix	*translation(float x, float y, float z);
t_matrix	*scaling(float x, float y, float z);
t_matrix	*rotation_x(float rad);
t_matrix	*rotation_y(float rad);
t_matrix	*rotation_z(float rad);

//operations/matrix/matrix_transform_2.c
t_matrix	*shearing_x(float y, float z);
t_matrix	*shearing_y(float x, float z);
t_matrix	*shearing_z(float x, float y);
void		set_transform(t_shape *shape, t_matrix *new_transform);

#endif
