/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mand.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 18:43:25 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/25 15:41:20 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

int	create_ambient(t_options *options, char **args)
{
	float		ambient;
	char		**colors;
	t_color3	color;

	(void)options;
	colors = ft_split(args[2], ',');
	ambient = ft_atof(args[1]);
	color = new_tuple(ft_atof(colors[0]), ft_atof(colors[1]),
			ft_atof(colors[2]), 1);
	current_ambient('s', ambient);
	global_color('s', color);
	return (0);
}

int	create_camera(t_camera **camera, char **args)
{
	t_point3	pos;
	t_vec3		orientation;
	char		**coords;
	char		**vector;

	(*camera) = camera_new(DEFAULT_WIDTH, DEFAULT_HEIGHT, ft_atof(args[3]));
	coords = ft_split(args[1], ',');
	pos = new_point3(ft_atof(coords[0]), ft_atof(coords[1]),
			ft_atof(coords[2]));
	vector = ft_split(args[2], ',');
	orientation = new_vec3(ft_atof(vector[0]), ft_atof(vector[1]),
			ft_atof(vector[2]));
	(*camera)->transform = view_transformation(pos, orientation);
	return (0);
}

int	create_light(t_light_p **lights, char **args)
{
	t_light_p	*light;
	char		**coords;
	char		**colors;
	float		brightness;

	coords = ft_split(args[1], ',');
	colors = ft_split(args[3], ',');
	light = malloc(sizeof(t_light_p));
	light->position = new_point3(ft_atof(coords[0]), ft_atof(coords[1]),
			ft_atof(coords[2]));
	light->intensity = new_tuple(ft_atof(colors[0]), ft_atof(colors[1]),
			ft_atof(colors[2]), 1);
	light->intensity = normalize(light->intensity);
	brightness = ft_atof(args[2]);
	light->intensity = mult_color_scalar(light->intensity, brightness);
	light->next = NULL;
	add_light(lights, light);
	return (0);
}
