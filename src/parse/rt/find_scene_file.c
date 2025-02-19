/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_scene_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 19:49:30 by mdomnik           #+#    #+#             */
/*   Updated: 2024/09/09 17:22:59 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

/**
 * @brief Validates the file name from the command line arguments and 
 * assigns itto the scene file in the options structure.
 *
 * This function iterates through the command line arguments and checks
 * if each argument is a valid scene file. If a valid scene file is found,
 * it is assigned to the `scene_file` variable and the `scene_count`
 * flag is set to true. If any error occurs during the scene file check,
 * the function returns -1. If no valid scene file is found, an error message
 * is printed to the standard error stream and the function returns -1.
 * Otherwise, the `scene_file` is assigned to the `scene_file` member of
 * the `options->scene` structure and the function returns 0.
 *
 * @param argv The command line arguments.
 * @param options The options structure.
 * @return 0 if the file name is validated and assigned successfully,
 * -1 otherwise.
 */
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
	options->scene.scene_file = scene_file;
	return (0);
}

/**
 * @brief Checks if the scene file is valid and updates the scene file
 * and scene count.
 *
 * This function checks if the given filename is a valid scene file. 
 * If it is valid and the scene count is 0, it updates the scene file and sets
 * the scene count to 1. If the scene count is already 1, it returns an error
 * indicating that multiple scene files are not allowed. If the filename
 * is not a valid scene file, it returns an error indicating 
 * that the filename is missing.
 *
 * @param filename The name of the scene file to be checked.
 * @param scene_file A pointer to the scene file string.
 * @param scene_count A pointer to the scene count variable.
 * @return 0 if the scene file is valid and updated successfully,
 * -1 if there is an error.
 */
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
	else if (check_scene_file(filename) == -2)
	{
		ft_dprintf(2, "%s\n", ERR_NO_NAME);
		return (-1);
	}
	return (0);
}

/**
 * @brief Checks if the given string represents a valid scene file.
 *
 * This function checks if the provided string is a valid scene file by
 * verifying its extension and length. A valid scene file must have a ".rt"
 * extension and a length of at least 4 characters.
 *
 * @param args The string representing the file name.
 * @return Returns 0 if the file is valid, -1 if it is invalid, and -2 if it is
 * an empty file name.
 */
int	check_scene_file(char *args)
{
	int	i;

	i = 0;
	if (args[0] == '\0')
		return (-1);
	while (args[i] != '\0')
		i++;
	if (args[i] == '\0' && args[i - 1] == 't'
		&& args[i - 2] == 'r' && args[i - 3] == '.' && i == 3)
		return (-2);
	if (i < 4)
		return (-1);
	if (args[i] != '\0' || args[i - 1] != 't'
		|| args[i - 2] != 'r' || args[i - 3] != '.')
		return (-1);
	return (0);
}

/**
 * @brief Checks the number of arguments passed to the program.
 *
 * This function checks the number of arguments passed to the program
 * and performs additional validation on the arguments. It ensures that
 * the arguments are in the correct format and that the scene file exists.
 *
 * @param argv The array of command-line arguments.
 * @return Returns 0 if the argument count is valid, -1 otherwise.
 */
int	check_arg_count(char **argv)
{
	int		i;
	bool	repeat;

	i = 0;
	repeat = false;
	while (argv[i])
	{
		if (argv[i][0] != '-' || (argv[i][0] == '-' && is_number(argv[i]) == 0))
		{
			if (repeat == true && check_scene_file(argv[i]) == -1)
			{
				ft_dprintf(2, "%s\n", ERR_ARGS);
				return (-1);
			}
			repeat = true;
		}
		if (argv[i][0] == '-' && is_number(argv[i]) == 1)
			repeat = false;
		i++;
	}
	return (0);
}
