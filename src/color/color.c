/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:59:34 by astavrop          #+#    #+#             */
/*   Updated: 2024/08/24 20:02:54 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/color.h"
#include "../../lib/libft/libft.h"
#include "vec3.h"
#include <stdio.h>

int	write_color(int fd, t_color *pixel_color)
{
	int	r;
	int	g;
	int	b;

	r = (pixel_color->a[R] * 255.999);
	g = (pixel_color->a[G] * 255.999);
	b = (pixel_color->a[B] * 255.999);
	ft_putnbr_fd(r, fd);
	ft_putstr_fd(" ", fd);
	ft_putnbr_fd(g, fd);
	ft_putstr_fd(" ", fd);
	ft_putnbr_fd(b, fd);
	ft_putstr_fd("\n", fd);
	return (0);
}

t_color	color(float red, float green, float blue)
{
	t_color	c;

	c.a[R] = red;
	c.a[G] = green;
	c.a[B] = blue;
	return (c);
}

/**
 * Sphere equation
 * (bx^2 + by^2 + bz^2)t^2 + (2(axbx + ayby + azbz))t + (ax^2 + ay^2 + az^2 -r^2) = 0
 * where
 * a = ray origin
 * b = ray dir
 * r = radius
 * t = hit distance
 **/
t_color	per_pixel(t_ray ray)
{
	double	radius = 0.5f;
	double	a = dot(&ray.dir, &ray.dir);
	double	b = 2.0f * dot(&ray.orig, &ray.dir);
	double	c = dot(&ray.orig, &ray.orig) - (radius * radius);
	double	discriminant = b * b - 4.0f * a * c;
	if (discriminant >= 0.0f)
		return (color(0.6f, 0.1f, 1.0f));
	else
		return (color(0.0f, 0.0f, 0.0f));
}

t_color	*ray_color(t_ray *r)
{
	t_vec3	*udir;
	float	a;

	udir = vec3_unit(&r->dir);
	a = 0.5 * (udir->a[Y] + 1.0);
	return (
		vec3_add(
			vec3_mult(vec3_new(1, 1, 1), (1.0 - a)),
			vec3_mult(vec3_new(0.5, 0.7, 1.0), a)
		)
	);
}
