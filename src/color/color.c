/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:59:34 by astavrop          #+#    #+#             */
/*   Updated: 2024/09/17 18:20:31 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/color.h"
#include "../../lib/libft/libft.h"
#include "../../inc/objects.h"
#include <stdio.h>

int	write_color(int fd, t_color *pixel_color)
{
//	ft_putnbr_fd(r, fd);
//	ft_putstr_fd(" ", fd);
//	ft_putnbr_fd(g, fd);
//	ft_putstr_fd(" ", fd);
//	ft_putnbr_fd(b, fd);
//	ft_putstr_fd("\n", fd);
	dprintf(fd, "%d %d %d\n", pixel_color->r, pixel_color->g, pixel_color->b);
	return (0);
}

t_color	color(float red, float green, float blue)
{
	t_color	c;

	c.r = red;
	c.g = green;
	c.b = blue;
	return (c);
}

t_color	ray_color(t_ray *r)
{
	/* TEST */
	// t_point3	sc1 = point3(4, 4, -40); // Test sphere center
	// v_vec3_neg(&sc1);
	// t_sphere	s1 = sphere(sc1, 4.0f);
	t_point3	sc2 = point3(-1, -1, -5); // Test sphere center
	t_sphere	s2 = sphere(sc2, 0.5f);
	t_point3	p1c = point3(0, 0, -1); // Test plane
	t_vec3		p1n = vec3(-0.5f, -2, 0.1f);
	t_plane		p1 = plane(p1c, p1n);

	t_vec3		cyc1 = vec3(1, 1, -10);
	t_vec3		cyax1 = vec3(0.8, 0.3, 0);
	//v_vec3_unit(&cyax1);

	float		cyr1 = 0.4f;
	float		cyh1 = 0.8f;
	t_cylinder	cy1 = cylinder(cyc1, cyax1, cyr1, cyh1);


	if (hit_cylinder(&cy1, r))
		return (color(255, 0, 0));
	else if (hit_sphere(&s2, r))
		return (color(0, 255, 0));
	else if (hit_plane(&p1, r))
		return (color(100, 100, 100));
	return (color(0, 0, 0));
}
