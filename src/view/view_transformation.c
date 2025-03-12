/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_transformation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:05:26 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/12 20:53:16 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

t_vec3	rotate_x(t_vec3 v, double angle)
{
	double	cos_a;
	double	sin_a;

	cos_a = cos(angle);
	sin_a = sin(angle);
	return (new_vec3(v.x, v.y * cos_a - v.z
			* sin_a, v.y * sin_a + v.z * cos_a));
}

t_vec3	rotate_y(t_vec3 v, double angle)
{
	double	cos_a;
	double	sin_a;

	cos_a = cos(angle);
	sin_a = sin(angle);
	return (new_vec3(v.x * cos_a + v.z * sin_a, v.y,
			-v.x * sin_a + v.z * cos_a));
}

t_vec3	rotate_z(t_vec3 v, double angle)
{
	double	cos_a;
	double	sin_a;

	cos_a = cos(angle);
	sin_a = sin(angle);
	return (new_vec3(v.x * cos_a - v.y * sin_a,
			v.x * sin_a + v.y * cos_a, v.z));
}

double	degrees_to_radians(double degrees)
{
	return (degrees * M_PI / 180.0);
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

	double angle_x = orientation.x * 180.0;
	double angle_y = orientation.y * 180.0;
	double angle_z = orientation.z * 180.0;

	double rad_x = degrees_to_radians(angle_x);
	double rad_y = degrees_to_radians(angle_y);
	double rad_z = degrees_to_radians(angle_z);

	forward = new_vec3(0, 0, 1);
	forward = rotate_x(forward, rad_x);
	forward = rotate_y(forward, rad_y);
	forward = rotate_z(forward, rad_z);
	forward = normalize(forward);
	if (fabs(forward.x) < EPSILON && fabs(forward.z) < EPSILON)
		up = (forward.y > 0) ? new_vec3(0, 0, 1) : new_vec3(0, 0, -1);
	else
		up = new_vec3(0, 1, 0);
	left = normalize(cross_product(forward, up));
	up = cross_product(left, forward);
	orientation_matrix = init_identity_matrix(4);
	fill_orientation_matrix(&orientation_matrix, left, up, forward);
	translation_matrix = translation(-from.x, -from.y, -from.z);
	return (multiply_matrices(orientation_matrix, translation_matrix));
}
