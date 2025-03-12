/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_format_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:12:38 by astavrop          #+#    #+#             */
/*   Updated: 2025/03/12 14:01:04 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

int	parse_param_value(char *param, int *i)
{
	while (param[*i] != ':' && param[*i] != '\0')
		(*i)++;
	if (param[*i] == '\0')
	{
		ft_dprintf(2, "Problem parsing: %s", param);
		return (-1);
	}
	return (0);
}

int	check_value_bound(char *param, char *arg)
{
	int		i;
	float	value;

	i = validate_arg_chars(arg);
	if (i == 2)
		return (2);
	value = ft_atof_mrt(arg);
	i = 0;
	if (parse_param_value(param, &i) == -1)
		return (-1);
	if (check_limits(param + i + 1, value) == -1)
		return (-1);
	return (0);
}

int	validate_arg_chars(char *arg)
{
	int	i;
	int	dot_count;

	i = 0;
	dot_count = 0;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	while (arg[i] != '\0')
	{
		if (arg[i] == '.')
		{
			dot_count++;
			if (dot_count > 1)
				return (-1);
		}
		else if (!ft_isdigit(arg[i]))
			return (-1);
		i++;
	}
	return (0);
}

static int	parse_limit_values(char *limits, float *min, float *max)
{
	char	**values;
	int		status;

	if (ft_strncmp(limits, "NULL", 4) == 0)
	{
		*min = 0;
		*max = 0;
		return (0);
	}
	values = ft_split(limits, '-');
	status = 0;
	if (!values[0] || !values[1])
		status = -1;
	else
	{
		*min = ft_atof_mrt(values[0]);
		*max = ft_atof_mrt(values[1]);
		if (*min > *max)
			status = -1;
	}
	free_double(values);
	return (status);
}

int	check_limits(char *limits, float value)
{
	float	min;
	float	max;

	if (parse_limit_values(limits, &min, &max) == -1)
	{
		ft_dprintf(2, "Invalid limit format: [%s]\n", limits);
		return (-1);
	}
	if (value < min || value > max)
	{
		printf("Value %f out of bounds [%f,%f]\n",
			value, min, max);
		return (-1);
	}
	return (0);
}
