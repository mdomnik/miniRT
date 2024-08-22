/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 19:32:44 by mdomnik           #+#    #+#             */
/*   Updated: 2024/08/22 19:43:47 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

int	option_preferences(char **argv)
{
	int	opt_flags;

	opt_flags = 0;
	if (check_file_format(argv, &opt_flags, ft_strdup(OPTS_FULL), 0) == -1)
		return (-1);
	if (check_file_format(argv, &opt_flags, ft_strdup(OPTS_SHORT), 1) == -1)
		return (-1);
	return (opt_flags);
}

int	check_file_format(char **argv, int *opt_flags, char *options, int type)
{
	int	i;
	int	ato_ret;

	i = 1;
	while (argv[i])
	{
		ato_ret = args_to_opts(argv[i], ft_strdup(options), type);
		if (ato_ret == -2)
			return (-1);
		else
			if (opt_binary_assignment(ato_ret, opt_flags) == -1)
				return (-1);
		i++;
	}
	return (0);
}

int	args_to_opts(char *str, char *options, int type)
{
	char	**opts;
	int		i;

	opts = ft_split(options, ',');
	i = 0;
	while (opts[i])
	{
		if (ft_strcmp(opts[i], str) == 0)
			return (i);
		i++;
	}
	if ((type == 0 && str[0] == '-' && str[1] == '-' )
		|| (type == 1 && str[0] == '-' && str[1] != '-'))
	{
		ft_dprintf(2, "%s\n", ERR_INVALID_OPT);
		return (-2);
	}
	return (-1);
}

int	opt_binary_assignment(int value, int *opt_flags)
{
	if (value < 0)
		return (0);
	if (*opt_flags & (1 << value))
	{
		ft_dprintf(2, "%s\n", ERR_DOUBLE_OPT);
		return (-1);
	}
	*opt_flags |= (1 << value);
	return (0);
}
