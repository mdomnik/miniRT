/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_skybox.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:41:07 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/26 17:50:50 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

int	get_skybox(char *str, t_material *mat)
{
	// char *filename;

	printf("str: [%s]\n", str);
	(void)mat;
	// https://www.humus.name/index.php?page=Textures&start=24
	// t_pattern *uv_left = texture_map(uv_image(canvas_from_ppm("z_hdri/negx.ppm")), planar_map);
	// t_pattern *uv_front = texture_map(uv_image(canvas_from_ppm("z_hdri/posz.ppm")), planar_map);
	// t_pattern *uv_right = texture_map(uv_image(canvas_from_ppm("z_hdri/posx.ppm")), planar_map);
	// t_pattern *uv_back = texture_map(uv_image(canvas_from_ppm("z_hdri/negz.ppm")), planar_map);
	// t_pattern *uv_up = texture_map(uv_image(canvas_from_ppm("z_hdri/posy.ppm")), planar_map);
	// t_pattern *uv_down = texture_map(uv_image(canvas_from_ppm("z_hdri/negy.ppm")), planar_map);

	// t_pattern *cube_map = new_cube_map(uv_left, uv_front, uv_right, uv_back, uv_up, uv_down);
	return (0);
}
