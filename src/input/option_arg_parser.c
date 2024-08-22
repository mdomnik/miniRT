/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_arg_parser.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 19:49:30 by mdomnik           #+#    #+#             */
/*   Updated: 2024/08/22 20:11:17 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

int get_option_values (int opt_flags, t_options *options, char **argv)
{
	int i;

	i = 1;
	while (argv[i])
	{
		if (opt_flags & (1 << 0))
			options->save = argv[i + 1];
		if (opt_flags & (1 << 1))
			options->reflection = argv[i + 1];
		i++;
	}
	printf("Save: %s\n", options->save);
	return (0);
}
