/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supersampling.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:44:18 by mdomnik           #+#    #+#             */
/*   Updated: 2025/01/20 20:47:02 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

int	supersampling_setting(int set, int quality)
{
	static int supersample = 1;
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

t_ray	*ray_for_pixel_with_offset(t_camera *camera, float x_offset, float y_offset)
{
	float	world_x;
	float	world_y;
	t_tuple	pixel;
	t_tuple	origin;
	t_tuple	direction;

	// Calculate the world coordinates of the offset
	world_x = camera->half_width - (x_offset * camera->pixel_size);
	world_y = camera->half_height - (y_offset * camera->pixel_size);

	// Transform the pixel and origin from camera space to world space
	pixel = multiply_matrix_tuple(inverse(camera->transform), new_point3(world_x, world_y, -1));
	origin = multiply_matrix_tuple(inverse(camera->transform), new_point3(0, 0, 0));

	// Compute the ray's direction and normalize it
	direction = normalize(sub_tuple(pixel, origin));

	// Create and return the ray
	return (ray_new(&origin, &direction));
}


mlx_image_t	*render_supersampling(mlx_t *mlx, t_camera *camera, t_world *world)
{
	mlx_image_t	*image;
	t_color3	color, sample_color;
	int			color_int;
	int			x, y;
	int			sample_x, sample_y;
	int			supersample = supersampling_setting(0, 0); // Get current supersampling setting
	int			samples_per_side = (int)sqrt(supersample);
	float		step = 1.0f / samples_per_side;

	image = mlx_new_image(mlx, camera->hsize, camera->vsize);
	y = 0;
	while (y < camera->vsize)
	{
		x = 0;
		while (x < camera->hsize)
		{
			color = new_color3(0, 0, 0); // Initialize color to black
			// Supersampling loop
			for (sample_y = 0; sample_y < samples_per_side; sample_y++)
			{
				for (sample_x = 0; sample_x < samples_per_side; sample_x++)
				{
					float offset_x = (sample_x + 0.5f) * step;
					float offset_y = (sample_y + 0.5f) * step;
					t_ray *ray = ray_for_pixel_with_offset(camera, x + offset_x, y + offset_y);
					sample_color = color_at(world, ray, quality(0, RECURSIVE_DEPTH));
					color = add_tuple(color, sample_color);
					free(ray); // Clean up dynamically allocated memory if applicable
				}
			}
			// Average the color by dividing by the number of samples
			color = mult_color_scalar(color, 1.0f / (samples_per_side * samples_per_side));
			color_int = color_to_int(color);
			mlx_put_pixel(image, x, y, color_int);
			x++;
		}
		y++;
	}
	return (image);
}
