/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_object.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:40:15 by mdomnik           #+#    #+#             */
/*   Updated: 2024/10/17 04:53:03 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

static int count_objects(t_obj *source)
{
	int count;
	 t_light *temp_light = source->light;
    t_sphere *temp_sphere = source->sphere;
    t_plane *temp_plane = source->plane;
    t_cylinder *temp_cylinder = source->cylinder;
	
	count = 2;
	while(temp_light)
	{
		count++;
		temp_light = temp_light->next;
	}
	while (temp_sphere)
	{
		count++;
		temp_sphere = temp_sphere->next;
	}
	while (temp_plane)
	{
		count++;
		temp_plane = temp_plane->next;
	}
	while (temp_cylinder)
	{
		count++;
		temp_cylinder = temp_cylinder->next;
	}
	return (count);
}

static int	populate_mandatory(t_object *object, t_obj *obj)
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
	return(index);
}

static void populate_optional(t_object *object, t_obj *obj, int index)
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

t_object	*populate_object_struct(t_obj *obj)
{
	t_object *object;
	int count;
	int	index;

	count = count_objects(obj);

	object = malloc(sizeof(t_object) * (count + 1));
	index = populate_mandatory(object, obj);
	populate_optional(object, obj, index);
	return (object);
}