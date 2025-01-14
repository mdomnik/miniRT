/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatter_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:15:18 by astavrop          #+#    #+#             */
/*   Updated: 2024/10/16 03:20:37 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	s_null(int fd)
{
	ft_putstr_fd("(null)", fd);
	return (6);
}

int	formatter_s(char *s, int count, int fd)
{
	if (!s)
		return (s_null(fd));
	ft_putstr_fd(s, fd);
	return (count + ft_strlen(s));
}
