/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_ops_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 22:15:19 by mdomnik           #+#    #+#             */
/*   Updated: 2025/01/17 21:34:00 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

float	cofactor(t_matrix mat, int row, int col)
{
	float	mnr;
	float	cofactor;

	mnr = minor(mat, row, col);
	if ((row + col) % 2 == 0)
		cofactor = mnr;
	else
		cofactor = -mnr;
	return (cofactor);
}

float	minor(t_matrix mat, int row, int col)
{
	t_matrix	sub;
	float		det;

	sub = submatrix(mat, row, col);
	det = determinant(sub);
	return (det);
}

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

// Function to compare two matrices
bool	compare_matrices(t_matrix mat1, t_matrix mat2)
{
	int	i;
	int	j;

	i = 0;
	while (i < mat1.size)
	{
		j = 0;
		while (j < mat1.size)
		{
			if (!is_equal(mat1.a[i][j], mat2.a[i][j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}
