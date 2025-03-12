/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mand.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 18:43:25 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/07 18:04:43 by mdomnik          ###   ########.fr       */
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
	ambient = ft_atof_mrt(args[1]);
	color = new_tuple(ft_atof_mrt(colors[0]), ft_atof_mrt(colors[1]),
			ft_atof_mrt(colors[2]), 1);
	current_ambient('s', ambient);
	global_color('s', color);
	free_double(colors);
	return (0);
}

int	create_camera(t_camera **camera, char **args)
{
	t_point3	pos;
	t_vec3		orientation;
	char		**coords;
	char		**vector;

	(*camera) = camera_new(DEFAULT_WIDTH, DEFAULT_HEIGHT, ft_atof_mrt(args[3]));
	coords = ft_split(args[1], ',');
	pos = new_point3(ft_atof_mrt(coords[0]), ft_atof_mrt(coords[1]),
			ft_atof_mrt(coords[2]));
	vector = ft_split(args[2], ',');
	orientation = new_vec3(ft_atof_mrt(vector[0]), ft_atof_mrt(vector[1]),
			ft_atof_mrt(vector[2]));
	(*camera)->transform = view_transformation(pos, orientation);
	free_double(coords);
	free_double(vector);
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
	light->position = new_point3(ft_atof_mrt(coords[0]), ft_atof_mrt(coords[1]),
			ft_atof_mrt(coords[2]));
	light->intensity = new_tuple(ft_atof_mrt(colors[0]), ft_atof_mrt(colors[1]),
			ft_atof_mrt(colors[2]), 1);
	light->intensity = normalize(light->intensity);
	brightness = ft_atof_mrt(args[2]);
	light->intensity = mult_color_scalar(light->intensity, brightness);
	light->next = NULL;
	add_light(lights, light);
	free_double(coords);
	free_double(colors);
	return (0);
}
