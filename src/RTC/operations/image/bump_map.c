/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:09:50 by mdomnik           #+#    #+#             */
/*   Updated: 2025/01/14 22:32:18 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

t_bump_map *bump_map_from_ppm(const char *filename, double scale, t_uv_val (*uv_maps)(t_point3))
{
    t_canvas *height_map = canvas_from_ppm(filename);
    if (!height_map) {
        fprintf(stderr, "Error loading bump map: %s\n", filename);
        exit(EXIT_FAILURE);
    }
    t_bump_map *bump_map = malloc(sizeof(t_bump_map));
    bump_map->height_map = height_map;
    bump_map->scale = scale;
	bump_map->uv_map = uv_maps;
    return bump_map;
}

t_vec3 perturb_normal(t_shape *shape, t_point3 *local_point, t_vec3 local_normal) {

	if (!shape->material.bump_map || !shape->material.bump_map->height_map) {
        return local_normal;
    }
    t_bump_map *bump_map = shape->material.bump_map;
    t_canvas *height_map = bump_map->height_map;

    t_uv_val uv = bump_map->uv_map(*local_point);
    int width = height_map->width;
    int height = height_map->height;

    int u_pixel = fmin(width - 1, fmax(0, (int)(uv.u * (width - 1))));
    int v_pixel = fmin(height - 1, fmax(0, (int)((1 - uv.v) * (height - 1)))); // Flip v for alignment

    float h_left = height_map->pixels[v_pixel][(int)fmax(0, u_pixel - 1)].r;
    float h_right = height_map->pixels[v_pixel][(int)fmin(width - 1, u_pixel + 1)].r;
    float h_up = height_map->pixels[(int)fmax(0, v_pixel - 1)][u_pixel].r;
    float h_down = height_map->pixels[(int)fmin(height - 1, v_pixel + 1)][u_pixel].r;

    float dU = (h_right - h_left) * bump_map->scale;
    float dV = (h_down - h_up) * bump_map->scale;

    t_vec3 tangent = new_vec3(1, 0, dU);
    t_vec3 bitangent = new_vec3(0, 1, dV);

    t_vec3 perturbed_normal = add_tuples(local_normal, add_tuples(tangent, bitangent));

    return normalize(perturbed_normal);
}



