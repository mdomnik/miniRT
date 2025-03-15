/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_step_pixel.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 09:50:32 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/15 09:52:10 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

void	process_pixel(t_world *world, t_render_data *data, t_pixel *px,
	t_loop *loop)
{
	px->color = 0;
	if (loop->opts->opts_flags & OPT_ANTIALIAS)
	{
		if (loop->opts->values->aa_samples > 1)
			process_pixel_aa(world, px, loop->opts->values->aa_samples);
	}
	else
		process_pixel_color(world, data->ray, data->comp, px);
}

void	process_step_pixels(t_render_data *data, t_world *world, int step,
	t_loop *loop)
{
	t_pixel	px;
	int		i;
	int		index;

	i = 0;
	while (i < data->total_pixels)
	{
		index = data->pixel_order[i];
		px.x = index % data->width;
		px.y = index / data->width;
		if ((fmodf(px.x, step) == 0.0f) && (fmodf(px.y, step) == 0.0f)
			&& !data->cmped_buf[(int)px.y][(int)px.x])
		{
			process_pixel(world, data, &px, loop);
			data->cmped_buf[(int)px.y][(int)px.x] = true;
			put_pixel_to_img(data->img, (int)px.x, (int)px.y, px.color);
		}
		if (i % 500 == 0)
			mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
		i++;
	}
}
