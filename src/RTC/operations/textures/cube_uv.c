/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_uv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:08:26 by mdomnik           #+#    #+#             */
/*   Updated: 2025/01/14 21:16:41 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

t_directions face_from_point(t_point3 point)
{
	float abs_x = fabs(point.x);
	float abs_y = fabs(point.y);
	float abs_z = fabs(point.z);
	float coord = fmax(fmax(abs_x, abs_y), abs_z);

	if (coord == abs_x)
	{
		if (point.x > 0)	
			return RIGHT;
		return LEFT;
	}
	if (coord == abs_y)
	{
		if (point.y > 0)
			return UP;
		return DOWN;
	}
	if (coord == abs_z)
	{
		if (point.z > 0)
			return FRONT;
		return BACK;
	}

	fprintf(stderr, "Error: Could not determine face from point.\n");
	exit(EXIT_FAILURE);
}

t_pattern *new_cube_map(t_pattern *left, t_pattern *front, t_pattern *right,
                        t_pattern *back, t_pattern *up, t_pattern *down)
{
    t_cube_map *cube = malloc(sizeof(t_cube_map));
    if (!cube) {
        fprintf(stderr, "Error: Could not allocate memory for cube map.\n");
        exit(EXIT_FAILURE);
    }

    cube->faces[LEFT] = left;
    cube->faces[FRONT] = front;
    cube->faces[RIGHT] = right;
    cube->faces[BACK] = back;
    cube->faces[UP] = up;
    cube->faces[DOWN] = down;

    t_pattern *pattern = malloc(sizeof(t_pattern));
    if (!pattern) {
        fprintf(stderr, "Error: Could not allocate memory for cube map pattern.\n");
        exit(EXIT_FAILURE);
    }

    pattern->type = CUBE_MAP;
    pattern->uv_pattern = cube; // Store the cube map in the UV pattern
    pattern->uv_map = NULL; // Not needed for cube maps
    pattern->transform = *init_identity_matrix(4);
    pattern->a = NULL;
    pattern->b = NULL;

    return pattern;
}

t_color3 pattern_at_cube_map(t_pattern *pattern, t_point3 point)
{
    t_cube_map *cube = (t_cube_map *)pattern->uv_pattern;

    // Determine the face from the point
    t_directions face = face_from_point(point);

    // Calculate (u, v) based on the face
    t_uv_val uv;
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
    else // DOWN
        uv = cube_uv_down(point);

    t_pattern *face_pattern = cube->faces[face];
    t_color3 color = uv_pattern_at_image(face_pattern->uv_pattern, uv.u, uv.v); //used to be uv_pattern_at_align_check, when running align_check_map
    return color;
}


