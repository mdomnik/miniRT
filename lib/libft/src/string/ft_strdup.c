/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:33:36 by astavrop          #+#    #+#             */
/*   Updated: 2024/08/19 17:23:25 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*new_s;
	int		s_len;
	int		i;

	s_len = ft_strlen((char *) s) + 1;
	new_s = gc_malloc(s_len * sizeof(char));
	if (new_s != NULL)
	{
		i = 0;
		while (s[i] != '\0')
		{
			new_s[i] = s[i];
			i++;
		}
		new_s[i] = '\0';
		return (new_s);
	}
	return (NULL);
}
