/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_format_op2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:25:49 by astavrop          #+#    #+#             */
/*   Updated: 2025/03/13 17:58:55 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

inline static int	compare_pattern_type(char *type, char *preset)
{
	return (ft_strncmp(type, preset, ft_strlen(type)) == 0);
}

static void	set_pattern_type(char *type, t_pattern *pattern)
{
	if (compare_pattern_type(type, "stripe"))
		pattern->type = STRIPE;
	else if (compare_pattern_type(type, "gradient"))
		pattern->type = GRADIENT;
	else if (compare_pattern_type(type, "ring"))
		pattern->type = RING;
	else if (compare_pattern_type(type, "checkers"))
		pattern->type = CHECKERS;
	else
	{
		pattern->type = FAIL;
		return ;
	}
	pattern->simple = true;
}

int	pattern_get_type(char *type, t_pattern *pattern)
{
	int		i;
	char	**types;

	types = ft_split(PREDETERMINED_PATTERNS, ',');
	i = 0;
	while (types[i] != NULL)
	{
		if (compare_pattern_type(type, types[i]))
			break ;
		i++;
	}
	if (types[i] == NULL)
	{
		free_double(types);
		return (-1);
	}
	set_pattern_type(types[i], pattern);
	free_double(types);
	return (0);
}
