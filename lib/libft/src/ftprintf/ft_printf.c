/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:45:26 by astavrop          #+#    #+#             */
/*   Updated: 2024/10/16 03:15:31 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include <stdarg.h>
#include <stdlib.h>

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	arg;
	int		done;

	if (!format)
		return (-1);
	if (*format == '\0')
		return (0);
	va_start (arg, format);
	done = print(fd, format, arg);
	va_end (arg);
	return (done);
}
