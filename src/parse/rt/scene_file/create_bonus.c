/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:47:33 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/24 17:31:30 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

int		check_bonus_objects(t_scene *scene, t_world *world, int i)
{
	if (ft_strcmp(scene->scene_objects[i][0], "co") == 0)
	{
		if (create_cone(world, scene->scene_objects[i]) == -1)
			return (-1);
	}
	if (ft_strcmp(scene->scene_objects[i][0], "hg") == 0)
	{
		if (create_hourglass(world, scene->scene_objects[i]) == -1)
			return (-1);
	}
	if (ft_strcmp(scene->scene_objects[i][0], "cb") == 0)
	{
		if (create_cube(world, scene->scene_objects[i]) == -1)
			return (-1);
	}
	if (ft_strcmp(scene->scene_objects[i][0], "obj") == 0)
	{
		if (create_obj(world, scene->scene_objects[i]) == -1)
			return (-1);
	}
	return (0);
}

int	create_cone(t_world *world, char **args)
{
	t_shape		*co;
	char		**coords;
	char		**normal;
	char		**color;
	t_matrix	transform;

	co = cone();
	coords = ft_split(args[1], ',');
	normal = ft_split(args[2], ',');
	color = ft_split(args[5], ',');

	transform = init_identity_matrix(4);
	transform = multiply_matrices(transform, translation(ft_atof(coords[0]), ft_atof(coords[1]) + (ft_atof(args[4]) / 2), ft_atof(coords[2])));
	transform = multiply_matrices(transform, rotation_x(deg_to_rad(ft_atof(normal[0])*180)));
	transform = multiply_matrices(transform, rotation_y(deg_to_rad(ft_atof(normal[1])*180)));
	transform = multiply_matrices(transform, rotation_z(deg_to_rad(ft_atof(normal[2])*180)));
	transform = multiply_matrices(transform, scaling(ft_atof(args[3]) / 2.0, ft_atof(args[4]), ft_atof(args[3]) / 2.0));
	
	co->size_cap.min = -1;
	co->size_cap.max = 0;
	co->size_cap.cap = true;
	co->material.color = new_color3(ft_atof(color[0]), ft_atof(color[1]),
			ft_atof(color[2]));
	co->material.color = div_color(co->material.color);
	set_transform(co, transform);
	add_shape(&world->shapes, co);
	return (0);
}

int	create_hourglass(t_world *world, char **args)
{
	t_shape		*hg;
	char		**coords;
	char		**normal;
	char		**color;
	t_matrix	transform;

	hg = hourglass();
	coords = ft_split(args[1], ',');
	normal = ft_split(args[2], ',');
	color = ft_split(args[5], ',');
	transform = init_identity_matrix(4);
	transform = multiply_matrices(transform, translation(ft_atof(coords[0]), ft_atof(coords[1]), ft_atof(coords[2])));
	transform = multiply_matrices(transform, rotation_x(deg_to_rad(ft_atof(normal[0])*180)));
	transform = multiply_matrices(transform, rotation_y(deg_to_rad(ft_atof(normal[1])*180)));
	transform = multiply_matrices(transform, rotation_z(deg_to_rad(ft_atof(normal[2])*180)));
	transform = multiply_matrices(transform, scaling(ft_atof(args[3]), ft_atof(args[4]), ft_atof(args[3])));
	
	hg->size_cap.min = -0.5;
	hg->size_cap.max = 0.5;
	hg->size_cap.cap = true;
	hg->material.color = new_color3(ft_atof(color[0]), ft_atof(color[1]),
			ft_atof(color[2]));
	hg->material.color = div_color(hg->material.color);
	set_transform(hg, transform);
	add_shape(&world->shapes, hg);
	return (0);
}

int	create_cube(t_world *world, char **args)
{
	t_shape		*cb;
	char		**coords;
	char		**normal;
	char		**color;
	t_matrix	transform;

	cb = cube();
	coords = ft_split(args[1], ',');
	normal = ft_split(args[2], ',');
	color = ft_split(args[4], ',');
	transform = init_identity_matrix(4);
	transform = multiply_matrices(transform, translation(ft_atof(coords[0]), ft_atof(coords[1]), ft_atof(coords[2])));
	transform = multiply_matrices(transform, rotation_x(deg_to_rad(ft_atof(normal[0])*180)));
	transform = multiply_matrices(transform, rotation_y(deg_to_rad(ft_atof(normal[1])*180)));
	transform = multiply_matrices(transform, rotation_z(deg_to_rad(ft_atof(normal[2])*180)));
	transform = multiply_matrices(transform, scaling(ft_atof(args[3]) / 2.0, ft_atof(args[3]) / 2.0, ft_atof(args[3]) / 2.0));
	
	cb->material.color = new_color3(ft_atof(color[0]), ft_atof(color[1]),
			ft_atof(color[2]));
	cb->material.color = div_color(cb->material.color);
	set_transform(cb, transform);
	add_shape(&world->shapes, cb);
	return (0);
}

int	create_obj(t_world *world, char **args)
{
	t_shape		*obj;
	t_group		*group;
	t_obj_file	*obj_file;
	char		**coords;
	char		**normal;
	char		**color;
	t_matrix	transform;

	obj_file = parse_obj_file(args[1]);
	group = obj_file->default_group;
	obj = objectGroup_to_group(group);
	coords = ft_split(args[1], ',');
	normal = ft_split(args[2], ',');
	color = ft_split(args[4], ',');
	transform = init_identity_matrix(4);
	transform = multiply_matrices(transform, translation(ft_atof(coords[0]), ft_atof(coords[1]), ft_atof(coords[2])));
	transform = multiply_matrices(transform, rotation_x(deg_to_rad(ft_atof(normal[0])*180)));
	transform = multiply_matrices(transform, rotation_y(deg_to_rad(ft_atof(normal[1])*180)));
	transform = multiply_matrices(transform, rotation_z(deg_to_rad(ft_atof(normal[2])*180)));
	transform = multiply_matrices(transform, scaling(ft_atof(args[3]) / 2.0, ft_atof(args[3]) / 2.0, ft_atof(args[3]) / 2.0));

	obj->material.color = new_color3(ft_atof(color[0]), ft_atof(color[1]),
			ft_atof(color[2]));
	obj->material.color = div_color(obj->material.color);
	set_transform(obj, transform);
	add_shape(&world->shapes, obj);
	return (0);
}

