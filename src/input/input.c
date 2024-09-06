/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 19:33:06 by mdomnik           #+#    #+#             */
/*   Updated: 2024/09/06 18:00:49 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

void	printf_option_values(t_options *options);
void	printf_objects(t_options *options);

int	main(int argc, char **argv)
{
	t_options	*options;

	(void)argc;
	options = gc_malloc(sizeof(t_options));
	if (validate_file_name(argv, options) == -1)
		return (1);
	if (check_arg_count(argv) == -1)
		return (1);
	if (option_preferences(argv, options) == -1)
		return (1);
	if (get_scene_data(options) == -1)
		return (1);
	if (check_scene_data(options) == -1)
		return (1);
	printf_option_values(options);
	printf_objects(options);
}

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

void printf_objects(t_options *options)
{
	printf("ambient_ratio: %f\n", options->objects.ambient->ratio.range);
	printf("ambient_color: %d %d %d\n", options->objects.ambient->color.r,
		options->objects.ambient->color.g, options->objects.ambient->color.b);
	printf("camera_coords: %f %f %f\n", options->objects.camera->coords.x,
		options->objects.camera->coords.y, options->objects.camera->coords.z);
	printf("camera_vector_range: %f %f %f\n", options->objects.camera->vector_range.x.range,
		options->objects.camera->vector_range.y.range, options->objects.camera->vector_range.z.range);
	printf("camera_fov: %f\n", options->objects.camera->fov.float_value);
	printf("light_coords: %f %f %f\n", options->objects.light->coords.x,
		options->objects.light->coords.y, options->objects.light->coords.z);
	printf("light_range: %f\n", options->objects.light->ratio.float_value);
	printf("light_color: %d %d %d\n", options->objects.light->color.r,
		options->objects.light->color.g, options->objects.light->color.b);
	printf("light_coords: %f %f %f\n", options->objects.light->next->coords.x,
		options->objects.light->next->coords.y, options->objects.light->next->coords.z);
	printf("light_range: %f\n", options->objects.light->next->ratio.float_value);
	printf("light_color: %d %d %d\n", options->objects.light->next->color.r,
		options->objects.light->next->color.g, options->objects.light->next->color.b);

	
}

void	printf_option_values(t_options *options)
{
	t_value	*current;

	current = options->values;
	while (current != NULL)
	{
		if (current->type == 0)
		{
			printf("type: %d | ", current->type);
			printf("string: %s\n", current->value.string.string_value);
		}
		if (current->type == 1)
		{
			printf("type: %d | ", current->type);
			printf("float: %f\n", current->value.float_value.float_value);
		}
		if (current->type == 2)
		{
			printf("type: %d | ", current->type);
			printf("string: %s\n", current->value.string.string_value);
		}
		if (current->type == 4)
		{
			printf("type: %d | ", current->type);
			printf("float: %f\n", current->value.float_value.float_value);
		}
		if (current->type == 5)
		{
			printf("type: %d | ", current->type);
			printf("vector: %f %f %f\n", current->value.vector.x,
				current->value.vector.y, current->value.vector.z);
		}
		if (current->type == 7)
		{
			printf("type: %d | ", current->type);
			printf("string: %s\n", current->value.string.string_value);
		}
		if (current->type == 6)
		{
			printf("type: %d | ", current->type);
			printf("vector: %f %f %f\n", current->value.vector.x,
				current->value.vector.y, current->value.vector.z);
		}
		current = current->next;
	}
}
