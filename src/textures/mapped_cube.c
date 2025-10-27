/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapped_cube.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:14:55 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/19 18:58:40 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

static t_color3	*init_cube_colors(void)
{
	t_color3	*colors;

	colors = malloc(sizeof(t_color3) * 8);
	colors[0] = new_color3(1, 0, 0);
	colors[1] = new_color3(1, 1, 0);
	colors[2] = new_color3(1, 0.5, 0);
	colors[3] = new_color3(0, 1, 0);
	colors[4] = new_color3(0, 1, 1);
	colors[5] = new_color3(0, 0, 1);
	colors[6] = new_color3(1, 0, 1);
	colors[7] = new_color3(1, 1, 1);
	return (colors);
}

static t_pattern	**init_cube_faces(t_color3 *colors)
{
	t_pattern	**faces;

	faces = malloc(sizeof(t_pattern *) * 6);
	faces[LEFT] = align_check_map(
			uv_align_check((t_color3[5]){colors[1], colors[4], colors[0],
				colors[5], colors[2]}), cube_uv_left);
	faces[FRONT] = align_check_map(
			uv_align_check((t_color3[5]){colors[4], colors[0], colors[1],
				colors[2], colors[3]}), cube_uv_front);
	faces[RIGHT] = align_check_map(
			uv_align_check((t_color3[5]){colors[0], colors[1], colors[6],
				colors[3], colors[7]}), cube_uv_right);
	faces[BACK] = align_check_map(
			uv_align_check((t_color3[5]){colors[3], colors[6], colors[4],
				colors[7], colors[5]}), cube_uv_back);
	faces[UP] = align_check_map(
			uv_align_check((t_color3[5]){colors[2], colors[4], colors[6],
				colors[0], colors[1]}), cube_uv_up);
	faces[DOWN] = align_check_map(
			uv_align_check((t_color3[5]){colors[6], colors[2], colors[3],
				colors[5], colors[7]}), cube_uv_down);
	return (faces);
}

t_shape	*create_mapped_cube(void)
{
	t_color3	*colors;
	t_pattern	**faces;
	t_shape		*s_cube;

	colors = init_cube_colors();
	faces = init_cube_faces(colors);
	s_cube = cube();
	s_cube->material.pattern = new_cube_map(faces);
	s_cube->material.ambient = 0.2;
	s_cube->material.specular = 0;
	s_cube->material.diffuse = 0.8;
	free(colors);
	free(faces);
	return (s_cube);
}
