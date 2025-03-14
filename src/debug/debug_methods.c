/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_methods.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:27:27 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/14 00:32:06 by mdomnik          ###   ########.fr       */
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

int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}
