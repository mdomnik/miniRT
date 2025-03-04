/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 21:31:32 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/19 18:56:28 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

void	movement_hooks(mlx_key_data_t keydata, t_loop *loop)
{
	if (keydata.key == MLX_KEY_D && (keydata.action == MLX_REPEAT
			|| keydata.action == MLX_PRESS))
		loop->camera->transform.a[0][3] += 1;
	if (keydata.key == MLX_KEY_A && (keydata.action == MLX_REPEAT
			|| keydata.action == MLX_PRESS))
		loop->camera->transform.a[0][3] -= 1;
	if (keydata.key == MLX_KEY_S && (keydata.action == MLX_REPEAT
			|| keydata.action == MLX_PRESS))
		loop->camera->transform.a[2][3] -= 1;
	if (keydata.key == MLX_KEY_W && (keydata.action == MLX_REPEAT
			|| keydata.action == MLX_PRESS))
		loop->camera->transform.a[2][3] += 1;
	if (keydata.key == MLX_KEY_SPACE && (keydata.action == MLX_REPEAT
			|| keydata.action == MLX_PRESS))
		loop->camera->transform.a[1][3] -= 1;
	if (keydata.key == MLX_KEY_LEFT_SHIFT && (keydata.action == MLX_REPEAT
			|| keydata.action == MLX_PRESS))
		loop->camera->transform.a[1][3] += 1;
}

// void	camera_movement_hooks(mlx_key_data_t keydata, t_loop *loop)
// {
	// t_camera *camera;
	// float r;

	// camera = loop->camera;
	// r = 1;
	// if (keydata.key == MLX_KEY_UP && (keydata.action == MLX_REPEAT
	// 		|| keydata.action == MLX_PRESS))
	// {
	// 	camera_multiply_transform(camera, rotation_x(r));
	// }
	// if (keydata.key == MLX_KEY_DOWN && (keydata.action == MLX_REPEAT
			// || keydata.action == MLX_PRESS))
	// {
		// camera_multiply_transform(camera, rotation_x(r));
	// }
// }

void	state_hooks(mlx_key_data_t keydata, t_loop *loop)
{
	if (keydata.key == MLX_KEY_ENTER && keydata.action == MLX_PRESS)
	{
		program_state(1, RENDER_MODE);
		loop->camera_mode = RENDER_MODE;
	}
	if (keydata.key == MLX_KEY_Q && keydata.action == MLX_PRESS)
	{
		program_state(1, CAMERA_MODE);
		loop->camera_mode = CAMERA_MODE;
	}
	if (keydata.key == MLX_KEY_TAB && keydata.action == MLX_PRESS)
	{
		if (loop->camera_mode == CAMERA_MODE)
		{
			program_state(1, EDIT_MODE);
			loop->camera_mode = EDIT_MODE;
		}
		else if (loop->camera_mode == EDIT_MODE)
		{
			loop->camera_mode = CAMERA_MODE;
			program_state(1, CAMERA_MODE);
		}
	}
}

void	downscale_hooks(mlx_key_data_t keydata, t_loop *loop)
{
	if (keydata.key == MLX_KEY_EQUAL && keydata.action == MLX_PRESS)
	{
		if (loop->downscale < 4)
		{
			loop->downscale++;
			downscale_setting(1, loop->downscale);
		}
	}
	else if (keydata.key == MLX_KEY_MINUS && keydata.action == MLX_PRESS)
	{
		if (loop->downscale >= 1)
		{
			loop->downscale--;
			downscale_setting(1, loop->downscale);
		}
	}
}
