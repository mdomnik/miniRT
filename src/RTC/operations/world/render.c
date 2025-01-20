/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 20:10:41 by mdomnik           #+#    #+#             */
/*   Updated: 2025/01/21 00:52:09 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

t_loop *loop_init(void)
{
	t_loop *loop;

	loop = malloc(sizeof(t_loop));
	loop->mlx = mlx_init(800, 400, "test", 1);
	loop->world = benchmark_2();
	// downscale_setting(1, SIXTEENTH);
	int e = quality(1, MEDIUM);
	(void)e;
	loop->camera = camera_new(800, 400, 0.8);
	loop->camera->transform = view_transformation(new_point3(0, 7, -7),
			new_point3(0, 0, 1), new_vec3(0, 1, 0));
	return (loop);
}


mlx_image_t	*render(mlx_t *mlx, t_camera *camera, t_world *world)
{
	mlx_image_t	*image;
	t_ray		*ray;
	t_color3	color;
	int			color_int;
	int			x;
	int			y;
	int			downscale;

	downscale = downscale_setting(0, 0); // Get the current downscale factor
	image = mlx_new_image(mlx, camera->hsize, camera->vsize);

	y = 0;
	while (y < camera->vsize)
	{
		x = 0;
		while (x < camera->hsize)
		{
			// Render every pixel based on the downscale factor
			if (x % downscale == 0 && y % downscale == 0)
			{
				ray = ray_for_pixel(camera, x, y);
				color = color_at(world, ray, quality(0, RECURSIVE_DEPTH));
				color_int = color_to_int(color);

				// Fill in the downscaled grid
				for (int dy = 0; dy < downscale; dy++)
				{
					for (int dx = 0; dx < downscale; dx++)
					{
						if ((x + dx) < camera->hsize && (y + dy) < camera->vsize)
							mlx_put_pixel(image, x + dx, y + dy, color_int);
					}
				}
			}
			x += downscale;
		}
		y += downscale;
	}
	return (image);
}



void	render_loop(void *param)
{
	t_loop *loop;

	loop = (t_loop *)param;
	loop->image = render(loop->mlx, loop->camera, loop->world);
	mlx_image_to_window(loop->mlx, loop->image, 0, 0);
}
