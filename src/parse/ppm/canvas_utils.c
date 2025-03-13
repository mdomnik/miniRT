/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 22:14:06 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/13 21:43:19 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

int	ft_isspace(int c)
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
		while (ft_isspace(*ptr))
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
