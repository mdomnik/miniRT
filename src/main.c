/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:26:20 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/14 02:30:48 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

int	main(int ac, char *av[])
{
	t_loop	*loop;

	loop = loop_init();
	if (check_args(ac, av, loop->opts) == 1)
	{
		set_window(loop);
		key_hook(65307, loop);
		return (-1);
	}
	set_window(loop);
	render(loop);
	ft_dprintf(1, "\033[1;32mSuccessfully rendered '");
	ft_dprintf(1, "\033[1;37m%s\033[1;32m'\033[0m\n",
		loop->opts->scene.scene_file);
	mlx_key_hook(loop->win, key_hook, loop);
	mlx_hook(loop->win, 17, 0, close_window, loop);
	mlx_loop(loop->mlx);
	return (0);
}
