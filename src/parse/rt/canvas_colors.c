/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 19:22:07 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/19 19:09:47 by mdomnik          ###   ########.fr       */
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
uint32_t color_to_uint32(t_color3 color)
{
	uint32_t result;

	result = 0;
	result |= (uint32_t)(color.r * 255) << 24;
	result |= (uint32_t)(color.g * 255) << 16;
	result |= (uint32_t)(color.b * 255) << 8;
	result |= (uint32_t)(color.al * 255);
	return (result);
}

//canvas_to_mlx
void canvas_to_mlx(t_canvas *canvas, t_project *project)
{
	for (int i = 0; i < canvas->height; i++)
	{
		for (int j = 0; j < canvas->width; j++)
		{
			mlx_put_pixel(project->image, j, i, color_to_uint32(canvas->pixels[i][j]));
		}
	}
}
