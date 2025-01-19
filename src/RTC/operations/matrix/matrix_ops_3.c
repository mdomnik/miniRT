/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_ops_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:30:07 by mdomnik           #+#    #+#             */
/*   Updated: 2025/01/17 21:35:28 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

#define abs(x) ((x) < 0 ? -(x) : (x))

static float	determinant_2x2(t_matrix mat)
{
	return (mat.a[0][0] * mat.a[1][1] - mat.a[0][1] * mat.a[1][0]);
}

static float	determinant_big(t_matrix mat, int size)
{
	float	det;
	int		col;

	det = 0;
	col = 0;
	while (col < size)
	{
		det += mat.a[0][col] * cofactor(mat, 0, col);
		col++;
	}
	return (det);
}

float	determinant(t_matrix mat)
{
	float	det;

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
	return (det);
}

// static void	divide_matrix(t_matrix *mat, float det)
// {
	// int	i;
	// int	j;

	// i = 0;
	// while (i < mat->size)
	// {
		// j = 0;
		// while (j < mat->size)
		// {
			// mat->a[i][j] /= det;
			// j++;
		// }
		// i++;
	// }
// }

#define N 4
// static int is_invertible(t_matrix *mtx) {
// 	// Create a copy of the matrix
// 	t_matrix	M;
// 	memcpy(&M, mtx, sizeof(M));
// 
// 	// For each diagonal element (pivot)
// 	for (int i = 0; i < N; i++) {
// 		// If pivot is zero, try to swap with a non-zero row
// 		if (abs(M.a[i][i]) < EPSILON) {
// 			int found_nonzero = 0;
// 			// Look for non-zero element in the same column
// 			for (int j = i + 1; j < N; j++) {
// 				if (abs(M.a[j][i]) > EPSILON) {
// 					// Swap rows
// 					for (int k = 0; k < N; k++) {
// 						double temp = M.a[i][k];
// 						M.a[i][k] = M.a[j][k];
// 						M.a[j][k] = temp;
// 					}
// 					found_nonzero = 1;
// 					break;
// 				}
// 			}
// 			// If no non-zero element found, matrix is not invertible
// 			if (!found_nonzero) {
// 				return 0;
// 			}
// 		}
// 
// 		// Eliminate column entries below pivot
// 		for (int j = i + 1; j < N; j++) {
// 			double factor = M.a[j][i] / M.a[i][i];
// 			for (int k = i; k < N; k++) {
// 				M.a[j][k] -= factor * M.a[i][k];
// 			}
// 		}
// 	}
// 
// 	// Check if any diagonal element is zero
// 	for (int i = 0; i < N; i++) {
// 		if (abs(M.a[i][i]) < EPSILON) {
// 			return 0;
// 		}
// 	}
// 
// 	return 1;
// }

static int invert_matrix(t_matrix *input, t_matrix *output) {
	// Initialize augmented matrix [A|I]
	double aug[N][2*N];

	// Fill the augmented matrix
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			aug[i][j] = input->a[i][j];
			// Fill identity matrix in right half
			aug[i][j+N] = (i == j) ? 1.0 : 0.0;
		}
	}

	// Perform Gauss-Jordan elimination
	for (int i = 0; i < N; i++) {
		// Find pivot
		int max_row = i;
		double max_val = fabs(aug[i][i]);

		for (int j = i + 1; j < N; j++) {
			if (fabs(aug[j][i]) > max_val) {
				max_val = fabs(aug[j][i]);
				max_row = j;
			}
		}

		// Check if matrix is invertible
		if (max_val < EPSILON) {
			return 0;  // Not invertible
		}

		// Swap rows if necessary
		if (max_row != i) {
			for (int j = 0; j < 2*N; j++) {
				double temp = aug[i][j];
				aug[i][j] = aug[max_row][j];
				aug[max_row][j] = temp;
			}
		}

		// Scale pivot row
		double pivot = aug[i][i];
		for (int j = 0; j < 2*N; j++) {
			aug[i][j] /= pivot;
		}

		// Eliminate column
		for (int j = 0; j < N; j++) {
			if (j != i) {
				double factor = aug[j][i];
				for (int k = 0; k < 2*N; k++) {
					aug[j][k] -= factor * aug[i][k];
				}
			}
		}
	}

	// Copy result to output matrix
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			output->a[i][j] = aug[i][j+N];
		}
	}

	return 1;  // Successfully inverted
}


t_matrix	inverse(t_matrix mat)
{
	// int			i;
	// int			j;
	t_matrix	result;

	result.size = mat.size;
	if (invert_matrix(&mat, &result)) {
		return result;
	} else {
		printf("Error: Matrix is not invertible\n");
		exit(1);
	}
	// i = 0;
	// if (!is_invertible(&mat))
	// {
		// printf("Error: Matrix is not invertible\n");
		// exit(1);
	// }
	// while (i < mat.size)
	// {
		// j = 0;
		// while (j < mat.size)
		// {
			// result.a[i][j] = cofactor(mat, i, j);
			// j++;
		// }
		// i++;
	// }
	// result.size = mat.size;
	// result = transpose_matrix(result);
	// divide_matrix(&result, determinant(mat));
	return (result);
}
