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

#define LEFT 0
#define FRONT 1
#define RIGHT 2
#define BACK 3
#define UP 4
#define DOWN 5
#define ABS_X 0
#define ABS_Y 1
#define ABS_Z 2
#define COORD 3

t_pattern	*new_cube_map(t_pattern *faces[6])
{
	t_cube_map	*cube;
	t_pattern	*pattern;

	cube = malloc(sizeof(t_cube_map));
	cube->faces[LEFT] = faces[LEFT];
	cube->faces[FRONT] = faces[FRONT];
	cube->faces[RIGHT] = faces[RIGHT];
	cube->faces[BACK] = faces[BACK];
	cube->faces[UP] = faces[UP];
	cube->faces[DOWN] = faces[DOWN];
	pattern = malloc(sizeof(t_pattern));
	pattern->type = CUBE_MAP;
	pattern->uv_pattern = cube;
	pattern->uv_map = NULL;
	pattern->transform = init_identity_matrix(4);
	pattern->a = (t_color3){0};
	pattern->b = (t_color3){0};
	return (pattern);
}

static t_directions	get_direction(t_point3 point, float val[4])
{
	if (val[COORD] == val[ABS_X])
	{
		if (point.x > 0)
			return (RIGHT);
		return (LEFT);
	}
	if (val[COORD] == val[ABS_Y])
	{
		if (point.y > 0)
			return (UP);
		return (DOWN);
	}
	if (val[COORD] == val[ABS_Z])
	{
		if (point.z > 0)
			return (FRONT);
		return (BACK);
	}
	ft_dprintf(2, "Error: Could not determine face from point.\n");
	exit(EXIT_FAILURE);
}

t_directions	face_from_point(t_point3 point)
{
	float	val[4];

	val[ABS_X] = fabs(point.x);
	val[ABS_Y] = fabs(point.y);
	val[ABS_Z] = fabs(point.z);
	val[COORD] = fmax(fmax(val[ABS_X], val[ABS_Y]), val[ABS_Z]);
	return (get_direction(point, val));
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
