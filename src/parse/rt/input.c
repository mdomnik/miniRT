/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 19:33:06 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/20 11:53:35 by mdomnik          ###   ########.fr       */
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

void free_options(t_options *options)
{
	//free_flags
	t_flags *current_flag;
	t_flags *next_flag;

	if (options->values != NULL)
	{
		current_flag = options->values;
		while (current_flag != NULL)
		{
			next_flag = current_flag->next;
			free(current_flag);
			current_flag = next_flag;
		}
	}
	//free_scene
	free(options->scene.scene_file);
	if (options->scene.scene_objects)
		free_tripleptr(options->scene.scene_objects);
	//free_obj
	free(options);
}

int	check_args(int argc, char **argv, t_world *world)
{
	t_options	*options;

	(void)argc;
	options = malloc(sizeof(t_options));
	options->scene.scene_objects = NULL;
	options->scene.scene_file = NULL;
	options->values = NULL;
	if (validate_file_name(argv, options) == -1)
	{
		free_options(options);
		return (1);
	}
	if (check_arg_count(argv) == -1)
	{
		free_options(options);
		return (1);
	}
	if (option_preferences(argv, options) == -1)
	{
		free_options(options);
		return (1);
	}
	if (get_scene_data(options) == -1)
	{
		free_options(options);
		return (1);
	}
	if (check_scene_data(options, world) == -1)
		return (1);
	// gc_free_gc(gc_set_storage('g'));
	//t_obj objects = project->options->objects;
	//project->objects = populate_object_struct(&objects);
	free_options(options);
	(void)world;
	return(0);
}
