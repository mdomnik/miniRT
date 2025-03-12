/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_from_ppm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:18:27 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/12 13:10:24 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

static void	get_rgb_values(char *ptr, int *r, int *g, int *b, int *read_count)
{
	while (ft_isspace(*ptr))
		ptr++;
	*r = ft_atoi(ptr);
	while (*ptr && !ft_isspace(*ptr))
		ptr++;
	while (ft_isspace(*ptr))
		ptr++;
	*g = ft_atoi(ptr);
	while (*ptr && !ft_isspace(*ptr))
		ptr++;
	while (ft_isspace(*ptr))
		ptr++;
	*b = ft_atoi(ptr);
	*read_count = (*r >= 0 && *g >= 0 && *b >= 0) ? 3 : 0;
}

void	canvas_from_ppm_pixels(int fd, t_canvas *canvas, int color_max)
{
	char		*line;
	float		scale_factor;
	int			v[6];
	char		*ptr;
	t_color3	color;

	line = gnl(fd);
	scale_factor = 1.0f / color_max;
	v[0] = 0;  // x
	v[1] = 0;  // y
	v[2] = -1; // r
	v[3] = -1; // g
	v[4] = -1; // b
	while (line != NULL)
	{
		ptr = line;
		while (*ptr)
		{
			get_rgb_values(ptr, &v[2], &v[3], &v[4], &v[5]);
			if (v[5] == 3)
			{
				color = new_color3(v[2] * scale_factor,
						v[3] * scale_factor, v[4] * scale_factor);
				canvas_write_pixel(canvas, v[0], v[1], color);
				v[0]++;
				if (v[0] >= canvas->width)
				{
					v[0] = 0;
					v[1]++;
					if (v[1] >= canvas->height)
						break ;
				}
				while (*ptr && !ft_isspace(*ptr))
					ptr++;
			}
			else
				break ;
		}
		free(line);
		line = NULL;
		if (v[1] >= canvas->height)
			break ;
		line = gnl(fd);
	}
	free(line);
	if (v[2] == -1 || v[3] == -1 || v[4] == -1)
	{
		ft_dprintf(2, "Error: %s\n", ERR_INCOMPLETE_RGB);
		exit(EXIT_FAILURE);
	}
}
