/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:52:39 by mdomnik           #+#    #+#             */
/*   Updated: 2025/01/14 18:36:24 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

//add shape
void add_shape(t_shape **shapes, t_shape *new_shape)
{
	t_shape *temp;

	if (!new_shape)
		return ;
	if (!*shapes)
	{
		*shapes = new_shape;
		return ;
	}
	temp = *shapes;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new_shape;
}

//test_shape
t_shape *test_shape(void)
{
	t_shape *shape;

	shape = malloc(sizeof(t_shape));
	shape->type = SPHERE;
	shape->transform = *init_identity_matrix(4);
	shape->material = *default_material();
	shape->next = NULL;
	return (shape);
}

t_shape *glass_sphere(void)
{
	t_shape *shape;

	shape = sphere();
	shape->material.transparency = 1.0;
	shape->material.refractive_index = 1.5;
	return (shape);
}

t_shape *create_mapped_cube(void)
{
    // Define colors for the align check patterns
    t_color3 red = new_color3(1, 0, 0);
    t_color3 yellow = new_color3(1, 1, 0);
    t_color3 brown = new_color3(1, 0.5, 0);
    t_color3 green = new_color3(0, 1, 0);
    t_color3 cyan = new_color3(0, 1, 1);
    t_color3 blue = new_color3(0, 0, 1);
    t_color3 purple = new_color3(1, 0, 1);
    t_color3 white = new_color3(1, 1, 1);

    // Create align check patterns for each face
    t_pattern *left = align_check_map(uv_align_check(yellow, cyan, red, blue, brown), cube_uv_left);
    t_pattern *front = align_check_map(uv_align_check(cyan, red, yellow, brown, green), cube_uv_front);
    t_pattern *right = align_check_map(uv_align_check(red, yellow, purple, green, white), cube_uv_right);
    t_pattern *back = align_check_map(uv_align_check(green, purple, cyan, white, blue), cube_uv_back);
    t_pattern *up = align_check_map(uv_align_check(brown, cyan, purple, red, yellow), cube_uv_up);
    t_pattern *down = align_check_map(uv_align_check(purple, brown, green, blue, white), cube_uv_down);

    // Create the cube with the patterns
    t_shape *s_cube = cube();
    s_cube->material.pattern = new_cube_map(left, front, right, back, up, down);
    s_cube->material.ambient = 0.2;
    s_cube->material.specular = 0;
    s_cube->material.diffuse = 0.8;

    return s_cube;
}

t_shape *create_texture_cube(void)
{
    // Define colors for the align check patterns
    t_color3 red = new_color3(1, 0, 0);
    t_color3 yellow = new_color3(1, 1, 0);
    t_color3 brown = new_color3(1, 0.5, 0);
    t_color3 green = new_color3(0, 1, 0);
    t_color3 cyan = new_color3(0, 1, 1);
    t_color3 blue = new_color3(0, 0, 1);
    t_color3 purple = new_color3(1, 0, 1);
    t_color3 white = new_color3(1, 1, 1);

	t_canvas *cnegx = canvas_from_ppm("Tenerife4/negx.ppm");
	t_pattern *back_tex = uv_image(cnegx);
	t_pattern *back = texture_map(back_tex, cube_uv_back);

    // Create align check patterns for each face
    t_pattern *left = align_check_map(uv_align_check(yellow, cyan, red, blue, brown), cube_uv_left);
    t_pattern *front = align_check_map(uv_align_check(cyan, red, yellow, brown, green), cube_uv_front);
    t_pattern *right = align_check_map(uv_align_check(red, yellow, purple, green, white), cube_uv_right);
    t_pattern *up = align_check_map(uv_align_check(brown, cyan, purple, red, yellow), cube_uv_up);
    t_pattern *down = align_check_map(uv_align_check(purple, brown, green, blue, white), cube_uv_down);

    // Create the cube with the patterns
    t_shape *s_cube = cube();
    s_cube->material.pattern = new_cube_map(left, front, right, back, up, down);
    s_cube->material.ambient = 0.2;
    s_cube->material.specular = 0;
    s_cube->material.diffuse = 0.8;

    return s_cube;
}

