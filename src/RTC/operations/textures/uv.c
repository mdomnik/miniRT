/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uv.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:39:17 by mdomnik           #+#    #+#             */
/*   Updated: 2024/12/08 18:54:08 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

t_uv *uv_checkers(int width, int height, t_color3 color_a, t_color3 color_b) {
    t_uv *pattern = malloc(sizeof(t_uv));
    if (!pattern) {
        fprintf(stderr, "Error: Could not allocate memory for UV checkers.\n");
        exit(EXIT_FAILURE);
    }
    pattern->width = width;
    pattern->height = height;
    pattern->color_a = color_a;
    pattern->color_b = color_b;
    return pattern;
}

t_pattern *texture_map(void *uv_pattern, t_uv_val (*uv_map)(t_point3)) {
    t_pattern *pattern = malloc(sizeof(t_pattern));
    if (!pattern) {
        fprintf(stderr, "Error: Could not allocate memory for texture map.\n");
        exit(EXIT_FAILURE);
    }

    pattern->type = TEXTURE_MAP;
    pattern->uv_pattern = uv_pattern;
    pattern->uv_map = uv_map;
    pattern->transform = *init_identity_matrix(4); // Default transform
    pattern->a = NULL; // Not used for texture maps
    pattern->b = NULL;

    return pattern;
}

t_pattern *align_check_map(void *uv_pattern, t_uv_val (*uv_map)(t_point3))
{
	t_pattern *pattern = malloc(sizeof(t_pattern));
	if (!pattern) {
		fprintf(stderr, "Error: Could not allocate memory for align check map.\n");
		exit(EXIT_FAILURE);
	}

	pattern->type = ALIGN_CHECK;
	pattern->uv_pattern = uv_pattern;
	pattern->uv_map = uv_map;
	pattern->transform = *init_identity_matrix(4); // Default transform
	pattern->a = NULL; // Not used for texture maps
	pattern->b = NULL;

	return pattern;
}

t_color3 uv_pattern_at(t_uv *pattern, float u, float v)
{
    int u2 = (int)floor(u * pattern->width);
    int v2 = (int)floor(v * pattern->height);

    if ((u2 + v2) % 2 == 0) {
        return pattern->color_a;
    } else {
        return pattern->color_b;
    }
}

