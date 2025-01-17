/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_ops_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 20:41:37 by mdomnik           #+#    #+#             */
/*   Updated: 2025/01/17 21:31:57 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

t_matrix	*multiply_matrices(t_matrix *mat1, t_matrix *mat2)
{
	int			i;
	int			j;
	int			k;
	t_matrix	*result;

	i = 0;
	result = malloc(sizeof(t_matrix));
	while (i < mat1->size)
	{
		j = 0;
		while (j < mat1->size)
		{
			result->a[i][j] = 0;
			k = 0;
			while (k < mat1->size)
			{
				result->a[i][j] += mat1->a[i][k] * mat2->a[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
	result->size = mat1->size;
	return (result);
}

//multiply 4x4 matrix by tuple
t_tuple	multiply_matrix_tuple(t_matrix *mat, t_tuple *tuple)
{
	int		i;
	t_tuple	result;

	i = 0;
	while (i < mat->size)
	{
		result.a[i] = mat->a[i][0] * tuple->x + mat->a[i][1]
			* tuple->y + mat->a[i][2] * tuple->z + mat->a[i][3] * tuple->w;
		i++;
	}
	return (result);
}

//init identity matrix
t_matrix	*init_identity_matrix(int size)
{
	int			i;
	int			j;
	t_matrix	*result;

	i = 0;
	result = malloc(sizeof(t_matrix));
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (i == j)
				result->a[i][j] = 1;
			else
				result->a[i][j] = 0;
			j++;
		}
		i++;
	}
	result->size = size;
	return (result);
}

t_matrix	submatrix(t_matrix mat, int ex_row, int ex_col)
{
	int			row;
	int			col;
	int			r_idx;
	int			c_idx;
	t_matrix	result;

	row = 0;
	r_idx = 0;
	if (ex_row < 0 || ex_row >= mat.size || ex_col < 0 || ex_col >= mat.size)
	{
		printf("Error: Invalid row or column index\n");
		exit(1);
	}
	while (row < mat.size)
	{
		if (row == ex_row)
		{
			row++;
			continue ;
		}
		col = 0;
		c_idx = 0;
		while (col < mat.size)
		{
			if (col == ex_col)
			{
				col++;
				continue ;
			}
			result.a[r_idx][c_idx] = mat.a[row][col];
			c_idx++;
			col++;
		}
		r_idx++;
		row++;
	}
	result.size = mat.size - 1;
	return (result);
}
