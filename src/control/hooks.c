/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:27:33 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/19 18:56:32 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

static void	quality_hooks(mlx_key_data_t keydata)
{
	if (keydata.key == MLX_KEY_1 && keydata.action == MLX_PRESS)
		quality(1, LOW);
	if (keydata.key == MLX_KEY_2 && keydata.action == MLX_PRESS)
		quality(1, MEDIUM);
}

static void	resolution_hooks(mlx_key_data_t keydata)
{
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
}

static void	sampling_hooks(mlx_key_data_t keydata)
{
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

void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_loop	*loop;

	loop = (t_loop *)param;
	movement_hooks(keydata, loop);
	state_hooks(keydata, loop);
	downscale_hooks(keydata, loop);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exit(0);
	quality_hooks(keydata);
	resolution_hooks(keydata);
	sampling_hooks(keydata);
}

void	scrollhook(double xdelta, double ydelta, void *param)
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
