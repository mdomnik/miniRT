/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:02:26 by mdomnik           #+#    #+#             */
/*   Updated: 2024/09/19 20:48:43 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

int start_mlx(t_render *render)
{
	int32_t width = 0;
	int32_t height = 0;

	mlx_get_monitor_size(0, &width, &height);
	if (width == 0 || height == 0)
	{
		width = VP_WIDTH;
		height = VP_HEIGHT;
	}
	render->window = mlx_init(width, height, "TriCycles", true);
	render->vp_img = mlx_new_image(render->window, width, height);
	if (display_image(render) == 1)
		return (1);
	mlx_key_hook(render->window, &closing_hook, render);

	
	return(0);
}


