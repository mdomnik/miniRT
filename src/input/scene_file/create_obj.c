/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:20:07 by mdomnik           #+#    #+#             */
/*   Updated: 2024/12/06 20:21:03 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

/**
 * Creates a sphere object and adds it to the list of objects in the options.
 *
 * @param w World structure.
 * @param args The arguments for creating the sphere.
 * @return 0 if successful.
 */
int	create_sphere(t_world *w, char **args)
{
	t_shape		*sp;
	char		**color;
	char		**coords;

	sp = sphere();
	color = ft_split(args[3], ',');
	*sp->material.color = new_tuple(ft_atoi(color[0]), ft_atoi(color[1]), ft_atoi(color[2]), 1);
	sp->material.diffuse = 0.7;
	sp->material.specular = 0.2;
	coords = ft_split(args[1], ',');
	set_transform(sp,
		multiply_matrices(translation(ft_atof(coords[0]), ft_atof(coords[1]), ft_atof(coords[2])),
		scaling(ft_atof(args[2])/2, ft_atof(args[2])/2, ft_atof(args[2])/2))
	);
	add_shape(&w->shapes, sp);
	return (0);
}

/**
 * Creates a plane object and adds it to the list of
 * objects in the options structure.
 *
 * @param w World structure.
 * @param args The arguments for creating the plane.
 * @return 0 if successful.
 */
int	create_plane(t_world *w, char **args)
{
	t_shape		*pl;
	char		**color;
	char		**coords;

	pl = plane();
	color = ft_split(args[3], ',');
	*pl->material.color = new_tuple(ft_atoi(color[0]), ft_atoi(color[1]), ft_atoi(color[2]), 1);
	pl->material.diffuse = 0.7;
	pl->material.specular = 0.2;
	coords = ft_split(args[1], ',');
	set_transform(pl,
		translation(ft_atof(coords[0]), ft_atof(coords[1]), ft_atof(coords[2]))
	);
	// t_plane		*plane;
	// char		**coords;
	// char		**normal;
	// char		**color;
	// plane = gc_malloc(sizeof(t_plane));
	// coords = ft_split(args[1], ',');
	// normal = ft_split(args[2], ',');
	// color = ft_split(args[3], ',');
	// plane->coords = new_point3(ft_atof(coords[0]), ft_atof(coords[1]),
			// ft_atof(coords[2]));
	// plane->normal = new_vec3(ft_atof(normal[0]), ft_atof(normal[1]),
			// ft_atof(normal[2]));
	// plane->color = new_tuple(ft_atoi(color[0]), ft_atoi(color[1]),
			// ft_atoi(color[2]), 1);
	// options->objects.plane = append_plane_list(options->objects.plane, plane);
	return (0);
}

/**
 * Creates a cylinder object and adds it to the list of objects
 * in the options structure.
 *
 * @param w World structure.
 * @param args The arguments for creating the cylinder.
 * @return 0 on success.
 */
int	create_cylinder(t_world *w, char **args)
{
	// t_cylinder	*cylinder;
	// char		**coords;
	// char		**normal;
	// char		**color;
// 
	// cylinder = gc_malloc(sizeof(t_cylinder));
	// coords = ft_split(args[1], ',');
	// normal = ft_split(args[2], ',');
	// color = ft_split(args[5], ',');
	// cylinder->coords = new_point3(ft_atof(coords[0]), ft_atof(coords[1]),
			// ft_atof(coords[2]));
	// cylinder->normal = new_vec3(ft_atof(normal[0]), ft_atof(normal[1]),
			// ft_atof(normal[2]));
	// cylinder->radius = ft_atof(args[2]) / 2.0;
	// cylinder->height = ft_atof(args[3]);
	// cylinder->color = new_tuple(ft_atoi(color[0]), ft_atoi(color[1]),
			// ft_atoi(color[2]), 1);
	// options->objects.cylinder
		// = append_cylinder_list(options->objects.cylinder, cylinder);
	// return (0);
}
