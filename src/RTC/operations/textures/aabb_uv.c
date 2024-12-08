/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aabb_uv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 20:16:01 by mdomnik           #+#    #+#             */
/*   Updated: 2024/12/08 18:51:42 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

t_uv_align_check *uv_align_check(t_color3 main, t_color3 ul, t_color3 ur, t_color3 bl, t_color3 br) {
    t_uv_align_check *pattern = malloc(sizeof(t_uv_align_check));
    if (!pattern) {
        fprintf(stderr, "Error: Could not allocate memory for UV align check pattern.\n");
        exit(EXIT_FAILURE);
    }
    pattern->main = main;
    pattern->ul = ul;
    pattern->ur = ur;
    pattern->bl = bl;
    pattern->br = br;
    return pattern;
}


t_color3 uv_pattern_at_align_check(t_uv_align_check *pattern, float u, float v) {
    // Check top corners
    if (v > 0.8) {
        if (u < 0.2) return pattern->ul; // Upper-left corner
        if (u > 0.8) return pattern->ur; // Upper-right corner
    }
    // Check bottom corners
    else if (v < 0.2) {
        if (u < 0.2) return pattern->bl; // Bottom-left corner
        if (u > 0.8) return pattern->br; // Bottom-right corner
    }
    // Default to main color
    return pattern->main;
}

