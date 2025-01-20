/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   downscale.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 19:54:46 by mdomnik           #+#    #+#             */
/*   Updated: 2025/01/20 20:12:09 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

int	downscale_setting(int set, int quality)
{
	static int downscale = 1;
	if (set)
	{
		downscale = quality;
		return (downscale);
	}
	if (downscale == FULL)
		return (1);
	if (downscale == HALF)
		return (2);
	if (downscale == QUARTER)
		return (4);
	if (downscale == EIGHTH)
		return (8);
	if (downscale == SIXTEENTH)
		return (16);
	return (-1);
}


