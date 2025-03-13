/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   align_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 20:16:01 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/13 17:56:32 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

#define MAIN 0
#define UL 1
#define UR 2
#define BL 3
#define BR 4

t_uv_align_check	*uv_align_check(t_color3 colors[5])
{
	t_uv_align_check	*pattern;

	pattern = malloc(sizeof(t_uv_align_check));
	pattern->main = colors[MAIN];
	pattern->ul = colors[UL];
	pattern->ur = colors[UR];
	pattern->bl = colors[BL];
	pattern->br = colors[BR];
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
	pattern->simple = false;
	pattern->uv_pattern = uv_pattern;
	pattern->uv_map = uv_map;
	pattern->transform = init_identity_matrix(4);
	pattern->a = (t_color3){0};
	pattern->b = (t_color3){0};
	return (pattern);
}
