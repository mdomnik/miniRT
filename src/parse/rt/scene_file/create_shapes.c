/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_shapes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:58:13 by astavrop          #+#    #+#             */
/*   Updated: 2025/03/07 18:00:00 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

static void	set_hourglass_transform(t_shape *hg, char **coords,
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
			scaling(ft_atof(args[3]),
				ft_atof(args[4]),
				ft_atof(args[3])));
	set_transform(hg, transform);
}

int	create_hourglass(t_world *world, char **args)
{
	t_shape	*hg;
	char	**coords;
	char	**normal;
	char	**color;

	hg = hourglass();
	coords = ft_split(args[1], ',');
	normal = ft_split(args[2], ',');
	color = ft_split(args[5], ',');
	hg->size_cap.min = -0.5;
	hg->size_cap.max = 0.5;
	hg->size_cap.cap = true;
	set_hourglass_transform(hg, coords, normal, args);
	if (args[6])
		get_material(args[6], &hg->material);
	hg->material.color = new_color3(ft_atof(color[0]),
			ft_atof(color[1]), ft_atof(color[2]));
	hg->material.color = div_color(hg->material.color);
	add_shape(&world->shapes, hg);
	free_double(color);
	free_double(coords);
	free_double(normal);
	return (0);
}

static void	set_cube_transform(t_shape *cb, char **coords,
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
			scaling(ft_atof(args[3]) / 2.0,
				ft_atof(args[3]) / 2.0,
				ft_atof(args[3]) / 2.0));
	set_transform(cb, transform);
}

int	create_cube(t_world *world, char **args)
{
	t_shape	*cb;
	char	**coords;
	char	**normal;
	char	**color;

	cb = cube();
	coords = ft_split(args[1], ',');
	normal = ft_split(args[2], ',');
	color = ft_split(args[4], ',');
	set_cube_transform(cb, coords, normal, args);
	if (args[5])
		get_material(args[5], &cb->material);
	cb->material.color = new_color3(ft_atof(color[0]),
			ft_atof(color[1]), ft_atof(color[2]));
	cb->material.color = div_color(cb->material.color);
	add_shape(&world->shapes, cb);
	free_double(color);
	free_double(coords);
	free_double(normal);
	return (0);
}
