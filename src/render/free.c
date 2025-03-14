/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                            :+:      :+:    :+:   */
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
		free_pattern(shape->material.pattern, shape);
		free_bump_map(shape->material.bump_map);
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

void	free_lights(t_light_p *light)
{
	t_light_p	*temp;

	while (light)
	{
		temp = light->next;
		free(light);
		if (temp)
			light = temp;
		else
			break ;
	}
}

void	free_world(t_world *world)
{
	free(world->camera);
	free_shapes(world->shapes);
	free_lights(world->light);
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

void	free_canvas(t_canvas *canvas)
{
	int	i;

	if (!canvas)
		return ;
	i = 0;
	while (i < canvas->height)
	{
		free(canvas->pixels[i]);
		i++;
	}
	free(canvas->pixels);
	free(canvas);
}
