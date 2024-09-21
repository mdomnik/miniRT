/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:59:34 by astavrop          #+#    #+#             */
/*   Updated: 2024/09/21 22:05:08 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"
#include "../../lib/libft/libft.h"
#include "../../inc/objects.h"
#include "../../inc/color.h"
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

t_color	ray_color(t_ray *r, t_render *render)
{
	t_obj 	obj;
	t_color pcolor;


	obj = render->options->objects;
	while (obj.sphere != NULL)
	{
		if (hit_sphere(obj.sphere, r))
			return(obj.sphere->color);
		obj.sphere = obj.sphere->next;
	}
	while (obj.cylinder != NULL)
	{
		if (hit_cylinder(obj.cylinder, r))
			return(obj.cylinder->color);
		obj.cylinder = obj.cylinder->next;
	}
	while (obj.plane != NULL)
	{
		if (hit_plane(obj.plane, r))
			return(obj.plane->color);
		obj.plane = obj.plane->next;
	}
	pcolor = color(0, 0, 0);
	return (pcolor);
}


