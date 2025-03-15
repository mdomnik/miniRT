/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:21:04 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/15 09:42:59 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"
/**
 * @brief Checks the validity of the scene data.
 *
 * This function checks the scene data for any duplicates, mandatory objects,
 * and the validity of each object's data. It also creates the objects if all
 * checks pass.
 *
 * @param options A pointer to the options struct containing the scene data.
 * @return Returns 0 if the scene data is valid, -1 otherwise.
 */
int	check_scene_data(t_options *options)
{
	int	i;

	i = 0;
	if (check_dup_objects(options, 0) == -1)
		return (-1);
	if (check_mandatory_objects(options) == -1)
		return (-1);
	while (options->scene.scene_objects[i] != NULL)
	{
		if (check_object_data(options->scene.scene_objects[i]) == -1)
			return (-1);
		i++;
	}
	return (0);
}

/**
 * @brief Check if all mandatory objects are present in the scene.
 *
 * This function checks if all the mandatory objects specified in the objects.h
 * header are present in the scene. It compares the objects in the scene with the
 * mandatory objects and counts the number of missing objects. If any mandatory
 * object is missing, an error message is printed and the function returns -1.
 *
 * @param options A pointer to the options structure.
 * @return 0 if all mandatory objects are present, -1 otherwise.
 */
int	check_mandatory_objects(t_options *options)
{
	char	**mandatory;
	int		count;
	int		i;
	int		j;

	mandatory = ft_split(MANDATORY_OBJECTS, ',');
	count = 0;
	i = 0;
	count = pointer_count(mandatory);
	while (mandatory[i] != NULL)
	{
		j = 0;
		while (options->scene.scene_objects[j] != NULL)
		{
			if (ft_strcmp(
					options->scene.scene_objects[j][0], mandatory[i]) == 0)
				count--;
			j++;
		}
		i++;
	}
	if (count > 0)
		return (free_double(mandatory), ft_dprintf(
				2, "%s '%s'\n", ERR_MISS_OBJ, MANDATORY_OBJECTS), -1);
	return (free_double(mandatory), 0);
}

/**
 * @brief Checks for duplicate objects in the scene.
 *
 * This function checks if there are any duplicate objects in the scene
 * by comparing them with a list of unique objects from the objects.h header.
 * It takes a pointer to the options struct and a binary value
 * as parameters.
 *
 * @param options A pointer to the options struct.
 * @param binary The binary value used for checking duplicates.
 * @return Returns 0 if there are no duplicate objects,
 * otherwise returns an error message and returns -1.
 */
int	check_dup_objects(t_options *options, int binary)
{
	char	**unique;
	int		i;
	int		j;

	i = -1;
	unique = ft_split(UNIQUE_OBJECTS, ',');
	if (options->scene.scene_objects == NULL)
		return (free_double(unique), ret_message(ERR_EMPTY_FILE, NULL));
	while (options->scene.scene_objects[++i] != NULL)
	{
		j = -1;
		while (unique[++j] != NULL)
		{
			if (ft_strcmp(options->scene.scene_objects[i][0], unique[j]) == 0)
			{
				if (binary & (1 << j))
				{
					return (free_double(unique), ret_message(ERR_DUP_OBJ,
							options->scene.scene_objects[i][0]));
				}
				binary |= (1 << j);
			}
		}
	}
	return (free_double(unique), 0);
}

/**
 * @brief Check the validity of object data.
 *
 * This function checks if the given object data is valid by comparing it
 * with a list of predefined object IDs.
 *
 * @param args An array of strings representing the object data.
 * @return Returns 0 if the object data is valid, -1 otherwise.
 */
int	check_object_data(char **args)
{
	char	**ids;
	int		i;

	ids = ft_split(SCENE_OBJECTS, ',');
	i = 0;
	while (ids[i] != NULL)
	{
		if (ft_strcmp(ids[i], args[0]) == 0)
			break ;
		i++;
	}
	if (ids[i] == NULL)
	{
		ft_dprintf(2, "%s '%s'\n", ERR_INV_OBJ, args[0]);
		free_double(ids);
		return (-1);
	}
	if (determine_object(args) == -1)
	{
		free_double(ids);
		return (-1);
	}
	free_double(ids);
	return (0);
}

/**
 * @brief Determines the object based on the given arguments.
 *
 * This function takes an array of arguments and compares them with
 * a set of rules to determine the object. It splits the rules and
 * data using delimiters and checks if the first argument matches
 * the first element of the data. If a match is found, it calls the
 * check_object_rules() function to validate the object rules. If the
 * validation fails, it returns -1. The function frees the memory
 * allocated for the data array after each iteration.
 *
 * @param args An array of arguments.
 * @return 0 if the object is determined successfully, -1 otherwise.
 */
int	determine_object(char **args)
{
	char	**rules;
	char	**data;
	int		i;

	rules = ft_split(OBJECT_RULES, ';');
	i = 0;
	while (rules[i] != NULL)
	{
		data = ft_split(rules[i], ',');
		if (ft_strcmp(data[0], args[0]) == 0)
		{
			if (check_object_rules(args, data) == -1)
			{
				free_double(data);
				free_double(rules);
				return (ret_message(PARSE_ARGS, NULL));
			}
		}
		free_double(data);
		data = NULL;
		i++;
	}
	free_double(rules);
	return (0);
}
