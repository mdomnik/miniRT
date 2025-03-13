/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 22:08:35 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/13 22:14:11 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

static t_pattern	*load_texture(char *filename,
		t_uv_val (*map_func)(t_point3))
{
	return (texture_map(uv_image(canvas_from_ppm(filename)), map_func));
}

static void	set_cube_texture(char *filename, t_material *mat)
{
	t_pattern	*side[6];
	int			i;

	i = 0;
	while (i < 6)
	{
		side[i] = load_texture(filename, planar_map);
		i++;
	}
	mat->pattern = new_cube_map(side);
}

static void	apply_texture(char *filename, t_material *mat, t_shape *shape)
{
	if (shape->type == SPHERE)
		mat->pattern = texture_map_sphere(uv_image(canvas_from_ppm(filename)),
				spherical_map);
	else if (shape->type == PLANE)
		mat->pattern = load_texture(filename, planar_map);
	else if (shape->type == CYLINDER || shape->type == CONE
		|| shape->type == HOURGLASS)
		mat->pattern = load_texture(filename, cylindrical_map);
	else if (shape->type == CUBE)
		set_cube_texture(filename, mat);
}

void	set_texture(char *type, char *transform, t_material *mat,
				t_shape *shape)
{
	char	*filename;

	if (!transform)
		return ;
	filename = ft_strjoin("textures/", type);
	if (open(filename, O_RDONLY) == -1)
	{
		free(filename);
		return ;
	}
	apply_texture(filename, mat, shape);
	pattern_get_transform(transform, mat->pattern);
	if (shape->type == SPHERE)
		mat->pattern->sphere_scale = mat->pattern->transform.a[0][0];
	free(filename);
}
