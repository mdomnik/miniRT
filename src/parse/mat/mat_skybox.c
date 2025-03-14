/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_skybox.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:41:07 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/14 15:40:30 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _POSIX_C_SOURCE 200809L
#include "mrt.h"

// https://www.humus.name/index.php?page=Textures&start=24
static t_pattern	*load_skybox_side(char *base_path, char *side_name)
{
	char		*filename;
	t_pattern	*side;

	filename = ft_strjoin(base_path, side_name);
	side = texture_map(uv_image(canvas_from_ppm(filename)), planar_map);
	free(filename);
	return (side);
}

static int	load_all_sides(char *str, t_pattern *sides[6])
{
	sides[0] = load_skybox_side(str, "/negx.ppm");
	sides[1] = load_skybox_side(str, "/posz.ppm");
	sides[2] = load_skybox_side(str, "/posx.ppm");
	sides[3] = load_skybox_side(str, "/negz.ppm");
	sides[4] = load_skybox_side(str, "/posy.ppm");
	sides[5] = load_skybox_side(str, "/negy.ppm");
	return (0);
}

int	get_skybox(char *str, t_material *mat)
{
	t_pattern	*side[6];
	t_pattern	*cube_map;
	char		*path;
	int			fd;

	path = ft_strjoin("skybox/", str);
	fd = open(path, O_DIRECTORY);
	if (fd == -1)
	{
		mat->pattern = NULL;
		return (-1);
	}
	load_all_sides(path, side);
	free(path);
	cube_map = new_cube_map(side);
	mat->pattern = cube_map;
	close(fd);
	return (0);
}
