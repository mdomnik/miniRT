/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatter_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:15:18 by astavrop          #+#    #+#             */
/*   Updated: 2024/08/19 17:22:48 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	numlen(long int n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	if (n < 0)
		n = -n;
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

int	formatter_di(int n, int count, int fd)
{
	int	len;

	len = numlen((long int) n);
	if (n < 0)
		len++;
	ft_putnbr_fd(n, fd);
	return (count + len);
}
