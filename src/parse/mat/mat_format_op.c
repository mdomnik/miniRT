/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_format_op.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:08:04 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/26 15:25:54 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

int pattern_get_type(char *type, t_pattern *pattern)
{
	int i;
	char **types;

	types = ft_split(PREDETERMINED_PATTERNS, ',');
	i = 0;
	while (types[i] != NULL)
	{
		if (ft_strncmp(type, types[i], ft_strlen(type)) == 0)
			break;
		i++;
	}
	if (types[i] == NULL)
	{
		free_double(types);
		return (-1);
	}
	if (ft_strncmp(types[i], "stripe", ft_strlen(types[i])) == 0)
		pattern->type = STRIPE;
	else if (ft_strncmp(types[i], "gradient", ft_strlen(types[i])) == 0)
		pattern->type = GRADIENT;
	else if (ft_strncmp(types[i], "ring", ft_strlen(types[i])) == 0)
		pattern->type = RING;
	else if (ft_strncmp(types[i], "checkers", ft_strlen(types[i])) == 0)
		pattern->type = CHECKERS;
	free_double(types);
	return (0);
}
int pattern_get_color(char *colors, t_pattern *pattern)
{
	if (colors[0] != '{' || colors[ft_strlen(colors) - 1] != '}')
		return (-1);
	char *temp = ft_substr(colors, 1, ft_strlen(colors) - 2);
	char **color_str = ft_split(temp, '|');
	if (color_str[0] == NULL || color_str[1] == NULL)
	{
		free_double(color_str);
		free(temp);
		return (-1);
	}
	char **rgb = ft_split(color_str[0], ',');
	if (rgb[0] == NULL || rgb[1] == NULL || rgb[2] == NULL)
	{
		free_double(color_str);
		free_double(rgb);
		free(temp);
		return (-1);
	}
	pattern->a = new_color3(ft_atof(rgb[0]), ft_atof(rgb[1]), ft_atof(rgb[2]));
	free_double(rgb);
	rgb = ft_split(color_str[1], ',');
	if (rgb[0] == NULL || rgb[1] == NULL || rgb[2] == NULL)
	{
		free_double(color_str);
		free_double(rgb);
		free(temp);
		return (-1);
	}
	pattern->b = new_color3(ft_atof(rgb[0]), ft_atof(rgb[1]), ft_atof(rgb[2]));
	free_double(rgb);
	free_double(color_str);
	free(temp);
	return (0);
}

int	pattern_get_transform(char *transforms, t_pattern *pattern)
{
	t_matrix transform;

	if (transforms[0] != '{' || transforms[ft_strlen(transforms) - 1] != '}')
		return (-1);
	char *temp = ft_substr(transforms, 1, ft_strlen(transforms) - 2);
	char **transform_str = ft_split(temp, '|');
	if (transform_str[0] == NULL || transform_str[1] == NULL || transform_str[2] == NULL)
	{
		free_double(transform_str);
		free(temp);
		return (-1);
	}
	transform = init_identity_matrix(4);
	char **scale = ft_split(transform_str[0], ',');
	transform = multiply_matrices(transform, scaling(ft_atof(scale[0]), ft_atof(scale[1]), ft_atof(scale[2])));
	free_double(scale);
	char **rotate = ft_split(transform_str[1], ',');
	transform = multiply_matrices(transform, rotation_x(ft_atof(rotate[0])));
	transform = multiply_matrices(transform, rotation_y(ft_atof(rotate[1])));
	transform = multiply_matrices(transform, rotation_z(ft_atof(rotate[2])));
	free_double(rotate);
	char **translate = ft_split(transform_str[2], ',');
	transform = multiply_matrices(transform, translation(ft_atof(translate[0]), ft_atof(translate[1]), ft_atof(translate[2])));
	set_pattern_transform(pattern, transform);
	free_double(transform_str);
	free(temp);
	return (0);	
}
