/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:59:34 by astavrop          #+#    #+#             */
/*   Updated: 2024/08/26 17:36:45 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/color.h"
#include "../../lib/libft/libft.h"
#include "../../inc/objects.h"
#include <stdio.h>

int	write_color(int fd, t_color *pixel_color)
{
	int	r;
	int	g;
	int	b;

	r = (pixel_color->a[R] * 255.999);
	g = (pixel_color->a[G] * 255.999);
	b = (pixel_color->a[B] * 255.999);
//	ft_putnbr_fd(r, fd);
//	ft_putstr_fd(" ", fd);
//	ft_putnbr_fd(g, fd);
//	ft_putstr_fd(" ", fd);
//	ft_putnbr_fd(b, fd);
//	ft_putstr_fd("\n", fd);
	dprintf(fd, "%d %d %d\n", r, g, b);
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

t_color	ray_color(t_ray *r)
{
	/* TEST */
	t_point3	sc = point3(0, 0, -1); // Test sphere center
	t_sphere	s = sphere(sc, 0.5f);
	if (hit_sphere(&s, r))
		return (color(1, 0, 0));

	t_color	clr1;
	t_color	clr2;

	t_vec3	udir = *vec3_unit(&r->dir);
	float	a = 0.5f * (udir.a[Y] + 1.0f);
	clr1 = color(1, 1, 1);
	clr2 = color(0.5f, 0.7f, 1);
	v_vec3_mult(&clr1, 1.0f - a);
	v_vec3_mult(&clr2, a);
	v_vec3_add(&clr1, &clr2);
	return (clr1);
}
