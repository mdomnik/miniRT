/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   materials.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:58:12 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/12 12:31:38 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIALS_H
# define MATERIALS_H

# define PARAM_LIST "ambient:0-1,diffuse:0-1,specular:0-1,shininess:10-200,\
reflection:0-1,transparency:0-1,refraction:1-3,bump_intensity:0-100,pattern:NULL,texture:NULL,bump_map:NULL"

# define PREDETERMINED_PATTERNS "stripe,gradient,ring,checkers"

# define PARAM_COUNT 8
# define FILE_PARAM_COUNT 2

//mat_format_op.c
int		pattern_get_type(char *type, t_pattern *pattern);
int		pattern_get_color(char *colors, t_pattern *pattern);
int		pattern_get_transform(char *transforms, t_pattern *pattern);

//mat_texture.c
int	check_texture_args(char *str, t_material *mat, t_shape *shape);

//mat_format.c
int	get_material(char *str, t_material *mat, t_shape *shape);

//mat_format_utils.c
int		validate_arg_chars(char *arg);
int		check_limits(char *param, float value);

//mat_skybox.c
int		get_skybox(char *str, t_material *mat);

//mat_uv_set.c
void	set_uv_pattern(t_shape *shape);

#endif
