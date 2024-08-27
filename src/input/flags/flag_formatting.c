/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_formatting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 19:32:44 by mdomnik           #+#    #+#             */
/*   Updated: 2024/08/27 00:25:23 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

/**
 * @brief Option preferences function.
 *
 * This function begins the process of checking the flag format
 * as well as their arguments. The function checks the full and short
 * options flags and updates the options structure accordingly.
 *
 * @param argv The command line arguments.
 * @param options The options structure to be updated.
 * @return 0 if the file format is successfully checked and updated,
 * -1 otherwise.
 */
int	option_preferences(char **argv, t_options *options)
{
	if (check_file_format(argv, options, ft_strdup(OPTS_FULL), 0) == -1)
		return (-1);
	if (check_file_format(argv, options, ft_strdup(OPTS_SHORT), 1) == -1)
		return (-1);
	return (0);
}

/**
 * @brief Checks each command line argument for a match with a list of flags.
 *
 * This function checks each argument against a list of flags
 * using the args_to_opts function. If the argument is not found in the list,
 * the function returns -1. Otherwise, the function performs binary assignment
 * using the opt_binary_assignment to update the options structure. I also calls
 * the value_containers function to process the argument value and update the
 * options structure. If any of the steps fail, the function returns -1.
 * 
 * @param argv The command line arguments.
 * @param options The options structure to store the converted options.
 * @param flag The flag to be used for conversion.
 * @param type The type of conversion to be performed.
 * @return 0 if the file format is valid, -1 otherwise.
 */
int	check_file_format(char **argv, t_options *options, char *flag, int type)
{
	int	i;
	int	ato_ret;

	i = 1;
	while (argv[i])
	{
		ato_ret = args_to_opts(argv[i], ft_strdup(flag), type);
		if (ato_ret == -2)
			return (-1);
		else
		{
			if (opt_binary_assignment(ato_ret, options) == -1)
				return (-1);
			if (value_containers(ato_ret, options, argv[i + 1], argv[i]) == -1)
				return (-1);
		}
		i++;
	}
	return (0);
}

/**
 * @brief Converts a string to an option index based on a given flag and type.
 *
 * This function takes a string, a flag, and a type as input parameters.
 * It splits the flag into options using a comma as a delimiter and compares
 * each option with the given string. If a match is found, the function returns
 * the index of the option. If the string is not a number and start with (-),
 * an error message is printed and -2 is returned.
 * If no match is found, -1 is returned.
 *
 * @param str The string to be converted to an option index.
 * @param flag The flag used to split into options.
 * @param type The type of the flag.
 * @return The index of the option if a match is found, -2
 * if the string is a non-valid flag, -1 if no match is found.
 */
int	args_to_opts(char *str, char *flag, int type)
{
	char	**opts;
	int		i;

	opts = ft_split(flag, ',');
	i = 0;
	while (opts[i])
	{
		if (ft_strcmp(opts[i], str) == 0)
			return (i);
		i++;
	}
	if (is_number(str) == 1)
	{
		if ((type == 0 && str[0] == '-' && str[1] == '-' )
			|| (type == 1 && str[0] == '-' && str[1] != '-'))
		{
			ft_dprintf(2, "%s '%s'\n", ERR_INVALID_OPT, str);
			return (-2);
		}
	}
	return (-1);
}

/**
 * @brief Assigns a binary value to an option flag.
 *
 * This function assigns a binary value to an option flag
 * in the provided `t_options` structure.
 * It checks if the value is less than 0 and returns 0 if true.
 * It also checks if the flag is already set and returns -1 if true,
 * printing an error message.
 * If the flag is not set, it sets the flag and returns 0.
 *
 * @param value The binary position index to assign (1) to the flag.
 * @param options Pointer to the `t_options` structure.
 * @return 0 if the flag was successfully set, -1 if the flag is already set.
 */
int	opt_binary_assignment(int value, t_options *options)
{
	if (value < 0)
		return (0);
	if (options->opts_flags & (1 << value))
	{
		ft_dprintf(2, "%s\n", ERR_DOUBLE_OPT);
		return (-1);
	}
	options->opts_flags |= (1 << value);
	return (0);
}
