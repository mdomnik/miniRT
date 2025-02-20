/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:26:20 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/19 20:15:44 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

int	main(int ac, char *av[])
{
	t_loop	*loop;

	loop = loop_init(ac, av);
	// downscale_setting(1, loop->downscale);
	// mlx_key_hook(loop->mlx, &my_keyhook, loop);
	// mlx_scroll_hook(loop->mlx, &my_scrollhook, loop);
	// mlx_mouse_hook(loop->mlx, &my_mousehook, loop);
	mlx_loop_hook(loop->mlx, render_loop, loop);
	mlx_loop(loop->mlx);
	return (0);
}
