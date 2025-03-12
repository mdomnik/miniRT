/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppm_file_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:18:27 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/12 23:28:59 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

int	ft_isspace(int c)
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
	if (ft_strncmp(line, "P3", 2) != 0)
		return (-1);
	while (line[i] != '\0')
	{
		if (!ft_isspace(line[i]))
			j++;
		i++;
	}
	if (j == 2)
		return (0);
	return (-1);
}

int	canvas_from_ppm_dimensions(t_canvas *canvas, char *line)
{
	char	**tokens;
	int		width;
	int		height;

	tokens = ft_split(line, ' ');
	if (!tokens || !tokens[0] || !tokens[1])
	{
		free_double(tokens);
		return (-1);
	}
	width = ft_atoi(tokens[0]);
	height = ft_atoi(tokens[1]);
	free_double(tokens);
	if (width <= 0 || height <= 0)
		return (-1);
	canvas->width = width;
	canvas->height = height;
	return (0);
}

t_canvas	*canvas_from_ppm(const char *filename)
{
	int			fd;
	char		*line;
	t_canvas	*canvas;
	int			color_max;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_dprintf(2, "Error: %s\n", ERR_OPEN_FILE);
		return (NULL);
	}
	line = skip_comments(fd);
	if (!line || check_ppm_magic_number(line) == -1)
	{
		ft_dprintf(2, "Error: %s\n", ERR_PPM_FORMAT);
		free(line);
		close(fd);
		return (NULL);
	}
	free(line);
	canvas = malloc(sizeof(t_canvas));
	if (!canvas)
	{
		ft_dprintf(2, "Error: %s\n", ERR_MEMORY);
		close(fd);
		return (NULL);
	}
	line = skip_comments(fd);
	if (canvas_from_ppm_dimensions(canvas, line) != 0)
	{
		ft_dprintf(2, "Error: %s\n", ERR_PPM_FORMAT);
		free(line);
		close(fd);
		return (NULL);
	}
	free(line);
	line = skip_comments(fd);
	color_max = ft_atoi(line);
	free(line);
	if (color_max > 255)
	{
		ft_dprintf(2, "Error: %s\n", ERR_COLOR_MAX);
		close(fd);
		return (NULL);
	}
	canvas = canvas_new(canvas, canvas->width, canvas->height);
	canvas_from_ppm_pixels(fd, canvas, color_max);
	close(fd);
	return (canvas);
}
