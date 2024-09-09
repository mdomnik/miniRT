/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:20:07 by mdomnik           #+#    #+#             */
/*   Updated: 2024/09/09 15:31:21 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

int create_sphere(t_options *options, char **args)
{
	t_sphere	*sphere;
	char		**coords;
	char		**color;
	
	sphere = gc_malloc(sizeof(t_sphere));
	coords = ft_split(args[1], ',');
	color = ft_split(args[3], ',');
	sphere->coords.x = ft_atob(coords[0]);
	sphere->coords.y = ft_atob(coords[1]);
	sphere->coords.z = ft_atob(coords[2]);
	sphere->diameter = ft_atob(args[2]);
	sphere->color.r = ft_atoi(color[0]);
	sphere->color.g = ft_atoi(color[1]);
	sphere->color.b = ft_atoi(color[2]);
	options->objects.sphere = append_sphere_list(options->objects.sphere, sphere);
	return (0);
}

int create_plane(t_options *options, char **args)
{
	t_plane		*plane;
	char		**coords;
	char		**normal;
	char		**color;
	
	plane = gc_malloc(sizeof(t_plane));
	coords = ft_split(args[1], ',');
	normal = ft_split(args[2], ',');
	color = ft_split(args[3], ',');
	plane->coords.x = ft_atob(coords[0]);
	plane->coords.y = ft_atob(coords[1]);
	plane->coords.z = ft_atob(coords[2]);
	plane->normal.x = ft_atob(normal[0]);
	plane->normal.y = ft_atob(normal[1]);
	plane->normal.z = ft_atob(normal[2]);
	plane->color.r = ft_atoi(color[0]);
	plane->color.g = ft_atoi(color[1]);
	plane->color.b = ft_atoi(color[2]);
	options->objects.plane = append_plane_list(options->objects.plane, plane);
	return (0);
}
int create_cylinder(t_options *options, char **args)
{
	t_cylinder	*cylinder;
	char		**coords;
	char		**normal;
	char		**color;
	
	cylinder = gc_malloc(sizeof(t_cylinder));
	coords = ft_split(args[1], ',');
	normal = ft_split(args[2], ',');
	color = ft_split(args[5], ',');
	cylinder->coords.x = ft_atob(coords[0]);
	cylinder->coords.y = ft_atob(coords[1]);
	cylinder->coords.z = ft_atob(coords[2]);
	cylinder->normal.x = ft_atob(normal[0]);
	cylinder->normal.y = ft_atob(normal[1]);
	cylinder->normal.z = ft_atob(normal[2]);
	cylinder->diameter = ft_atob(args[2]);
	cylinder->height = ft_atob(args[3]);
	cylinder->color.r = ft_atoi(color[0]);
	cylinder->color.g = ft_atoi(color[1]);
	cylinder->color.b = ft_atoi(color[2]);
	options->objects.cylinder = append_cylinder_list(options->objects.cylinder, cylinder);
	return (0);
}
