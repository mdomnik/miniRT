/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_pixel_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:34:34 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/14 14:34:55 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

#define PP_STEP_SIZE 0
#define PP_HALF_STEP 1
#define PP_SAMPLE_X 2
#define PP_SAMPLE_Y 3
#define PP_I 0
#define PP_J 1
#define PP_K 2

static void	allocate_sample_arrays(t_ray *sample_ray[], t_comp *sample_comp[])
{
	int	i;

	i = -1;
	while (++i <= RECURSIVE_DEPTH)
	{
		sample_ray[i] = malloc(sizeof(t_ray));
		sample_comp[i] = malloc(sizeof(t_comp));
	}
}

static void	free_sample_arrays(t_ray *sample_ray[], t_comp *sample_comp[])
{
	int	i;

	i = -1;
	while (++i <= RECURSIVE_DEPTH)
	{
		free(sample_ray[i]);
		free(sample_comp[i]);
	}
}

static t_color3	process_single_sample(t_aa_sample_data *a, int i, int j)
{
	t_color3	sample_color;
	int			k;

	a->a[PP_SAMPLE_X] = a->px->x
		+ (i * a->a[PP_STEP_SIZE]) + a->a[PP_HALF_STEP];
	a->a[PP_SAMPLE_Y] = a->px->y
		+ (j * a->a[PP_STEP_SIZE]) + a->a[PP_HALF_STEP];
	k = 0;
	while (k <= RECURSIVE_DEPTH)
	{
		ft_memset(a->sample_ray[k], 0, sizeof(t_ray));
		k++;
	}
	ray_for_pixel(a->world->camera, a->a[PP_SAMPLE_X],
		a->a[PP_SAMPLE_Y], a->sample_ray[0]);
	k = 0;
	while (k <= RECURSIVE_DEPTH)
	{
		ft_memset(a->sample_comp[k], 0, sizeof(t_comp));
		k++;
	}
	sample_color = color_at(a->world, a->sample_ray,
			a->sample_comp, RECURSIVE_DEPTH);
	return (sample_color);
}

static t_color3	process_samples(t_aa_sample_data *a)
{
	int			i;
	int			j;
	t_color3	accumulated_color;

	accumulated_color = (t_color3){0};
	i = 0;
	while (i < a->grid_size)
	{
		j = 0;
		while (j < a->grid_size)
		{
			accumulated_color = add_tuple(accumulated_color,
					process_single_sample(a, i, j));
			j++;
		}
		i++;
	}
	return (accumulated_color);
}

t_color3	ray_shooter(int grid_size, float a[],
	t_pixel *px, t_world *world)
{
	t_aa_sample_data	sample_data;
	t_color3			accumulated_color;

	sample_data.grid_size = grid_size;
	sample_data.px = px;
	sample_data.world = world;
	memcpy(sample_data.a, a, sizeof(float) * 4);
	allocate_sample_arrays(sample_data.sample_ray, sample_data.sample_comp);
	accumulated_color = process_samples(&sample_data);
	free_sample_arrays(sample_data.sample_ray, sample_data.sample_comp);
	return (accumulated_color);
}
