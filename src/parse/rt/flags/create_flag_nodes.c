/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_flag_nodes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 22:43:50 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/10 17:30:04 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

/**
 * @brief This function is a starting point for populating the options->values
 * linked list with flag arguments.
 *
 * 
 * This function takes the value of the flag, a pointer to a t_options struct,
 * an argument string, and a flag. It groups the flag, flag_type,
 * and argument string into a single array of strings, flag_join.
 * Then, it calls the process_flag function with the appropriate arguments
 * to create a new value node and append it to the options->values linked list.
 * it returns 0 if successful, -1 if an error occurs.
 *
 * @param value The value for the flag.
 * @param options A pointer to a t_options struct.
 * @param str A string of the flag's argument.
 * @param flag flag string.
 * @return 0 if successful, -1 if an error occurs.
 */
int	value_containers(int value, t_options *options, char *str, char *flag)
{
	char	**f_types;
	char	**flag_join;
	char	*opts_value;

	opts_value = ft_strdup(OPTS_VALUE);
	if (value < 0)
		return (free(opts_value), 0);
	f_types = ft_split(opts_value, ',');
	free(opts_value);
	flag_join = malloc(sizeof(char *) * 4);
	flag_join[0] = ft_strdup(flag);
	flag_join[1] = ft_strdup(f_types[value]);
	free_double(f_types);
	if (str)
		flag_join[2] = ft_strdup(str);
	else
		flag_join[2] = NULL;
	flag_join[3] = NULL;
	if (process_flag(flag_join[1], options, value, flag_join) == -1)
		return (-1);
	return (0);
}

/**
 * @brief compares the flag's corresponding input type
 * against a preset type list and creates a new option node.
 *
 * 
 * This function processes the flag's arguments based on the flag's type.
 * If the flag type matches a given type, it calls the create_option function.
 * If the flag type is "NULL", it calls the handle_null_value function.
 * The following process will check if the argument for a flag is valid, if not,
 * it will print an error message to stderr and return -1.
 * 
 * @param f_type The type of the flag.
 * @param options The options structure to update.
 * @param value The value of the flag.
 * @param flag_join (char **), which holds relevant flag information.
 * @return 0 if the flag was processed successfully, -1 otherwise.
 */
int	process_flag(char *f_type, t_options *options, int value, char **flag_join)
{
	if (ft_strnstr(f_type, "STRING", ft_strlen(f_type))
		|| ft_strnstr(f_type, "INT", ft_strlen(f_type)))
	{
		if (create_option(options, value, flag_join) == -1)
			return (-1);
	}
	return (0);
}

/**
 * @brief creates a t_value node and appends it to the 
 * options->values linked list if the flag's argument is valid.
 *
 * This function checks if the flag's argument is valid against its
 * relevant flag type. If the flag's argument is valid, it creates a new
 * t_value node and appends it to the back of the options->values linked list.
 * if the flag's argument is invalid, it prints an error message to stderr
 * and returns -1.
 * 
 * @param options The options list to add the new node to.
 * @param value The value of the option.
 * @param flag_join The array of relevant flag information.
 * @return 0 if the option node was successfully created and added, -1 otherwise.
 */
int	create_option(t_options *options, int value, char **flag_join)
{
	char	*arg;

	arg = check_if_option(flag_join[2]);
	if (value == 0)
		options->values->filename = ft_strdup(arg);
	if (value == 1)
	{
		options->values->aa_samples = 0;
		if (ft_atoi(arg) > 0)
			options->values->aa_samples = ft_atoi(arg);
	}
	if (value == 2)
	{
		options->values->threads = 0;
		if (ft_atoi(arg) > 0)
			options->values->threads = ft_atoi(arg);
	}
	else if (arg == NULL)
	{
		ft_dprintf(2, "Error: Option '%s' %s\n", flag_join[0], ERR_REQ_ARG);
		return (-1);
	}
	return (0);
}
