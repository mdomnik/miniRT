/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_rand.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:02:30 by astavrop          #+#    #+#             */
/*   Updated: 2025/03/11 18:18:48 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

int	ft_srand(int seed)
{
	static int	state = 0;

	if (seed != 0)
		state = state + (state / seed);
	return (state++);
}

int	ft_rand(void)
{
	int	state;

	state = ft_srand(42);
	state = state * 1664525 + 1013904223;
	if (state < 0)
		return ((-state) >> 24);
	return (state >> 24);
}
