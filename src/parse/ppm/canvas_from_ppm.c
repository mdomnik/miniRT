/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_from_ppm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:18:27 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/12 23:43:42 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

void	canvas_from_ppm_pixels(int fd, t_canvas *canvas, int color_max)
{
	char		*line;
	float		scale_factor;
	int			v[6]; // x, y, r, g, b, read_count
	int			r, g, b;
	t_color3	color;
	char		*ptr;

	line = gnl(fd);
	scale_factor = 1.0f / color_max;
	v[0] = 0;  // x position
	v[1] = 0;  // y position

	while (line != NULL)
	{
		ptr = line;
		while (*ptr) // Process the entire line using sscanf
		{
			int count = sscanf(ptr, "%d %d %d", &r, &g, &b);
			if (count == 3) // Valid RGB triplet
			{
				color = new_color3(r * scale_factor, g * scale_factor, b * scale_factor);
				canvas_write_pixel(canvas, v[0], v[1], color);

				// Move to next pixel position
				v[0]++;
				if (v[0] >= canvas->width)
				{
					v[0] = 0;
					v[1]++;
					if (v[1] >= canvas->height) // Stop if canvas is full
						break;
				}
				// Move ptr forward
				while (*ptr && !ft_isspace(*ptr)) ptr++; // Skip the number
				while (*ptr && ft_isspace(*ptr)) ptr++; // Skip spaces
			}
			else
				break;
		}
		free(line);
		if (v[1] >= canvas->height) // Stop reading if canvas is full
			break;
		line = gnl(fd);
	}
}



