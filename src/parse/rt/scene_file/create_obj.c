/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:20:07 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/26 15:46:35 by mdomnik          ###   ########.fr       */
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
	if (args[4])
		get_material(args[4], &sp->material);
	sp->material.color = new_color3(ft_atof(color[0]), ft_atof(color[1]),
			ft_atof(color[2]));
	sp->material.color = div_color(sp->material.color);
	if (sp->material.pattern)
	{
		set_uv_pattern(sp);
		if (sp->material.pattern->type == CHECKERS)
		{
			t_uv *uv = uv_checkers(10, 10, sp->material.pattern->a, sp->material.pattern->b);
			free(sp->material.pattern);
			sp->material.pattern = texture_map(uv, spherical_map);
		}
	}
	add_shape(&world->shapes, sp);
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
	if (args[4])
		get_material(args[4], &pl->material);
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
		transform = multiply_matrices(transform, translation(ft_atof(coords[0]), ft_atof(coords[1]), ft_atof(coords[2])));
		transform = multiply_matrices(transform, rotation_x(deg_to_rad(ft_atof(normal[0])*180)));
		transform = multiply_matrices(transform, rotation_y(deg_to_rad(ft_atof(normal[1])*180)));
		transform = multiply_matrices(transform, rotation_z(deg_to_rad(ft_atof(normal[2])*180)));
		transform = multiply_matrices(transform, scaling(ft_atof(args[3]) / 2.0, ft_atof(args[4]), ft_atof(args[3]) / 2.0));
		
		cy->size_cap.min = -0.5;
		cy->size_cap.max = 0.5;
		cy->size_cap.cap = true;
		if (args[6])
			get_material(args[6], &cy->material);
		cy->material.color = new_color3(ft_atof(color[0]), ft_atof(color[1]),
				ft_atof(color[2]));
		cy->material.color = div_color(cy->material.color);
		set_transform(cy, transform);
		if (cy->material.pattern)
		{
			set_uv_pattern(cy);
			if (cy->material.pattern->type == CHECKERS)
			{
				t_uv *uv = uv_checkers(10, 10, cy->material.pattern->a, cy->material.pattern->b);
				free(cy->material.pattern);
				cy->material.pattern = texture_map(uv, cylindrical_map);
			}
		}
		add_shape(&world->shapes, cy);
		return (0);
}
