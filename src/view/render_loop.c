/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:25:02 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/22 01:08:01 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

t_loop *loop_init(int ac, char *av[])
{
	t_loop *loop;

	loop = malloc(sizeof(t_loop));
	loop->mlx = mlx_init();
	loop->win = mlx_new_window(loop->mlx, 800, 400, "test");
	loop->world = malloc(sizeof(t_world));
	loop->world->shapes = NULL;
	loop->world->light = NULL;
	loop->world->camera = NULL;
	if (check_args(ac, av, loop->world))
		exit(42);
	loop->camera = camera_new(800, 400, 0.8);
	loop->camera->transform = view_transformation(new_point3(0, 30, -50),
			new_point3(0, 0, 1), new_vec3(0, 1, 0));
	return (loop);
}

void	render(t_loop *loop)
{
	t_ray *ray;
	t_comp *comp;
	t_color3 color;
	int color_int;
	int y = 0;
	int x = 0;

	ray = malloc(sizeof(t_ray));
	if (!ray)
	{
		fprintf(stderr, "Memory allocation failed for ray\n");
		exit(EXIT_FAILURE);
	}
	comp = malloc(sizeof(t_comp));
	if (!comp)
	{
		fprintf(stderr, "Memory allocation failed for comp\n");
		exit(EXIT_FAILURE);
	}
	while(y < loop->camera->vsize)
	{
		x = 0;
		while(x < loop->camera->hsize)
		{
			ray_for_pixel(loop->camera, x, y, ray);
			memset(comp, 0, sizeof(t_comp));
			color = color_at(loop->world, ray, comp, RECURSIVE_DEPTH); //should be recursive_depth
			color_int = color_to_int(color);
			mlx_pixel_put(loop->mlx, loop->win, x, y, color_int);
			x++;
		}
		y++;
	}
}
