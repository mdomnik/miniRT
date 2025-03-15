/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:45:51 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/15 17:05:42 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

// // Function to join all threads after rendering
// void	join_threads(pthread_t *threads, int thread_count)
// {
// 	int	i;

// 	i = 0;
// 	while (i < thread_count)
// 	{
// 		pthread_join(threads[i], NULL);
// 		i++;
// 	}
// }

// void	allocate_threads(pthread_t **threads,
// 		t_thread_data **thread_data, int thread_count)
// {
// 	*threads = malloc(thread_count * sizeof(pthread_t));
// 	*thread_data = malloc(thread_count * sizeof(t_thread_data));
// 	if (!*threads || !*thread_data)
// 	{
// 		fprintf(stderr, "Memory allocation failed.\n");
// 		free(*threads);
// 		free(*thread_data);
// 		exit(EXIT_FAILURE);
// 	}
// }

// void	initialize_threads(t_loop *loop, pthread_t *threads,
// 						t_thread_data *thread_data, int thread_count)
// {
// 	int	i;

// 	i = 0;
// 	while (i < thread_count)
// 	{
// 		thread_data[i].loop = loop;
// 		thread_data[i].thread_id = i;
// 		thread_data[i].total_threads = thread_count;
// 		if (pthread_create(&threads[i], NULL,
// 				render_worker, &thread_data[i]) != 0)
// 		{
// 			fprintf(stderr, "Failed to create thread %d\n", i);
// 			free(threads);
// 			free(thread_data);
// 			exit(EXIT_FAILURE);
// 		}
// 		i++;
// 	}
// }

// void	create_threads(t_loop *loop, pthread_t **threads,
// 					t_thread_data **thread_data, int *thread_count)
// {
// 	*thread_count = loop->opts->values->threads;
// 	if (*thread_count < 1)
// 		*thread_count = 1;
// 	allocate_threads(threads, thread_data, *thread_count);
// 	initialize_threads(loop, *threads, *thread_data, *thread_count);
// }

// void	render_multithreaded(t_loop *loop)
// {
// 	int				thread_count;
// 	pthread_t		*threads;
// 	t_thread_data	*thread_data;
// 	int				i;

// 	create_threads(loop, &threads, &thread_data, &thread_count);
// 	i = 0;
// 	while (i < thread_count)
// 	{
// 		pthread_join(threads[i], NULL);
// 		i++;
// 	}
// 	mlx_put_image_to_window(loop->mlx, loop->win, loop->img->img, 0, 0);
// 	if (loop->opts->opts_flags & OPT_SAVE
// 		&& loop->opts->values->filename != NULL)
// 		save_image(loop->img, loop->opts->values->filename);
// 	free(threads);
// 	free(thread_data);
// }
