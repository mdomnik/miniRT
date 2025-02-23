/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:26:20 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/23 18:35:20 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

void free_world(t_world *world)
{
	t_shape *shape;
	t_light_p *light;

	while (world->shapes)
	{
		shape = world->shapes;
		world->shapes = world->shapes->next;
		free(shape);
	}
	while (world->light)
	{
		light = world->light;
		world->light = world->light->next;
		free(light);
	}
	free(world);
}

void free_loop(t_loop *loop)
{
	free_world(loop->world);
	free(loop);
}

int	key_hook(int keycode, void *param)
{
	t_loop *loop = (t_loop *)param;
	if (keycode == 65307)
	{
		mlx_destroy_window(loop->mlx, loop->win);
		if (loop->mlx)
		{
			mlx_destroy_display(loop->mlx);
			free(loop->mlx);
		}
		free_loop(loop);
		exit(0);
	}
	return (0);
}

int	main(int ac, char *av[])
{
	t_loop	*loop;

	loop = loop_init(ac, av);
	render(loop);
	mlx_key_hook(loop->win, key_hook, &loop);
	mlx_loop(loop->mlx);
	// loop->image = render(loop->mlx, loop->camera, loop->world);
	// free_loop(loop);
	// downscale_setting(1, loop->downscale);
	// mlx_key_hook(mlx, &test_keyhook, mlx);
	// mlx_scroll_hook(loop->mlx, &my_scrollhook, loop);
	// mlx_mouse_hook(loop->mlx, &my_mousehook, loop);
	// mlx_loop_hook(loop->mlx, render_loop, loop);
	// mlx_image_to_window(loop->mlx, loop->image, 0, 0);
	return (0);
}
