/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 18:43:25 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/25 15:41:20 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

void	*error_handler(char *error_msg, FILE *file)
{
	ft_dprintf(2, "Error: %s\n", error_msg);
	if (file)
		fclose(file);
	return (NULL);
}

int	error_handler_int(char *error_msg, FILE *file)
{
	ft_dprintf(2, "Error: %s\n", error_msg);
	if (file)
		fclose(file);
	return (-1);
}