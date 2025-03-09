/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:45:51 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/09 19:18:19 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"
#include <stdio.h>

t_loop	*loop_init(void)
{
	t_loop	*loop;

	loop = malloc(sizeof(*loop));
	if (!loop)
		return (NULL);
	loop->mlx = mlx_init();
	if (!loop->mlx)
		return (free(loop), NULL);
	loop->win = mlx_new_window(loop->mlx, DEFAULT_WIDTH, DEFAULT_HEIGHT, "=D");
	if (!loop->win)
		return (free(loop), NULL);
	if (!init_loop_img(loop))
		return (free(loop), NULL);
	if (!init_loop_opts(loop))
		return (free(loop), NULL);
	return (loop);
}

void	put_pixel_to_img(t_image *img, int x, int y, int color)
{
	int	pixel_index;

	if (x < 0 || y < 0 || x >= img->width || y >= img->height)
		return ;
	pixel_index = (y * img->size_line) + (x * (img->bits_per_pixel / 8));
	*(int *)(img->buffer + pixel_index) = color;
}

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#include <sys/stat.h>
#include <sys/types.h>

void create_directory(const char *path)
{
    struct stat st = {0};
    if (stat(path, &st) == -1) // Check if the directory exists
        mkdir(path, 0700); // Create the directory with rwx------ permissions
}

void save_image(t_image *img, char *filename)
{
	FILE *file;
	int x, y;
	int offset;
	unsigned char r, g, b;
	char *file_name;

	if (!img || !img->buffer)
	{
		fprintf(stderr, "Error: Invalid image data.\n");
		return;
	}
	create_directory("saved/");
	file_name = ft_strjoin("saved/", filename);
	free(filename);
	filename = ft_strjoin(file_name, ".ppm");
	file = fopen(filename, "w");
	free(file_name);
	if (!file)
	{
		fprintf(stderr, "Error: Could not open file for writing.\n");
		return;
	}
	// Write PPM header
	fprintf(file, "P3\n%d %d\n255\n", img->width, img->height);
	// Iterate over pixels row by row
	for (y = 0; y < img->height; y++)
	{
		for (x = 0; x < img->width; x++)
		{
			offset = (y * img->size_line) + (x * (img->bits_per_pixel / 8));

			// Extract pixel colors based on endian format
			if (img->endian == 0) // Little endian (default for most systems)
			{
				b = (unsigned char)img->buffer[offset];
				g = (unsigned char)img->buffer[offset + 1];
				r = (unsigned char)img->buffer[offset + 2];
			}
			else // Big endian
			{
				r = (unsigned char)img->buffer[offset];
				g = (unsigned char)img->buffer[offset + 1];
				b = (unsigned char)img->buffer[offset + 2];
			}

			// Write pixel values
			fprintf(file, "%d %d %d\n", r, g, b);
		}
	}

	fclose(file);
	printf("\033[1;35mImage saved as %s\033[0m\n", filename);
}

void	render(t_loop *loop, int ac, char *av[])
{
	pthread_t		threads[NUM_THREADS];
	t_thread_data	thread_data[NUM_THREADS];
	int				i;

	i = -1;
	while (++i < NUM_THREADS)
	{
		thread_data[i].loop = loop;
		thread_data[i].thread_id = i;
		thread_data[i].ac = ac;
		thread_data[i].av = av;
		if (pthread_create(&threads[i], NULL,
				render_worker, &thread_data[i]) != 0)
		{
			fprintf(stderr, "Failed to create thread %d\n", i);
			exit(EXIT_FAILURE);
		}
	}
	join_threads(threads);
	free_triple_ptr(loop->opts->scene.scene_objects);
	mlx_put_image_to_window(loop->mlx, loop->win, loop->img->img, 0, 0);
	if (loop->opts->opts_flags & OPT_SAVE)
	{
		while(loop->opts->values->type != 0)
			loop->opts->values = loop->opts->values->next;
		save_image(loop->img, loop->opts->values->value.string);
	}
}
