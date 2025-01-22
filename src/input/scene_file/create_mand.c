/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mand.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 18:43:25 by mdomnik           #+#    #+#             */
/*   Updated: 2024/11/19 15:59:11 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

/**
 * @brief Creates objects in the scene based on the provided options.
 *
 * This function iterates through the scene objects array in the options struct
 * and creates the corresponding objects based on their type.
 *
 * @param options The options struct containing the scene objects.
 * @return 0 if all objects are successfully created, -1 otherwise.
 */
int create_objects(t_options *options, t_world *world)
{
	int			i;

	i = 0;
	while (options->scene.scene_objects[i] != NULL)
	{
		// if (ft_strcmp(options->scene.scene_objects[i][0], "A") == 0)
		// 	if (create_ambient(options, options->scene.scene_objects[i]) == -1)
		// 		return (-1);
		if (ft_strcmp(options->scene.scene_objects[i][0], "C") == 0)
			if (create_camera(&world->camera, options->scene.scene_objects[i]) == -1)
				return (-1);
		if (ft_strcmp(options->scene.scene_objects[i][0], "L") == 0)
		{
			if (create_light(&world->light, options->scene.scene_objects[i]) == -1)
				return (-1);
		}
		if (check_objects_helper(&options->scene, world, i) == -1)
			return (-1);
		i++;
	}
	return (0);
}

/**
 * @brief Helper function to check and create objects in the scene.
 *
 * This function checks the type of object specified in the scene file
 * and calls the respective create function to create the object.
 *
 * @param options A pointer to the options struct.
 * @param i The index of the object in the scene.
 * @return Returns 0 if the object creation is successful, -1 otherwise.
 */
int		check_objects_helper(t_scene *scene, t_world *world, int i)
{
	if (ft_strcmp(scene->scene_objects[i][0], "sp") == 0)
	{
		if (create_sphere(world, scene->scene_objects[i]) == -1)
			return (-1);
	}
	if (ft_strcmp(scene->scene_objects[i][0], "pl") == 0)
	{
		if (create_plane(world, scene->scene_objects[i]) == -1)
			return (-1);
	}
	if (ft_strcmp(scene->scene_objects[i][0], "cy") == 0)
	{
		if (create_cylinder(world, scene->scene_objects[i]) == -1)
			return (-1);
	}
	return (0);
}

/**
 * Creates an ambient light object and assigns it to the options structure.
 *
 * @param options The options structure to assign the ambient light to.
 * @param args The arguments containing the light ratio and color values.
 * @return 0 on success.
 */
int create_ambient(t_options *options, char **args)
{
	t_ambient *ambient;
	char **colors;

	ambient = gc_malloc(sizeof(t_ambient));
	colors = ft_split(args[2], ',');
	ambient->light_ratio = ft_atof(args[1]);
	ambient->color = new_tuple(ft_atof(colors[0]), ft_atof(colors[1]),
							   ft_atof(colors[2]), 1);
	options->objects.ambient = ambient;
	return (0);
}

/**
 * Creates a camera object and assigns it to the options structure.
 *
 * @param options The options structure to assign the camera to.
 * @param args The arguments containing the camera coordinates,
 * vector, and field of view.
 * @return 0 if the camera was successfully created and assigned
 */
int create_camera(t_camera **camera, char **args)
{
	char **coords;
	char **vector;
	t_point3 pos;

	*camera = camera_new(DEFAULT_WIDTH, DEFAULT_HEIGHT, ft_atof(args[3]));
	coords = ft_split(args[1], ',');
	vector = ft_split(args[2], ',');
	pos = new_point3(ft_atof(coords[0]),
		ft_atof(coords[1]), ft_atof(coords[2]));
	(*camera)->transform = view_transformation(pos,
		add_tuples(pos, new_point3(ft_atof(vector[0]), ft_atof(vector[1]),
				   ft_atof(vector[2]))),
		new_vec3(0, 1, 0));
	return (0);
}

/**
 * Creates a light object and adds it to the options object.
 *
 * @param lights The lights object to add the light to.
 * @param args The arguments for creating the light.
 *             args[1] - The coordinates of the light (x,y,z).
 *             args[2] - The brightness of the light.
 *             args[3] - The color of the light (r,g,b).
 * @return 0 if the light was successfully created and added
 */
int create_light(t_light_p **lights, char **args)
{
	t_light_p *light;
	char **coords;
	char **colors;
	float brightness;

	coords = ft_split(args[1], ',');
	colors = ft_split(args[3], ',');
	light = gc_malloc(sizeof(*light));
	light->position = new_point3(ft_atof(coords[0]), ft_atof(coords[1]),
								 ft_atof(coords[2]));
	light->intensity = new_tuple(ft_atof(colors[0]), ft_atof(colors[1]),
								 ft_atof(colors[2]), 1);
	light->intensity = normalize(light->intensity);
	brightness = ft_atof(args[2]);
	light->intensity = mult_color(light->intensity, brightness);
	//add_light(&lights, light);
	(*lights) = light;
	return (0);
}
