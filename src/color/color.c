/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:59:34 by astavrop          #+#    #+#             */
/*   Updated: 2024/08/22 19:56:17 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/color.h"
#include "../../lib/libft/libft.h"

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

t_color	*ray_color(t_ray *r)
{
	t_vec3	*udir;
	float	a;

	udir = vec3_unit(r->dir);
	a = 0.5 * (udir->a[Y] + 1.0);
	return (
		vec3_add(
			vec3_mult(vec3_new(1, 1, 1), (1.0 - a)),
			vec3_mult(vec3_new(0.5, 0.7, 1.0), a)
		)
	);
}
