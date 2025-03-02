/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 19:22:37 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/25 19:13:20 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

static float	parse_num(const char *str, int *i, bool isf, float frac_div);
static float	parse_frac(const char *str, int *i, float frac_div);

/**
 * @brief Checks if the given string is of 'flag' format.
 *
 * This function checks if the given string has a valid format for a flag.
 * it also considers negative numbers with the (-) sign, to be ignored.
 * If the string is a valid option, it is duplicated and returned.
 * Otherwise, NULL is returned.
 *
 * @param str The string to be checked.
 * @return A pointer to the duplicated string
 * if it is a valid option, otherwise NULL.
 */
char	*check_if_option(char *str)
{
	char	*ret;

	if (!str)
		return (NULL);
	if (check_scene_file(str) == 0)
		return (NULL);
	if ((is_number(str) == 1) && str[0] == '-')
		return (NULL);
	ret = ft_strdup(str);
	return (ret);
}

/**
 * @brief Checks if a string is a number.
 *
 * This function checks if a given string is a valid number. It iterates through
 * each character of the string and checks if it falls within the range of valid
 * characters for a number. The valid characters include digits (0-9), decimal
 * point ('.'), minus sign ('-'), and comma (',').
 *
 * @param str The string to be checked.
 * @return Returns 0 if the string is a valid number, otherwise returns 1.
 */
int	is_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < 48 || str[i] > 57) && str[i] != '.'
			&& str[i] != '-' && str[i] != ',')
			return (1);
		i++;
	}
	return (0);
}

/**
 * Converts a string to a float value.
 *
 * @param str The string to be converted.
 * @return The converted float value.
 */
float	ft_atof(char *str)
{
	int		i;
	float	result;
	bool	is_negative;

	i = 0;
	is_negative = false;
	if (str[i] == '-')
	{
		is_negative = true;
		i++;
	}
	else if (str[i] == '+')
		i++;
	result = parse_num(str, &i, false, 10.0f);
	if (str[i] == '.')
	{
		i++;
		result += parse_frac(str, &i, 10.0f);
	}
	if (is_negative)
		result = -result;
	return (result);
}

/**
 * Parses a number from a string.
 *
 * This function takes a string and parses a number from it.
 * It iterates through the characters of the string and converts them
 * into a float value. The function supports both integer and
 * floating-point numbers. If the string contains invalid characters,
 * an error message is printed to the standard error stream and -1 is returned.
 *
 * @param str The string to parse the number from.
 * @param i   A pointer to the current index in the string.
 * @param isf A boolean flag indicating if the number is a floating-point number.
 * @param frac_div The divisor used to calculate
 * the fractional part of the number.
 * @return The parsed number as a float value, or -1 if an error occurred.
 */
static float	parse_num(const char *str, int *i, bool isf, float frac_div)
{
	float	result;

	result = 0.0f;
	while (str[*i] != '\0' && (ft_isdigit(str[*i]) || (str[*i] == '.' && !isf)))
	{
		if (ft_isdigit(str[*i]))
		{
			if (isf)
			{
				result += (str[*i] - '0') / frac_div;
				frac_div *= 10;
			}
			else
				result = result * 10 + (str[*i] - '0');
		}
		else if (str[*i] == '.')
			isf = true;
		else
		{
			ft_dprintf(2, "%s '%c'\n", ERR_INVALID_ATOB, str[*i]);
			return (-1);
		}
		(*i)++;
	}
	return (result);
}

/**
 * Parses a fraction from a string and returns the corresponding float value.
 *
 * @param str The string to parse the fraction from.
 * @param i   A pointer to the current index in the string.
 * @param frac_div The divisor used to calculate the fraction.
 * @return The parsed fraction as a float value.
 */
static float	parse_frac(const char *str, int *i, float frac_div)
{
	float	frac;

	frac = 0.0f;
	while (str[*i] != '\0' && ft_isdigit(str[*i]))
	{
		frac += (str[*i] - '0') / frac_div;
		frac_div *= 10;
		(*i)++;
	}
	return (frac);
}
