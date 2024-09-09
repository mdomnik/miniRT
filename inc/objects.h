/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:59:50 by mdomnik           #+#    #+#             */
/*   Updated: 2024/09/09 17:17:06 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# define SCENE_OBJECTS	"A,C,L,sp,pl,cy"

# define UNIQUE_OBJECTS	"A,C"
# define MANDATORY_OBJECTS	"A,C,L"

//MANDATORY OBJECTS
# define OBJECT_RULES	"A,RATIO,COLOR;\
C,VECTOR,VRANGE,FOV;\
L,VECTOR,FLOAT,COLOR;\
sp,VECTOR,FLOAT,COLOR;\
pl,VECTOR,VRANGE,COLOR;\
cy,VECTOR,VRANGE,FLOAT,FLOAT,COLOR"

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
	double			light_ratio;
	t_color			color;
}	t_ambient;

typedef struct s_camera
{
	t_vector		coords;
	t_vector		vrange;
	double			fov;
}	t_camera;

typedef struct s_light
{
	t_vector		coords;
	t_color			color;
	double			brightness;
	struct s_light	*next;
}	t_light;

// OPTIONAL OBJECT STRUCTS
typedef struct s_sphere
{
	t_vector		coords;
	double			diameter;
	t_color			color;
	struct s_sphere	*next;
}	t_sphere;

typedef struct s_plane
{
	t_vector		coords;
	t_vector		normal;
	t_color			color;
	struct s_plane	*next;
}	t_plane;

typedef struct s_cylinder
{
	t_vector			coords;
	t_vector			normal;
	double				diameter;
	double				height;
	t_color				color;
	struct s_cylinder	*next;
}	t_cylinder;

//SCENE STRUCTS
typedef struct s_obj
{
	t_ambient	*ambient;
	t_camera	*camera;
	t_light		*light;
	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cylinder;
}	t_obj;

#endif
