/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:29:18 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/26 15:26:06 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

static void set_material_pattern(char *type, char *colors, char *transforms, t_material *mat);

int	check_texture_args(char *str, t_material *mat)
{
	int i;
	char **input;
	
	input = ft_split(str, ' ');
	i = 0;
	while (input[i] != NULL)
		i++;
	if (i < 2)
	{
		free_double(input);
		return (0);
	}
	if (ft_strncmp(input[0], "pattern:", ft_strlen(input[0])) == 0)
		set_material_pattern(input[1], input[2], input[3], mat);
	// if (ft_strncmp(input[0], "texture:", ft_strlen(input[0])) == 0)
	// 	set_material_texture(input[1], input[2], mat);
	// if (ft_strncmp(input[0], "skybox:", ft_strlen(input[0])) == 0)
	// 	set_material_skybox(input[1], input[2], mat);
	// if (ft_strncmp(input[0], "bump_map:", ft_strlen(input[0])) == 0)
	// 	set_material_bumpmap(input[1], mat);
	free_double(input);
	return (0);
}

static void set_material_pattern(char *type, char *colors, char *transforms, t_material *mat)
{
	t_pattern *pattern;

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
