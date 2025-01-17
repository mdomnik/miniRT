/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 19:55:51 by mdomnik           #+#    #+#             */
/*   Updated: 2025/01/17 19:55:16 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

static void	fill_row(t_matrix *orientation, t_tuple input, int row);

t_matrix	view_transformation(t_point3 from, t_point3 to, t_vec3 up)
{
	t_vec3		forward;
	t_vec3		left;
	t_vec3		true_up;
	t_matrix	orientation;

	forward = normalize(sub_tuple_p(&to, &from));
	left = cross_product(forward, normalize(up));
	true_up = cross_product(left, forward);
	orientation.size = 4;
	orientation = *init_identity_matrix(4);
	fill_row(&orientation, left, 0);
	fill_row(&orientation, true_up, 1);
	fill_row(&orientation, neg_vec3(forward), 2);
	orientation = *multiply_matrices
		(&orientation, translation(-from.x, -from.y, -from.z));
	return (orientation);
}

static void	fill_row(t_matrix *orientation, t_tuple input, int row)
{
	orientation->a[row][0] = input.x;
	orientation->a[row][1] = input.y;
	orientation->a[row][2] = input.z;
}
