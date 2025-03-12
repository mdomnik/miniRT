/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 22:14:06 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/12 13:10:35 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

void	canvas_write_pixel(t_canvas *canvas, int x, int y, t_color3 color)
{
	if (x < 0 || x >= canvas->width || y < 0 || y >= canvas->height)
	{
		 ft_dprintf(2, "Error: %s\n", ERR_WRITE_PIXEL);
		exit(EXIT_FAILURE);
	}
	canvas->pixels[y][x] = color;
}

char	*skip_comments(int fd)
{
	char	*line;
	char	*ptr;

	line = gnl(fd);
	while (line != NULL)
	{
		ptr = line;
		while (ft_isspace(*ptr))
			ptr++;
		if (*ptr == '\0' || *ptr == '#')
		{
			free(line);
			line = gnl(fd);
			continue ;
		}
		return (line);
	}
	free(line);
	return (NULL);
}
