/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_from_ppm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:18:27 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/14 00:33:03 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

static void	handle_pixel(t_canvas *canvas, int *x, int *y, t_color3 color)
{
	canvas_write_pixel(canvas, *x, *y, color);
	(*x)++;
	if (*x >= canvas->width)
	{
		*x = 0;
		(*y)++;
	}
}

static void	parse_rgb(char **ptr, float scale_factor,
		t_color3 *color, int *status)
{
	int	r;
	int	g;
	int	b;
	int	read_count;

	while (ft_isspace(**ptr))
		(*ptr)++;
	read_count = sscanf(*ptr, "%d %d %d", &r, &g, &b);
	if (read_count == 3)
	{
		*color = new_color3(r * scale_factor, g * scale_factor,
				b * scale_factor);
		*status = 1;
	}
	else
	{
		*status = 0;
	}
}
#define X 0
#define Y 1
#define STATUS 2

static void	process_line(char *line, t_canvas *canvas, int a[],
		float scale_factor)
{
	char		*ptr;
	t_color3	color;
	int			status;

	ptr = line;
	while (*ptr)
	{
		parse_rgb(&ptr, scale_factor, &color, &status);
		if (status)
		{
			handle_pixel(canvas, &a[X], &a[Y], color);
			ptr = strchr(ptr, ' ');
			if (ptr)
				ptr = strchr(ptr + 1, ' ');
			if (ptr)
				ptr = strchr(ptr + 1, ' ');
		}
		else
			break ;
	}
}

static int	read_ppm_data(FILE *file, t_canvas *canvas,
		int a[], float scale_factor)
{
	char	*line;
	size_t	len;
	ssize_t	read;

	line = NULL;
	len = 0;
	read = getline(&line, &len, file);
	while (read != -1)
	{
		process_line(line, canvas, a, scale_factor);
		free(line);
		line = NULL;
		if (a[Y] >= canvas->height)
			break ;
		read = getline(&line, &len, file);
	}
	free(line);
	return (a[STATUS]);
}

void	canvas_from_ppm_pixels(FILE *file, t_canvas *canvas, int color_max)
{
	float	scale_factor;
	int		a[3];

	scale_factor = 1.0f / color_max;
	a[X] = 0;
	a[Y] = 0;
	a[STATUS] = 1;
	a[STATUS] = read_ppm_data(file, canvas, a, scale_factor);
	if (!a[STATUS])
	{
		fprintf(stderr, "%s\n", ERR_INCOMPLETE_RGB);
		fclose(file);
		exit(EXIT_FAILURE);
	}
}
