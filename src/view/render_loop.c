/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:25:02 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/20 10:09:08 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

t_loop *loop_init(int ac, char *av[])
{
	t_loop *loop;

	loop = malloc(sizeof(t_loop));
	loop->mlx = mlx_init(800, 400, "test", 1);
	loop->world = malloc(sizeof(t_world));
	loop->world->shapes = NULL;
	loop->world->light = NULL;
	if (check_args(ac, av, loop->world))
		exit(42);
	// downscale_setting(1, SIXTEENTH);
	int e = quality(1, MEDIUM);
	(void)e;
	loop->camera = camera_new(800, 400, 0.8);
	loop->camera->transform = view_transformation(new_point3(0, 30, -50),
			new_point3(0, 0, 1), new_vec3(0, 1, 0));
	loop->camera_mode = CAMERA_MODE;
	loop->downscale = 0;
	return (loop);
}
mlx_image_t *render_tooltip(mlx_t *mlx, t_camera *camera)
{
	mlx_image_t	*image;
	int			x, y;

	image = mlx_new_image(mlx, camera->hsize, camera->vsize);
	y = 0;
	while (y < (camera->vsize / 3))
	{
		x = 0;
		while (x < (camera->hsize / 8))
		{
			mlx_put_pixel(image, x, y, 0x06397088);
			x++;
		}
		y++;
	}

	return (image);
}

mlx_image_t *render(mlx_t *mlx, t_camera *camera, t_world *world)
{
	mlx_image_t *image;
	t_ray *ray;
	t_comp *comp;
	t_color3 color;
	int color_int;
	int y = 0;
	int x = 0;


	image = mlx_new_image(mlx, camera->hsize, camera->vsize);
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
	while(y < camera->vsize)
	{
		x = 0;
		while(x < camera->hsize)
		{
			ray_for_pixel(camera, x, y, ray);
			memset(comp, 0, sizeof(t_comp));
			
			color = color_at(world, ray, comp, RECURSIVE_DEPTH);
			color_int = color_to_int(color);
			mlx_put_pixel(image, x, y, color_int);
			x++;
		}
		y++;
	}
	return(image);
}

void	render_loop(void *param)
{
	t_loop *loop;

	loop = (t_loop *)param;
	loop->image = render(loop->mlx, loop->camera, loop->world);
	// mlx_image_t *image_tooptip = render_tooltip(loop->mlx, loop->camera);
	mlx_image_to_window(loop->mlx, loop->image, 0, 0);
	// mlx_image_to_window(loop->mlx, image_tooptip, 5, 5);
}
