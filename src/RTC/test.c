/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:41:10 by mdomnik           #+#    #+#             */
/*   Updated: 2024/11/13 16:59:35 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"
//print 4x4 matrix
void	print_matrix(t_matrix mat) {
	for (int i = 0; i < mat.size; i++) {
		for (int j = 0; j < mat.size; j++) {
			printf("%f ", mat.a[i][j]);
		}
		printf("\n");
	}
}

//print tuple
void	print_tuple(t_tuple tuple)
{
	printf("x: %f, y: %f, z: %f, w: %f\n", tuple.x, tuple.y, tuple.z, tuple.w);
}
