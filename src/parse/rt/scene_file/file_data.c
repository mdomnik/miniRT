/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:51:23 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/14 01:27:56 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

/**
 * @brief Retrieves scene data from a file and populates
 * the options structure.
 *
 * This function opens the specified scene file
 * and reads its contents line by line. Each line is then passed
 * to the append_object_nodes function to append object nodes
 * to the options structure. If any error occurs during file opening
 * or reading, an appropriate error message
 * is printed to the standard error stream.
 *
 * @param options A pointer to the options structure.
 * @return 0 if the scene data is successfully retrieved,
 * -1 otherwise.
 */
int	get_scene_data(t_options *options)
{
	int		fd;
	char	*line;

	options->scene.scene_objects = NULL;
	fd = open(options->scene.scene_file, O_RDONLY);
	if (fd == -1)
		return (ft_dprintf(2, "%s\n", ERR_OPEN_FILE), -1);
	line = gnl(fd);
	if (line == NULL)
	{
		ft_dprintf(2, "%s\n", ERR_EMPTY_FILE);
		close(fd);
		return (-1);
	}
	while (line != NULL)
	{
		if ((ft_strcmp(line, "\n") != 0)
			&& (append_object_nodes(options, line) == -1))
			return (ret_message(ERR_FAIL_LINE, line), free(line),
				close(fd), gnl(-1), -1);
		free(line);
		line = gnl(fd);
	}
	return (close(fd), 0);
}

/**
 * Appends object nodes to the options structure based on the provided line.
 *
 * @param options The options structure to append the object nodes to.
 * @param line The line containing the object nodes.
 * @return 0 if successful, -1 if an error occurred.
 */
#define I 0
#define J 1

int	append_object_nodes(t_options *options, char *line)
{
	int		a[2];
	char	**args;
	char	*temp;

	a[I] = 0;
	args = NULL;
	while (line[a[I]] != '\0')
	{
		a[I] = omit_whitespaces(line, a[I]);
		if (line[a[I]] == '#')
			return (0);
		a[J] = 0;
		if (line[a[I]] == '\0' || line[a[I]] == '\n')
			break ;
		while (line[a[I] + a[J]] != ' ' && line[a[I] + a[J]] != '\t'
			&& line[a[I] + a[J]] != '\0' && line[a[I] + a[J]] != '\n')
			a[J]++;
		temp = ft_substr(line, a[I], a[J]);
		args = append_to_double(args, temp);
		free(temp);
		a[I] += a[J] + 1;
	}
	if (line[0] != '\n' && append_to_triple(options, args) == -1)
		return (-1);
	return (0);
}

/**
 * Appends a string to a double pointer array of strings.
 *
 * @param args The double pointer array of strings to append to.
 * @param temp The string to append.
 * @return The updated double pointer array of strings.
 */
char	**append_to_double(char **args, char *temp)
{
	int		i;
	char	**new_args;

	i = 0;
	if (args == NULL)
	{
		new_args = malloc(sizeof(char *) * 2);
		new_args[0] = ft_strdup(temp);
		new_args[1] = NULL;
		return (new_args);
	}
	while (args[i] != NULL)
		i++;
	new_args = malloc(sizeof(char *) * (i + 2));
	i = 0;
	while (args[i] != NULL)
	{
		new_args[i] = args[i];
		i++;
	}
	new_args[i] = ft_strdup(temp);
	new_args[i + 1] = NULL;
	free(args);
	return (new_args);
}

/**
 * Appends a double pointer args to a triple pointer in options.
 *
 * @param options The options structure.
 * @param args The arguments to be appended.
 * @return 0 if successful, -1 if args is NULL or args[0] is NULL.
 */
int	append_to_triple(t_options *options, char **args)
{
	int		i;
	char	***new_triple;

	i = 0;
	if (options->scene.scene_objects == NULL)
	{
		options->scene.scene_objects = malloc(sizeof(char **) * 2);
		options->scene.scene_objects[0] = args;
		options->scene.scene_objects[1] = NULL;
		return (0);
	}
	if (args == NULL || args[0] == NULL)
		return (-1);
	while (options->scene.scene_objects[i] != NULL)
		i++;
	new_triple = malloc(sizeof(char **) * (i + 2));
	i = -1;
	while (options->scene.scene_objects[++i] != NULL)
		new_triple[i] = options->scene.scene_objects[i];
	new_triple[i] = args;
	new_triple[i + 1] = NULL;
	free(options->scene.scene_objects);
	options->scene.scene_objects = new_triple;
	return (0);
}

int	check_file_open_format(char *str)
{
	(void)str;
	return (0);
}
