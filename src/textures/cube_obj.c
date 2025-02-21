/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:27:27 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/21 18:09:11 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

t_pattern	*new_cube_map(t_pattern *left, t_pattern *front, t_pattern *right,
	t_pattern *back, t_pattern *up, t_pattern *down)
{
t_cube_map	*cube;
t_pattern	*pattern;

cube = malloc(sizeof(t_cube_map));
cube->faces[LEFT] = left;
cube->faces[FRONT] = front;
cube->faces[RIGHT] = right;
cube->faces[BACK] = back;
cube->faces[UP] = up;
cube->faces[DOWN] = down;
pattern = malloc(sizeof(t_pattern));
pattern->type = CUBE_MAP;
pattern->uv_pattern = cube;
pattern->uv_map = NULL;
pattern->transform = init_identity_matrix(4);
pattern->a = (t_color3){0};
pattern->b = (t_color3){0};
return (pattern);
}

t_directions	face_from_point(t_point3 point)
{
	float	abs_x;
	float	abs_y;
	float	abs_z;
	float	coord;

	abs_x = fabs(point.x);
	abs_y = fabs(point.y);
	abs_z = fabs(point.z);
	coord = fmax(fmax(abs_x, abs_y), abs_z);
	if (coord == abs_x)
	{
		if (point.x > 0)
			return (RIGHT);
		return (LEFT);
	}
	if (coord == abs_y)
	{
		if (point.y > 0)
			return (UP);
		return (DOWN);
	}
	if (coord == abs_z)
	{
		if (point.z > 0)
			return (FRONT);
		return (BACK);
	}
	ft_dprintf(2, "Error: Could not determine face from point.\n");
	exit(EXIT_FAILURE);
}

t_color3	pattern_at_cube_map(t_pattern *pattern, t_point3 point)
{
	t_cube_map		*cube;
	t_directions	face;
	t_uv_val		uv;
	t_pattern		*face_pattern;
	t_color3		color;

	cube = (t_cube_map *)pattern->uv_pattern;
	face = face_from_point(point);
	if (face == LEFT)
		uv = cube_uv_left(point);
	else if (face == FRONT)
		uv = cube_uv_front(point);
	else if (face == RIGHT)
		uv = cube_uv_right(point);
	else if (face == BACK)
		uv = cube_uv_back(point);
	else if (face == UP)
		uv = cube_uv_up(point);
	else
		uv = cube_uv_down(point);
	face_pattern = cube->faces[face];
	color = uv_pattern_at_image(face_pattern->uv_pattern, uv.u, uv.v);
	return (color);
}
