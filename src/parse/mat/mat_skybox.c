/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_skybox.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:41:07 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/26 19:24:42 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _POSIX_C_SOURCE 200809L
#include "mrt.h"

// https://www.humus.name/index.php?page=Textures&start=24
int	get_skybox(char *str, t_material *mat)
{
	char *filename;
	t_pattern *side[6];
	t_pattern *cube_map;

	printf("str: [%s]\n", str);
	if (open(str, O_DIRECTORY) == -1)
	{
		ft_dprintf(2, "Error\nSkybox texture not found\n");
		return (-1);
	}
	filename = ft_strjoin(str, "/negx.ppm");
	printf("filename: [%s]\n", filename);
	side[0] = texture_map(uv_image(canvas_from_ppm(filename)), planar_map);
	free(filename);
	filename = ft_strjoin(str, "/posz.ppm");
	side[1] = texture_map(uv_image(canvas_from_ppm(filename)), planar_map);
	free(filename);
	filename = ft_strjoin(str, "/posx.ppm");
	side[2] = texture_map(uv_image(canvas_from_ppm(filename)), planar_map);
	free(filename);
	filename = ft_strjoin(str, "/negz.ppm");
	side[3] = texture_map(uv_image(canvas_from_ppm(filename)), planar_map);
	free(filename);
	filename = ft_strjoin(str, "/posy.ppm");
	side[4] = texture_map(uv_image(canvas_from_ppm(filename)), planar_map);
	free(filename);
	filename = ft_strjoin(str, "/negy.ppm");
	side[5] = texture_map(uv_image(canvas_from_ppm(filename)), planar_map);
	free(filename);

	cube_map = new_cube_map(side[0], side[1], side[2], side[3], side[4], side[5]);
	mat->pattern = cube_map;
	return (0);
}
