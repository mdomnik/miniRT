/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_ops_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:30:07 by mdomnik           #+#    #+#             */
/*   Updated: 2024/11/26 16:35:08 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

static float determinant_2x2(t_matrix mat) {
	return (mat.a[0][0] * mat.a[1][1] - mat.a[0][1] * mat.a[1][0]);
}

static float determinant_big(t_matrix mat, int size)
{
	float det = 0;
	int	col;

	col = 0;
	while(col < size)
	{
		det += mat.a[0][col] * cofactor(mat, 0, col);
		col++;
	}
	return det;
}

float determinant(t_matrix mat)
{
	float det;
	if (mat.size == 2)
		det = determinant_2x2(mat);
	else if (mat.size == 3)
		det = determinant_big(mat, 3);
	else if (mat.size == 4)
		det = determinant_big(mat, 4);
	else
	{
		printf("Error: Matrix size not supported\n");
		exit(1);
	}

	return det;
}

static void divide_matrix(t_matrix *mat, float det)
{
	int i;
	int j;

	i = 0;
	while (i < mat->size)
	{
		j = 0;
		while (j < mat->size)
		{
			mat->a[i][j] /= det;
			j++;
		}
		i++;
	}
}

t_matrix *inverse(t_matrix mat)
{
	int i;
	int j;
	t_matrix *result;

	i = 0;
	if (determinant(mat) == 0)
	{
		printf("Error: Matrix is not invertible\n");
		exit(1);
	}
	result = init_identity_matrix(mat.size);
	while(i < mat.size)
	{
		j = 0;
		while (j < mat.size)
		{
			result->a[i][j] = cofactor(mat, i, j);
			j++;
		}
		i++;
	}
	result->size = mat.size;
	result = transpose_matrix(result);
	divide_matrix(result, determinant(mat));
	return result;
}
