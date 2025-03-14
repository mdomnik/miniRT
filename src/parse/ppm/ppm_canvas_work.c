/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppm_canvas_work.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 00:40:25 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/14 02:19:01 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

static FILE	*open_ppm_file_a(const char *filename)
{
	FILE	*file;

	file = fopen(filename, "r");
	if (!file)
	{
		fprintf(stderr, "Error: %s\n", ERR_OPEN_FILE);
	}
	return (file);
}

static int	validate_ppm_format(FILE *file)
{
	char	*line;
	int		valid;

	line = skip_comments(file);
	valid = (line && check_ppm_magic_number(line) != -1);
	if (!valid)
		fprintf(stderr, "Error: %s\n", ERR_PPM_FORMAT);
	free(line);
	return (valid);
}

static int	parse_ppm_header(FILE *file, t_canvas *canvas)
{
	char	*line;
	int		color_max;

	line = skip_comments(file);
	if (canvas_from_ppm_dimensions(canvas, line) != 0)
	{
		fprintf(stderr, "Error: %s\n", ERR_PPM_FORMAT);
		free(line);
		return (-1);
	}
	free(line);
	line = skip_comments(file);
	color_max = atoi(line);
	free(line);
	if (color_max > 255)
	{
		fprintf(stderr, "Error: %s\n", ERR_COLOR_MAX);
		return (-1);
	}
	return (color_max);
}

static t_canvas	*create_canvas_and_load_pixels(FILE *file,
		int color_max, t_canvas *canvas)
{
	canvas = canvas_new(canvas, canvas->width, canvas->height);
	if (!canvas)
	{
		fprintf(stderr, "Error: %s\n", ERR_MEMORY);
		fclose(file);
		return (NULL);
	}
	canvas_from_ppm_pixels(file, canvas, color_max);
	return (canvas);
}

t_canvas	*canvas_from_ppm(const char *filename)
{
	FILE		*file;
	t_canvas	*canvas;
	int			color_max;

	file = open_ppm_file_a(filename);
	if (!file)
		return (NULL);
	if (!validate_ppm_format(file))
	{
		fclose(file);
		return (NULL);
	}
	canvas = malloc(sizeof(t_canvas));
	if (!canvas)
	{
		fprintf(stderr, "Error: %s\n", ERR_MEMORY);
		fclose(file);
		return (NULL);
	}
	color_max = parse_ppm_header(file, canvas);
	if (color_max == -1)
		return (fclose(file), free(canvas), NULL);
	canvas = create_canvas_and_load_pixels(file, color_max, canvas);
	fclose(file);
	return (canvas);
}
