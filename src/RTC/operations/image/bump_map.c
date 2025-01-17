/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:09:50 by mdomnik           #+#    #+#             */
/*   Updated: 2025/01/17 22:12:06 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

t_bump_map	*bump_map_from_ppm(const char *filename,
	double scale, t_uv_val (*uv_maps)(t_point3))
{
	t_canvas	*height_map;
	t_bump_map	*bump_map;

	height_map = canvas_from_ppm(filename);
	if (!height_map)
	{
		fprintf(stderr, "Error loading bump map: %s\n", filename);
		exit(EXIT_FAILURE);
	}
	bump_map = malloc(sizeof(t_bump_map));
	bump_map->height_map = height_map;
	bump_map->scale = scale;
	bump_map->uv_map = uv_maps;
	return (bump_map);
}

t_vec3	perturb_normal(t_shape *shape,
	t_point3 *local_point, t_vec3 local_normal)
{
	t_bump_map	*bump_map;
	t_canvas	*height_map;
	t_uv_val	uv;
	int			width;
	int			height;
	int			u_pixel;
	int			v_pixel;
	float		h_left;
	float		h_right;
	float		h_up;
	float		h_down;
	float		dU;
	float		dV;
	t_vec3		tangent;
	t_vec3		bitangent;
	t_vec3		perturbed_normal;

	if (!shape->material.bump_map || !shape->material.bump_map->height_map)
		return (local_normal);
	bump_map = shape->material.bump_map;
	height_map = bump_map->height_map;
	uv = bump_map->uv_map(*local_point);
	width = height_map->width;
	height = height_map->height;
	u_pixel = fmin(width - 1, fmax(0, (int)(uv.u * (width - 1))));
	v_pixel = fmin(height - 1, fmax(0, (int)((1 - uv.v) * (height - 1))));
	h_left = height_map->pixels[v_pixel][(int)fmax(0, u_pixel - 1)].r;
	h_right = height_map->pixels[v_pixel][(int)fmin(width - 1, u_pixel + 1)].r;
	h_up = height_map->pixels[(int)fmax(0, v_pixel - 1)][u_pixel].r;
	h_down = height_map->pixels[(int)fmin(height - 1, v_pixel + 1)][u_pixel].r;
	dU = (h_right - h_left) * bump_map->scale;
	dV = (h_down - h_up) * bump_map->scale;
	tangent = new_vec3(1, 0, dU);
	bitangent = new_vec3(0, 1, dV);
	perturbed_normal = add_tuples(local_normal, add_tuples(tangent, bitangent));
	return (normalize(perturbed_normal));
}
