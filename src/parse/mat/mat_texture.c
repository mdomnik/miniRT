/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:29:18 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/26 12:15:05 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

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
		free(str);
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
	free(str);
	return (0);
}

static void set_material_pattern(char *type, char *colors, char *transforms, t_material *mat)
{
	t_pattern *pattern;

	pattern = malloc(sizeof(t_pattern));
	if (pattern_get_color(colors, mat->pattern))
	
}