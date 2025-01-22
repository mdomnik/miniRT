/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:52:58 by mdomnik           #+#    #+#             */
/*   Updated: 2025/01/22 18:12:20 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

void	get_pixel_size(t_camera *camera);

t_camera	*camera_new(int hsize, int vsize, float fov)
{
	t_camera	*camera;

	camera = malloc(sizeof(t_camera));
	camera->hsize = hsize;
	camera->vsize = vsize;
	camera->fov = fov;
	camera->transform = *init_identity_matrix(4);
	camera->y_angle = 0;
	get_pixel_size(camera);
	return (camera);
}

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

t_ray	*ray_for_pixel(t_camera *camera, int px, int py)
{
	float	xoffset;
	float	yoffset;
	float	world_x;
	float	world_y;
	t_tuple	pixel;
	t_tuple	origin;
	t_tuple	direction;

	xoffset = (px + 0.5) * camera->pixel_size;
	yoffset = (py + 0.5) * camera->pixel_size;
	world_x = camera->half_width - xoffset;
	world_y = camera->half_height - yoffset;
	pixel = multiply_matrix_tuple(inverse(camera->transform), new_point3(world_x, world_y, -1));
	origin = multiply_matrix_tuple(inverse(camera->transform), new_point3(0, 0, 0));
	direction = normalize(sub_tuple(pixel, origin));
	return (ray_new(&origin, &direction));
}

// t_matrix pivot_camera(t_matrix orientation, double angle, char axis)
// {
//     t_matrix rotation_matrix;
//     t_matrix result;

//     // Initialize the rotation matrix as an identity matrix
//     rotation_matrix = *init_identity_matrix(4);

//     // Determine the axis of rotation and populate the rotation matrix
//     if (axis == 'x')
//     {
//         rotation_matrix.a[1][1] = cos(angle);
//         rotation_matrix.a[1][2] = -sin(angle);
//         rotation_matrix.a[2][1] = sin(angle);
//         rotation_matrix.a[2][2] = cos(angle);
//     }
//     else if (axis == 'y')
//     {
//         rotation_matrix.a[0][0] = cos(angle);
//         rotation_matrix.a[0][2] = sin(angle);
//         rotation_matrix.a[2][0] = -sin(angle);
//         rotation_matrix.a[2][2] = cos(angle);
//     }
//     else if (axis == 'z')
//     {
//         rotation_matrix.a[0][0] = cos(angle);
//         rotation_matrix.a[0][1] = -sin(angle);
//         rotation_matrix.a[1][0] = sin(angle);
//         rotation_matrix.a[1][1] = cos(angle);
//     }
//     else
//     {
//         return orientation;
//     }

//     result = *multiply_matrices(&orientation, &rotation_matrix);

//     return result;
// }

// mlx_image_t	*render(mlx_t *mlx, t_camera *camera, t_world *world)
// {
// 	mlx_image_t	*image;
// 	t_ray		*ray;
// 	t_color3	color;
// 	int			color_int;
// 	int			x;
// 	int			y;
// 	// int			total;

// 	x = 0;
// 	y = 0;
// 	// total = camera->hsize * camera->vsize;
// 	image = mlx_new_image(mlx, camera->hsize, camera->vsize);
// 	while (y < camera->vsize)
// 	{
// 		x = 0;
// 		while (x < camera->hsize)
// 		{
// 			// printf("Rendering %d/%d\n", y * camera->hsize + x, total);
// 			ray = ray_for_pixel(camera, x, y);
// 			color = color_at(world, ray, quality(0, RECURSIVE_DEPTH));
// 			color_int = color_to_int(color);
// 			mlx_put_pixel(image, x, y, color_int);
// 			x++;
// 		}
// 		y++;
// 	}
// 	return (image);
// }
