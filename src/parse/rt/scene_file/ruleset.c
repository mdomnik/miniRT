/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ruleset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 15:32:39 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/24 18:16:04 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

/**
 * @brief Checks the rules for the objects in the scene file.
 *
 * This function checks the rules for each object in the scene file based on
 * the given arguments and rules. It iterates through the rules and performs
 * specific checks based on the rule type.
 * The supported rule types are: COLOR, RATIO, VECTOR, VRANGE, FLOAT, and FOV.
 *
 * @param args An array of strings representing the arguments for each object.
 * @param rules An array of strings representing the rules for each object.
 * @return Returns 0 if all the rules are satisfied, -1 otherwise.
 */
int	check_object_rules(char **args, char **rules)
{
	int	i;

	i = 0;
	while (rules[++i] != NULL)
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
		if (ft_strcmp(rules[i], "STRING") == 0)
			if (check_string_format(args[i]) == -1)
				return (-1);
	}
	return (0);
}

/**
 * @brief Checks the format of a color string.
 *
 * This function checks if the given string represents a valid color format.
 * The color format should be in the form "R,G,B" where R, G, and B are integers
 * between 0 and 255 inclusive. The function returns 0 if the color format
 * is valid, otherwise it returns an error code.
 *
 * @param str The string to be checked.
 * @return 0 if the color format is valid, otherwise an error code.
 */
int	check_color_format(char *str)
{
	char	**rgb;
	int		i;
	int		num;

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

/**
 * @brief Check the format of a ratio string.
 *
 * This function checks if a given string has a valid format for a ratio.
 * The ratio should consist of digits, a dot ('.'), and a minus sign ('-').
 * Any other character will cause the function to return an error.
 *
 * @param str The string to be checked.
 * @param min The minimum value allowed for the ratio.
 * @param max The maximum value allowed for the ratio.
 * @return 0 if the ratio format is valid, otherwise an error code.
 */
int	check_ratio_format(char *str, int min, int max)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '.' && str[i] != '-' && ft_isdigit(str[i]) == 0)
			return (ret_message(ERR_INV_CHAR, str));
		i++;
	}
	i = 0;
	if (ft_atof(str) < min || ft_atof(str) > max)
		return (ret_message(ERR_RANGE, str));
	return (0);
}

/**
 * @brief Checks if the given string has a valid vector range format.
 *
 * This function checks if the string contains valid characters and follows
 * the format for a vector range. The valid characters include digits, commas,
 * dashes, and periods.
 * The format for a vector range is three numbers separated by commas.
 *
 * @param str The string to be checked.
 * @return Returns 0 if the string has a valid vector range format,
 * otherwise returns an error code.
 */
int	check_vector_range_format(char *str)
{
	char	**xyz;
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ',' && str[i] != '-'
			&& str[i] != '.' && ft_isdigit(str[i]) == 0)
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
