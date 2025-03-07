/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:45:51 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/07 17:16:01 by mdomnik          ###   ########.fr       */
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
}
