/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:09:50 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/19 13:02:28 by mdomnik          ###   ########.fr       */
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

static void	get_height_values(t_bump_map *bump_map, t_uv_val uv,
	float *heights)
{
	t_canvas	*height_map;
	int			width;
	int			height;
	int			u_pixel;
	int			v_pixel;

	height_map = bump_map->height_map;
	width = height_map->width;
	height = height_map->height;
	u_pixel = fmin(width - 1, fmax(0, (int)(uv.u * (width - 1))));
	v_pixel = fmin(height - 1, fmax(0, (int)((1 - uv.v) * (height - 1))));
	heights[0] = height_map->pixels[v_pixel][(int)fmax(0, u_pixel - 1)].r;
	heights[1] = height_map->pixels[v_pixel][(int)fmin(
			width - 1, u_pixel + 1)].r;
	heights[2] = height_map->pixels[(int)fmax(0, v_pixel - 1)][u_pixel].r;
	heights[3] = height_map->pixels[(int)fmin(
			height - 1, v_pixel + 1)][u_pixel].r;
}

#define DU 0
#define DV 1

t_vec3	perturb_normal(t_shape *shape, t_point3 *local_point,
	t_vec3 local_normal)
{
	t_bump_map	*bump_map;
	float		heights[4];
	float		d[2];
	t_vec3		perturbed_normal;
	t_uv_val	uv;

	if (!shape->material.bump_map || !shape->material.bump_map->height_map)
		return (local_normal);
	bump_map = shape->material.bump_map;
	uv = bump_map->uv_map(*local_point);
	get_height_values(bump_map, uv, heights);
	d[DU] = (heights[1] - heights[0]) * bump_map->scale;
	d[DV] = (heights[3] - heights[2]) * bump_map->scale;
	perturbed_normal = add_tuple(local_normal,
			add_tuple(new_vec3(1, 0, d[DU]), new_vec3(0, 1, d[DV])));
	return (normalize(perturbed_normal));
}
