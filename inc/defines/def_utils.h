/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:45:30 by mdomnik           #+#    #+#             */
/*   Updated: 2024/12/08 18:37:54 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_UTILS_H
# define DEF_UTILS_H

//operations/utils/default.c
t_material *default_material(void);
t_world	*default_world(void);
t_world *test_world(void);
t_world *test_world_plane(void);
t_world *test_textures(void);
t_world *test_planar_mapping_scene(void);
t_world *test_cylindrical_mapping_scene(void);
t_world *test_uv_align_check_scene(void);

//operations/utils/utils_1.c
bool		is_equal(float a, float b);
float		deg_to_rad(float deg);
int			color_to_int(t_color3 color);

#endif
