/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:25:57 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/19 18:58:49 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

t_uv	*uv_checkers(int width, int height, t_color3 color_a, t_color3 color_b)
{
	t_uv	*pattern;

	pattern = malloc(sizeof(t_uv));
	pattern->width = width;
	pattern->height = height;
	pattern->color_a = color_a;
	pattern->color_b = color_b;
	return (pattern);
}

t_pattern	*uv_image(t_canvas *canvas)
{
	t_uv_image	*uv_img;
	t_pattern	*pattern;

	uv_img = malloc(sizeof(t_uv_image));
	uv_img->canvas = canvas;
	pattern = malloc(sizeof(t_pattern));
	pattern->type = UV_IMAGE;
	pattern->uv_pattern = uv_img;
	pattern->transform = *init_identity_matrix(4);
	pattern->a = (t_color3){0};
	pattern->b = (t_color3){0};
	return (pattern);
}

t_pattern	*texture_map(void *uv_pattern, t_uv_val (*uv_map)(t_point3))
{
	t_pattern	*pattern;

	pattern = malloc(sizeof(t_pattern));
	pattern->type = TEXTURE_MAP;
	pattern->uv_pattern = uv_pattern;
	pattern->uv_map = uv_map;
	pattern->transform = *init_identity_matrix(4);
	pattern->a = (t_color3){0};
	pattern->b = (t_color3){0};
	return (pattern);
}
