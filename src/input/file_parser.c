/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 19:33:06 by mdomnik           #+#    #+#             */
/*   Updated: 2024/08/23 20:15:06 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

void printf_option_values(t_options *options);

int	main(int argc, char **argv)
{
	t_options	*options;

	options = gc_malloc(sizeof(t_options));
	if (validate_arg_count(argc))
		return (1);
	if (option_preferences(argv, options) == -1)
		return (1);
	if (get_option_values(options, argv) == -1)
		return (1);
	printf_option_values(options);
}

int	validate_arg_count(int argc)
{
	if (argc < 2)
	{
		ft_dprintf(2, "%s\n", ERR_SCENE_FILE);
		return (1);
	}
	return (0);
}

void printf_option_values(t_options *options)
{
	t_value *current;

	current = options->values;
	while (current != NULL)
	{
		if (current->type == 0)
			printf("string: %s\n", current->value.string.string_value);
		if (current->type == 1)
			printf("float: %f\n", current->value.float_value.float_value);
		if (current->type == 2)
			printf("string: %s\n", current->value.string.string_value);
		if (current->type == 4)
			printf("float: %f\n", current->value.float_value.float_value);
		if (current->type == 5)
			printf("vector: %f %f %f\n", current->value.vector.x, current->value.vector.y, current->value.vector.z);
		if (current->type == 7)
			printf("string: %s\n", current->value.string.string_value);
		current = current->next;
	}
}
