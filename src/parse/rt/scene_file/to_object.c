/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_object.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:40:15 by mdomnik           #+#    #+#             */
/*   Updated: 2024/11/19 20:20:39 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

static int	count_toremoves(t_obj *source)
{
	int			count;
	t_light		*temp_light;
	t_sphere	*temp_sphere;
	t_plane		*temp_plane;
	t_cylinder	*temp_cylinder;

	count = 2;
	temp_light = source->light;
	temp_sphere = source->sphere;
	temp_plane = source->plane;
	temp_cylinder = source->cylinder;
	while (temp_light && count++ != 0)
		temp_light = temp_light->next;
	while (temp_sphere && count++ != 0)
		temp_sphere = temp_sphere->next;
	while (temp_plane && count++ != 0)
		temp_plane = temp_plane->next;
	while (temp_cylinder && count++ != 0)
		temp_cylinder = temp_cylinder->next;
	return (count);
}

static int	populate_mandatory(t_toremove *object, t_obj *obj)
{
	int	index;

	index = 0;
	if (obj->ambient)
	{
		object[index].type = AMBIENT;
		object[index].object = (void *)obj->ambient;
		index++;
	}
	if (obj->camera)
	{
		object[index].type = CAMERA;
		object[index].object = (void *)obj->camera;
		index++;
	}
	while (obj->light)
	{
		object[index].type = LIGHT;
		object[index].object = (void *)obj->light;
		index++;
		obj->light = obj->light->next;
	}
	return (index);
}

static void	populate_optional(t_toremove *object, t_obj *obj, int index)
{
	while (obj->sphere)
	{
		object[index].type = SPHERE;
		object[index].object = (void *)obj->sphere;
		index++;
		obj->sphere = obj->sphere->next;
	}
	while (obj->plane)
	{
		object[index].type = PLANE;
		object[index].object = (void *)obj->plane;
		index++;
		obj->plane = obj->plane->next;
	}
	while (obj->cylinder)
	{
		object[index].type = CYLINDER;
		object[index].object = (void *)obj->cylinder;
		index++;
		obj->cylinder = obj->cylinder->next;
	}
	object[index].type = NONE;
	object[index].object = NULL;
}

t_toremove	*populate_object_struct(t_obj *obj)
{
	t_toremove	*object;
	int			count;
	int			index;

	count = count_toremoves(obj);
	object = malloc(sizeof(t_toremove) * (count + 1));
	index = populate_mandatory(object, obj);
	populate_optional(object, obj, index);
	return (object);
}
