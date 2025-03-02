/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_value_format.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 22:40:48 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/25 15:45:09 by mdomnik          ###   ########.fr       */
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
		if ((str[i] < 48 || str[i] > 57) && str[i] != '.' && str[i] != '-')
		{
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

	i = 0;
	dot_count = 0;
	while (str[i])
	{
		if ((str[i] < 48 || str[i] > 57) && str[i] != '.'
			&& str[i] != '-' && str[i] != ',')
		{
			ft_dprintf(2, "%s '%c'\n", ERR_INVALID_CHAR, str[i]);
			return (-1);
		}
		else if (str[i] == '.')
			dot_count++;
		if (dot_count > 1)
		{
			ft_dprintf(2, "%s\n", ERR_DOT_COUNT);
			return (-1);
		}
		else if (str[i] == ',')
			dot_count = 0;
		i++;
	}
	return (0);
}
