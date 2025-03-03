/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppm_file_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:18:27 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/26 19:24:13 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

static int	process_ppm_header(FILE *file, t_canvas *canvas, int *color_max);

int	check_ppm_magic_number(char *line)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (strncmp(line, "P3", 2) != 0)
		return (-1);
	while (line[i])
	{
		if (!ft_isspace(line[i]))
			count++;
		i++;
	}
	if (count != 2)
		return (-1);
	return (0);
}

int	canvas_from_ppm_dimensions(t_canvas *canvas, char *line)
{
	int	width;
	int	height;

	if (sscanf(line, "%d %d", &width, &height) != 2)
		return (-1);
	canvas->width = width;
	canvas->height = height;
	return (0);
}

t_canvas	*canvas_from_ppm(const char *filename)
{
	FILE		*file;
	char		*line;
	t_canvas	*canvas;
	int			color_max;

	file = fopen(filename, "r");
	if (!file)
		return (error_handler(ERR_OPEN_FILE, NULL));
	line = skip_comments(file);
	if (!line || check_ppm_magic_number(line) == -1)
		return (error_handler(ERR_PPM_FORMAT, file));
	free(line);
	canvas = malloc(sizeof(t_canvas));
	if (!canvas)
		return (error_handler(ERR_MEMORY, file));
	if (process_ppm_header(file, canvas, &color_max) == -1)
		return (NULL);
	canvas_from_ppm_pixels(file, canvas, color_max);
	fclose(file);
	return (canvas);
}

static int	process_ppm_header(FILE *file, t_canvas *canvas, int *color_max)
{
	char	*line;

	line = skip_comments(file);
	if (canvas_from_ppm_dimensions(canvas, line) != 0)
		return (error_handler_int(ERR_PPM_FORMAT, file));
	free(line);
	line = skip_comments(file);
	*color_max = atoi(line);
	free(line);
	if (*color_max > 255)
		return (error_handler_int(ERR_COLOR_MAX, file));
	canvas = canvas_new(canvas->width, canvas->height);
	return (0);
}
