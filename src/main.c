/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:26:20 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/13 14:31:30 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

void set_window(t_loop *loop)
{
	char *title;

	if (loop->opts->scene.scene_file == NULL)
		loop->win = mlx_new_window(loop->mlx, DEFAULT_WIDTH, DEFAULT_HEIGHT, "Error");
	else
	{
		title = ft_strjoin("MiniRT | Rendering - ", loop->opts->scene.scene_file);
		loop->win = mlx_new_window(loop->mlx, DEFAULT_WIDTH, DEFAULT_HEIGHT, title);
		free(title);
	}
	if (!loop->win)
		free(loop);
}
void clean_dependencies(t_loop *loop)
{
	if (!loop->win)
		set_window(loop);
	if (loop->opts)
	{
		if (loop->opts->values)
		{
			if (loop->opts->values->filename)
			{
				free(loop->opts->values->filename);
				loop->opts->values->filename = NULL;
			}
			free(loop->opts->values);
			loop->opts->values = NULL;
		}
		if (loop->opts->scene.scene_file)
		{
			free(loop->opts->scene.scene_file);
			loop->opts->scene.scene_file = NULL;
		}
		if (loop->opts->scene.scene_objects)
		{
			free_triple_ptr(loop->opts->scene.scene_objects);
			loop->opts->scene.scene_objects = NULL;
		}
		free(loop->opts);
		loop->opts = NULL;
	}
	if (loop->img)
	{
		mlx_destroy_image(loop->mlx, loop->img->img);
		free(loop->img);
		loop->img = NULL;
	}
	if (loop->mlx)
	{
		if (loop->win)
			mlx_destroy_window(loop->mlx, loop->win);
		mlx_destroy_display(loop->mlx);
		free(loop->mlx);
		loop->mlx = NULL;
	}
	free(loop);
}

int	key_hook(int keycode, void *param)
{
	t_loop	*loop;

	loop = (t_loop *)param;
	if (!loop)
		return (-1);
	if (keycode == 65307 || keycode == 17)
	{
		clean_dependencies(loop);
		exit(0);
	}
	return (0);
}
int	close_window(void *param)
{
	t_loop *loop;

	loop = (t_loop *)param;
	if (!loop)
		return (-1);
	clean_dependencies(loop);
	exit(0);
}

int	main(int ac, char *av[])
{
	t_loop	*loop;

	loop = loop_init();
	if (check_args(ac, av, loop->opts) == 1)
	{
		key_hook(65307, loop);
		return (-1);
	}
	set_window(loop);
	render(loop);
	ft_dprintf(1, "\033[1;32mSuccessfully rendered '\033[1;37m%s\033[1;32m'\033[0m\n", loop->opts->scene.scene_file);
	mlx_key_hook(loop->win, key_hook, loop);
	mlx_hook(loop->win, 17, 0, close_window, loop);
	mlx_loop(loop->mlx);
	return (0);
}
