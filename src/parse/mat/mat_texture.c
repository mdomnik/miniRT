/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:29:18 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/13 22:09:40 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

static void	set_pattern(char *type, char *colors, char *transforms,
				t_material *mat);
static void	set_bump_map(char *type, char *transform, t_material *mat,
				t_shape *shape);

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
	if (ft_strncmp(input[0], "texture:", ft_strlen(input[0])) == 0)
		set_texture(input[1], input[2], mat, shape);
	else if (ft_strncmp(input[0], "pattern:", ft_strlen(input[0])) == 0)
		set_pattern(input[1], input[2], input[3], mat);
	if (ft_strncmp(input[0], "bump_map:", ft_strlen(input[0])) == 0)
		set_bump_map(input[1], input[2], mat, shape);
	free_double(input);
	return (0);
}

static void	set_pattern(char *type, char *colors, char *transforms,
				t_material *mat)
{
	t_pattern	*pattern;

	if (mat->pattern)
		return ;
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

static void	set_bump_map(char *type, char *transform, t_material *mat,
				t_shape *shape)
{
	char		*join;

	if (!transform)
		return ;
	join = ft_strjoin("bump_maps/", type);
	if (open(join, O_RDONLY) == -1)
		return ;
	if (shape->type == SPHERE)
		mat->bump_map = bump_map_from_ppm_sphere(join, mat->bump_map_scale,
				spherical_map);
	else if (shape->type == PLANE)
		mat->bump_map = bump_map_from_ppm(join, mat->bump_map_scale,
				planar_map);
	else if (shape->type == CYLINDER || shape->type == CONE
		|| shape->type == HOURGLASS)
		mat->bump_map = bump_map_from_ppm(join, mat->bump_map_scale,
				cylindrical_map);
	else if (shape->type == CUBE || shape->type == GROUP)
		return (free(join));
	bump_map_get_transform(transform, mat->bump_map);
	if (shape->type == SPHERE)
		mat->bump_map->sphere_scale = mat->bump_map->transform.a[0][0];
	free(join);
}
