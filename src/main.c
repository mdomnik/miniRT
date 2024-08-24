/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 20:06:31 by astavrop          #+#    #+#             */
/*   Updated: 2024/08/24 20:02:58 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/color.h"
#include "../inc/vec3.h"
#include "../inc/ray.h"
#include "../inc/mrt.h"
#include "../lib/libft/libft.h"

#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	t_ray	ray;
	t_color	c;
	double	image_width = 500;
	double	image_height = 300;
	double	aspect_ratio = image_width / image_height;
	double	view_height = 2.0;
	double	view_width = aspect_ratio * view_height;
	double	focal_length = 1.0;
	t_vec3	horizontal = vec3(view_width, 0.0, 0.0);
	t_vec3	vertical = vec3(0.0, view_height, 0.0);
	t_vec3	lower_left_corner = vec3(-view_width / 2, -view_height / 2, -focal_length);

	write(1, "P3\n500 300\n255\n", 15);

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
			c = per_pixel(ray);
			write_color(1, &c);
		}
	}
	write(2, "\n", 1);
	return (0);}
