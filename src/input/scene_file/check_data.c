/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:21:04 by mdomnik           #+#    #+#             */
/*   Updated: 2024/08/29 18:02:44 by mdomnik          ###   ########.fr       */
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
	if (strncmp(args[0], "A", ft_strlen(args[0])) == 0)
	{
		printf("Ambient light: %s\n", args[0]);
	}
	(void)options;
	return (0);
}