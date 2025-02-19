/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   downscale.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 19:54:46 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/19 18:56:24 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

int	downscale_setting(int set, int quality)
{
	static int downscale = 0;
	if (set)
	{
		downscale = quality;
		return (downscale);
	}
	if (downscale == FULL)
		return (1);
	if (downscale == HALF)
		return (2);
	if (downscale == QUARTER)
		return (4);
	if (downscale == EIGHTH)
		return (8);
	if (downscale == SIXTEENTH)
		return (16);
	return (-1);
}

mlx_image_t	*render_downscale(mlx_t *mlx, t_camera *camera, t_world *world)
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
