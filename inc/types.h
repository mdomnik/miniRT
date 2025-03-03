/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:39:06 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/26 14:25:16 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include "mrt.h"

typedef struct s_tuple				t_tuple;
typedef struct s_tuple				t_point3;
typedef struct s_tuple				t_vec3;
typedef struct s_tuple				t_color3;
typedef struct s_tuple				t_vertex;

typedef struct s_matrix				t_matrix;

typedef struct s_ray				t_ray;

typedef struct s_comp				t_comp;

typedef struct s_loop				t_loop;

typedef struct s_pattern			t_pattern;

typedef struct s_material			t_material;

typedef struct s_uv_val				t_uv_val;

typedef struct s_uv					t_uv;

typedef struct s_uv_align_check		t_uv_align_check;

typedef struct s_cube_map			t_cube_map;

typedef struct s_bump_map			t_bump_map;

typedef struct s_canvas				t_canvas;

typedef struct s_uv_image			t_uv_image;

typedef enum e_pattern_type
{
	STRIPE,
	GRADIENT,
	RING,
	CHECKERS,
	TEXTURE_MAP,
	ALIGN_CHECK,
	CUBE_MAP,
	UV_IMAGE
}	t_pattern_type;

typedef enum e_directions
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	FRONT,
	BACK
}	t_directions;

struct	s_tuple
{
	union
	{
		float	a[4];
		struct
		{
			float	x;
			float	y;
			float	z;
			float	w; //point is 1, vector is 0
		};
		struct
		{
			float	r;
			float	g;
			float	b;
			float	al;
		};
	};
};

struct s_matrix
{
	union
	{
		float	a[4][4];
		struct
		{
			float	mat[16];
		};
	};
	int			size;
};

struct s_ray
{
	t_point3	orig;
	t_vec3		dir;
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

struct	s_loop
{
	void		*mlx;
	void		*win;
	t_image		*img;
	t_options	*opts;
};

struct s_uv_val
{
	float			u;
	float			v;
};

struct s_uv
{
	int				width;
	int				height;
	t_color3		color_a;
	t_color3		color_b;
};

struct s_uv_align_check
{
	t_color3	main;
	t_color3	ul;
	t_color3	ur;
	t_color3	bl;
	t_color3	br;
};

struct s_pattern
{
	t_color3		a;
	t_color3		b;
	t_matrix		transform;
	t_pattern_type	type;
	void			*uv_pattern;
	t_uv_val		(*uv_map)(t_point3 point);
};

struct s_cube_map
{
	t_pattern	*faces[6];
};

struct s_canvas
{
	int			width;
	int			height;
	t_color3	**pixels;
};

struct s_uv_image
{
	t_canvas	*canvas;
};

struct s_bump_map
{
	t_canvas	*height_map;
	t_uv_val	(*uv_map)(t_point3 point);
	float		scale;
};

struct s_material
{
	t_color3		color;
	t_pattern		*pattern;
	float			ambient;
	float			diffuse;
	float			specular;
	float			shininess;
	float			reflective;
	float			transparency;
	float			refractive_index;
	t_bump_map		*bump_map;
};

typedef struct s_pixel
{
	int	x;
	int	y;
	int	color;
}	t_pixel;

typedef struct s_thread_data
{
	t_loop	*loop;
	int		thread_id;
	int		ac;
	char	**av;
	int		current_y;
}	t_thread_data;

typedef struct s_render_data
{
	t_thread_data	*data;
	t_world			*world;
	t_ray			**ray;
	t_comp			**comp;
	int				coords[2];
}	t_render_data;

#endif /* TYPES_H */
