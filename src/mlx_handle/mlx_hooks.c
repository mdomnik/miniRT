/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:52:13 by mdomnik           #+#    #+#             */
/*   Updated: 2024/09/10 19:13:22 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

void closing_hook(mlx_key_data_t keydata, void *param)
{
	t_render *render;
	
	render = (t_render *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_close_window(render->window);
		exit(0);
	}
}

void movement_hook_press(mlx_key_data_t keydata, void *param)
{
	t_render *render;

	render = (t_render *)param;

	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		render->options->objects.camera->coords.z += 1;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		render->options->objects.camera->coords.z -= 1;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		render->options->objects.camera->coords.x -= 1;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		render->options->objects.camera->coords.x += 1;

	// Print the camera coordinates using the full path
	printf("x: %f, y: %f, z: %f\n",
		   render->options->objects.camera->coords.x,
		   render->options->objects.camera->coords.y,
		   render->options->objects.camera->coords.z);
}

void movement_hook_hold(mlx_key_data_t keydata, void *param)
{
	t_render *render;

	render = (t_render *)param;

	if (keydata.key == MLX_KEY_W && keydata.action == MLX_REPEAT)
		render->options->objects.camera->coords.z += 1;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_REPEAT)
		render->options->objects.camera->coords.z -= 1;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_REPEAT)
		render->options->objects.camera->coords.x -= 1;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_REPEAT)
		render->options->objects.camera->coords.x += 1;
		// Print the camera coordinates using the full path
	printf("x: %f, y: %f, z: %f\n",
		   render->options->objects.camera->coords.x,
		   render->options->objects.camera->coords.y,
		   render->options->objects.camera->coords.z);
}

