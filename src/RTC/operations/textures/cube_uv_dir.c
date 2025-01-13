/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_uv_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:21:41 by mdomnik           #+#    #+#             */
/*   Updated: 2025/01/13 20:59:42 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

t_uv_val cube_uv_front(t_point3 point) {
    t_uv_val uv;
    uv.u = ((point.x + 1.0f) / 2.0f);
    uv.v = ((point.y + 1.0f) / 2.0f);
    return uv;
}

// UV mapping for the back face
t_uv_val cube_uv_back(t_point3 point) {
    t_uv_val uv;
    uv.u = ((-point.x + 1.0f) / 2.0f);
    uv.v = ((point.y + 1.0f) / 2.0f);
    return uv;
}

// UV mapping for the left face
t_uv_val cube_uv_left(t_point3 point) {
    t_uv_val uv;
    uv.u = fmod((point.z + 1.0) + 2.0, 2.0) / 2.0; // Adjust z to map 1 to 0 and -1 to 1
    uv.v = fmod((point.y + 1.0) + 2.0, 2.0) / 2.0; // Map y to v (no change needed)
    return uv;
}

// UV mapping for the right face
t_uv_val cube_uv_right(t_point3 point) {
    t_uv_val uv;
    uv.u = fmod((1.0 - point.z) + 2.0, 2.0) / 2.0; // Reverse z for left face
    uv.v = fmod((point.y + 1.0) + 2.0, 2.0) / 2.0; // Map y to v
    return uv;
}

// UV mapping for the upper face
t_uv_val cube_uv_up(t_point3 point) {
    t_uv_val uv;
    uv.u = ((point.x + 1.0f) / 2.0f);
    uv.v = ((-point.z + 1.0f) / 2.0f);
    return uv;
}

// UV mapping for the lower face
t_uv_val cube_uv_down(t_point3 point) {
    t_uv_val uv;
    uv.u = ((point.x + 1.0f) / 2.0f);
    uv.v = ((point.z + 1.0f) / 2.0f);
    return uv;
}
