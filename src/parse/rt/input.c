/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 19:33:06 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/10 19:20:58 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

void	free_doubleptr(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str)
			free(str[i]);
		i++;
	}
	free(str);
}

void	free_tripleptr(char ***str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i])
			free_doubleptr(str[i]);
		i++;
	}
	free(str);
}

void	free_options(t_options *options)
{
	free(options->scene.scene_file);
	if (options->scene.scene_objects)
		free_tripleptr(options->scene.scene_objects);
	if (options->values->filename != NULL)
		free(options->values->filename);
	free(options);
}

int	check_args(int argc, char **argv, t_options *options)
{
	(void)argc;
	if (validate_file_name(argv, options) == -1)
		return (free_options(options), 1);
	if (check_arg_count(argv) == -1)
		return (free_options(options), 1);
	if (option_preferences(argv, options) == -1)
		return (free_options(options), 1);
	if (get_scene_data(options) == -1)
	{
		fprintf(stderr, "Error: Failed to load scene data\n");
		free_options(options);
		return (1);
	}
	if (check_scene_data(options) == -1)
	{
		fprintf(stderr, "Error: Invalid scene data\n");
		free_options(options);
		return (1);
	}
	return (0);
}

int	make_world(t_options *options, t_world *world)
{
	printf("making world\n");
	if (create_objects(options, world) == -1)
		return (-1);
	return (0);
}
