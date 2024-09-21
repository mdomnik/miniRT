/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:16:46 by mdomnik           #+#    #+#             */
/*   Updated: 2024/09/21 21:41:12 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

int	transform_color(t_color *color)
{
	return (color->r << 24 | color->g << 16 | color->b << 8 | 255);
}

int render(t_render *rnd, t_camera *camera)
{
	int		x;
	int 	y;
	t_color pcolor;
	t_ray	pray;
	
	y = 0;
	while(y < rnd->window->height)
	{
		x = 0;
		while(x < rnd->window->width)
		{
			pray = ray_to_pixel(camera, x, y);
			pcolor = ray_color(&pray, rnd);
			mlx_put_pixel(rnd->vp_img, x, y, transform_color(&pcolor));
			x++;
		}
		y++;
	}
	mlx_image_to_window(rnd->window, rnd->vp_img, 0, 0);
	return (0);
}

//NOISE TEST
/* int display_image(t_render *render)
{
	for (uint32_t x = 0; x < render->vp_img->width; x++)
		for(uint32_t y= 0; y < render->vp_img->height; y++)
			mlx_put_pixel(render->vp_img, x, y, rand() % RAND_MAX);
	mlx_image_to_window(render->window, render->vp_img, 0, 0);
	return (0);
} */

//GRADIENT TEST
/* 	int get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}
int display_image(t_render *render)
{
	int j = 0;
	while (j < (int)render->vp_img->height)
	{
		int i = 0;
		while (i < (int)render->vp_img->width)
		{
			double r = (double)i / (render->vp_img->width - 1);
			double g = (double)j / (render->vp_img->width - 1);
			double b = 0.0;

			int ir = (int)(255.999 * r);
			int ig = (int)(255.999 * g);
			int ib = (int)(255.999 * b);

			int color = get_rgba(ir, ig, ib, 255);
			mlx_put_pixel(render->vp_img, i, j, color);
			i++;
		}
		j++;
	}
	mlx_image_to_window(render->window, render->vp_img, 0, 0);
	return (0);
} */
