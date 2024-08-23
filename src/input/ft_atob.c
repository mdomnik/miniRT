/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 19:22:37 by mdomnik           #+#    #+#             */
/*   Updated: 2024/08/23 20:02:35 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

double	parse_number(const char *str, int *i, bool isf, double frac_div);
double	parse_frac(const char *str, int *i, double frac_div);

double	ft_atob(char *str)
{
	int		i;
	double	result;
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
	result = parse_number(str, &i, false, 10.0);
	if (str[i] == '.')
	{
		i++;
		result += parse_frac(str, &i, 10.0);
	}
	if (is_negative)
		result = -result;
	return (result);
}

double	parse_number(const char *str, int *i, bool isf, double frac_div)
{
	double	result;

	result = 0.0;
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
			ft_dprintf(2, "Error: Invalid character of '%c'\n", str[*i]);
			return (-1);
		}
		(*i)++;
	}
	return (result);
}

double	parse_frac(const char *str, int *i, double frac_div)
{
	double	frac;

	frac = 0.0;
	while (str[*i] != '\0' && ft_isdigit(str[*i]))
	{
		frac += (str[*i] - '0') / frac_div;
		frac_div *= 10;
		(*i)++;
	}
	return (frac);
}
