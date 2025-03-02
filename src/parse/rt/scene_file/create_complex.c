/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_complex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-02 16:57:56 by astavrop          #+#    #+#             */
/*   Updated: 2025-03-02 16:57:56 by astavrop         ###   ########:w        */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

#define COORD 0
#define NORMAL 1
#define COLOR 2

static void	set_obj_transform(t_shape *obj, char **coords,
		char **normal, char **args)
{
	t_matrix	transform;

	transform = init_identity_matrix(4);
	transform = multiply_matrices(transform,
			translation(ft_atof(coords[0]),
				ft_atof(coords[1]),
				ft_atof(coords[2])));
	transform = multiply_matrices(transform,
			rotation_x(deg_to_rad(ft_atof(normal[0]) * 180)));
	transform = multiply_matrices(transform,
			rotation_y(deg_to_rad(ft_atof(normal[1]) * 180)));
	transform = multiply_matrices(transform,
			rotation_z(deg_to_rad(ft_atof(normal[2]) * 180)));
	transform = multiply_matrices(transform,
			scaling(ft_atof(args[4]) / 2.0,
				ft_atof(args[4]) / 2.0,
				ft_atof(args[4]) / 2.0));
	set_transform(obj, transform);
}

int	create_obj(t_world *world, char **args)
{
	t_shape		*obj;
	t_group		*group;
	t_obj_file	*obj_file;
	char		**vectors[3];

	obj_file = parse_obj_file(args[1]);
	group = obj_file->default_group;
	obj = objectGroup_to_group(group);
	vectors[COORD] = ft_split(args[2], ',');
	vectors[NORMAL] = ft_split(args[3], ',');
	vectors[COLOR] = ft_split(args[5], ',');
	set_obj_transform(obj, vectors[COORD], vectors[NORMAL], args);
	if (args[6])
		get_material(args[6], &obj->material);
	obj->material.color = new_color3(ft_atof(vectors[COLOR][0]),
			ft_atof(vectors[COLOR][1]),
			ft_atof(vectors[COLOR][2]));
	obj->material.color = div_color(obj->material.color);
	obj->bounds_cache = group_bounds(obj);
	inherit_material(obj);
	add_shape(&world->shapes, obj);
	return (0);
}

int	create_skybox(t_world *world, char **args)
{
	t_shape		*sb;
	char		**color;
	t_matrix	transform;

	sb = create_mapped_cube();
	sb->type = SKYBOX;
	color = ft_split(args[1], ',');
	transform = init_identity_matrix(4);
	transform = scaling(100, 100, 100);
	sb->material.diffuse = 0;
	sb->material.specular = 0;
	sb->material.reflective = 0;
	sb->material.ambient = 1;
	sb->material.color = new_color3(ft_atof(color[0]),
			ft_atof(color[1]), ft_atof(color[2]));
	sb->material.color = div_color(sb->material.color);
	if (args[2])
		get_skybox(args[2], &sb->material);
	set_transform(sb, transform);
	add_shape(&world->shapes, sb);
	return (0);
}
