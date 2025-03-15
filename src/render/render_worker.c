/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_worker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 02:32:53 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/14 21:37:38 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

static void	free_computed_buffer(bool **computed_buffer, int vsize)
{
	int	i;

	i = 0;
	while (i < vsize)
	{
		free(computed_buffer[i]);
		i++;
	}
	free(computed_buffer);
}

static void	process_pixel(t_multithread_data *mdata, int x, int y)
{
	t_pixel	px;

	if (!mdata->computed_buffer[y][x])
	{
		px.x = x;
		px.y = y;
		if (mdata->thread_data->loop->opts->opts_flags & OPT_ANTIALIAS)
		{
			if (mdata->thread_data->loop->opts->values->aa_samples > 1)
				process_pixel_aa(mdata->world, &px,
					mdata->thread_data->loop->opts->values->aa_samples);
		}
		else
			process_pixel_color(mdata->world, mdata->ray, mdata->comp, &px);
		mdata->computed_buffer[y][x] = true;
		put_pixel_to_img(mdata->thread_data->loop->img, px.x, px.y, px.color);
	}
}

static void	render_pass(t_multithread_data *mdata, int step)
{
	int	y;
	int	x;

	y = mdata->thread_data->thread_id;
	while (y < mdata->world->camera->vsize)
	{
		x = 0;
		while (x < mdata->world->camera->hsize)
		{
			if (x % step == 0 && y % step == 0)
				process_pixel(mdata, x, y);
			x++;
		}
		if (y % 10 == 0)
			update_display(mdata->thread_data->loop);
		y += mdata->thread_data->total_threads;
	}
}

static bool	setup_multithread_data(t_multithread_data *mdata,
		t_thread_data *thread_data)
{
	mdata->thread_data = thread_data;
	mdata->world = init_local_world(thread_data);
	if (!mdata->world)
	{
		fprintf(stderr, ERR_THREAD, thread_data->thread_id);
		return (false);
	}
	if (!init_worker_memory(mdata->ray, mdata->comp))
	{
		free_world(mdata->world);
		return (false);
	}
	mdata->computed_buffer = allocate_computed_buffer(
			mdata->world->camera->hsize, mdata->world->camera->vsize);
	if (!mdata->computed_buffer)
	{
		free_worker_memory(mdata->ray, mdata->comp);
		free_world(mdata->world);
		return (false);
	}
	return (true);
}

void	*render_worker(void *arg)
{
	t_multithread_data	mdata;
	int					step;

	if (!setup_multithread_data(&mdata, (t_thread_data *)arg))
		pthread_exit(NULL);
	step = 16;
	while (step >= 1)
	{
		render_pass(&mdata, step);
		step /= 2;
	}
	free_computed_buffer(mdata.computed_buffer, mdata.world->camera->vsize);
	free_worker_memory(mdata.ray, mdata.comp);
	free_world(mdata.world);
	pthread_exit(NULL);
}
