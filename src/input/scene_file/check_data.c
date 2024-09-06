/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:21:04 by mdomnik           #+#    #+#             */
/*   Updated: 2024/09/06 18:02:52 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

int check_scene_data(t_options *options)
{
	int i;
	
	i = 0;
	if (check_dup_objects(options, 0) == -1)
		return (-1);
	if (check_mandatory_objects(options) == -1)
		return (-1);
	while(options->scene.scene_objects[i] != NULL)
	{
		if (check_object_data(options, options->scene.scene_objects[i]) == -1)
			return (-1);
		i++;
	}
	if (create_objects(options) == -1)
		return (-1);
	return (0);
}
int check_mandatory_objects(t_options *options)
{
	char	**mandatory;
	int		count;
	int		i;

	mandatory = ft_split(MANDATORY_OBJECTS, ',');
	count = 0;
	i = 0;
	count = pointer_count(mandatory);
	while (mandatory[i] != NULL)
	{
		if (ft_strcmp(options->scene.scene_objects[i][0], mandatory[i]) == 0)
			count--;
		i++;
	}
	if (count != 0)
	{
		ft_dprintf(2, "%s '%s'\n", ERR_MISS_OBJ, MANDATORY_OBJECTS);
		return (-1);
	}
	return (0);
}
int check_dup_objects(t_options *options, int binary)
{
	char	**unique;
	int		i;
	int		j;

	i = 0;
	unique = ft_split(UNIQUE_OBJECTS, ',');
	while (options->scene.scene_objects[i] != NULL)
	{
		j = 0;
		while (unique[j] != NULL)
		{
			if (ft_strcmp(options->scene.scene_objects[i][0], unique[j]) == 0)
			{
				if (binary & (1 << j))
				{
					ft_dprintf(2, "%s '%s'\n", ERR_DUP_OBJ, options->scene.scene_objects[i][0]);
					return (-1);
				}
				binary |= (1 << j);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int check_object_data(t_options *options, char **args)
{
	char	**ids;
	int		i;
	
	ids = ft_split(SCENE_OBJECTS, ',');
	i = 0;
	while (ids[i] != NULL)
	{
		if (ft_strcmp(ids[i], args[0]) == 0)
			break;
		i++;
	}
	if (ids[i] == NULL)
	{
		ft_dprintf(2, "%s '%s'\n", ERR_INV_OBJ, args[0]);
		return (-1);
	}
	if (determine_object(options, args) == -1)
		return (-1);
	return (0);
}

int determine_object(t_options *options, char **args)
{
	char	**rules;
	char	**data;
	int		i;
	
	rules = ft_split(OBJECT_RULES, ';');
	i = 0;
	while(rules[i] != NULL)
	{
		data = ft_split(rules[i], ',');
		if (ft_strcmp(data[0], args[0]) == 0)
		{
			if (check_object_rules(options, args, data) == -1)
				return (-1);
		}
		free_double(data);
		data = NULL;
		i++;
	}
	return (0);
}

