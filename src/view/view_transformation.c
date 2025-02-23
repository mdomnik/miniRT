/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_transformation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:05:26 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/22 21:42:11 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

// static void	fill_row(t_matrix *orientation, t_tuple input, int row)
// {
// 	orientation->a[row][0] = input.x;
// 	orientation->a[row][1] = input.y;
// 	orientation->a[row][2] = input.z;
// }

t_matrix view_transformation(t_point3 from, t_vec3 orientation)
{
	if (fabs(orientation.x) < EPSILON && fabs(orientation.y) < EPSILON && fabs(orientation.z) < EPSILON)
		orientation = new_vec3(0, 0, 1);
	t_vec3 forward = normalize(orientation);
	t_vec3 up = new_vec3(0, 1, 0);
	if (fabs(forward.x) < EPSILON && fabs(forward.z) < EPSILON)
		up = new_vec3(0, 0, (forward.y > 0) ? 1 : -1);
	t_vec3 left = normalize(cross_product(up, forward));
	t_vec3 true_up = cross_product(forward, left);
	t_matrix orientation_matrix = init_identity_matrix(4);

	orientation_matrix.a[0][0] = left.x;
	orientation_matrix.a[0][1] = left.y;
	orientation_matrix.a[0][2] = left.z;
		
	orientation_matrix.a[1][0] = true_up.x;
	orientation_matrix.a[1][1] = true_up.y;
	orientation_matrix.a[1][2] = true_up.z;
		
	orientation_matrix.a[2][0] = -forward.x;
	orientation_matrix.a[2][1] = -forward.y;
	orientation_matrix.a[2][2] = -forward.z;

	t_matrix translation_matrix = translation(-from.x, -from.y, -from.z);

	return multiply_matrices(orientation_matrix, translation_matrix);
}


