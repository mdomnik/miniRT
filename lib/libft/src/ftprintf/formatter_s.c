/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatter_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:15:18 by astavrop          #+#    #+#             */
/*   Updated: 2024/08/19 17:22:49 by astavrop         ###   ########.fr       */
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
