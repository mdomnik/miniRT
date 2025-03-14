/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:39:06 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/14 14:33:40 by mdomnik          ###   ########.fr       */
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

typedef struct s_mutexes			t_mutexes;

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
	UV_IMAGE,
	FAIL
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
	t_mutexes	*mutexes;
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
	bool			simple;
	void			*uv_pattern;
	t_uv_val		(*uv_map)(t_point3 point);
	t_uv_val		(*uv_map_sphere)(t_point3 point, float scale);
	float			sphere_scale;
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
	t_uv_val	(*uv_map_sphere)(t_point3 point, float scale);
	float		scale;
	float		sphere_scale;
	t_matrix	transform;
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
	float			bump_map_scale;
};

typedef struct s_pixel
{
	float		x;
	float		y;
	int			color;
	bool		computed;
}	t_pixel;

typedef struct s_thread_data
{
	t_loop	*loop;
	t_world	*world;
	int		thread_id;
	int		total_threads;
}	t_thread_data;

typedef struct s_render_data
{
	t_ray	**ray;
	t_comp	**comp;
	int		*pixel_order;
	bool	**cmped_buf;
	int		total_pixels;
	int		width;
	int		height;
	t_image	*img;
	void	*mlx;
	void	*win;
}	t_render_data;

typedef struct s_lighting
{
	t_material	*m;
	t_shape		*shape;
	t_light_p	*light;
	t_point3	*point;
	t_vec3		eyev;
	t_vec3		normalv;
	bool		in_shadow;

}	t_lighting;

typedef struct s_sampling_params
{
	int		grid_size;
	float	step_size;
	float	half_step;

}	t_sampling_params;

typedef struct s_sample_context
{
	t_ray	*rays[RECURSIVE_DEPTH + 1];
	t_comp	*comps[RECURSIVE_DEPTH + 1];
}	t_sample_context;

typedef struct s_mutexes
{
	pthread_mutex_t		world;
	pthread_mutex_t		mlx;
}	t_mutexes;

typedef struct s_aa_sample_data
{
	int		grid_size;
	float	a[4];
	t_pixel	*px;
	t_world	*world;
	t_ray	*sample_ray[RECURSIVE_DEPTH + 1];
	t_comp	*sample_comp[RECURSIVE_DEPTH + 1];
}	t_aa_sample_data;

#endif /* TYPES_H */
