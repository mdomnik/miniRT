/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:45:30 by mdomnik           #+#    #+#             */
/*   Updated: 2025/01/18 17:57:10 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_UTILS_H
# define DEF_UTILS_H

//operations/utils/default.c
t_material *default_material(void);
t_size_cap *default_size_cap(void);
t_world	*default_world(void);
t_world *test_world(void);
t_world *test_world_plane(void);
t_world *test_textures(void);
t_world *test_planar_mapping_scene(void);
t_world *test_cylindrical_mapping_scene(void);
t_world *test_uv_align_check_scene(void);
t_world *setup_cube_scene();
t_world *create_earth_scene(void);
t_world *create_skybox_scene(void);
t_world *create_bump_map_scene(void);
t_world *test_groups_scene(void);
t_world *try_hexagon_scene(void);
t_world *triangle_scene(void);

t_world *benchmark_1(void);
t_world *benchmark_2(void);
t_world *benchmark_3(void);
t_world *benchmark_4(void);
t_world *benchmark_5(void);

//operations/utils/utils_1.c
bool		is_equal(float a, float b);
float		deg_to_rad(float deg);
int			color_to_int(t_color3 color);
int isspace(int c);

#endif
