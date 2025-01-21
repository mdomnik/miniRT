/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:27:33 by mdomnik           #+#    #+#             */
/*   Updated: 2025/01/21 18:05:08 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

static void	movement_hooks(mlx_key_data_t keydata, t_loop *loop);

void my_keyhook(mlx_key_data_t keydata, void* param)
{
	t_loop	*loop;

	loop = (t_loop *)param;
	

	movement_hooks(keydata, loop);
	if (keydata.key == MLX_KEY_SPACE && keydata.action == MLX_PRESS)
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
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exit(0);
	if (keydata.key == MLX_KEY_1 && keydata.action == MLX_PRESS)
		quality(1, LOW);
	if (keydata.key == MLX_KEY_2 && keydata.action == MLX_PRESS)
		quality(1, MEDIUM);
	if (keydata.key == MLX_KEY_I && keydata.action == MLX_PRESS)
		downscale_setting(1, FULL);
	if (keydata.key == MLX_KEY_O && keydata.action == MLX_PRESS)
		downscale_setting(1, HALF);
	if (keydata.key == MLX_KEY_P && keydata.action == MLX_PRESS)
		downscale_setting(1, QUARTER);
	if (keydata.key == MLX_KEY_L && keydata.action == MLX_PRESS)
		downscale_setting(1, EIGHTH);
	if (keydata.key == MLX_KEY_K && keydata.action == MLX_PRESS)
		downscale_setting(1, SIXTEENTH);
	if (keydata.key == MLX_KEY_V && keydata.action == MLX_PRESS)
		supersampling_setting(1, SS_OFF);
	if (keydata.key == MLX_KEY_B && keydata.action == MLX_PRESS)
		supersampling_setting(1, SS_2X);
	if (keydata.key == MLX_KEY_N && keydata.action == MLX_PRESS)
		supersampling_setting(1, SS_4X);
	if (keydata.key == MLX_KEY_M && keydata.action == MLX_PRESS)
		supersampling_setting(1, SS_8X);
	if (keydata.key == MLX_KEY_COMMA && keydata.action == MLX_PRESS)
		supersampling_setting(1, SS_16X);
	
}

void my_scrollhook(double xdelta, double ydelta, void* param)
{
	t_camera	*camera;

	camera = ((t_loop *)param)->camera;
	if (ydelta > 0)
	{
		camera->fov += 0.01;
		get_pixel_size(camera);
	}
	else if (ydelta < 0)
	{
		camera->fov -= 0.01;
		get_pixel_size(camera);
	}
	(void)xdelta;
}

void	rotate_camera_up(t_loop *loop, int direction)
{
	t_matrix	*rotation;
	t_matrix	*product;

	if (direction == 1)
		rotation = rotation_x(0.1);
	else if (direction == 2)
		rotation = rotation_x(-0.1);
	else if (direction == 3)
		rotation = rotation_y(0.1);
	else if (direction == 4)
		rotation = rotation_y(-0.1);
	else if (direction == 5)
		rotation = rotation_z(0.1);
	else
		rotation = rotation_z(-0.1);
	product = multiply_matrices(&loop->camera->transform, rotation);
	loop->camera->transform = *product;	
}
void my_cursorhook(double xpos, double ypos, void* param)
{
	t_loop	*loop;

	loop = (t_loop *)param;
	static int xpos_old = 0;
	static int ypos_old = 0;
	if (xpos_old > xpos)
	{
		rotate_camera_up(loop, 3);
		xpos_old = xpos;
	}
	else if (xpos_old < xpos)
	{
		rotate_camera_up(loop, 4);
		xpos_old = xpos;
	}
	// if (ypos_old > ypos)
	// {
	// 	rotate_camera_up(loop, 1);
	// 		ypos_old = ypos;
	// }
	// else if (ypos_old < ypos)
	// {
	// 	rotate_camera_up(loop, 2);
	// 		ypos_old = ypos;
	// }
	(void)ypos;
	(void)ypos_old;
}

void my_mousehook(mouse_key_t button, action_t action, modifier_key_t mods, void* param)
{
	t_loop	*loop;

	loop = (t_loop *)param;
	if (button == MLX_MOUSE_BUTTON_LEFT && (action == MLX_REPEAT || action == MLX_PRESS))
	{
		mlx_set_mouse_pos(loop->mlx, loop->camera->hsize / 2, loop->camera->vsize / 2);
	}
	// (void)button;
	// (void)action;
	(void)mods;
	(void)param;
}
static void	movement_hooks(mlx_key_data_t keydata, t_loop *loop)
{
	if (keydata.key == MLX_KEY_D && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		loop->camera->transform.a[0][3] += 0.1;
	if (keydata.key == MLX_KEY_A && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		loop->camera->transform.a[0][3] -= 0.1;
	if (keydata.key == MLX_KEY_S && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		loop->camera->transform.a[2][3] -= 0.1;
	if (keydata.key == MLX_KEY_W && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		loop->camera->transform.a[2][3] += 0.1;
}

