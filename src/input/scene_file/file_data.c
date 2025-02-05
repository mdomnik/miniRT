/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:51:23 by mdomnik           #+#    #+#             */
/*   Updated: 2024/10/16 20:59:09 by mdomnik          ###   ########.fr       */
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

	fd = open(options->scene.scene_file, O_RDONLY);
	line = gnl(fd);
	if (fd == -1)
	{
		ft_dprintf(2, "%s\n", ERR_OPEN_FILE);
		return (-1);
	}
	while (line != NULL)
	{
		if (append_object_nodes(options, line) == -1)
			return (ret_message(ERR_FAIL_LINE, line));
		line = gnl(fd);
		if (line == NULL)
			break ;
	}
	close(fd);
	return (0);
}

/**
 * Appends object nodes to the options structure based on the provided line.
 *
 * @param options The options structure to append the object nodes to.
 * @param line The line containing the object nodes.
 * @return 0 if successful, -1 if an error occurred.
 */
int	append_object_nodes(t_options *options, char *line)
{
	int		i;
	int		j;
	char	**args;
	char	*temp;

	i = 0;
	args = NULL;
	while (line[i] != '\0' && line[i] != '\n')
	{
		i = omit_whitespaces(line, i);
		if (line[i] == '#')
			return (0);
		j = 0;
		if (line[i] == '\0' || line[i] == '\n')
			return (0);
		while (line[i + j] != ' ' && line[i + j] != '\t'
			&& line[i + j] != '\0' && line[i + j] != '\n')
			j++;
		temp = ft_substr(line, i, j);
		args = append_to_double(args, temp);
		i += j + 1;
	}
	if (append_to_triple(options, args) == -1)
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
		new_args = gc_malloc(sizeof(char *) * 2);
		new_args[0] = temp;
		new_args[1] = NULL;
		return (new_args);
	}
	while (args[i] != NULL)
		i++;
	new_args = gc_malloc(sizeof(char *) * (i + 2));
	i = 0;
	while (args[i] != NULL)
	{
		new_args[i] = args[i];
		i++;
	}
	new_args[i] = temp;
	new_args[i + 1] = NULL;
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
		options->scene.scene_objects = gc_malloc(sizeof(char **) * 2);
		options->scene.scene_objects[0] = args;
		options->scene.scene_objects[1] = NULL;
		return (0);
	}
	if (args == NULL || args[0] == NULL)
		return (-1);
	while (options->scene.scene_objects[i] != NULL)
		i++;
	new_triple = gc_malloc(sizeof(char **) * (i + 2));
	i = -1;
	while (options->scene.scene_objects[++i] != NULL)
		new_triple[i] = options->scene.scene_objects[i];
	new_triple[i] = args;
	new_triple[i + 1] = NULL;
	options->scene.scene_objects = new_triple;
	return (0);
}
