/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:47:33 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/23 23:44:50 by mdomnik          ###   ########.fr       */
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
	return (0);
}

int	create_cone(t_world *world, char **args)
{
	t_shape		*co;
	char		**coords;
	char		**normal;
	char		**color;
	t_matrix	transform;

	float		correction;

	co = cone();
	coords = ft_split(args[1], ',');
	normal = ft_split(args[2], ',');
	color = ft_split(args[5], ',');

	correction = (ft_atof(args[4]) * fabs(ft_atof(normal[2])));
	printf("correct: %f\n", correction);
	transform = init_identity_matrix(4);
	if (ft_atof(normal[2]) >= 0)
		transform = multiply_matrices(transform, translation(ft_atof(coords[0]) - correction, ft_atof(coords[1]) - correction - 1 + (ft_atof(args[4]) / 2), ft_atof(coords[2])));
	else
		transform = multiply_matrices(transform, translation(ft_atof(coords[0]) + correction, ft_atof(coords[1]) - correction - 1 + (ft_atof(args[4]) / 2), ft_atof(coords[2])));
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
