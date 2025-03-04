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

#define DS_X 0
#define DS_Y 1
#define DS_DX 2
#define DS_DY 3
#define DS_SCALE 4
#define DS_COLOR 5

int	downscale_setting(int set, int quality)
{
	static int	downscale = 0;

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

static void	fill_downscale_grid(mlx_image_t *image, int v[6],
		t_camera *camera)
{
	v[DS_DY] = 0;
	while (v[DS_DY] < v[DS_SCALE])
	{
		v[DS_DX] = 0;
		while (v[DS_DX] < v[DS_SCALE])
		{
			if ((v[DS_X] + v[DS_DX]) < camera->hsize
				&& (v[DS_Y] + v[DS_DY]) < camera->vsize)
				put_pixel_to_img(image, v[DS_X] + v[DS_DX],
					v[DS_Y] + v[DS_DY], v[DS_COLOR]);
			v[DS_DX]++;
		}
		v[DS_DY]++;
	}
}

mlx_image_t	*render_downscale(mlx_t *mlx, t_camera *camera, t_world *world)
{
	mlx_image_t	*image;
	t_ray		*ray;
	t_color3	color;
	int			v[6];

	v[DS_SCALE] = downscale_setting(0, 0);
	image = mlx_new_image(mlx, camera->hsize, camera->vsize);
	v[DS_Y] = 0;
	while (v[DS_Y] < camera->vsize)
	{
		v[DS_X] = 0;
		while (v[DS_X] < camera->hsize)
		{
			if (v[DS_X] % v[DS_SCALE] == 0 && v[DS_Y] % v[DS_SCALE] == 0)
			{
				ray_for_pixel(camera, v[DS_X], v[DS_Y], ray);
				color = color_at(world, ray, quality(0, RECURSIVE_DEPTH), 0);
				v[DS_COLOR] = color_to_int(color);
				fill_downscale_grid(image, v, camera);
			}
			v[DS_X] += v[DS_SCALE];
		}
		v[DS_Y] += v[DS_SCALE];
	}
	return (image);
}
