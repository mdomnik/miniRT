/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:21:04 by mdomnik           #+#    #+#             */
/*   Updated: 2024/08/30 18:44:58 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

int check_scene_data(t_options *options)
{
	int i;
	
	i = 0;
	while(options->scene.scene_objects[i] != NULL)
	{
		if (check_object_data(options, options->scene.scene_objects[i]) == -1)
			return (-1);
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
	char **values;


}