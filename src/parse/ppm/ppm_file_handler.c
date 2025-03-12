/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppm_file_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:18:27 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/12 13:15:32 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

int	isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

int	check_ppm_magic_number(char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (strncmp(line, "P3", 2) != 0)
		return (-1);
	while (line[i] != '\0')
	{
		if (!isspace(line[i]))
			j++;
		i++;
	}
	if (j == 2)
		return (0);
	return (-1);
}

int	canvas_from_ppm_dimensions(t_canvas *canvas, char *line)
{
	int		width;
	int		height;

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
	{
		fprintf(stderr, "Error: %s\n", ERR_OPEN_FILE);
		return (NULL);
	}
	line = skip_comments(file);
	if (!line || check_ppm_magic_number(line) == -1)
	{
		fprintf(stderr, "Error: %s\n", ERR_PPM_FORMAT);
		free(line);
		fclose(file);
		return (NULL);
	}
	free(line);
	canvas = malloc(sizeof(t_canvas));
	if (!canvas)
	{
		fprintf(stderr, "Error: %s\n", ERR_MEMORY);
		fclose(file);
		return (NULL);
	}
	line = skip_comments(file);
	if (canvas_from_ppm_dimensions(canvas, line) != 0)
	{
		fprintf(stderr, "Error: %s\n", ERR_PPM_FORMAT);
		free(line);
		fclose(file);
		return (NULL);
	}
	free(line);
	line = skip_comments(file);
	color_max = atoi(line);
	free(line);
	if (color_max > 255)
	{
		fprintf(stderr, "Error: %s\n", ERR_COLOR_MAX);
		fclose(file);
		return (NULL);
	}
	canvas = canvas_new(canvas->width, canvas->height);
	canvas_from_ppm_pixels(file, canvas, color_max);
	fclose(file);
	return (canvas);
}
