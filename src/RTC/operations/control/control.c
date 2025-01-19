/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:05:21 by mdomnik           #+#    #+#             */
/*   Updated: 2025/01/19 18:16:24 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

int	quality(bool set, int variable)
{
	static int quality = LOW;

	if (set)
	{
		quality = variable;
		return (quality);
	}
	if (variable == RECURSIVE_DEPTH)
	{
		if (quality == LOW)
			return (0);
		if (quality == MEDIUM)
			return (3);
		if (quality == HIGH)
			return (5);
		if (quality == MAX)
			return (10);
	}
	return (quality);
}
