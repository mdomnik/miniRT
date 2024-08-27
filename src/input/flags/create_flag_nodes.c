/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_flag_nodes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 22:43:50 by mdomnik           #+#    #+#             */
/*   Updated: 2024/08/27 00:58:39 by mdomnik          ###   ########.fr       */
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
		return (0);
	f_types = ft_split(opts_value, ',');
	flag_join = gc_malloc(sizeof(char *) * 4);
	flag_join[0] = ft_strdup(flag);
	flag_join[1] = ft_strdup(f_types[value]);
	printf("flag_join[1]: %s\n", flag_join[1]);
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
		|| ft_strnstr(f_type, "FLOAT", ft_strlen(f_type))
		|| ft_strnstr(f_type, "VECTOR", ft_strlen(f_type)))
	{
		if (create_option(options, value, flag_join) == -1)
			return (-1);
	}
	if (ft_strnstr(f_type, "NULL", ft_strlen(f_type)))
	{
		if (handle_null_value(flag_join[2]) == 1)
		{
			ft_dprintf(2, "Error: Option '%s' %s\n", flag_join[0], ERR_NO_ARG);
			return (-1);
		}
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
	t_value	*new_value_node;
	char	*arg;

	arg = check_if_option(flag_join[2]);
	if (flag_join[1][0] == '*' && arg == NULL)
		new_value_node = create_value_node(value, flag_join[1], NULL);
	else if (arg == NULL)
	{
		ft_dprintf(2, "Error: Option '%s' %s\n", flag_join[0], ERR_REQ_ARG);
		return (-1);
	}
	else
		new_value_node = create_value_node(value, flag_join[1], arg);
	if (new_value_node == NULL)
		return (-1);
	append_value_node(options, new_value_node);
	return (0);
}

/**
 * @brief Creates a new value node with the specified type, value type, and data.
 *
 * This function compares the value type against a list of known types and
 * runs the appropriate function to check and handle the flag's argument.
 * If the flag's argument is valid, it creates a new value node
 * and returns a pointer to it. If the flag's argument is invalid,
 * it prints an error message to stderr and returns NULL.
 *
 * @param type enum of the flag's type.
 * @param value_type string holding the value type.
 * @param data argument string.
 * @return A pointer to the newly created value node,
 * or NULL if an error occurred.
 */
t_value	*create_value_node(t_opts_type type, char *value_type, char *data)
{
	t_value	*new_value_node;

	new_value_node = (t_value *)gc_malloc(sizeof(t_value));
	new_value_node->type = type;
	if (ft_strnstr(value_type, "STRING", ft_strlen(value_type)))
	{
		if (handle_string_value(new_value_node, data) == -1)
			return (NULL);
	}
	else if (ft_strnstr(value_type, "FLOAT", ft_strlen(value_type)))
	{
		if (handle_float_value(new_value_node, data) == -1)
			return (NULL);
	}
	else if (ft_strnstr(value_type, "VECTOR", ft_strlen(value_type)))
	{
		if (handle_vector_value(new_value_node, data) == -1)
			return (NULL);
	}
	new_value_node->next = (NULL);
	return (new_value_node);
}

/**
 * Appends a new value node to the options->value structure.
 *
 * @param options The options structure to append the value node to.
 * @param new_value_node The new value node to append.
 */
void	append_value_node(t_options *options, t_value *new_value_node)
{
	t_value	*last;

	if (options->values == NULL)
	{
		options->values = new_value_node;
		return ;
	}
	last = options->values;
	while (last->next != NULL)
		last = last->next;
	last->next = new_value_node;
}
