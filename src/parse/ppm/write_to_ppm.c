/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_to_ppm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:39:02 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/09 19:29:49 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"
#include <sys/stat.h>
#include <sys/types.h>

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

static void create_directory(const char *path)
{
    struct stat st = {0};
    if (stat(path, &st) == -1) // Check if the directory exists
        mkdir(path, 0700); // Create the directory with rwx------ permissions
}

void save_image(t_image *img, char *filename)
{
	FILE *file;
	int x, y;
	int offset;
	unsigned char r, g, b;
	char *file_name;

	if (!img || !img->buffer)
	{
		fprintf(stderr, "Error: Invalid image data.\n");
		return;
	}
	create_directory("saved/");
	file_name = ft_strjoin("saved/", filename);
	free(filename);
	filename = ft_strjoin(file_name, ".ppm");
	file = fopen(filename, "w");
	free(file_name);
	if (!file)
	{
		fprintf(stderr, "Error: Could not open file for writing.\n");
		return;
	}
	// Write PPM header
	fprintf(file, "P3\n%d %d\n255\n", img->width, img->height);
	// Iterate over pixels row by row
	for (y = 0; y < img->height; y++)
	{
		for (x = 0; x < img->width; x++)
		{
			offset = (y * img->size_line) + (x * (img->bits_per_pixel / 8));

			// Extract pixel colors based on endian format
			if (img->endian == 0) // Little endian (default for most systems)
			{
				b = (unsigned char)img->buffer[offset];
				g = (unsigned char)img->buffer[offset + 1];
				r = (unsigned char)img->buffer[offset + 2];
			}
			else // Big endian
			{
				r = (unsigned char)img->buffer[offset];
				g = (unsigned char)img->buffer[offset + 1];
				b = (unsigned char)img->buffer[offset + 2];
			}

			// Write pixel values
			fprintf(file, "%d %d %d\n", r, g, b);
		}
	}

	fclose(file);
	printf("\033[1;35mImage saved as %s\033[0m\n", filename);
}
