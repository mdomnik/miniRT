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

int program_state(bool set, int variable)
{
	static int state = CAMERA_MODE;

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

int tooltip_state(bool set, int variable)
{
	static int state = TOOLTIP_OFF;

	if (set)
	{
		state = variable;
		return (state);
	}
	if (state == TOOLTIP_OFF)
		return (TOOLTIP_OFF);
	if (state == TOOLTIP_ON)
		return (TOOLTIP_ON);
	return (TOOLTIP_OFF);
}



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
	if (variable == LIGHTING)
	{
		if (quality == LOW)
			return (0);
		if (quality == MEDIUM)
			return (1);
		if (quality == HIGH)
			return (1);
		if (quality == MAX)
			return (1);
	}
	return (quality);
}

int	render_max(bool set, int variable)
{
	static int max = 0;

	if (set)
	{
		max = variable;
		return (max);
	}
	return (max);
}
