/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_to_ppm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:39:02 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/09 11:13:38 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

static t_color3	pixel_at_ppm(t_canvas *canvas, int x, int y)
{
	if (x < 0 || x >= canvas->width || y < 0 || y >= canvas->height)
	{
		fprintf(stderr, "Error: Attempted to read pixel \
				outside of canvas bounds.\n");
		exit(EXIT_FAILURE);
	}
	return (canvas->pixels[y][x]);
}

t_canvas	*canvas_new(int width, int height)
{
	t_canvas	*canvas;
	int			i;
	int			j;

	canvas = malloc(sizeof(t_canvas));
	if (!canvas)
	{
		fprintf(stderr, "Error: Could not allocate memory for canvas.\n");
		exit(EXIT_FAILURE);
	}
	canvas->width = width;
	canvas->height = height;
	canvas->pixels = malloc(sizeof(t_color3 *) * height);
	i = 0;
	while (i < height)
	{
		j = -1;
		canvas->pixels[i] = malloc(sizeof(t_color3) * width);
		while (++j < width)
			canvas->pixels[i][j] = new_color3(0, 0, 0);
		i++;
	}
	return (canvas);
}

void	write_pixel(t_canvas *canvas, int x, int y, t_color3 color)
{
	if (x < 0 || x >= canvas->width || y < 0 || y >= canvas->height)
	{
		ft_dprintf(2, "Error: Attempted to write \
				pixel outside of canvas bounds.\n");
		exit(EXIT_FAILURE);
	}
	canvas->pixels[y][x] = color;
}

int	canvas_to_ppm(t_canvas *canvas, char *filename)
{
	FILE		*file;
	t_color3	color;
	int			i;
	int			j;

	file = fopen(filename, "w");
	if (!file)
		return (ft_dprintf(2, "Error: Could not open file for writing.\n"), -1);
	fprintf(file, "P3\n%d %d\n255\n", canvas->width, canvas->height);
	i = 0;
	while (i < canvas->height)
	{
		j = 0;
		while (j < canvas->width)
		{
			color = pixel_at_ppm(canvas, j, i);
			fprintf(file, "%d %d %d\n", (int)(color.r * 255),
				(int)(color.g * 255), (int)(color.b * 255));
			j++;
		}
		i++;
	}
	return (fclose(file), 0);
}
