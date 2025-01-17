/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_ppm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 22:14:06 by mdomnik           #+#    #+#             */
/*   Updated: 2025/01/17 22:26:13 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

int	isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

void	canvas_write_pixel(t_canvas *canvas, int x, int y, t_color3 color)
{
	if (x < 0 || x >= canvas->width || y < 0 || y >= canvas->height)
	{
		fprintf(stderr, "Error: %s\n", ERR_WRITE_PIXEL);
		exit(EXIT_FAILURE);
	}
	canvas->pixels[y][x] = color;
}

char	*skip_comments(FILE *file)
{
	char	*line;
	char	*ptr;
	size_t	len;

	line = NULL;
	len = 0;
	while (getline(&line, &len, file) != -1)
	{
		ptr = line;
		while (isspace(*ptr))
			ptr++;
		if (*ptr == '\0' || *ptr == '#')
		{
			free(line);
			line = NULL;
			continue ;
		}
		return (line);
	}
	free(line);
	return (NULL);
}

void	canvas_from_ppm_pixels(FILE *file, t_canvas *canvas, int color_max)
{
	int	x;
	int	y;
	int	r;
	int	g;
	int	b;
	char	*line;
	size_t	len;
	ssize_t	read;
	float	scale_factor;
	char *ptr;
	int read_count;
	t_color3 color;

	line = NULL;
	len = 0;
	scale_factor = 1.0f / color_max;
	x = 0;
	y = 0;
	r = -1;
	g = -1;
	b = -1;
	while ((read = getline(&line, &len, file)) != -1)
	{
		ptr = line;
		while (*ptr)
		{
			while (isspace(*ptr))
				ptr++;
			read_count = sscanf(ptr, "%d %d %d", &r, &g, &b);
			if (read_count == 3)
			{
				color = new_color3(
						r * scale_factor,
						g * scale_factor,
						b * scale_factor
						);
				canvas_write_pixel(canvas, x, y, color);
				x++;
				if (x >= canvas->width)
				{
					x = 0;
					y++;
					if (y >= canvas->height)
						break ;
				}
				ptr = strchr(ptr, ' ');
				if (ptr)
					ptr = strchr(ptr + 1, ' ');
				if (ptr)
					ptr = strchr(ptr + 1, ' ');
			}
			else
				break ;
		}
		free(line);
		line = NULL;
		if (y >= canvas->height)
			break ;
	}
	free(line);
	if (r == -1 || g == -1 || b == -1)
	{
		fprintf(stderr, "Error: %s\n", ERR_INCOMPLETE_RGB);
		exit(EXIT_FAILURE);
	}
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
