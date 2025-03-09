/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_values.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 22:39:24 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/09 18:29:45 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

/**
 * @brief Checks if a flag of type NULL hold no arguments.
 *
 * This function checks if the flag's argument is null. if its another flag
 * or its NULL, it returns 0. Otherwise, it returns 1.
 * The outer function will handle the error message.
 *
 * @param str The input string to be checked.
 * @return 0 if the string is null or is not a number
 * and has the (-) sign, 1 otherwise.
 */
int	handle_null_value(char *str)
{
	if (!str)
		return (0);
	if ((is_number(str) == 1) && str[0] == '-')
		return (0);
	return (1);
}

/**
 * @brief Handles the assignment of a string value to a t_value node.
 *
 * This function is responsible for assigning a string value
 * to the specified t_value node of type string. If the data is NULL,
 * the string value of the t_value node will be set to NULL. Otherwise,
 * it will first check the format of the string using the check_string_format
 * function. If the format check fails, the function will return -1. Otherwise,
 * the function will allocate memory for the string value using ft_strdup and 
 * return 0.
 * 
 * @param new_value_node Pointer to the t_value node to assign
 * the string value to.
 * @param data The string value to assign.
 * @return 0 on success, -1 if the format check fails.
 */
int	handle_string_value(t_flags *new_value_node, char *data)
{
	if (data == NULL)
	{
		new_value_node->value.string = NULL;
	}
	else
	{
		if (check_string_format(data) == -1)
			return (-1);
		else
			new_value_node->value.string= ft_strdup(data);
	}
	return (0);
}

/**
 * @brief Handles the assignment of a float value to a t_value node.
 *
 * This function is responsible for assigning a float value
 * to the specified t_value node of type float. If the data is NULL,
 * the float value of the t_value node will be set to 0. Otherwise,
 * it will first check the format of the float using the check_float_format
 * function. If the format check fails, the function will return -1. Otherwise,
 * the function will convert the string into a double and return 0.
 * 
 * @param new_value_node Pointer to the t_value node to assign
 * the float value to.
 * @param data The float value to assign.
 * @return 0 on success, -1 if the format check fails.
 */
int	handle_float_value(t_flags *new_value_node, char *data)
{
	if (data == NULL)
	{
		new_value_node->value.value = 0;
	}
	else
	{
		if (check_float_format(data) == -1)
			return (-1);
		else
			new_value_node->value.value = ft_atof(data);
	}
	return (0);
}

/**
 * @brief Handles the assignment of vector values to a t_value node.
 *
 * This function is responsible for assigning a values to vector components
 * (x,y,z) in a t_value node. If the data is NULL,
 * the vector values of the t_value node will be set to 0 by default. Otherwise,
 * it will first check the format of the data value using the check_vector_format
 * function. If the format check fails, the function will return -1. Otherwise,
 * the function will convert the string into a set of 3 doubles and return 0.
 * 
 * @param new_value_node Pointer to the t_value node to assign
 * the float value to.
 * @param data The float value to assign.
 * @return 0 on success, -1 if the format check fails.
 */
int	handle_vector_value(t_flags *new_value_node, char *data)
{
	char	**vector;
	int		i;

	i = 0;
	if (data == NULL)
		set_vector_values(new_value_node, NULL);
	else
	{
		if (check_vector_format(data) == -1)
			return (-1);
		else
		{
			vector = ft_split(data, ',');
			while (vector[i] != NULL)
				i++;
			if (i == 3)
				set_vector_values(new_value_node, vector);
			else
			{
				ft_dprintf(1, "%s\n", ERR_VEC_ARG);
				return (-1);
			}
		}
	}
	return (0);
}

/**
 * @brief sets the values of a vector in a given value node.
 * 
 * This function serves as a helper function to handle_vector_value.
 * It is responsible for setting the values of a vector in a given value node.
 *
 * @param new_value_node The value node to set the vector values in.
 * @param vector The vector values to set.
 */
void	set_vector_values(t_flags *new_value_node, char **vector)
{
	if (vector == NULL)
	{
		new_value_node->value.vector.x = 0;
		new_value_node->value.vector.y = 0;
		new_value_node->value.vector.z = 0;
	}
	else
	{
		new_value_node->value.vector.x = ft_atof(vector[0]);
		new_value_node->value.vector.y = ft_atof(vector[1]);
		new_value_node->value.vector.z = ft_atof(vector[2]);
	}
}
