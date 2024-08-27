/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 19:33:06 by mdomnik           #+#    #+#             */
/*   Updated: 2024/08/27 16:45:12 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

void	printf_option_values(t_options *options);

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
	if (parse_scene_file(options) == -1)
		return (1);
	printf("scene file: %s\n", options->scene_file);
	printf_option_values(options);
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
