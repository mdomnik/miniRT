/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:58:01 by astavrop          #+#    #+#             */
/*   Updated: 2025/03/11 17:31:25 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

static void	set_cone_transform(t_shape *co, char **coords,
		char **normal, char **args)
{
	t_matrix	transform;

	transform = init_identity_matrix(4);
	transform = multiply_matrices(transform,
			translation(ft_atof_mrt(coords[0]),
				ft_atof_mrt(coords[1]) + (ft_atof_mrt(args[4]) / 2),
				ft_atof_mrt(coords[2])));
	transform = multiply_matrices(transform,
			rotation_x(deg_to_rad(ft_atof_mrt(normal[0]) * 180)));
	transform = multiply_matrices(transform,
			rotation_y(deg_to_rad(ft_atof_mrt(normal[1]) * 180)));
	transform = multiply_matrices(transform,
			rotation_z(deg_to_rad(ft_atof_mrt(normal[2]) * 180)));
	transform = multiply_matrices(transform,
			scaling(ft_atof_mrt(args[3]) / 2.0,
				ft_atof_mrt(args[4]),
				ft_atof_mrt(args[3]) / 2.0));
	set_transform(co, transform);
}

int	create_cone(t_world *world, char **args)
{
	t_shape	*co;
	char	**coords;
	char	**normal;
	char	**color;

	co = cone();
	coords = ft_split(args[1], ',');
	normal = ft_split(args[2], ',');
	color = ft_split(args[5], ',');
	co->size_cap.min = -1;
	co->size_cap.max = 0;
	co->size_cap.cap = true;
	set_cone_transform(co, coords, normal, args);
	if (args[6])
		get_material(args[6], &co->material, co);
	co->material.color = new_color3(ft_atof_mrt(color[0]),
			ft_atof_mrt(color[1]), ft_atof_mrt(color[2]));
	co->material.color = div_color(co->material.color);
	set_cylinder_pattern(co);
	add_shape(&world->shapes, co);
	free_double(color);
	free_double(coords);
	free_double(normal);
	return (0);
}
