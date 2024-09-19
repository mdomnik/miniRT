/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:16:46 by mdomnik           #+#    #+#             */
/*   Updated: 2024/09/19 20:48:05 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

int	transform_color(t_color *color)
{
	return (color->r << 24 | color->g << 16 | color->b << 8 | 255);
}

int display_image(t_render *render)
{
	t_ray	ray;
	t_color	c;
	int image_width = render->vp_img->width;
	int image_height = render->vp_img->height;
	double	aspect_ratio = image_width / image_height;
	double	view_height = 2.0;
	double	view_width = aspect_ratio * view_height;
	double	focal_length = 1.0;
	t_vec3	horizontal = vec3(view_width, 0.0, 0.0);
	t_vec3	vertical = vec3(0.0, view_height, 0.0);
	t_vec3	lower_left_corner = vec3(-view_width / 2, -view_height / 2, -focal_length);
// 
	dprintf(2, "W/H :: %d/%d\n", (int) image_width, (int) image_height);
// 
	ray.orig = vec3(0.0f, 0.0f, 2.0f);
	dprintf(2, "rendering...\n");
	for (int y = 0; y < image_height; ++y)
	{
		dprintf(2, "%d/%d        \r", y, (int) image_height);
		for (int x = 0; x < image_width; ++x)
		{
			double u = (double)x / (image_width - 1);
			double v = (double)y / (image_height - 1);
			t_vec3 dir = lower_left_corner;
			v_vec3_add(&dir, vec3_mult(&horizontal, u));
			v_vec3_add(&dir, vec3_mult(&vertical, v));
			ray.dir = *vec3_unit(vec3_sub(&dir, &ray.orig));
			c = ray_color(&ray);
			int color = transform_color(&c);
			mlx_put_pixel(render->vp_img, x, y, color);
		}
	}
	write(2, "\n", 1);
	mlx_image_to_window(render->window, render->vp_img, 0, 0);
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