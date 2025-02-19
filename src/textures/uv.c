/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uv.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:25:05 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/19 16:26:15 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"


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
