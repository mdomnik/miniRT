/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppm_file_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:18:27 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/14 02:29:48 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

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
	int		width;
	int		height;

	if (sscanf(line, "%d %d", &width, &height) != 2)
		return (-1);
	canvas->width = width;
	canvas->height = height;
	return (0);
}

t_canvas	*canvas_new(t_canvas *canv, int width, int height)
{
	int			i;
	int			j;

	canv->pixels = malloc(sizeof(t_color3 *) * height);
	i = 0;
	while (i < height)
	{
		j = -1;
		canv->pixels[i] = malloc(sizeof(t_color3) * width);
		while (++j < width)
			canv->pixels[i][j] = new_color3(0, 0, 0);
		i++;
	}
	return (canv);
}

int	open_ppm_file(char *filename)
{
	char	*file_name;
	char	*temp;
	int		fd;

	temp = ft_strjoin("saved/", filename);
	file_name = ft_strjoin(temp, ".ppm");
	free(temp);
	fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		ft_dprintf(2, "Error: Could not open file for writing.\n");
		free(file_name);
		return (-1);
	}
	ft_dprintf(0, "\033[1;35mImage saved to %s.ppm!\033[0m\n", filename);
	free(file_name);
	return (fd);
}

t_bump_map	*bump_map_from_ppm(const char *filename,
	double scale, t_uv_val (*uv_maps)(t_point3))
{
	t_canvas	*height_map;
	t_bump_map	*bump_map;

	height_map = canvas_from_ppm(filename);
	if (!height_map)
	{
		ft_dprintf(2, "Error loading bump map: %s\n", filename);
		exit(EXIT_FAILURE);
	}
	bump_map = malloc(sizeof(t_bump_map));
	bump_map->height_map = height_map;
	bump_map->scale = scale;
	bump_map->uv_map = uv_maps;
	bump_map->transform = init_identity_matrix(4);
	return (bump_map);
}
