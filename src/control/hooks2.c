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

void	cursorhook(double xpos, double ypos, void *param)
{
	static int	xpos_old = 0;
	static int	ypos_old = 0;
	t_loop		*loop;

	loop = (t_loop *)param;
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
	(void)ypos;
	(void)ypos_old;
}

void	mousehook(mouse_key_t button, action_t action,
		modifier_key_t mods, void *param)
{
	t_loop	*loop;

	loop = (t_loop *)param;
	if (button == MLX_MOUSE_BUTTON_LEFT
		&& (action == MLX_REPEAT || action == MLX_PRESS))
	{
		mlx_set_mouse_pos(loop->mlx,
			loop->camera->hsize / 2, loop->camera->vsize / 2);
	}
	(void)mods;
	(void)param;
}
