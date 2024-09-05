/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_file.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:59:50 by mdomnik           #+#    #+#             */
/*   Updated: 2024/09/05 14:52:31 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_FILE_H
# define SCENE_FILE_H

# define SCENE_OBJECTS	"A,C,L,sp,pl,cy"

# define UNIQUE_OBJECTS	"A,C"

//MANDATORY OBJECTS
# define OBJECT_RULES	"A,FLOAT,COLOR;\
						C,VECTOR,VECTOR_RANGE,FLOAT;\
						L,VECTOR,FLOAT,COLOR;\
						sp,VECTOR,FLOAT,COLOR;\
						pl,VECTOR,VECTOR_RANGE,COLOR;\
						cy,VECTOR,VECTOR_RANGE,FLOAT,FLOAT,COLOR"

//ENUM OF OBJECTS
typedef enum e_objects
{
	AMBIENT = 0,
	CAMERA = 1,
	LIGHT = 2,
	SPHERE = 3,
	PLANE = 4,
	CYLINDER = 5
}	t_objects;

//REQUIRED OBJECT STRUCTS
typedef struct s_ambient
{
	char	*id;
	t_float	ratio;
	t_color	color;
} t_ambient;

typedef struct s_camera
{
	char			*id;
	t_vector		coords;
	t_vector_range	vector_range;
	t_float			fov;
}	t_camera;

typedef struct s_light
{
	char			*id;
	t_vector		coords;
	t_float			ratio;
	t_color			color;
	struct s_light	*next;
}	t_light;

// OPTIONAL OBJECT STRUCTS
typedef struct s_sphere
{
	char	*id;
	t_vector	coords;
	t_float		diameter;
	t_color		color;
}	t_sphere;

typedef struct s_plane
{
	char	*id;
	t_vector		coords;
	t_vector_range	normal;
	t_color			color;
}	t_plane;

typedef struct s_cylinder
{
	char			*id;
	t_vector		coords;
	t_vector_range	normal;
	t_float			diameter;
	t_float			height;
	t_color			color;
}	t_cylinder;

// OBJECT UNION
typedef union u_object
{
	t_sphere	sphere;
	t_plane		plane;
	t_cylinder	cylinder;
}	t_object;

//SCENE STRUCTS
typedef struct s_obj
{
	t_ambient	ambient;
	t_camera	camera;
	t_light		light;
	t_object	objects;
}	t_obj;

typedef struct s_scene
{
	char	*scene_file;
	char	***scene_objects;
}	t_scene;

#endif
