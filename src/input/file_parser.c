/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 19:33:06 by mdomnik           #+#    #+#             */
/*   Updated: 2024/08/22 20:08:56 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

int	main(int argc, char **argv)
{
	t_options	*options;

	options = gc_malloc(sizeof(t_options));
	if (validate_arg_count(argc))
		return (1);
	options->opts_flags = option_preferences(argv);
	if (options->opts_flags == -1)
		return (1);
	if (get_option_values(options->opts_flags, options, argv) == -1)
		return (1);
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
