/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:02:26 by mdomnik           #+#    #+#             */
/*   Updated: 2024/09/10 19:15:18 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

int start_mlx(t_render *render)
{
	render->window = mlx_init(960, 540, "TriCycles", true);
	mlx_key_hook(render->window, &closing_hook, render);
	mlx_key_hook(render->window, &movement_hook_press, render);
	mlx_key_hook(render->window, &movement_hook_hold, render);
	
	return(0);
}


