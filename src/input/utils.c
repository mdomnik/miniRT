/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 20:55:12 by mdomnik           #+#    #+#             */
/*   Updated: 2024/08/22 20:56:06 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

char **double_dup(char **src)
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