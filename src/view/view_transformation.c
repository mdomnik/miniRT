/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_transformation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:05:26 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/21 18:30:35 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

static void	fill_row(t_matrix *orientation, t_tuple input, int row)
{
	orientation->a[row][0] = input.x;
	orientation->a[row][1] = input.y;
	orientation->a[row][2] = input.z;
}

t_matrix view_transformation(t_point3 from, t_point3 to, t_vec3 up)
{
	t_vec3 forward;
	t_vec3 upn;
	t_vec3 left;
	t_vec3 true_up;
	t_matrix orientation;
	t_matrix *translation_matrix;
	
	// to = new_point3((from.x + to.x),(from.y + to.y), (from.z + to.z));
	forward = normalize(sub_tuple_p(&to, &from));
	upn = normalize(up);
	left = cross_product(forward, upn);
	if (magnitude(left) < EPSILON)
	{
		upn = normalize(new_vec3(1, 0, 0));
		left = cross_product(forward, upn);
	}
	true_up = cross_product(left, forward);
	orientation = init_identity_matrix(4);
	fill_row(&orientation, left, 0);
	fill_row(&orientation, true_up, 1);
	fill_row(&orientation, neg_vec3(forward), 2);
	translation_matrix = translation(-from.x, -from.y, -from.z);
	return (*multiply_matrices(&orientation, translation_matrix));
}
