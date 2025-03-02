/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:07:08 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/22 20:48:44 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

void	get_pixel_size(t_camera *camera)
{
	float	half_view;
	float	aspect;

	half_view = tan(camera->fov / 2);
	aspect = (float)camera->hsize / (float)camera->vsize;
	if (aspect >= 1)
	{
		camera->half_width = half_view;
		camera->half_height = half_view / aspect;
	}
	else
	{
		camera->half_width = half_view * aspect;
		camera->half_height = half_view;
	}
	camera->pixel_size = (camera->half_width * 2) / camera->hsize;
}

t_camera	*camera_new(int hsize, int vsize, float fov)
{
	t_camera	*camera;

	camera = malloc(sizeof(t_camera));
	camera->hsize = hsize;
	camera->vsize = vsize;
	camera->fov = fov;
	camera->transform = init_identity_matrix(4);
	camera->y_angle = 0;
	get_pixel_size(camera);
	return (camera);
}

void	ray_for_pixel(t_camera *camera, int px, int py, t_ray *ray)
{
	float		xoffset;
	float		yoffset;
	float		world_x;
	float		world_y;
	t_matrix	inv_transform;

	inv_transform = inverse(camera->transform);
	xoffset = (px + 0.5f) * camera->pixel_size;
	yoffset = (py + 0.5f) * camera->pixel_size;
	world_x = camera->half_width - xoffset;
	world_y = camera->half_height - yoffset;
	ray->orig = multiply_matrix_tuple(inv_transform, new_point3(0, 0, 0));
	ray->dir = multiply_matrix_tuple(inv_transform, new_point3(world_x,
				world_y, -1));
	ray->dir = sub_tuple(ray->dir, ray->orig);
	if (!is_near_zero(ray->dir))
		ray->dir = normalize(ray->dir);
	else
		ray->dir = new_vec3(0, 0, -1);
}
