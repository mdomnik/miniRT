/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   materials.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:58:12 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/25 18:38:25 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIALS_H
# define MATERIALS_H

#define PARAM_LIST "ambient:0-1,diffuse:0-1,specular:0-1,shininess:10-200,reflection:0-1,transparency:0-1,refraction:1-3,bump_intensity:0-1"

#define FILE_PARAM "pattern:,bump_map:"

#define PARAM_COUNT 8
#define FILE_PARAM_COUNT 2

//mat_format.c
int	get_material(char *str, t_material *mat);

#endif
