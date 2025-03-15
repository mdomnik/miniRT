/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 01:41:10 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/15 18:30:17 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

static void	free_uv_image(t_uv_image *uv_img)
{
	t_canvas	*canvas;

	if (uv_img)
	{
		canvas = uv_img->canvas;
		if (canvas)
			free_canvas(canvas);
		free(uv_img);
	}
}

static void	free_single_pattern(t_pattern *pattern)
{
	t_pattern	*pat;
	t_uv_image	*uv_img;

	if (!pattern)
		return ;
	pat = (t_pattern *)pattern->uv_pattern;
	uv_img = (t_uv_image *)pat->uv_pattern;
	free_uv_image(uv_img);
	free(pat);
}

static void	free_cube_map(t_cube_map *cube_map)
{
	int			i;
	t_pattern	*pat;
	t_pattern	*p;
	t_uv_image	*uv_img;

	if (!cube_map)
		return ;
	i = 0;
	while (i < 6)
	{
		pat = cube_map->faces[i];
		p = (t_pattern *)pat->uv_pattern;
		uv_img = (t_uv_image *)p->uv_pattern;
		free_uv_image(uv_img);
		free(p);
		free(pat);
		i++;
	}
	free(cube_map);
}

void	free_pattern(t_pattern *pattern, t_shape *shape)
{
	if (!pattern)
		return ;
	if (pattern->simple == true)
	{
		if (pattern->is_checkers == true)
			free(pattern->uv_pattern);
		free(pattern);
		return ;
	}
	if (shape->type != CUBE && shape->type != SKYBOX)
		free_single_pattern(pattern);
	else
		free_cube_map((t_cube_map *)pattern->uv_pattern);
	free(pattern);
}

void	free_bump_map(t_bump_map *bump_map)
{
	if (!bump_map)
		return ;
	free_canvas(bump_map->height_map);
	free(bump_map);
}
