/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_arg_parser.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 19:49:30 by mdomnik           #+#    #+#             */
/*   Updated: 2024/08/23 16:51:55 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

// to be implemented
int get_option_values (t_options *options, char **argv)
{
	int i;

	i = 1;
	while (argv[i])
	{
/* 		if (argv[i] == "--save" || argv[i] == "-s") //save
			if (save_option(argv[i + 1], options))
				return (-1); */
/* 		if (options->opts_flags & (1 << 1))
			options->reflection = argv[i + 1]; */
		i++;
	}
	printf("opts_flags: %d\n", options->opts_flags);
	return (0);
}
