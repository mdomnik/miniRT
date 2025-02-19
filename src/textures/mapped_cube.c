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

t_shape	*create_mapped_cube(void)
{
	t_color3	red;
	t_color3	yellow;
	t_color3	brown;
	t_color3	green;
	t_color3	cyan;
	t_color3	blue;
	t_color3	purple;
	t_color3	white;
	t_pattern	*left;
	t_pattern	*front;
	t_pattern	*right;
	t_pattern	*back;
	t_pattern	*up;
	t_pattern	*down;
	t_shape		*s_cube;

	red = new_color3(1, 0, 0);
	yellow = new_color3(1, 1, 0);
	brown = new_color3(1, 0.5, 0);
	green = new_color3(0, 1, 0);
	cyan = new_color3(0, 1, 1);
	blue = new_color3(0, 0, 1);
	purple = new_color3(1, 0, 1);
	white = new_color3(1, 1, 1);
	left = align_check_map(
			uv_align_check(yellow, cyan, red, blue, brown), cube_uv_left);
	front = align_check_map(
			uv_align_check(cyan, red, yellow, brown, green), cube_uv_front);
	right = align_check_map(
			uv_align_check(red, yellow, purple, green, white), cube_uv_right);
	back = align_check_map(
			uv_align_check(green, purple, cyan, white, blue), cube_uv_back);
	up = align_check_map(
			uv_align_check(brown, cyan, purple, red, yellow), cube_uv_up);
	down = align_check_map(
			uv_align_check(purple, brown, green, blue, white), cube_uv_down);
	s_cube = cube();
	s_cube->material.pattern = new_cube_map(left, front, right, back, up, down);
	s_cube->material.ambient = 0.2;
	s_cube->material.specular = 0;
	s_cube->material.diffuse = 0.8;
	return (s_cube);
}
