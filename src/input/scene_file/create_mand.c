/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mand.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 18:43:25 by mdomnik           #+#    #+#             */
/*   Updated: 2024/09/09 15:28:42 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

int create_objects(t_options *options)
{
	int i;

	i = 0;
	while (options->scene.scene_objects[i] != NULL)
	{
		if (ft_strcmp(options->scene.scene_objects[i][0], "A") == 0)
			if (create_ambient(options, options->scene.scene_objects[i]) == -1)
				return (-1);
		if (ft_strcmp(options->scene.scene_objects[i][0], "C") == 0)
			if (create_camera(options, options->scene.scene_objects[i]) == -1)
				return (-1);
		if (ft_strcmp(options->scene.scene_objects[i][0], "L") == 0)
			if (create_light(options, options->scene.scene_objects[i]) == -1)
				return (-1);
		if (ft_strcmp(options->scene.scene_objects[i][0], "sp") == 0)
			if (create_sphere(options, options->scene.scene_objects[i]) == -1)
				return (-1);
		if (ft_strcmp(options->scene.scene_objects[i][0], "pl") == 0)
			if (create_plane(options, options->scene.scene_objects[i]) == -1)
				return (-1);
		if (ft_strcmp(options->scene.scene_objects[i][0], "cy") == 0)
			if (create_cylinder(options, options->scene.scene_objects[i]) == -1)
				return (-1);
		i++;
	}
	return (0);
}

int create_ambient(t_options *options, char **args)
{
	t_ambient	*ambient;
	char		**colors;

	ambient = gc_malloc(sizeof(t_ambient));
	colors = ft_split(args[2], ',');
	ambient->light_ratio = ft_atob(args[1]);
	ambient->color.r = ft_atoi(colors[0]);
	ambient->color.g = ft_atoi(colors[1]);
	ambient->color.b = ft_atoi(colors[2]);
	options->objects.ambient = ambient;
	return (0);
}

int create_camera(t_options *options, char **args)
{
	t_camera	*camera;
	char		**coords;
	char		**vector;

	camera = gc_malloc(sizeof(t_camera));
	coords = ft_split(args[1], ',');
	vector = ft_split(args[2], ',');
	camera->coords.x = ft_atob(coords[0]);
	camera->coords.y = ft_atob(coords[1]);
	camera->coords.z = ft_atob(coords[2]);
	camera->vrange.x= ft_atob(vector[0]);
	camera->vrange.y = ft_atob(vector[1]);
	camera->vrange.z = ft_atob(vector[2]);
	camera->fov = ft_atob(args[3]);
	options->objects.camera = camera;
	return (0);
}

int create_light(t_options *options, char **args)
{
	t_light		*light;
	char		**coords;
	char 		**colors;

	coords = ft_split(args[1], ',');
	colors = ft_split(args[3], ',');

	light = gc_malloc(sizeof(t_light));
	light->coords.x = ft_atob(coords[0]);
	light->coords.y = ft_atob(coords[1]);
	light->coords.z= ft_atob(coords[2]);
	light->color.r = ft_atoi(colors[0]);
	light->color.g = ft_atoi(colors[1]);
	light->color.b = ft_atoi(colors[2]);
	light->brightness = ft_atob(args[2]);
	options->objects.light = append_light_list(options->objects.light, light);
	return (0);
}
