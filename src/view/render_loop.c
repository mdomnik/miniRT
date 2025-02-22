/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:45:51 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/22 17:37:19 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

t_loop *loop_init(int ac, char *av[])
{
	t_loop *loop;

	// Allocate memory for t_loop
	loop = malloc(sizeof(t_loop));
	if (!loop)
	{
		fprintf(stderr, "Failed to allocate t_loop\n");
		exit(EXIT_FAILURE);
	}

	// Initialize MLX and create a window
	loop->mlx = mlx_init();
	if (!loop->mlx)
	{
		fprintf(stderr, "Failed to initialize MLX\n");
		exit(EXIT_FAILURE);
	}
	loop->win = mlx_new_window(loop->mlx, 800, 400, "test");

	// Allocate memory for t_image
	loop->img = malloc(sizeof(t_image));
	if (!loop->img)
	{
		fprintf(stderr, "Failed to allocate t_image\n");
		exit(EXIT_FAILURE);
	}

	// Create an image and get its buffer
	loop->img->img = mlx_new_image(loop->mlx, 800, 400);
	if (!loop->img->img)
	{
		fprintf(stderr, "Failed to create MLX image\n");
		exit(EXIT_FAILURE);
	}

	// Get image buffer information (this function assigns values automatically)
	loop->img->buffer = mlx_get_data_addr(loop->img->img, 
										  &loop->img->bits_per_pixel, 
										  &loop->img->size_line, 
										  &loop->img->endian);

	// Set width and height for easy access
	loop->img->width = 800;
	loop->img->height = 400;

	// Debugging: Print values to confirm they are initialized
	printf("Image initialized: bpp=%d, size_line=%d, endian=%d\n", 
		   loop->img->bits_per_pixel, 
		   loop->img->size_line, 
		   loop->img->endian);

	// Allocate memory for t_world
	loop->world = malloc(sizeof(t_world));
	if (!loop->world)
	{
		fprintf(stderr, "Failed to allocate t_world\n");
		exit(EXIT_FAILURE);
	}
	loop->world->shapes = NULL;
	loop->world->light = NULL;
	loop->world->camera = NULL;

	if (check_args(ac, av, loop->world))
		exit(42);

	// Initialize camera
	loop->camera = camera_new(800, 400, 0.8);
	loop->camera->transform = view_transformation(new_point3(0, 0, -15),
												  new_point3(0, 0, 1),
												  new_vec3(0, 1, 0));

	return loop;
}


void put_pixel_to_img(t_image *img, int x, int y, int color)
{
	if (x < 0 || y < 0 || x >= img->width || y >= img->height)
		return;

	int pixel_index = (y * img->size_line) + (x * (img->bits_per_pixel / 8));
	*(int *)(img->buffer + pixel_index) = color;
}

void render(t_loop *loop)
{
	t_ray *ray[RECURSIVE_DEPTH + 1];
	t_comp *comp;
	t_color3 color;
	int color_int;

	// Allocate rays
	for (int i = 0; i < (RECURSIVE_DEPTH + 1); i++)
	{
		ray[i] = malloc(sizeof(t_ray));
		if (!ray[i])
		{
			fprintf(stderr, "Failed to allocate ray[%d]\n", i);
			exit(EXIT_FAILURE);
		}
	}

	// Allocate t_comp struct
	comp = malloc(sizeof(t_comp));
	if (!comp)
	{
		fprintf(stderr, "Memory allocation failed for comp\n");
		exit(EXIT_FAILURE);
	}

	// Iterate through pixels
	for (int y = 0; y < loop->camera->vsize; y++)
	{
		for (int x = 0; x < loop->camera->hsize; x++)
		{
			ray_for_pixel(loop->camera, x, y, ray[0]);
			memset(comp, 0, sizeof(t_comp));
			color = color_at(loop->world, ray, comp, RECURSIVE_DEPTH);
			color_int = color_to_int(color);
			put_pixel_to_img(loop->img, x, y, color_int);
		}
		if (y % 10 == 0)
			mlx_put_image_to_window(loop->mlx, loop->win, loop->img->img, 0, 0);
	}
	// Display the rendered image
	mlx_put_image_to_window(loop->mlx, loop->win, loop->img->img, 0, 0);
	printf("done\n");
	// Free memory
	for (int i = 0; i < (RECURSIVE_DEPTH + 1); i++)
		free(ray[i]);
	free(comp);
}

