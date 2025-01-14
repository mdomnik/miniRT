/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtc.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:04:51 by mdomnik           #+#    #+#             */
/*   Updated: 2025/01/13 23:53:07 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTC_H
# define RTC_H

#define R 0
#define G 1
#define B 2

#define MAT2 2
#define MAT3 3
#define MAT4 4

typedef struct s_scene	t_scene;

typedef struct s_options	t_options;

typedef struct s_canvas	t_canvas;

typedef struct s_project	t_project;

typedef struct s_x	t_x;

typedef struct s_intersection		t_i;

typedef struct s_light_p	t_light_p;

typedef struct s_world		t_world;

//-----------------------------------------

typedef struct s_camera		t_camera;

typedef struct s_shape		t_shape;

typedef struct s_comp		t_comp;

typedef struct s_uv_image	t_uv_image;


struct s_canvas
{
	int			width;
	int			height;
	t_color3	**pixels;
};

struct s_uv_image
{
    t_canvas *canvas;
};


struct s_scene
{
	char		*scene_file;
	char		***scene_objects;
};

// OPTIONS STRUCT
struct s_options
{
	int			opts_flags;
	t_scene		scene;
	t_flags		*values;
	t_obj		objects;
};

struct s_project
{
	mlx_t		*window;
	mlx_image_t	*image;
	t_options	*options;
	t_toremove	*objects;
	t_canvas	canvas;
};

struct s_x
{
	int			count;
	t_i			*i;
};

struct s_intersection
{
	float			t;
	t_shape		*shape;
};

struct s_light_p
{
	t_point3			*position;
	t_color3			*intensity;
	struct s_light_p	*next;
};

struct s_world
{
	t_light_p		*light;
	t_shape			*shapes;
};

struct s_comp
{
	float			t;
	t_shape			*shape;
	t_point3		point;
	t_vec3			eyev;
	t_vec3			normalv;
	t_vec3			reflectv;
	int				inside;
	t_point3		over_point;
	t_point3		under_point;
	float			n1;
	float			n2;
};

struct s_camera
{
	int				hsize;
	int				vsize;
	float			fov;
	float			pixel_size;
	float			half_width;
	float			half_height;
	t_matrix		transform;
};

struct	s_shape
{
	t_type				type;
	t_matrix			transform;
	t_material			material;
	t_ray				*saved_ray;
	struct s_shape		*next;
};

//test TO REMOVE !!!!!!!!!!!!!
void		print_matrix(t_matrix mat);
void		print_tuple(t_tuple tuple);
#endif
