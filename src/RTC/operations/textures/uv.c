/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uv.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:39:17 by mdomnik           #+#    #+#             */
/*   Updated: 2025/01/17 20:42:22 by mdomnik          ###   ########.fr       */
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

t_pattern	*texture_map(void *uv_pattern, t_uv_val (*uv_map)(t_point3))
{
	t_pattern	*pattern;

	pattern = malloc(sizeof(t_pattern));
	pattern->type = TEXTURE_MAP;
	pattern->uv_pattern = uv_pattern;
	pattern->uv_map = uv_map;
	pattern->transform = *init_identity_matrix(4);
	pattern->a = NULL;
	pattern->b = NULL;
	return (pattern);
}

t_color3	uv_pattern_at(t_uv *pattern, float u, float v)
{
	int	u2;
	int	v2;

	u2 = (int)floor(u * pattern->width);
	v2 = (int)floor(v * pattern->height);
	if ((u2 + v2) % 2 == 0)
		return (pattern->color_a);
	else
		return (pattern->color_b);
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
	pattern->a = NULL;
	pattern->b = NULL;
	return (pattern);
}

t_color3	uv_pattern_at_image(t_pattern *pattern, double u, double v)
{
	t_uv_image	*uv_img;
	t_canvas	*canvas;
	int			x;
	int			y;

	uv_img = (t_uv_image *)pattern->uv_pattern;
	canvas = uv_img->canvas;
	v = 1 - v;
	x = round(u * (canvas->width - 1));
	y = round(v * (canvas->height - 1));
	x = fmin(fmax(x, 0), canvas->width - 1);
	y = fmin(fmax(y, 0), canvas->height - 1);
	return (canvas->pixels[y][x]);
}
