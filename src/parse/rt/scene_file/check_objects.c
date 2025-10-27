/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 18:43:25 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/14 17:43:17 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

static int	create_mandatory_objects(t_options *options, t_world *world,
		char ***objects, int i)
{
	if (ft_strcmp(objects[i][0], "A") == 0)
		if (create_ambient(options, objects[i]) == (-1))
			return (-1);
	if (ft_strcmp(objects[i][0], "C") == 0)
		if (create_camera(&world->camera, objects[i]) == (-1))
			return (-1);
	if (ft_strcmp(objects[i][0], "L") == 0)
		if (create_light(&world->light, objects[i]) == (-1))
			return (-1);
	return (0);
}

int	create_objects(t_options *options, t_world *world)
{
	int	i;

	i = 0;
	if (!options->scene.scene_objects)
	{
		ft_dprintf(2, "Error: Scene objects are NULL\n");
		return (-1);
	}
	while (options->scene.scene_objects[i] != NULL)
	{
		if (create_mandatory_objects(options, world,
				options->scene.scene_objects, i) == (-1))
			return (-1);
		if (check_objects_helper(&options->scene, world, i) == (-1))
			return (-1);
		if (check_bonus_objects(&options->scene, world, i) == (-1))
			return (-1);
		i++;
	}
	if (world->shapes == NULL)
	{
		ft_dprintf(2, "Error: No objects found in the scene\n");
		return (-1);
	}
	return (0);
}

int	check_objects_helper(t_scene *scene, t_world *world, int i)
{
	if (ft_strcmp(scene->scene_objects[i][0], "sp") == 0)
		if (create_sphere(world, scene->scene_objects[i]) == (-1))
			return (-1);
	if (ft_strcmp(scene->scene_objects[i][0], "pl") == 0)
		if (create_plane(world, scene->scene_objects[i]) == (-1))
			return (-1);
	if (ft_strcmp(scene->scene_objects[i][0], "cy") == 0)
		if (create_cylinder(world, scene->scene_objects[i]) == (-1))
			return (-1);
	return (0);
}
