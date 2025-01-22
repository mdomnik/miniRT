/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 20:10:41 by mdomnik           #+#    #+#             */
/*   Updated: 2025/01/21 22:31:52 by mdomnik          ###   ########.fr       */
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


void	render_loop(void *param)
{
	t_loop *loop;

	loop = (t_loop *)param;
	if (program_state(0, 0) == EDIT_MODE)
	{
		mlx_set_window_title(loop->mlx, "EDIT MODE");
	}
	else if (program_state(0, 0) == CAMERA_MODE)
	{
		mlx_set_window_title(loop->mlx, "CAMERA MODE");
	}
	else
	{
		mlx_set_window_title(loop->mlx, "RENDER MODE");
	}
	if (render_max(0, 0) == 0)
		loop->image = render_downscale(loop->mlx, loop->camera, loop->world);
	else
		loop->image = render_supersampling(loop->mlx, loop->camera, loop->world);
	// mlx_image_t *image_tooptip = render_tooltip(loop->mlx, loop->camera);
	mlx_image_to_window(loop->mlx, loop->image, 0, 0);
	// mlx_image_to_window(loop->mlx, image_tooptip, 5, 5);
}
