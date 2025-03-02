/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_transformation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:05:26 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/23 18:59:31 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

// static void	fill_row(t_matrix *orientation, t_tuple input, int row)
// {
// 	orientation->a[row][0] = input.x;
// 	orientation->a[row][1] = input.y;
// 	orientation->a[row][2] = input.z;
// }

static void	set_vertical_up(t_vec3 *up, float y_val)
{
	if (y_val > 0)
		*up = new_vec3(0, 0, 1);
	else
		*up = new_vec3(0, 0, -1);
}

static void	fill_orientation_matrix(t_matrix *m, t_vec3 l, t_vec3 u, t_vec3 f)
{
	m->a[0][0] = l.x;
	m->a[0][1] = l.y;
	m->a[0][2] = l.z;
	m->a[1][0] = u.x;
	m->a[1][1] = u.y;
	m->a[1][2] = u.z;
	m->a[2][0] = -f.x;
	m->a[2][1] = -f.y;
	m->a[2][2] = -f.z;
}

t_matrix	view_transformation(t_point3 from, t_vec3 orientation)
{
	t_matrix	orientation_matrix;
	t_matrix	translation_matrix;
	t_vec3		forward;
	t_vec3		up;
	t_vec3		left;

	if (fabs(orientation.x) < 0.0001 && fabs(orientation.y) < 0.0001
		&& fabs(orientation.z) < 0.0001)
		orientation = new_vec3(0, 0, 1);
	forward = normalize(orientation);
	up = new_vec3(0, 1, 0);
	if (fabs(forward.x) < 0.0001 && fabs(forward.z) < 0.0001)
		set_vertical_up(&up, forward.y);
	left = normalize(cross_product(forward, up));
	up = cross_product(left, forward);
	orientation_matrix = init_identity_matrix(4);
	fill_orientation_matrix(&orientation_matrix, left, up, forward);
	translation_matrix = translation(-from.x, -from.y, -from.z);
	return (multiply_matrices(orientation_matrix, translation_matrix));
}
