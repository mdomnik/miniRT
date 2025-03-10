/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:45:51 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/10 17:42:16 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

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

void	render(t_loop *loop)
{
	if (loop->opts->values->aa_samples > 0)
		printf("\033[1;33mAntialiasing enabled with %d samples\033[0m\n", loop->opts->values->aa_samples);
	if (loop->opts->opts_flags & OPT_MULTITHREAD && loop->opts->values->threads > 1)
	{
		printf("\033[1;33mMultithreaded rendering enabled with %d threads\033[0m\n", loop->opts->values->threads);
		render_multithreaded(loop);
	}
	else
		render_single(loop);
}
