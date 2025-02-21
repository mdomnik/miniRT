/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:26:20 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/21 16:41:10 by mdomnik          ###   ########.fr       */
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
	if (world->camera)
		free(world->camera);
	free(world);
}
int	main(int ac, char *av[])
{
	// t_loop	*loop;

	// loop = loop_init(ac, av);
	t_world *world = malloc(sizeof(t_world));
	world->shapes = NULL;
	world->light = NULL;
	world->camera = NULL;
	if (check_args(ac, av, world) == 1)
		printf("World alloc failed\n");
	free_world(world);
	// downscale_setting(1, loop->downscale);
	// mlx_key_hook(loop->mlx, &my_keyhook, loop);
	// mlx_scroll_hook(loop->mlx, &my_scrollhook, loop);
	// mlx_mouse_hook(loop->mlx, &my_mousehook, loop);
	// mlx_loop_hook(loop->mlx, render_loop, loop);
	// loop->image = render(loop->mlx, loop->camera, loop->world);
	// mlx_image_to_window(loop->mlx, loop->image, 0, 0);
	// mlx_loop(loop->mlx);
	return (0);
}
