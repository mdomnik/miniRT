/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:26:20 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/25 15:42:38 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

int	key_hook(int keycode, void *param)
{
	t_loop *loop = (t_loop *)param;
	if (!loop)
		return (-1);
	if (keycode == 65307)
	{
		mlx_destroy_window(loop->mlx, loop->win);
		if (loop->mlx)
		{
			mlx_destroy_display(loop->mlx);
			free(loop->mlx);
		}
		gc_free_gc(-1);
		exit(0);
	}
	return (0);
}

int main(int ac, char *av[])
{
	t_loop *loop = loop_init();
	if (check_args(ac, av, loop->opts) == 1)
		return (-1);
	render(loop, ac, av);
	mlx_key_hook(loop->win, key_hook, loop);
	mlx_loop(loop->mlx);
	return 0;
}
