/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:20:07 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/23 19:05:36 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

/**
 * Creates a sphere object and adds it to the list of objects in the options.
 *
 * @param options The options struct containing the list of objects.
 * @param args The arguments for creating the sphere.
 * @return 0 if successful.
 */
int	create_sphere(t_world *world, char **args)
{
	t_shape		*sp;
	char		**coords;
	char		**color;
	float		radius;
	t_matrix	transform;

	sp = sphere();
	coords = ft_split(args[1], ',');
	color = ft_split(args[3], ',');
	transform = init_identity_matrix(4);
	radius = ft_atof(args[2]) / 2.0;
	transform = multiply_matrices(translation(ft_atof(coords[0]), ft_atof(coords[1]), ft_atof(coords[2])), scaling(radius, radius, radius));
	set_transform(sp, transform);
	sp->material.color = new_color3(ft_atof(color[0]), ft_atof(color[1]),
			ft_atof(color[2]));
	sp->material.color = div_color(sp->material.color);
	add_shape(&world->shapes, sp);
	//world->shapes = sp;
	//print_matrix(sp->transform);
	return (0);
}

/**
 * Creates a plane object and adds it to the list of
 * objects in the options structure.
 *
 * @param options The options structure.
 * @param args The arguments for creating the plane.
 * @return 0 if successful.
 */
int	create_plane(t_world *world, char **args)
{
	t_shape		*pl;
	char		**coords;
	char		**normal;
	char		**color;
	t_matrix	transform;

	pl = plane();
	coords = ft_split(args[1], ',');
	normal = ft_split(args[2], ',');
	color = ft_split(args[3], ',');
	transform = init_identity_matrix(4);
	transform = multiply_matrices(transform, translation(ft_atof(coords[0]), ft_atof(coords[1]),
			ft_atof(coords[2])));
	transform = multiply_matrices(transform, rotation_x(deg_to_rad(ft_atof(normal[0])*180)));
	transform = multiply_matrices(transform, rotation_y(deg_to_rad(ft_atof(normal[1])*180)));
	transform = multiply_matrices(transform, rotation_z(deg_to_rad(ft_atof(normal[2])*180)));
	set_transform(pl, transform);
	pl->material.color = new_color3(ft_atof(color[0]), ft_atof(color[1]),
			ft_atof(color[2]));
	pl->material.color = div_color(pl->material.color);
	add_shape(&world->shapes, pl);
	return (0);
}

/**
 * Creates a cylinder object and adds it to the list of objects
 * in the options structure.
 *
 * @param options The options structure.
 * @param args The arguments for creating the cylinder.
 * @return 0 on success.
 */

	int	create_cylinder(t_world *world, char **args)
	{
		t_shape		*cy;
		char		**coords;
		char		**normal;
		char		**color;
		t_matrix	transform;

		cy = cylinder();
		coords = ft_split(args[1], ',');
		normal = ft_split(args[2], ',');
		color = ft_split(args[5], ',');
		transform = init_identity_matrix(4);
		transform = multiply_matrices(transform, translation(ft_atof(coords[0]), (ft_atof(coords[1]) - 1.0), ft_atof(coords[2])));
		transform = multiply_matrices(transform, rotation_x(deg_to_rad(ft_atof(normal[0])*180)));
		transform = multiply_matrices(transform, rotation_y(deg_to_rad(ft_atof(normal[1])*180)));
		transform = multiply_matrices(transform, rotation_z(deg_to_rad(ft_atof(normal[2])*180)));
		transform = multiply_matrices(transform, scaling(ft_atof(args[3]) / 2.0, ft_atof(args[4]), ft_atof(args[3]) / 2.0));
		
		cy->size_cap.min = -0.5;
		cy->size_cap.max = 0.5;
		cy->size_cap.cap = true;
		cy->material.color = new_color3(ft_atof(color[0]), ft_atof(color[1]),
				ft_atof(color[2]));
		cy->material.color = div_color(cy->material.color);
		set_transform(cy, transform);
		add_shape(&world->shapes, cy);
		return (0);
}
