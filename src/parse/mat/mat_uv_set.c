/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_uv_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:25:46 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/26 15:10:02 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

void	set_uv_pattern(t_shape *shape)
{
	t_pattern	*pattern;
	t_pattern	*end_pattern;

	pattern = shape->material.pattern;
	end_pattern = new_pattern(pattern->type, pattern->a, pattern->b);
	set_pattern_transform(end_pattern, pattern->transform);
	free(pattern);
	shape->material.pattern = end_pattern;
}
