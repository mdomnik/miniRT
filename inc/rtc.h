/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtc.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:04:51 by mdomnik           #+#    #+#             */
/*   Updated: 2024/11/14 17:44:12 by astavrop         ###   ########.fr       */
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

struct s_canvas
{
	int			width;
	int			height;
	t_color3	**pixels;
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
	t_object	*objects;
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
	t_object		*object;
};

struct s_light_p
{
	t_point3		*position;
	t_color3		*intensity;
};

struct s_world
{
	t_light_p		*light;
	t_object		*objects;
};




t_sphere	*sphere_new(void);



//test TO REMOVE !!!!!!!!!!!!!
void		print_matrix(t_matrix mat);
void		print_tuple(t_tuple tuple);
#endif
