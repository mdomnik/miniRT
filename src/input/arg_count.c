/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_count.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 03:28:56 by mdomnik           #+#    #+#             */
/*   Updated: 2024/08/27 03:47:42 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

int	check_arg_count(char **argv)
{
	int		i;
	bool	repeat;

	i = 0;
	repeat = false;
	while (argv[i])
	{
		if (argv[i][0] != '-')
		{
			if (repeat == true && check_scene_file(argv[i]) == -1)
			{
				ft_dprintf(2, "%s\n", ERR_ARGS);
				return (-1);
			}
			repeat = true;
		}
		if (argv[i][0] == '-')
			repeat = false;
		i++;
	}
	return (0);
}
