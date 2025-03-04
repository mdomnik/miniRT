/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:05:21 by mdomnik           #+#    #+#             */
/*   Updated: 2025/01/21 17:36:38 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

int	program_state(bool set, int variable)
{
	static int	state = CAMERA_MODE;

	if (set)
	{
		state = variable;
		return (state);
	}
	if (state == CAMERA_MODE)
		return (CAMERA_MODE);
	if (state == EDIT_MODE)
		return (EDIT_MODE);
	return (RENDER_MODE);
}

int	tooltip_state(bool set, int variable)
{
	static int	state = TOOLTIP_OFF;

	if (set)
	{
		state = variable;
		return (state);
	}
	return (state);
}

int	quality(bool set, int variable)
{
	static int	quality = LOW;
	static int	recursive_depth[4] = {
	[LOW] = 0,
	[MEDIUM] = 3,
	[HIGH] = 5,
	[MAX] = 10
	};
	static int	lighting[4] = {
	[LOW] = 0,
	[MEDIUM] = 1,
	[HIGH] = 1,
	[MAX] = 1
	};

	if (set)
		return (quality = variable);
	if (variable == RECURSIVE_DEPTH)
		return (recursive_depth[quality]);
	if (variable == LIGHTING)
		return (lighting[quality]);
	return (quality);
}

int	render_max(bool set, int variable)
{
	static int	max = 0;

	if (set)
	{
		max = variable;
		return (max);
	}
	return (max);
}
