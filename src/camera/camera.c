/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 21:06:27 by astavrop          #+#    #+#             */
/*   Updated: 2024/08/23 13:53:38 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/camera.h"

t_camera	camera_new(void)
{
	t_camera	c;

	c.aspect_ration = (double) AR_WIDTH / AR_HEIGHT;
	c.img_width = IMG_WIDTH;
	c.img_height = (double) c.img_width / c.aspect_ration;
	if (c.img_height < 1)
		c.img_height = 1;
	c.max_depth = MAX_DEPTH;
	c.FOV = 70;
	c.focal_dist = 10;
	c.origin = point3(0, 0, 0);
	c.center = c.origin;
	c.dir = point3(0, 0, 1);
}

int	viewport_init(t_camera *c)
{
	double	vp_width;
	double	vp_height;

	vp_height = 2 * tan(deg_to_rad(c->FOV) / 2) * c->focal_dist;
	vp_width = vp_height * ((double) c->img_width / c->img_height);
}
