/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:29:18 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/11 19:44:10 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

static void	set_pattern(char *type, char *colors, char *transforms,
				t_material *mat);
static void	set_texture(char *type, char *transforms, t_material *mat, t_shape *shape);

int	check_texture_args(char *str, t_material *mat, t_shape *shape)
{
	int		i;
	char	**input;

	input = ft_split(str, ' ');
	i = 0;
	while (input[i] != NULL)
		i++;
	if (i < 2)
	{
		free_double(input);
		return (0);
	}
	i = 0;
	if (ft_strncmp(input[0], "pattern:", ft_strlen(input[0])) == 0)
		set_pattern(input[1], input[2], input[3], mat);
	if (ft_strncmp(input[0], "texture:", ft_strlen(input[0])) == 0)
		set_texture(input[1], input[2], mat, shape);
	if (ft_strncmp(input[0], "bump_map:", ft_strlen(input[0])) == 0)
		set_bump_map(input[1], input[2], mat, shape);
	/*
	** Future implementations:
	** set_material_texture(input[1], input[2], mat);
	** set_material_bumpmap(input[1], mat);
	*/
	free_double(input);
	return (0);
}

static void	set_pattern(char *type, char *colors, char *transforms,
				t_material *mat)
{
	t_pattern	*pattern;

	pattern = malloc(sizeof(t_pattern));
	pattern->transform = init_identity_matrix(4);
	if (pattern_get_type(type, pattern) == -1)
	{
		free(pattern);
		return ;
	}
	if (pattern_get_color(colors, pattern) == -1)
	{
		free(pattern);
		return ;
	}
	div_color(pattern->a);
	div_color(pattern->b);
	if (pattern_get_transform(transforms, pattern) == -1)
	{
		free(pattern);
		return ;
	}
	mat->pattern = pattern;
}

static void	set_texture(char *type, char *transform, t_material *mat, t_shape *shape)
{
	char 		*join;
	int			i;

	if (!transform)
		return ;
	join = ft_strjoin("textures/", type);
	if (open(join, O_RDONLY) == -1)
		return ;
	if (shape->type == SPHERE)
		mat->pattern = texture_map(uv_image(canvas_from_ppm(join)), spherical_map);
	else if (shape->type == PLANE)
		mat->pattern = texture_map(uv_image(canvas_from_ppm(join)), planar_map);
	else if (shape->type == CYLINDER || shape->type == CONE || shape->type == HOURGLASS)
		mat->pattern = texture_map(uv_image(canvas_from_ppm(join)), cylindrical_map);
	else if (shape->type == CUBE)
	{
		t_pattern	*side[6];
		i = 0;
		while (i < 6)
		{
			side[i] = texture_map(uv_image(canvas_from_ppm(join)), planar_map);
			i++;
		}
		mat->pattern = new_cube_map(side);
	}
	pattern_get_transform(transform, mat->pattern);
	free(join);
}

static void	set_texture(char *type, char *transform, t_material *mat, t_shape *shape)
{
	char 		*join;
	int			i;

	if (!transform)
		return ;
	join = ft_strjoin("textures/", type);
	if (open(join, O_RDONLY) == -1)
		return ;
	if (shape->type == SPHERE)
		mat->pattern = texture_map(uv_image(canvas_from_ppm(join)), spherical_map);
	else if (shape->type == PLANE)
		mat->pattern = texture_map(uv_image(canvas_from_ppm(join)), planar_map);
	else if (shape->type == CYLINDER || shape->type == CONE || shape->type == HOURGLASS)
		mat->pattern = texture_map(uv_image(canvas_from_ppm(join)), cylindrical_map);
	else if (shape->type == CUBE)
	{
		t_pattern	*side[6];
		i = 0;
		while (i < 6)
		{
			side[i] = texture_map(uv_image(canvas_from_ppm(join)), planar_map);
			i++;
		}
		mat->pattern = new_cube_map(side);
	}
	pattern_get_transform(transform, mat->pattern);
	free(join);
}