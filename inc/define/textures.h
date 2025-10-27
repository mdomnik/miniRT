/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:15:05 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/15 18:10:59 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H
# define TEXTURES_H

//align_check.c
t_uv_align_check	*uv_align_check(t_color3 colors[5]);
t_color3			uv_pattern_at_align_check(t_uv_align_check *pattern,
						float u, float v);
t_pattern			*align_check_map(void *uv_pattern,
						t_uv_val (*uv_map)(t_point3));

//bump_map.c
t_bump_map			*bump_map_from_ppm(const char *filename,
						double scale, t_uv_val (*uv_maps)(t_point3));
t_bump_map			*bump_map_from_ppm_sphere(const char *filename,
						double scale, t_uv_val (*uv_maps)(t_point3, float));
t_vec3				perturb_normal(t_shape *shape,
						t_point3 *local_point, t_vec3 local_normal,
						t_point3 transformed_point);
int					bump_map_get_transform(char *transform,
						t_bump_map *bump_map);

//cube_obj.c
t_pattern			*new_cube_map(t_pattern *faces[6]);
t_directions		face_from_point(t_point3 point);
t_color3			pattern_at_cube_map(t_pattern *pattern, t_point3 point);

//cube_side_align_1.c
t_uv_val			cube_uv_front(t_point3 point);
t_uv_val			cube_uv_back(t_point3 point);
t_uv_val			cube_uv_left(t_point3 point);

//cube_side_align_2.c
t_uv_val			cube_uv_right(t_point3 point);
t_uv_val			cube_uv_up(t_point3 point);
t_uv_val			cube_uv_down(t_point3 point);

//map_basic_obj.c
t_uv_val			spherical_map(t_point3 p, float scale);
t_uv_val			planar_map(t_point3 p);
t_uv_val			cylindrical_map(t_point3 p);

//mapped_cube.c
t_shape				*create_mapped_cube(void);

//pattern_lib.c
t_color3			stripe_at(t_pattern pattern, t_point3 *point);
t_color3			gradient_at(t_pattern *pattern, t_point3 *point);
t_color3			ring_at(t_pattern *pattern, t_point3 *point);
t_color3			checkers_at(t_pattern *pattern, t_point3 *point);

//pattern.c
t_pattern			*new_pattern(t_pattern_type pattern, t_color3 a,
						t_color3 b);
void				set_pattern_transform(t_pattern *pattern,
						t_matrix new_transform);
t_color3			pattern_at_object(t_pattern *pattern,
						t_shape *shape, t_point3 *point);
t_color3			pattern_at(t_pattern *pattern, t_point3 *point,
						t_shape *shape);

//texture_init.c
t_uv				*uv_checkers(int width, int height, t_color3 color_a,
						t_color3 color_b);
t_pattern			*uv_image(t_canvas *canvas);
t_pattern			*texture_map(void *uv_pattern,
						t_uv_val (*uv_map)(t_point3));
t_pattern			*texture_map_sphere(void *uv_pattern,
						t_uv_val (*uv_map)(t_point3, float));

//uv.c
t_color3			uv_pattern_at(t_uv *pattern, float u, float v);
t_color3			uv_pattern_at_image(t_pattern *pattern, double u, double v);

#endif
