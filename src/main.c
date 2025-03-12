/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:26:20 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/12 16:43:46 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

int	key_hook(int keycode, void *param)
{
	t_loop	*loop;

	loop = (t_loop *)param;
	if (!loop)
		return (-1);
	if (keycode == 65307 || keycode == 17)
	{
		mlx_destroy_image(loop->mlx, loop->img->img);
		if (loop->img)
			free(loop->img);
		mlx_destroy_window(loop->mlx, loop->win);
		if (loop->mlx)
		{
			mlx_destroy_display(loop->mlx);
			free(loop->mlx);
		}
		if (loop)
			free(loop);
		exit(0);
	}
	return (0);
}

int	close_window(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int	main(int ac, char *av[])
{
	t_loop	*loop;

	loop = loop_init();
	if (check_args(ac, av, loop->opts) == 1)
		return (key_hook(65307, loop), -1);
	render(loop);
	ft_dprintf(1, "\033[1;33mSuccessfully rendered '\033[1;37m%s\033[1;33m'\033[0m\n", loop->opts->scene.scene_file);
	free_triple_ptr(loop->opts->scene.scene_objects);
	free(loop->opts->values);
	free(loop->opts->scene.scene_file);
	free(loop->opts);
	mlx_hook(loop->win, 17, 1L << 17, key_hook, loop);
	mlx_key_hook(loop->win, key_hook, loop);
	mlx_hook(loop->win, 17, 1L<<17, close_window, NULL);
	mlx_loop(loop->mlx);
	return (0);
}
