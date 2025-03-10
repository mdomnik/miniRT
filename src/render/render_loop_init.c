/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:45:51 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/26 19:01:09 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

bool	init_loop_img(t_loop *loop)
{
	loop->img = malloc(sizeof(t_image));
	if (!loop->img)
		return (false);
	loop->img->img = mlx_new_image(loop->mlx, DEFAULT_WIDTH, DEFAULT_HEIGHT);
	loop->img->buffer = mlx_get_data_addr(loop->img->img,
			&loop->img->bits_per_pixel,
			&loop->img->size_line,
			&loop->img->endian);
	loop->img->width = DEFAULT_WIDTH;
	loop->img->height = DEFAULT_HEIGHT;
	return (true);
}

bool	init_loop_opts(t_loop *loop)
{
	loop->opts = malloc(sizeof(t_options));
	if (!loop->opts)
		return (false);
	loop->opts->scene.scene_objects = NULL;
	loop->opts->scene.scene_file = NULL;
	loop->opts->values = malloc(sizeof(t_flags));
	loop->opts->values->filename = NULL;
	return (true);
}
