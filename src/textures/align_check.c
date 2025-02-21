/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   align_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 20:16:01 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/21 18:10:46 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

t_uv_align_check	*uv_align_check(t_color3 main, t_color3 ul,
	t_color3 ur, t_color3 bl, t_color3 br)
{
	t_uv_align_check	*pattern;

	pattern = malloc(sizeof(t_uv_align_check));
	pattern->main = main;
	pattern->ul = ul;
	pattern->ur = ur;
	pattern->bl = bl;
	pattern->br = br;
	return (pattern);
}

t_color3	uv_pattern_at_align_check(t_uv_align_check *pattern,
	float u, float v)
{
	if (v > 0.8)
	{
		if (u < 0.2)
			return (pattern->ul);
		if (u > 0.8)
			return (pattern->ur);
	}
	else if (v < 0.2)
	{
		if (u < 0.2)
			return (pattern->bl);
		if (u > 0.8)
			return (pattern->br);
	}
	return (pattern->main);
}

t_pattern	*align_check_map(void *uv_pattern, t_uv_val (*uv_map)(t_point3))
{
	t_pattern	*pattern;

	pattern = malloc(sizeof(t_pattern));
	pattern->type = ALIGN_CHECK;
	pattern->uv_pattern = uv_pattern;
	pattern->uv_map = uv_map;
	pattern->transform = init_identity_matrix(4);
	pattern->a = (t_color3){0};
	pattern->b = (t_color3){0};
	return (pattern);
}
