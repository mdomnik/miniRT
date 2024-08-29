/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_file.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:59:50 by mdomnik           #+#    #+#             */
/*   Updated: 2024/08/29 17:54:20 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_FILE_H
# define SCENE_FILE_H

# define SCENE_OBJECTS	"A,C,L,SP,PL,CY"

//REQUIRED OBJECT STRUCTS
typedef struct s_ambient
{
	char	*id;
	double	ratio;
	t_color	color;
} t_ambient;

typedef struct s_camera
{
	char	*id;
	t_vector	coords;
	t_vector_range	vector_range;
	double	fov;
}	t_camera;

typedef struct s_light
{
	char			*id;
	t_vector		coords;
	double			ratio;
	t_color			color;
	struct s_light	*next;
}	t_light;

// OPTIONAL OBJECT STRUCTS

typedef struct s_sphere
{
	char	*id;
	t_vector	coords;
	double		diameter;
	t_color		color;
}	t_sphere;

//SCENE STRUCTS
typedef struct s_obj
{
	t_ambient	ambient;
	t_camera	camera;
	t_light		light;
	t_sphere	sphere;
}	t_obj;

typedef struct s_scene
{
	char	*scene_file;
	char	***scene_objects;
	t_obj	*obj;
}	t_scene;

#endif