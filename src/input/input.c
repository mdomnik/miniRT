/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 19:33:06 by mdomnik           #+#    #+#             */
/*   Updated: 2024/09/09 17:24:42 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

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
