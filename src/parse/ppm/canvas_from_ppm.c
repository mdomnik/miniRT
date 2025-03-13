/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_from_ppm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:18:27 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/12 23:46:27 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

static int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

void	canvas_from_ppm_pixels(FILE *file, t_canvas *canvas, int color_max)
{
	char		*line;
	size_t		len;
	ssize_t		read;
	float		scale_factor;
	int			x;
	int			y;
	int			r;
	int			g;
	int			b;
	char		*ptr;
	int			read_count;
	t_color3	color;

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
			while (ft_isspace(*ptr))
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



