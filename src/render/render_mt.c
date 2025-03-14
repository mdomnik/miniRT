/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_worker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:45:51 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/26 19:01:09 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

// Function to join all threads after rendering
void	join_threads(pthread_t *threads, int thread_count)
{
	for (int i = 0; i < thread_count; i++)
		pthread_join(threads[i], NULL);
}

void	render_multithreaded(t_loop *loop)
{
	int				thread_count;
	pthread_t		*threads;
	t_thread_data	*thread_data;

	thread_count = loop->opts->values->threads;
	if (thread_count < 1)
		thread_count = 1;
	threads = malloc(thread_count * sizeof(pthread_t));
	thread_data = malloc(thread_count * sizeof(t_thread_data));
	if (!threads || !thread_data)
	{
		fprintf(stderr, "Memory allocation failed.\n");
		free(threads);
		free(thread_data);
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < thread_count; i++)
	{
		thread_data[i].loop = loop;
		thread_data[i].thread_id = i;
		thread_data[i].total_threads = thread_count;
		if (pthread_create(&threads[i], NULL, render_worker,
				&thread_data[i]) != 0)
		{
			fprintf(stderr, "Failed to create thread %d\n", i);
			free(threads);
			free(thread_data);
			exit(EXIT_FAILURE);
		}
	}
	for (int i = 0; i < thread_count; i++)
		pthread_join(threads[i], NULL);
	free(threads);
	free(thread_data);
}
