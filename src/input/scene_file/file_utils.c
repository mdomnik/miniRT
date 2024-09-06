/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:24:02 by mdomnik           #+#    #+#             */
/*   Updated: 2024/09/06 17:51:40 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

int omit_whitespaces(char *str, int i)
{
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	return (i);
}

void free_double(char **args)
{
	int i;

	i = 0;
	while (args[i] != NULL)
	{
		free(args[i]);
		i++;
	}
	free(args);
}

int pointer_count(char **args)
{
	int i;

	i = 0;
	while (args[i] != NULL)
		i++;
	return (i);
}

int ret_message(char *message, char *str)
{
	ft_dprintf(2, "%s '%s'\n", message, str);
	return (-1);
}

t_light *append_to_list(t_light *list, t_light *new)
{
	t_light *current;

	if (list == NULL)
		return (new);
	current = list;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
	return (list);
}
