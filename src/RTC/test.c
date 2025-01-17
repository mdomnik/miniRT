/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:41:10 by mdomnik           #+#    #+#             */
/*   Updated: 2025/01/17 22:49:49 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"
//print 4x4 matrix
void	print_matrix(t_matrix mat)
{
	int	i;
	int	j;

	i = 0;
	while (i < mat.size)
	{
		j = 0;
		while (j < mat.size)
		{
			printf("%f ", mat.a[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

//print tuple
void	print_tuple(t_tuple tuple)
{
	printf("x: %f, y: %f, z: %f, w: %f\n", tuple.x, tuple.y, tuple.z, tuple.w);
}
