/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:29:46 by astavrop          #+#    #+#             */
/*   Updated: 2024/08/19 17:23:29 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strrchr(const char *str, char c)
{
	char	*s;

	s = NULL;
	while (*str)
	{
		if (*str == c)
			s = (char *) str;
		str++;
	}
	if (*str == c)
		s = (char *) str;
	return (s);
}
