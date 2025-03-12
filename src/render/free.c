/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_worker_utils_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:45:51 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/26 19:01:09 by mdomnik          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "forward.h"
#include "mrt.h"

static void	free_shapes(t_shape *shape)
{
	t_shape	*temp;

	while (shape)
	{
		temp = shape->next;
		if (shape->triangle)
			free(shape->triangle);
		if (shape->children)
			free_shapes(shape->children);
		free(shape);
		if (temp)
			shape = temp;
		else
			break ;
	}
}

void	free_world(t_world *world)
{
	free(world->camera);
	free_shapes(world->shapes);
	free(world->light);
	free(world);
}

void	free_triple_ptr(char ***str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i])
		{
			free_double(str[i]);
		}
		i++;
	}
	free(str);
}

void	free_pattern(t_pattern *pattern)
{
	if (!pattern)
		return ;
	if (pattern->type == UV_IMAGE)
	{
		free(((t_uv_image*)pattern->uv_pattern)->canvas);
		free(pattern->uv_pattern);
	}
	free(pattern);
}
