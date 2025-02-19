/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:24:02 by mdomnik           #+#    #+#             */
/*   Updated: 2024/10/16 03:16:07 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

/**
 * Omit whitespaces in a string starting from a given index.
 *
 * @param str The string to process.
 * @param i The starting index.
 * @return The index after omitting whitespaces.
 */
int	omit_whitespaces(char *str, int i)
{
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	return (i);
}

/**
 * @brief Free the memory allocated for a double pointer array.
 *
 * This function frees the memory allocated for a double pointer array
 * and all its elements.
 *
 * @param args The double pointer array to be freed.
 */
void	free_double(char **args)
{
	int	i;

	i = 0;
	while (args[i] != NULL)
	{
		free(args[i]);
		i++;
	}
	free(args);
}

/**
 * Counts the number of pointers in an array of strings.
 *
 * @param args The array of strings.
 * @return The number of pointers in the array.
 */
int	pointer_count(char **args)
{
	int	i;

	i = 0;
	while (args[i] != NULL)
		i++;
	return (i);
}

/**
 * @brief Prints an error message along with a string.
 *
 * This function prints an error message along with a
 * specified string to the standard error stream.
 *
 * @param message The error message to be printed.
 * @param str The string to be printed along with the error message.
 * @return Returns -1.
 */
int	ret_message(char *message, char *str)
{
	ft_dprintf(2, "%s '%s'\n", message, str);
	return (-1);
}

/**
 * @brief Duplicates a double pointer array of strings.
 *
 * This function duplicates a double pointer array of strings.
 *
 * @param src The double pointer array to be duplicated.
 * @return The duplicated double pointer array.
 */
char	**double_dup(char **src)
{
	char	**dst;
	int		i;

	i = 0;
	while (src[i])
		i++;
	dst = gc_malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (src[i])
	{
		dst[i] = ft_strdup(src[i]);
		i++;
	}
	dst[i] = NULL;
	return (dst);
}
