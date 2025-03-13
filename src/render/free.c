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

void free_lights(t_light_p *light)
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

void free_canvas(t_canvas *canvas)
{
    int i;

    if (!canvas)
        return;

    // Free each row of the pixels array
    for (i = 0; i < canvas->height; i++)
    {
        free(canvas->pixels[i]);
    }

    // Free the pixels array itself
    free(canvas->pixels);

    // Free the canvas structure
    free(canvas);
}

void	free_pattern(t_pattern *pattern, t_shape *shape)
{
	t_pattern	*pat;
	t_uv_image	*uv_img;
	t_cube_map	*cube_map;
	t_pattern	*p;
	t_canvas	*canvas;

	if (!pattern)
		return ;
	if (pattern->simple == true)
	{
		free(pattern->uv_pattern);
		free(pattern);
		return ;
	}
	if (shape->type != CUBE && shape->type != SKYBOX)
	{
		pat = (t_pattern *)pattern->uv_pattern;
		uv_img = (t_uv_image *)pat->uv_pattern;
		if (uv_img && uv_img->canvas)
		{
			canvas = uv_img->canvas;
			free_canvas(canvas);
		}
		if (uv_img)
			free(uv_img);
		if (pat)
			free(pat);
	}
	else
	{
		cube_map = (t_cube_map *)pattern->uv_pattern;
		int i = 0;
		while (i < 6)
		{
			pat = cube_map->faces[i];
			p = (t_pattern *)pat->uv_pattern;
			uv_img = (t_uv_image *)p->uv_pattern;
			if (uv_img && uv_img->canvas)
			{
				canvas = uv_img->canvas;
				free_canvas(canvas);
			}
			if (uv_img)
				free(uv_img);
			if (p)
				free(p);
			if (pat)
				free(pat);
			i++;
		}
		free(cube_map);
	}
	free(pattern);
}

void free_bump_map(t_bump_map *bump_map)
{
	if (!bump_map)
		return ;
	free_canvas(bump_map->height_map);
	free(bump_map);
}