/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:41:41 by mdomnik           #+#    #+#             */
/*   Updated: 2024/09/21 18:56:20 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

// void	printf_objects(t_options *options)
// {
// 	printf("AMBIENT\n");
// 	printf("ambient_ratio: %f\n", options->objects.ambient->light_ratio);
// 	printf("ambient_color: %d %d %d\n", options->objects.ambient->color.r,
// 		options->objects.ambient->color.g, options->objects.ambient->color.b);
// 	printf("---------------------------------------------------\nCAMERA\n");
// 	printf("camera_coords: %f %f %f\n", options->objects.camera->center.x,
// 		options->objects.camera->center.y, options->objects.camera->center.z);
// 	printf("camera_vector_range: %f %f %f\n", options->objects.camera->vrange.x,
// 		options->objects.camera->vrange.y, options->objects.camera->vrange.z);
// 	printf("camera_fov: %f\n", options->objects.camera->fov);
// 	printf("---------------------------------------------------\nLIGHTS\n");
// 	while (options->objects.light != NULL)
// 	{
// 		printf("light_coords: %f %f %f\n", options->objects.light->coords.x,
// 			options->objects.light->coords.y, options->objects.light->coords.z);
// 		printf("light_range: %f\n", options->objects.light->brightness);
// 		printf("light_color: %d %d %d\n", options->objects.light->color.r,
// 			options->objects.light->color.g, options->objects.light->color.b);
// 		printf("--------------------\n");
// 		options->objects.light = options->objects.light->next;
// 	}
// 	printf("SPHERES\n");
// 	while (options->objects.sphere != NULL)
// 	{
// 		printf("sphere_coords: %f %f %f\n", options->objects.sphere->coords.x,
// 			options->objects.sphere->coords.y, options->objects.sphere->coords.z);
// 		printf("sphere_diameter: %f\n", options->objects.sphere->diameter);
// 		printf("sphere_color: %d %d %d\n", options->objects.sphere->color.r,
// 			options->objects.sphere->color.g, options->objects.sphere->color.b);
// 		printf("--------------------\n");
// 		options->objects.sphere = options->objects.sphere->next;
// 	}
// 	printf("PLANES\n");
// 	while (options->objects.plane != NULL)
// 	{
// 		printf("plane_coords: %f %f %f\n", options->objects.plane->coords.x,
// 			options->objects.plane->coords.y, options->objects.plane->coords.z);
// 		printf("plane_normal: %f %f %f\n", options->objects.plane->normal.x,
// 			options->objects.plane->normal.y, options->objects.plane->normal.z);
// 		printf("plane_color: %d %d %d\n", options->objects.plane->color.r,
// 			options->objects.plane->color.g, options->objects.plane->color.b);
// 		printf("--------------------\n");
// 		options->objects.plane = options->objects.plane->next;
// 	}
// 	printf("CYLINDERS\n");
// 	while (options->objects.cylinder != NULL)
// 	{
// 		printf("cylinder_coords: %f %f %f\n", options->objects.cylinder->coords.x,
// 			options->objects.cylinder->coords.y, options->objects.cylinder->coords.z);
// 		printf("cylinder_normal: %f %f %f\n", options->objects.cylinder->normal.x,
// 			options->objects.cylinder->normal.y, options->objects.cylinder->normal.z);
// 		printf("cylinder_diameter: %f\n", options->objects.cylinder->diameter);
// 		printf("cylinder_height: %f\n", options->objects.cylinder->height);
// 		printf("cylinder_color: %d %d %d\n", options->objects.cylinder->color.r,
// 			options->objects.cylinder->color.g, options->objects.cylinder->color.b);
// 		printf("--------------------\n");
// 		options->objects.cylinder = options->objects.cylinder->next;
// 	}
// }

// void	printf_option_values(t_options *options)
// {
// 	t_value	*current;

// 	current = options->values;
// 	while (current != NULL)
// 	{
// 		if (current->type == 0)
// 		{
// 			printf("type: %d | ", current->type);
// 			printf("string: %s\n", current->value.string.string_value);
// 		}
// 		if (current->type == 1)
// 		{
// 			printf("type: %d | ", current->type);
// 			printf("float: %f\n", current->value.float_value.float_value);
// 		}
// 		if (current->type == 2)
// 		{
// 			printf("type: %d | ", current->type);
// 			printf("string: %s\n", current->value.string.string_value);
// 		}
// 		if (current->type == 4)
// 		{
// 			printf("type: %d | ", current->type);
// 			printf("float: %f\n", current->value.float_value.float_value);
// 		}
// 		if (current->type == 5)
// 		{
// 			printf("type: %d | ", current->type);
// 			printf("vector: %f %f %f\n", current->value.vector.x,
// 				current->value.vector.y, current->value.vector.z);
// 		}
// 		if (current->type == 7)
// 		{
// 			printf("type: %d | ", current->type);
// 			printf("string: %s\n", current->value.string.string_value);
// 		}
// 		if (current->type == 6)
// 		{
// 			printf("type: %d | ", current->type);
// 			printf("vector: %f %f %f\n", current->value.vector.x,
// 				current->value.vector.y, current->value.vector.z);
// 		}
// 		current = current->next;
// 	}
// }
