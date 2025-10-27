/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:20:07 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/15 18:30:40 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

static void	set_sphere_transform(t_shape *sp, char **coords, float radius)
{
	t_matrix	transform;

	transform = init_identity_matrix(4);
	transform = multiply_matrices(
			translation(ft_atof_mrt(coords[0]), ft_atof_mrt(coords[1]),
				ft_atof_mrt(coords[2])),
			scaling(radius, radius, radius));
	set_transform(sp, transform);
}

static void	set_sphere_pattern(t_shape *sp)
{
	t_uv	*uv;

	if (!sp->material.pattern)
		return ;
	if (sp->material.pattern->type == CHECKERS)
	{
		uv = uv_checkers(10, 10, sp->material.pattern->a,
				sp->material.pattern->b);
		free(sp->material.pattern);
		sp->material.pattern = texture_map_sphere(uv, spherical_map);
		sp->material.pattern->is_checkers = true;
		sp->material.pattern->simple = true;
	}
}

/**
 * Creates a sphere object and adds it to the list of objects in the options.
 *
 * @param options The options struct containing the list of objects.
 * @param args The arguments for creating the sphere.
 * @return 0 if successful.
 */
int	create_sphere(t_world *world, char **args)
{
	t_shape	*sp;
	char	**coords;
	char	**color;
	float	radius;

	sp = sphere();
	coords = ft_split(args[1], ',');
	color = ft_split(args[3], ',');
	radius = ft_atof_mrt(args[2]) / 2.0;
	set_sphere_transform(sp, coords, radius);
	if (args[4])
		get_material(args[4], &sp->material, sp);
	sp->material.color = new_color3(ft_atof_mrt(color[0]),
			ft_atof_mrt(color[1]), ft_atof_mrt(color[2]));
	sp->material.color = div_color(sp->material.color);
	set_sphere_pattern(sp);
	add_shape(&world->shapes, sp);
	free_double(color);
	free_double(coords);
	return (0);
}

static void	set_plane_transform(t_shape *pl, char **coords, char **normal)
{
	t_matrix	transform;

	transform = init_identity_matrix(4);
	transform = multiply_matrices(transform,
			translation(ft_atof_mrt(coords[0]), ft_atof_mrt(coords[1]),
				ft_atof_mrt(coords[2])));
	transform = multiply_matrices(transform,
			rotation_x(deg_to_rad(ft_atof_mrt(normal[0]) * 180)));
	transform = multiply_matrices(transform,
			rotation_y(deg_to_rad(ft_atof_mrt(normal[1]) * 180)));
	transform = multiply_matrices(transform,
			rotation_z(deg_to_rad(ft_atof_mrt(normal[2]) * 180)));
	set_transform(pl, transform);
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
	t_shape	*pl;
	char	**coords;
	char	**normal;
	char	**color;

	pl = plane();
	coords = ft_split(args[1], ',');
	normal = ft_split(args[2], ',');
	color = ft_split(args[3], ',');
	set_plane_transform(pl, coords, normal);
	if (args[4])
		get_material(args[4], &pl->material, pl);
	pl->material.color = new_color3(ft_atof_mrt(color[0]),
			ft_atof_mrt(color[1]), ft_atof_mrt(color[2]));
	pl->material.color = div_color(pl->material.color);
	add_shape(&world->shapes, pl);
	free_double(color);
	free_double(coords);
	free_double(normal);
	return (0);
}
