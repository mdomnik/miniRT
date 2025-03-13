/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_transformation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artem <artem@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:05:26 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/13 20:10:35 by artem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

#define VT_ANGLE_X  0
#define VT_ANGLE_Y  1
#define VT_ANGLE_Z  2
#define VT_RAD_X    0
#define VT_RAD_Y    1
#define VT_RAD_Z    2

inline double	degrees_to_radians(double degrees)
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

static void	calculate_view_vectors(t_vec3 vectors[3], double radians[3])
{
	vectors[0] = new_vec3(0, 0, 1);
	vectors[0] = rotate_x(vectors[0], radians[VT_RAD_X]);
	vectors[0] = rotate_y(vectors[0], radians[VT_RAD_Y]);
	vectors[0] = rotate_z(vectors[0], radians[VT_RAD_Z]);
	vectors[0] = normalize(vectors[0]);
	if (fabs(vectors[0].x) < EPSILON && fabs(vectors[0].z) < EPSILON)
	{
		if (vectors[0].y > 0)
			vectors[1] = new_vec3(0, 0, 1);
		else
			vectors[1] = new_vec3(0, 0, -1);
	}
	else
		vectors[1] = new_vec3(0, 1, 0);
	vectors[2] = normalize(cross_product(vectors[0], vectors[1]));
	vectors[1] = cross_product(vectors[2], vectors[0]);
}

t_matrix	view_transformation(t_point3 from, t_vec3 orientation)
{
	t_matrix	matrices[2];
	t_vec3		vectors[3];
	double		angles[3];
	double		radians[3];

	angles[VT_ANGLE_X] = orientation.x * 180.0;
	angles[VT_ANGLE_Y] = orientation.y * 180.0;
	angles[VT_ANGLE_Z] = orientation.z * 180.0;
	radians[VT_RAD_X] = deg_to_rad(angles[VT_ANGLE_X]);
	radians[VT_RAD_Y] = deg_to_rad(angles[VT_ANGLE_Y]);
	radians[VT_RAD_Z] = deg_to_rad(angles[VT_ANGLE_Z]);
	calculate_view_vectors(vectors, radians);
	matrices[0] = init_identity_matrix(4);
	fill_orientation_matrix(&matrices[0], vectors[2], vectors[1], vectors[0]);
	matrices[1] = translation(-from.x, -from.y, -from.z);
	return (multiply_matrices(matrices[0], matrices[1]));
}
