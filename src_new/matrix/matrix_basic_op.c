/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_basic_op.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:09:16 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/19 13:21:26 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

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

//multiplies two matrices and returns the result
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

//multiply matrix by a tuple
t_tuple	multiply_matrix_tuple(t_matrix mat, t_tuple tuple)
{
	int		i;
	t_tuple	result;

	i = 0;
	while (i < mat.size)
	{
		result.a[i] = mat.a[i][0] * tuple.x + mat.a[i][1]
			* tuple.y + mat.a[i][2] * tuple.z + mat.a[i][3] * tuple.w;
		i++;
	}
	return (result);
}

// transposes the matrix (rows become columns)
t_matrix	transpose_matrix(t_matrix mat)
{
	int			i;
	int			j;
	t_matrix	result;

	result.size = mat.size;
	i = 0;
	while (i < mat.size)
	{
		j = 0;
		while (j < mat.size)
		{
			result.a[i][j] = mat.a[j][i];
			j++;
		}
		i++;
	}
	return (result);
}