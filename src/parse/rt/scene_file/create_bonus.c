/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:47:33 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/26 19:21:09 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

static int	create_bonus_object(t_world *world, char **args, char *type,
		int (*create_func)(t_world *, char **))
{
	if (ft_strcmp(args[0], type) == 0)
		return (create_func(world, args));
	return (0);
}

int	check_bonus_objects(t_scene *scene, t_world *world, int i)
{
	char	**args;
	int		status;

	args = scene->scene_objects[i];
	status = create_bonus_object(world, args, "co", create_cone);
	if (status == -1)
		return (-1);
	status = create_bonus_object(world, args, "hg", create_hourglass);
	if (status == -1)
		return (-1);
	status = create_bonus_object(world, args, "cb", create_cube);
	if (status == -1)
		return (-1);
	status = create_bonus_object(world, args, "obj", create_obj);
	if (status == -1)
		return (-1);
	status = create_bonus_object(world, args, "sb", create_skybox);
	if (status == -1)
		return (-1);
	return (0);
}
