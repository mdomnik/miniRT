/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtc.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:04:51 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/22 00:14:41 by mdomnik          ###   ########.fr       */
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

#define DEFAULT_WIDTH 800
#define DEFAULT_HEIGHT 600

typedef struct s_scene	t_scene;

typedef struct s_options	t_options;

typedef struct s_x	t_x;

typedef struct s_intersection		t_i;

typedef struct s_loop		t_loop;

typedef struct s_light_p	t_light_p;

typedef struct s_world		t_world;

//-----------------------------------------

typedef struct s_camera		t_camera;

typedef struct s_shape		t_shape;

typedef struct s_comp		t_comp;

typedef struct s_size_cap	t_size_cap;

typedef struct s_bounds		t_bounds;

typedef struct s_triangle	t_triangle;

typedef struct s_obj_file		t_obj_file;

typedef struct s_group		t_group;

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
	t_point3			position;
	t_color3			intensity;
	struct s_light_p	*next;
};

struct s_world
{
	t_light_p		*light;
	t_shape			*shapes;
	t_camera		*camera;
};

struct	s_loop
{
	void		*mlx;
	void		*win;
	void		*image;
	t_world		*world;
	t_camera	*camera;
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
	float			y_angle;
	t_matrix		transform;
};

struct s_size_cap
{
	float			min;
	float			max;
	bool			cap;
};

struct s_bounds
{
	t_point3		min;
	t_point3		max;
};

struct	s_shape
{
	t_type				type;
	t_matrix			transform;
	t_material			material;
	t_size_cap			size_cap;
	t_ray				*saved_ray;

	t_triangle			*triangle;

	struct s_shape		*children;
	int					children_count;
	struct s_shape		*parent;

	struct s_bounds    (*bounds)(struct s_shape *shape);
	struct s_shape		*next;
};

struct s_triangle
{
	t_point3		p1;
	t_point3		p2;
	t_point3		p3;
	t_vec3			e1;
	t_vec3			e2;
	t_vec3			normal;
};

struct s_group
{
	char				*name;
	t_shape				*group;
	int					faces_count;
	struct s_group		*next;
};

struct s_obj_file
{
	t_vertex		vertices[MAX_VERTEX_COUNT + 1];
	t_triangle		faces[MAX_FACE_COUNT];
	t_group			*default_group;
	int				vertex_count;
	int				face_count;
};

#endif
