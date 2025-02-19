/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_ops_inverse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:30:07 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/19 13:22:20 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

#define abs(x) ((x) < 0 ? -(x) : (x))

#define N 4
static int invert_matrix(t_matrix *input, t_matrix *output)
{
	double aug[N][2*N];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			aug[i][j] = input->a[i][j];
			aug[i][j+N] = (i == j) ? 1.0 : 0.0;
		}
	}

	for (int i = 0; i < N; i++) {
		int max_row = i;
		double max_val = fabs(aug[i][i]);

		for (int j = i + 1; j < N; j++) {
			if (fabs(aug[j][i]) > max_val) {
				max_val = fabs(aug[j][i]);
				max_row = j;
			}
		}

		if (max_val < EPSILON) {
			return 0;
		}

		if (max_row != i) {
			for (int j = 0; j < 2*N; j++) {
				double temp = aug[i][j];
				aug[i][j] = aug[max_row][j];
				aug[max_row][j] = temp;
			}
		}

		double pivot = aug[i][i];
		for (int j = 0; j < 2*N; j++) {
			aug[i][j] /= pivot;
		}

		for (int j = 0; j < N; j++) {
			if (j != i) {
				double factor = aug[j][i];
				for (int k = 0; k < 2*N; k++) {
					aug[j][k] -= factor * aug[i][k];
				}
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			output->a[i][j] = aug[i][j+N];
		}
	}

	return 1;
}

//inverts the matrix
t_matrix	inverse(t_matrix mat)
{
	t_matrix	result;

	result.size = mat.size;
	if (invert_matrix(&mat, &result))
		return result;
	else
	{
		printf("Error: Matrix is not invertible\n");
		exit(1);
	}
	return (result);
}
