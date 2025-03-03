/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_from_ppm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:18:27 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/26 19:24:13 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

static int	read_pixel_values(char *ptr, int *r, int *g, int *b)
{
	while (ft_isspace(*ptr))
		ptr++;
	if (sscanf(ptr, "%d %d %d", r, g, b) != 3)
		return (-1);
	return (0);
}

static void	proc_pxl(t_canvas *canvas, int *coords,
		t_color3 color)
{
	canvas_write_pixel(canvas, coords[0], coords[1], color);
	coords[0]++;
	if (coords[0] >= canvas->width)
	{
		coords[0] = 0;
		coords[1]++;
	}
}

void	canvas_from_ppm_pixels(FILE *file, t_canvas *canvas, int color_max)
{
	char		*line;
	size_t		len;
	float		scale;
	int			coords[2];
	int			rgb[3];

	line = NULL;
	len = 0;
	scale = 1.0f / color_max;
	coords[0] = 0;
	coords[1] = 0;
	rgb[0] = -1;
	while (getline(&line, &len, file) != -1 && coords[1] < canvas->height)
	{
		if (read_pixel_values(line, &rgb[0], &rgb[1], &rgb[2]) == 0)
			proc_pxl(canvas, coords,
				new_color3(rgb[0] * scale, rgb[1] * scale, rgb[2] * scale));
		free(line);
		line = NULL;
	}
	free(line);
}

// static t_canvas	*process_ppm_header(FILE *file, int *color_max)
// {
// 	char		*line;
// 	t_canvas	*canvas;

// 	line = skip_comments(file);
// 	if (!line || check_ppm_magic_number(line) == -1)
// 		return (free(line), ft_dprintf(2, "Error: %s\n", ERR_PPM_FORMAT), NULL);
// 	free(line);
// 	canvas = malloc(sizeof(t_canvas));
// 	if (!canvas)
// 		return (ft_dprintf(2, "Error: %s\n", ERR_MEMORY), NULL);
// 	line = skip_comments(file);
// 	if (canvas_from_ppm_dimensions(canvas, line) != 0)
// 		return (free(line), ft_dprintf(2, "Error: %s\n", ERR_PPM_FORMAT), NULL);
// 	free(line);
// 	line = skip_comments(file);
// 	*color_max = atoi(line);
// 	free(line);
// 	return (canvas);
// }

// t_canvas	*canvas_from_ppm(const char *filename)
// {
// 	FILE		*file;
// 	t_canvas	*canvas;
// 	int			color_max;

// 	file = fopen(filename, "r");
// 	if (!file)
// 		return (ft_dprintf(2, "Error: %s\n", ERR_OPEN_FILE), NULL);
// 	canvas = process_ppm_header(file, &color_max);
// 	if (!canvas)
// 		return (fclose(file), NULL);
// 	if (color_max > 255)
// 		return (ft_dprintf(2, "Error:%s\n", ERR_COLOR_MAX), fclose(file), NULL);
// 	canvas = canvas_new(canvas->width, canvas->height);
// 	canvas_from_ppm_pixels(file, canvas, color_max);
// 	return (fclose(file), canvas);
// }
