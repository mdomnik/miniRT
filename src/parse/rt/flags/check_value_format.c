/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_value_format.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 22:40:48 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/14 18:03:40 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

/**
 * @brief Checks the format of a flag's string argument.
 *
 * This function checks if a given flag's string has a valid format.
 * The valid format consists of uppercase letters (A-Z),
 * lowercase letters (a-z), and underscores (_).
 * If the string contains any other characters, an error message
 * is printed to the standard error stream and the function returns -1.
 * Otherwise, the function returns 0.
 *
 * @param str The flag's string argument to be checked.
 * @return 0 if the string has a valid format, -1 otherwise.
 */
int	check_string_format(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < 65 || str[i] > 90)
			&& (str[i] < 97 || str[i] > 122)
			&& (str[i] < '0' || str[i] > '9') && str[i] != '_'
			&& str[i] != '.' && str[i] != '/')
		{
			ft_dprintf(2, "%s '%c'\n", ERR_INVALID_CHAR, str[i]);
			return (-1);
		}
		i++;
	}
	return (0);
}

/**
 * @brief Checks the format of a flag's float value argument.
 *
 * This function checks if the given string represents a valid float value.
 * The valid format consists of digits (0-9), a single decimal point (.),
 * and an optional negative sign (-) at the beginning of the string.
 * If the string contains any other characters or multiple (.), an error message
 * is printed to the standard error stream and the function returns -1.
 *
 * @param str The flag's float (char *) to be checked.
 * @return Returns 0 if the format is valid, -1 otherwise.
 */
int	check_float_format(char *str)
{
	int	i;
	int	dot_count;

	i = 0;
	dot_count = 0;
	while (str[i])
	{
		if ((str[i] < 48 || str[i] > 57) && str[i] != '.')
		{
			if (str[i] == '-')
				return (ret_message(ERR_NON_NEG, str));
			else
				ft_dprintf(2, "%s '%c'\n", ERR_INVALID_CHAR, str[i]);
			return (-1);
		}
		if (str[i] == '.')
			dot_count++;
		i++;
	}
	if (dot_count > 1)
	{
		ft_dprintf(2, "%s\n", ERR_DOT_COUNT);
		return (-1);
	}
	return (0);
}

/**
 * @brief Checks if the string contains any empty values between commas,
 *        at the start, or at the end.
 *
 * This function checks if the input string contains consecutive commas,
 * starts with a comma, or ends with a comma, indicating empty values in
 * the vector format.
 *
 * @param str The input string to check.
 * @return Returns 1 if there are empty values, 0 otherwise.
 */
static int	has_empty_value(char *str)
{
	int	i;
	int	n_commas;

	i = 0;
	if (str[0] == ',' || str[ft_strlen(str) - 1] == ',')
		return (1);
	while (str[i])
	{
		if (str[i] == ',' && str[i + 1] == ',')
			return (1);
		i++;
	}
	i = -1;
	n_commas = 0;
	while (str[++i])
	{
		if (str[i] == ',')
			n_commas++;
	}
	if (n_commas != 2)
		return (1);
	return (0);
}

/**
 * @brief Checks the format of a flag's vector value argument.
 *
 * This function checks if the given string represents a valid vector value.
 * The valid format consists of digits (0-9), a single decimal point (.),
 * and an optional negative sign (-) at the beginning of the value.
 * 3 values are separated by commas (,) and the values are x, y, and z.
 * If the string contains any other characters or multiple (.) before a comma,
 * an error message is printed to the standard error stream and the function.
 *
 * @param str The flag's vector (char *) to be checked.
 * @return Returns 0 is the format is valid, -1 otherwise.
 */
int	check_vector_format(char *str)
{
	int	i;
	int	dot_count;

	if (has_empty_value(str))
		return (-1);
	i = -1;
	dot_count = 0;
	while (str[++i])
	{
		if (i < ft_strlen(str) && str[i] == '-' && (str[i + 1] < '0'
				|| str[i + 1] > '9'))
			return (-1);
		if ((str[i] < '0' || str[i] > '9') && str[i] != '.'
			&& str[i] != '-' && str[i] != ',')
			return (ft_dprintf(2, "%s '%c'\n", ERR_INVALID_CHAR, str[i]), -1);
		else if (str[i] == '.')
			dot_count++;
		if (dot_count > 1)
			return (ft_dprintf(2, "%s\n", ERR_DOT_COUNT), -1);
		else if (str[i] == ',')
			dot_count = 0;
	}
	return (0);
}
