/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:59:50 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/23 16:45:16 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# define SCENE_OBJECTS	"A,C,L,sp,pl,cy,co"

# define UNIQUE_OBJECTS	"A,C"
# define MANDATORY_OBJECTS	"A,C,L"

//MANDATORY OBJECTS
# define OBJECT_RULES	"A,RATIO,COLOR;\
C,VECTOR,VRANGE,FOV;\
L,VECTOR,FLOAT,COLOR;\
sp,VECTOR,FLOAT,COLOR;\
pl,VECTOR,VRANGE,COLOR;\
cy,VECTOR,VRANGE,FLOAT,FLOAT,COLOR;\
co,VECTOR,VRANGE,FLOAT,FLOAT,COLOR;"


typedef struct s_ambient	t_ambient;
// typedef struct s_camera		t_camera;
typedef struct s_light		t_light;
typedef struct s_sphere		t_sphere;
typedef struct s_plane		t_plane;
typedef struct s_cylinder	t_cylinder;

typedef struct s_obj		t_obj;
typedef struct s_toremove		t_toremove;

typedef struct s_temp		t_temp;

//ENUM OF OBJECTS
typedef enum e_type
{
	NONE = -1,
	AMBIENT = 0,
	CAMERA = 1,
	LIGHT = 2,

	SPHERE = 3,
	PLANE = 4,
	CUBE = 5,
	CYLINDER = 6,
	CONE = 7,
	GROUP = 8,
	TRIANGLE = 9
}	t_type;

//REQUIRED OBJECT STRUCTS
struct s_ambient
{
	float				light_ratio;
	t_color3			color;
};



struct s_light
{
	t_point3			coords;
	t_color3			color;
	float				brightness;
	struct s_light		*next;
};

// OPTIONAL OBJECT STRUCTS
struct s_sphere
{
	int					id;
	t_point3			coords;
	float				radius;
	t_color3			color;
	t_matrix			transform;
	t_material			*material;
	struct s_sphere		*next;
};

struct s_plane
{
	t_point3			coords;
	t_vec3				normal;
	t_color3			color;
	struct s_plane		*next;
};

struct s_cylinder
{
	t_point3			coords;
	t_vec3				normal;
	float				radius;
	float				height;
	t_color3			color;
	struct s_cylinder	*next;
};

struct s_temp
{
	t_point3			coords;
	t_vec3				normal;
	float				fov;
};

//SCENE STRUCTS
struct s_obj
{
	t_ambient		*ambient;
	t_temp			*camera;
	t_light			*light;
	t_sphere		*sphere;
	t_plane			*plane;
	t_cylinder		*cylinder;
};

struct s_toremove
{
	t_type		type;
	void			*object;
	struct s_toremove	*next;
};



#endif
