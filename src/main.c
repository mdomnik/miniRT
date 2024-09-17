/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 20:06:31 by astavrop          #+#    #+#             */
/*   Updated: 2024/09/17 18:32:10 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/color.h"
#include "../inc/vec3.h"
#include "../inc/ray.h"

#include <stdio.h>
#include <unistd.h>

#ifndef WIDTH
# define WIDTH 900
#endif

#ifndef HEIGHT
# define HEIGHT 600
#endif

#include "../inc/mrt.h"

// int main(int argc, char **argv)
// {
	// t_render	render;
	// 
	// if(check_args(argc, argv, &render) == 1)
		// return(1);
	// if(start_mlx(&render) == 1)
		// return(1);
	// mlx_loop(render.window);

  int	main(void)
{
	t_ray	ray;
	t_color	c;
	double	image_width = WIDTH;
	double	image_height = HEIGHT;
	double	aspect_ratio = image_width / image_height;
	double	view_height = 2.0;
	double	view_width = aspect_ratio * view_height;
	double	focal_length = 1.0;
	t_vec3	horizontal = vec3(view_width, 0.0, 0.0);
	t_vec3	vertical = vec3(0.0, view_height, 0.0);
	t_vec3	lower_left_corner = vec3(-view_width / 2, -view_height / 2, -focal_length);
// 
	dprintf(2, "W/H :: %d/%d\n", (int) image_width, (int) image_height);
	dprintf(1, "P3\n%d %d\n255\n", (int) image_width, (int) image_height);
// 
	ray.orig = vec3(0.0f, 0.0f, 2.0f);
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
			write_color(1, &c);
		}
	}
	write(2, "\n", 1);
	return (0);
}
