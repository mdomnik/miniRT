/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_ppm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:39:02 by mdomnik           #+#    #+#             */
/*   Updated: 2025/01/13 21:53:14 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

t_canvas *canvas_new(int width, int height)
{
	t_canvas *canvas;
	int i;
	int j;

	canvas = malloc(sizeof(t_canvas));
	if (!canvas)
	{
		fprintf(stderr, "Error: Could not allocate memory for canvas.\n");
		exit(EXIT_FAILURE);
	}
	canvas->width = width;
	canvas->height = height;
	canvas->pixels = malloc(sizeof(t_color3 *) * height);
	if (!canvas->pixels)
	{
		fprintf(stderr, "Error: Could not allocate memory for canvas pixels.\n");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < height)
	{
		j = 0;
		canvas->pixels[i] = malloc(sizeof(t_color3) * width);
		if (!canvas->pixels[i])
		{
			fprintf(stderr, "Error: Could not allocate memory for canvas pixels.\n");
			exit(EXIT_FAILURE);
		}
		while(j < width)
		{
			canvas->pixels[i][j] = new_color3(0, 0, 0);
			j++;
		}
		i++;
	}
	return (canvas);
}

void write_pixel(t_canvas *canvas, int x, int y, t_color3 color)
{
	if (x < 0 || x >= canvas->width || y < 0 || y >= canvas->height)
	{
		fprintf(stderr, "Error: Attempted to write pixel outside of canvas bounds.\n");
		exit(EXIT_FAILURE);
	}
	canvas->pixels[y][x] = color;
}

t_color3 pixel_at(t_canvas *canvas, int x, int y)
{
	if (x < 0 || x >= canvas->width || y < 0 || y >= canvas->height)
	{
		fprintf(stderr, "Error: Attempted to read pixel outside of canvas bounds.\n");
		exit(EXIT_FAILURE);
	}
	return (canvas->pixels[y][x]);
}

void canvas_to_ppm(t_canvas *canvas, char *filename)
{
	FILE *file;

	file = fopen(filename, "w");
	if (!file)
	{
		fprintf(stderr, "Error: Could not open file for writing.\n");
		exit(EXIT_FAILURE);
	}
	fprintf(file, "P3\n%d %d\n255\n", canvas->width, canvas->height);
}
