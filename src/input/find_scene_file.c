/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_scene_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 19:49:30 by mdomnik           #+#    #+#             */
/*   Updated: 2024/08/27 03:20:41 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

int	validate_file_name(char **argv, t_options *options)
{
	char	*scene_file;
	int		i;
	bool	scene_count;

	scene_file = NULL;
	i = 0;
	scene_count = 0;
	while (argv[i])
	{
		if (scene_file_check(argv[i], &scene_file, &scene_count) != 0)
			return (-1);
		i++;
	}
	if (scene_count == 0)
	{
		ft_dprintf(2, "%s\n", ERR_SCENE_FILE);
		return (-1);
	}
	options->scene_file = scene_file;
	return (0);
}

int	scene_file_check(char *filename, char **scene_file, bool *scene_count)
{
	if (check_scene_file(filename) == 0)
	{
		if (*scene_count == 0)
		{
			*scene_file = ft_strdup(filename);
			*scene_count = 1;
		}
		else
		{
			ft_dprintf(2, "%s\n", ERR_MULTIPLE_SCENE);
			return (-1);
		}
	}
	return (0);
}

int	check_scene_file(char *args)
{
	int	i;

	i = 0;
	if (args[0] == '\0')
		return (-1);
	while (args[i] != '\0')
		i++;
	if (i < 4)
		return (-1);
	if (args[i] != '\0' || args[i - 1] != 't'
		|| args[i - 2] != 'r' || args[i - 3] != '.')
		return (-1);
	return (0);
}
