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

//inverts the matrix
t_matrix	inverse(t_matrix mat)
{
	t_matrix	result;

	result.size = mat.size;
	if (invert_matrix(&mat, &result))
		return (result);
	else
	{
		printf("Error: Matrix is not invertible\n");
		exit(1);
	}
	return (result);
}
