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

int	validate_file_name(char **argv)
{
	char **args =  double_dup(argv);
	
	args = remove_flags(args);
	return (0);
}

char **double_dup(char **strs)
{
	char **ret;
	int i;

	i = 0;
	while (strs[i])
		i++;
	ret = gc_malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (strs[i])
	{
		ret[i] = ft_strdup(strs[i]);
		i++;
	}
	ret[i] = NULL;
	return (ret);
}

char **remove_flags(char **args)
{
	int i;
	int j;
	char **ret;

	i = 0;
	j = 0;
	ret = NULL;
	while (args[i])
	{
		if (args[i][0] != '-')
		{
			ret[j] = ft_strdup(args[i]);
			j++;
		}
		i++;
	}
	ret[j] = NULL;
	return (ret);
}

int valid_format(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((str[i] > 90 || str[i] < 65) && (str[i] > 122 || str[i] < 97) && (str[i] < 48 || str[i] > 57) && str[i] != '_')
			return (1);
		i++;
	}
	return (0);
}