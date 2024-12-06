/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 19:33:06 by mdomnik           #+#    #+#             */
/*   Updated: 2024/12/06 19:58:53 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

int	check_args(int argc, char **argv, t_project *project)
{
	(void)argc;
	project->options = gc_malloc(sizeof(t_options));
	if (validate_file_name(argv, project->options) == -1)
		return (1);
	if (check_arg_count(argv) == -1)
		return (1);
	if (option_preferences(argv, project->options) == -1)
		return (1);
	if (get_scene_data(project->options) == -1)
		return (1);
	if (check_scene_data(project->options) == -1)
		return (1);
	t_obj objects = project->options->objects;
	project->objects = populate_object_struct(&objects);
	return(0);
}

t_project	*init_project(int argc, char **argv)
{
	t_project	*project;

	project = gc_malloc(sizeof(t_project));
	if (check_args(argc, argv, project) == 1)
		return (NULL);
	
	return (project);
}
