/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ruleset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 15:32:39 by mdomnik           #+#    #+#             */
/*   Updated: 2024/09/06 17:56:17 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

int check_object_rules(t_options *options, char **args, char **rules)
{
	int i;
	(void)options;

	i = 1;
	while (rules[i] != NULL)
	{
		if (ft_strcmp(rules[i], "COLOR") == 0)
			if (check_color_format(args[i]) == -1)
				return (-1);
		if (ft_strcmp(rules[i], "RATIO") == 0)
			if (check_ratio_format(args[i], 0, 1) == -1)
				return (-1);
		if (ft_strcmp(rules[i], "VECTOR") == 0)
			if (check_vector_format(args[i]) == -1)
				return (-1);
		if (ft_strcmp(rules[i], "VRANGE") == 0)
			if (check_vector_range_format(args[i]) == -1)
				return (-1);
		if (ft_strcmp(rules[i], "FLOAT") == 0)
			if (check_float_format(args[i]) == -1)
				return (-1);
		if (ft_strcmp(rules[i], "FOV") == 0)
			if (check_ratio_format(args[i], 0, 180) == -1)
				return (-1);
		i++;
	}
	return (0);
}

int check_color_format(char *str)
{
	char	**rgb;
	int		i;
	int 	num;
	
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ',' && ft_isdigit(str[i]) == 0)
			return (ret_message(ERR_INV_CHAR, str));
		i++;
	}
	i = 0;
	rgb = ft_split(str, ',');
	if (rgb == NULL || pointer_count(rgb) != 3)
		return (ret_message(ERR_COLOR_NUM, str));
	while (rgb[i] != NULL)
	{
		num = ft_atoi(rgb[i]);
		if (num < 0 || num > 255)
			return (ret_message(ERR_COLOR_RANGE, str));
		i++;
	}
	return (0);
}

int check_ratio_format(char *str, int min, int max)
{
	int i;
	
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '.' && str[i] != '-' && ft_isdigit(str[i]) == 0)
			return (ret_message(ERR_INV_CHAR, str));
		i++;
	}
	i = 0;
	if (ft_atob(str) < min || ft_atob(str) > max)
		return (ret_message(ERR_RANGE, str));
	return (0);
}

int check_vector_range_format(char *str)
{
	char	**xyz;
	int		i;
	
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ',' && str[i] != '-' &&  str[i] != '.' && ft_isdigit(str[i]) == 0)
			return (ret_message(ERR_INV_CHAR, str));
		i++;
	}
	i = 0;
	xyz = ft_split(str, ',');
	if (xyz == NULL || pointer_count(xyz) != 3)
		return (ret_message(ERR_VEC_NUM, str));
	while (xyz[i] != NULL)
	{
		if (check_ratio_format(xyz[i], -1, 1) == -1)
			return (-1);
		i++;
	}
	return (0);
}
