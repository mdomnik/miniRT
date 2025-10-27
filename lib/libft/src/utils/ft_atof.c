/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-12 17:43:32 by astavrop          #+#    #+#             */
/*   Updated: 2025-03-12 17:43:32 by astavrop         ###   ########:w        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
			ft_putstr_fd("Error: Invalid character in number (ft_atof)", 2);
			return (-1);
		}
		(*i)++;
	}
	return (result);
}

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

float	ft_atof(const char *str)
{
	int		i;
	float	result;
	int		sign;

	i = 0;
	sign = 1;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	result = parse_num(str, &i, false, 10.0f);
	if (str[i] == '.')
	{
		i++;
		result += parse_frac(str, &i, 10.0f);
	}
	return (result * sign);
}
