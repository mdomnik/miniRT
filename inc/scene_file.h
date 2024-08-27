/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_file.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:59:50 by mdomnik           #+#    #+#             */
/*   Updated: 2024/08/27 16:16:00 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_FILE_H
# define SCENE_FILE_H

//scene_file/scene_file.c
int	parse_scene_file(t_options *options);


# define RULES "SPHERE_RULES, CUBE_RULES"
# define SPHERE_RULES "sp UNLIMITED,UNLIMITED,UNLIMITED UNLIMETED COLOR\n"

// typedef struct s_vector
// {
// 	double	x;
// 	double	y;
// 	double	z;
// }			t_vector;

// typedef struct s_color
// {
// 	int		red;
// 	int		green;
// 	int		blue;
// }			t_color;

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
