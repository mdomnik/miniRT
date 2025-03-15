/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 15:15:04 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/15 17:05:49 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

// void	assign_loop_locks(t_loop *loop)
// {
// 	t_mutexes	*mutexes;

// 	mutexes = malloc(sizeof(t_mutexes));
// 	if (!mutexes)
// 	{
// 		fprintf(stderr, "Failed to allocate memory for mutexes.\n");
// 		exit(EXIT_FAILURE);
// 	}
// 	pthread_mutex_init(&mutexes->world, NULL);
// 	pthread_mutex_init(&mutexes->mlx, NULL);
// 	loop->mutexes = mutexes;
// }

// bool	**allocate_computed_buffer(int hsize, int vsize)
// {
// 	bool	**computed_buffer;
// 	int		i;
// 	int		j;

// 	computed_buffer = malloc(vsize * sizeof(bool *));
// 	if (!computed_buffer)
// 		return (NULL);
// 	i = 0;
// 	while (i < vsize)
// 	{
// 		computed_buffer[i] = calloc(hsize, sizeof(bool));
// 		if (!computed_buffer[i])
// 		{
// 			j = 0;
// 			while (j < i)
// 			{
// 				free(computed_buffer[j]);
// 				j++;
// 			}
// 			free(computed_buffer);
// 			return (NULL);
// 		}
// 		i++;
// 	}
// 	return (computed_buffer);
// }
