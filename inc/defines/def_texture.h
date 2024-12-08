/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_texture.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:39:32 by mdomnik           #+#    #+#             */
/*   Updated: 2024/12/08 18:54:18 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_TEXTURE_H
# define DEF_TEXTURE_H

// t_uv_val spherical_map(t_point3 point);
// t_uv_val planar_map(t_point3 point);
// t_uv_val cylindrical_map(t_point3 point);

t_uv *uv_checkers(int width, int height, t_color3 color_a, t_color3 color_b);
t_color3 uv_pattern_at(t_uv *pattern, float u, float v);
t_uv_val spherical_map(t_point3 p);
t_pattern *texture_map(void *uv_pattern, t_uv_val (*uv_map)(t_point3));
t_color3 uv_pattern_at(t_uv *pattern, float u, float v);
t_uv_val planar_map(t_point3 p);
t_uv_val cylindrical_map(t_point3 p);
t_uv_align_check *uv_align_check(t_color3 main, t_color3 ul, t_color3 ur, t_color3 bl, t_color3 br);
t_color3 uv_pattern_at_align_check(t_uv_align_check *align_check, float u, float v);
t_pattern *align_check_map(void *uv_pattern, t_uv_val (*uv_map)(t_point3));

#endif
