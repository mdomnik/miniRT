/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern_types.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 19:20:31 by mdomnik           #+#    #+#             */
/*   Updated: 2024/11/30 20:35:59 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

//stripe at
t_color3 *stripe_at(t_pattern *pattern, t_point3 *point)
{
	if ((int)floor(point->x) % 2 == 0)
		return (pattern->a);
	return (pattern->b);
}

t_color3 *gradient_at(t_pattern *pattern, t_point3 *point)
{
	t_color3 *distance;
	t_color3 *fraction;
	t_color3 *result;

	distance = sub_color(pattern->b, pattern->a);
	fraction = mult_color(distance, (point->x - floor(point->x)));
	result = add_tuples_p(pattern->a, fraction);
	return (result);
}

t_color3 *ring_at(t_pattern *pattern, t_point3 *point)
{
	if ((int)(sqrt(pow(point->x, 2) + pow(point->z, 2))) % 2 == 0)
		return (pattern->a);
	return (pattern->b);
}

t_color3 *checkers_at(t_pattern *pattern, t_point3 *point)
{
	if (((int)floor(point->x) + (int)floor(point->y) + (int)floor(point->z)) % 2 == 0)
		return (pattern->a);
	return (pattern->b);
}
