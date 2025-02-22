/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 19:22:07 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/22 00:25:38 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

t_canvas new_canvas(int width, int height)
{
	t_canvas canvas;

	canvas.width = width;
	canvas.height = height;
	canvas.pixels = (t_color3 **)malloc(sizeof(t_color3 *) * canvas.height);
	for (int i = 0; i < canvas.height; i++)
	{
		canvas.pixels[i] = (t_color3 *)malloc(sizeof(t_color3) * canvas.width);
		for (int j = 0; j < canvas.width; j++)
		{
			canvas.pixels[i][j] = new_tuple(0, 0, 0, 1);
		}
	}
	return(canvas);
}

//pixel_at
t_color3 pixel_at(t_canvas *canvas, int x, int y)
{
	return (canvas->pixels[y][x]);
}

//color to uint32_t
int color_to_uint32(t_color3 color)
{
	int result;

	result = 0;
	result |= (int)(color.r * 255) << 24;
	result |= (int)(color.g * 255) << 16;
	result |= (int)(color.b * 255) << 8;
	result |= (int)(color.al * 255);
	return (result);
}
