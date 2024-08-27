/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_file.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:59:50 by mdomnik           #+#    #+#             */
/*   Updated: 2024/08/27 16:53:37 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_FILE_H
# define SCENE_FILE_H

//scene_file/scene_file.c
int	parse_scene_file(t_options *options);


# define RULES "SPHERE_RULES, CUBE_RULES"
# define SPHERE_RULES "sp UNLIMITED,UNLIMITED,UNLIMITED UNLIMETED COLOR\n"
# define AMBIENT_RULES "A RANGE COLOR\n"


typedef struct s_color
{
	int		r;
	int		g;
	int		b;
}			t_color;

typedef struct s_ratio
{
	double	range;
}			t_ratio;

typedef struct s_coords
{
	double	x;
	double	y;
	double	z;
}			t_coords;

typedef struct s_vector_range
{
	t_ratio		x;
	t_ratio		y;
	t_ratio		z;
}	t_vector_range;

typedef struct s_f
{
	double f;
} t_float;


// typedef struct s_objects
// {
// 	char	*id;
// 	(void *)object;
// }


// typedef struct s_object
// {
// 	t_vector	origin;
// 	t_vector	direction;
// 	double		distance;
// }	t_object;

// typedef struct s_sphere
// {
// 	struct s_object	obj;
// 	t_vector		center;
// 	double			diameter;
// 	t_color			color;
//	struct s_sphere	*next;
// }			t_sphere;

// typedef struct s_scene
// {
	// t_sphere *spheres;
// }
// 
#endif
