/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_format_op.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:08:04 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/11 23:27:10 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

static int	parse_color(char *color_str, t_color3 *color)
{
	char	**rgb;
	int		status;

	rgb = ft_split(color_str, ',');
	status = 0;
	if (!rgb[0] || !rgb[1] || !rgb[2])
		status = -1;
	else
		*color = new_color3(ft_atof(rgb[0]), ft_atof(rgb[1]), ft_atof(rgb[2]));
	free_double(rgb);
	return (status);
}

int	pattern_get_color(char *colors, t_pattern *pattern)
{
	char	*temp;
	char	**color_str;
	int		status;

	if (colors[0] != '{' || colors[ft_strlen(colors) - 1] != '}')
		return (-1);
	temp = ft_substr(colors, 1, ft_strlen(colors) - 2);
	color_str = ft_split(temp, '|');
	status = 0;
	if (!color_str[0] || !color_str[1])
		status = -1;
	else
	{
		if (parse_color(color_str[0], &pattern->a) == -1
			|| parse_color(color_str[1], &pattern->b) == -1)
			status = -1;
	}
	free_double(color_str);
	free(temp);
	return (status);
}

static int	apply_transform(char **transform_str, t_pattern *pattern)
{
	t_matrix	transform;
	char		**scale;
	char		**rotate;
	char		**translate;

	transform = init_identity_matrix(4);
	scale = ft_split(transform_str[0], ',');
	transform = multiply_matrices(transform,
			scaling(ft_atof(scale[0]), ft_atof(scale[1]), ft_atof(scale[2])));
	free_double(scale);
	rotate = ft_split(transform_str[1], ',');
	transform = multiply_matrices(transform, rotation_x(ft_atof(rotate[0])));
	transform = multiply_matrices(transform, rotation_y(ft_atof(rotate[1])));
	transform = multiply_matrices(transform, rotation_z(ft_atof(rotate[2])));
	free_double(rotate);
	translate = ft_split(transform_str[2], ',');
	transform = multiply_matrices(transform,
			translation(ft_atof(translate[0]), ft_atof(translate[1]),
				ft_atof(translate[2])));
	free_double(translate);
	set_pattern_transform(pattern, transform);
	return (0);
}

int	pattern_get_transform(char *transforms, t_pattern *pattern)
{
	char	*temp;
	char	**transform_str;
	int		status;

	if (transforms[0] != '{' || transforms[ft_strlen(transforms) - 1] != '}')
		return (-1);
	temp = ft_substr(transforms, 1, ft_strlen(transforms) - 2);
	transform_str = ft_split(temp, '|');
	status = 0;
	if (!transform_str[0] || !transform_str[1] || !transform_str[2])
		status = -1;
	else
		status = apply_transform(transform_str, pattern);
	free_double(transform_str);
	free(temp);
	return (status);
}
