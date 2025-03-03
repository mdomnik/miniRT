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

#define N 4

#define IDX_I 0
#define IDX_J 1
#define IDX_K 2
#define IDX_MAX_ROW 3
#define ITER_COUNT 4

#define VAL_MAX 0
#define VAL_TEMP 1
#define VAL_PIVOT 2
#define VAL_FACTOR 3
#define VAL_COUNT 4

static void	init_augmented(t_matrix *input, double aug[N][2 *N],
		int idx[ITER_COUNT])
{
	idx[IDX_I] = 0;
	while (idx[IDX_I] < N)
	{
		idx[IDX_J] = 0;
		while (idx[IDX_J] < N)
		{
			aug[idx[IDX_I]][idx[IDX_J]] = input->a[idx[IDX_I]][idx[IDX_J]];
			if (idx[IDX_I] == idx[IDX_J])
				aug[idx[IDX_I]][idx[IDX_J] + N] = 1.0;
			else
				aug[idx[IDX_I]][idx[IDX_J] + N] = 0.0;
			idx[IDX_J]++;
		}
		idx[IDX_I]++;
	}
}

static int	find_pivot(double aug[N][2 *N], int idx[ITER_COUNT],
		double val[VAL_COUNT])
{
	idx[IDX_MAX_ROW] = idx[IDX_I];
	val[VAL_MAX] = fabs(aug[idx[IDX_I]][idx[IDX_I]]);
	idx[IDX_J] = idx[IDX_I] + 1;
	while (idx[IDX_J] < N)
	{
		if (fabs(aug[idx[IDX_J]][idx[IDX_I]]) > val[VAL_MAX])
		{
			val[VAL_MAX] = fabs(aug[idx[IDX_J]][idx[IDX_I]]);
			idx[IDX_MAX_ROW] = idx[IDX_J];
		}
		idx[IDX_J]++;
	}
	if (val[VAL_MAX] < EPSILON)
		return (0);
	return (1);
}

static void	swap_and_normalize(double aug[N][2 *N], int idx[ITER_COUNT],
		double val[VAL_COUNT])
{
	if (idx[IDX_MAX_ROW] != idx[IDX_I])
	{
		idx[IDX_J] = 0;
		while (idx[IDX_J] < 2 * N)
		{
			val[VAL_TEMP] = aug[idx[IDX_I]][idx[IDX_J]];
			aug[idx[IDX_I]][idx[IDX_J]] = aug[idx[IDX_MAX_ROW]][idx[IDX_J]];
			aug[idx[IDX_MAX_ROW]][idx[IDX_J]] = val[VAL_TEMP];
			idx[IDX_J]++;
		}
	}
	val[VAL_PIVOT] = aug[idx[IDX_I]][idx[IDX_I]];
	idx[IDX_J] = 0;
	while (idx[IDX_J] < 2 * N)
	{
		aug[idx[IDX_I]][idx[IDX_J]] /= val[VAL_PIVOT];
		idx[IDX_J]++;
	}
}

static void	eliminate_column(double aug[N][2 *N], int idx[ITER_COUNT],
		double val[VAL_COUNT])
{
	idx[IDX_J] = 0;
	while (idx[IDX_J] < N)
	{
		if (idx[IDX_J] != idx[IDX_I])
		{
			val[VAL_FACTOR] = aug[idx[IDX_J]][idx[IDX_I]];
			idx[IDX_K] = 0;
			while (idx[IDX_K] < 2 * N)
			{
				aug[idx[IDX_J]][idx[IDX_K]] -= val[VAL_FACTOR]
					* aug[idx[IDX_I]][idx[IDX_K]];
				idx[IDX_K]++;
			}
		}
		idx[IDX_J]++;
	}
}

int	invert_matrix(t_matrix *input, t_matrix *output)
{
	double	aug[N][2 * N];
	int		idx[ITER_COUNT];
	double	val[VAL_COUNT];

	init_augmented(input, aug, idx);
	idx[IDX_I] = 0;
	while (idx[IDX_I] < N)
	{
		if (!find_pivot(aug, idx, val))
			return (0);
		swap_and_normalize(aug, idx, val);
		eliminate_column(aug, idx, val);
		idx[IDX_I]++;
	}
	idx[IDX_I] = 0;
	while (idx[IDX_I] < N)
	{
		idx[IDX_J] = -1;
		while (++idx[IDX_J] < N)
			output->a[idx[IDX_I]][idx[IDX_J]]
				= aug[idx[IDX_I]][idx[IDX_J] + N];
		idx[IDX_I]++;
	}
	return (1);
}
