/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forward.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:33:02 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/19 18:59:52 by mdomnik          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORWARD_H
# define FORWARD_H

// Basic types
typedef struct s_tuple t_tuple;
typedef struct s_tuple t_point3;
typedef struct s_tuple t_vec3;
typedef struct s_tuple t_color3;
typedef struct s_tuple t_vertex;
typedef struct s_matrix t_matrix;
typedef struct s_ray t_ray;

// Core structures
typedef struct s_comp t_comp;
typedef struct s_loop t_loop;
typedef struct s_world t_world;
typedef struct s_camera t_camera;
typedef struct s_image t_image;

// Scene and objects
typedef struct s_shape t_shape;
typedef struct s_ambient t_ambient;
typedef struct s_light t_light;
typedef struct s_light_p t_light_p;
typedef struct s_sphere t_sphere;
typedef struct s_plane t_plane;
typedef struct s_cylinder t_cylinder;
typedef struct s_triangle t_triangle;
typedef struct s_group t_group;
typedef struct s_obj t_obj;
typedef struct s_obj_file t_obj_file;
typedef struct s_toremove t_toremove;
typedef struct s_temp t_temp;

// Patterns and materials
typedef struct s_pattern t_pattern;
typedef struct s_material t_material;
typedef struct s_uv t_uv;
typedef struct s_uv_val t_uv_val;
typedef struct s_uv_align_check t_uv_align_check;
typedef struct s_cube_map t_cube_map;
typedef struct s_bump_map t_bump_map;
typedef struct s_canvas t_canvas;
typedef struct s_uv_image t_uv_image;

// Rendering and threading
typedef struct s_thread_data t_thread_data;
typedef struct s_render_data t_render_data;
typedef struct s_pixel t_pixel;
typedef struct s_size_cap t_size_cap;
typedef struct s_bounds t_bounds;

// Intersection and computation
typedef struct s_x t_x;
typedef struct s_intersection t_i;

// Scene management
typedef struct s_scene t_scene;
typedef struct s_options t_options;
typedef struct s_flags t_flags;
typedef struct s_string t_string;
typedef struct s_float t_float;
typedef union u_value_type t_value_type;

// Enums
typedef enum e_opts_type t_opts_type;
typedef enum e_type t_type;
typedef enum e_pattern_type t_pattern_type;
typedef enum e_directions t_directions;

#endif 