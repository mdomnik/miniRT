/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supersampling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:44:18 by mdomnik           #+#    #+#             */
/*   Updated: 2025/01/20 20:47:02 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

#define SS_X 0
#define SS_Y 1
#define SS_SAMPLE_X 2
#define SS_SAMPLE_Y 3
#define SS_SAMPLES 4
#define SS_PER_SIDE 5
#define SS_COLOR_INT 6

int	supersampling_setting(int set, int quality)
{
	static int	supersample = 1;

	if (set)
	{
		supersample = quality;
		return (supersample);
	}
	if (supersample == SS_OFF)
		return (1);
	if (supersample == SS_2X)
		return (2);
	if (supersample == SS_4X)
		return (4);
	if (supersample == SS_8X)
		return (8);
	if (supersample == SS_16X)
		return (16);
	return (-1);
}

t_ray	*ray_for_pixel_with_offset(t_camera *camera,
		float x_offset, float y_offset)
{
	float	world_x;
	float	world_y;
	t_tuple	pixel;
	t_tuple	origin;
	t_tuple	direction;

	world_x = camera->half_width - (x_offset * camera->pixel_size);
	world_y = camera->half_height - (y_offset * camera->pixel_size);
	pixel = multiply_matrix_tuple(inverse(camera->transform),
			new_point3(world_x, world_y, -1));
	origin = multiply_matrix_tuple(inverse(camera->transform),
			new_point3(0, 0, 0));
	direction = normalize(sub_tuple(pixel, origin));
	return (ray_new(&origin, &direction));
}

static t_color3	calculate_pixel_color(t_camera *camera, t_world *world,
		int v[7], float step)
{
	t_color3	color;
	t_color3	sample_color;
	t_ray		*ray;
	float		offset_x;
	float		offset_y;

	color = new_color3(0, 0, 0);
	v[SS_SAMPLE_Y] = 0;
	while (v[SS_SAMPLE_Y] < v[SS_PER_SIDE])
	{
		v[SS_SAMPLE_X] = 0;
		while (v[SS_SAMPLE_X] < v[SS_PER_SIDE])
		{
			offset_x = (v[SS_SAMPLE_X] + 0.5f) * step;
			offset_y = (v[SS_SAMPLE_Y] + 0.5f) * step;
			ray = ray_for_pixel_with_offset(camera, v[SS_X] + offset_x,
					v[SS_Y] + offset_y);
			sample_color = color_at(world, ray, quality(0, RECURSIVE_DEPTH));
			color = add_tuple(color, sample_color);
			free(ray);
			v[SS_SAMPLE_X]++;
		}
		v[SS_SAMPLE_Y]++;
	}
	return (mult_color_scalar(color, 1.0f / (v[SS_PER_SIDE] * v[SS_PER_SIDE])));
}

mlx_image_t	*render_supersampling(mlx_t *mlx, t_camera *camera, t_world *world)
{
	mlx_image_t	*image;
	int			v[7];
	float		step;
	t_color3	color;

	v[SS_SAMPLES] = supersampling_setting(0, 0);
	v[SS_PER_SIDE] = (int)sqrt(v[SS_SAMPLES]);
	step = 1.0f / v[SS_PER_SIDE];
	image = mlx_new_image(mlx, camera->hsize, camera->vsize);
	v[SS_Y] = 0;
	while (v[SS_Y] < camera->vsize)
	{
		v[SS_X] = 0;
		while (v[SS_X] < camera->hsize)
		{
			color = calculate_pixel_color(camera, world, v, step);
			v[SS_COLOR_INT] = color_to_int(color);
			mlx_put_pixel(image, v[SS_X], v[SS_Y], v[SS_COLOR_INT]);
			v[SS_X]++;
		}
		v[SS_Y]++;
	}
	return (image);
}
