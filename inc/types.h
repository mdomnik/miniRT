/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:39:06 by mdomnik           #+#    #+#             */
/*   Updated: 2024/11/12 17:12:13 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

typedef struct s_tuple	t_tuple;
typedef struct s_tuple	t_point3;
typedef struct s_tuple	t_vec3;
typedef struct s_tuple	t_color3;

typedef struct s_matrix	t_matrix;

typedef struct s_ray	t_ray;

typedef struct s_material	t_material;

struct	s_tuple
{
	union {
			float	a[4];
			struct {
				float	x;
				float	y;
				float	z;
				float	w; //point is 1, vector is 0
			};
			struct {
				float	r;
				float	g;
				float	b;
				float	al;
			};
	};
};

struct s_matrix
{
	union {
		float	a[4][4];
		struct {
			float	mat[16];
		};
	};
	int size;
};

struct s_ray
{
	t_point3	orig;
	t_vec3		dir;
};

struct s_material
{
	t_color3		*color;
	float			ambient;
	float			diffuse;
	float			specular;
	float			shininess;
};
