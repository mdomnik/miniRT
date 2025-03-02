/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:20:07 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/26 15:46:35 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

static void	set_cylinder_transform(t_shape *cy, char **coords,
		char **normal, char **args)
{
	t_matrix	transform;

	transform = init_identity_matrix(4);
	transform = multiply_matrices(transform,
			translation(ft_atof(coords[0]), ft_atof(coords[1]),
				ft_atof(coords[2])));
	transform = multiply_matrices(transform,
			rotation_x(deg_to_rad(ft_atof(normal[0]) * 180)));
	transform = multiply_matrices(transform,
			rotation_y(deg_to_rad(ft_atof(normal[1]) * 180)));
	transform = multiply_matrices(transform,
			rotation_z(deg_to_rad(ft_atof(normal[2]) * 180)));
	transform = multiply_matrices(transform,
			scaling(ft_atof(args[3]) / 2.0, ft_atof(args[4]),
				ft_atof(args[3]) / 2.0));
	set_transform(cy, transform);
}

static void	set_cylinder_pattern(t_shape *cy)
{
	t_uv	*uv;

	if (!cy->material.pattern)
		return ;
	set_uv_pattern(cy);
	if (cy->material.pattern->type == CHECKERS)
	{
		uv = uv_checkers(10, 10, cy->material.pattern->a,
				cy->material.pattern->b);
		free(cy->material.pattern);
		cy->material.pattern = texture_map(uv, cylindrical_map);
	}
}

int	create_cylinder(t_world *world, char **args)
{
	t_shape	*cy;
	char	**coords;
	char	**normal;
	char	**color;

	cy = cylinder();
	coords = ft_split(args[1], ',');
	normal = ft_split(args[2], ',');
	color = ft_split(args[5], ',');
	cy->size_cap.min = -0.5;
	cy->size_cap.max = 0.5;
	cy->size_cap.cap = true;
	set_cylinder_transform(cy, coords, normal, args);
	if (args[6])
		get_material(args[6], &cy->material);
	cy->material.color = new_color3(ft_atof(color[0]), ft_atof(color[1]),
			ft_atof(color[2]));
	cy->material.color = div_color(cy->material.color);
	set_cylinder_pattern(cy);
	add_shape(&world->shapes, cy);
	return (0);
}
