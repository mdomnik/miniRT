/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:49:12 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/15 18:46:30 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

t_pattern	*new_pattern(t_pattern_type pattern, t_color3 a, t_color3 b)
{
	t_pattern	*p;

	p = malloc(sizeof(t_pattern));
	if (pattern)
		p->type = pattern;
	else
		p->type = FAIL;
	p->simple = false;
	p->a = a;
	p->b = b;
	p->transform = init_identity_matrix(4);
	return (p);
}

void	set_pattern_transform(t_pattern *pattern, t_matrix new_transform)
{
	int			i;
	int			j;
	t_matrix	*transform;

	transform = &pattern->transform;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			transform->a[i][j] = new_transform.a[i][j];
			j++;
		}
		i++;
	}
}

//pattern at object
t_color3	pattern_at_object(t_pattern *pattern,
	t_shape *shape, t_point3 *point)
{
	t_point3	object_space;
	t_point3	pattern_space;
	t_color3	c;

	object_space = multiply_matrix_tuple(inverse(shape->transform), *point);
	pattern_space = multiply_matrix_tuple
		(inverse(pattern->transform), object_space);
	c = pattern_at(pattern, &pattern_space, shape);
	return (c);
}

static t_color3	handle_texture_map(t_pattern *pattern,
		t_point3 *point, t_shape *shape)
{
	t_uv_val	uv;
	t_color3	color;
	t_uv		*uv_pattern;

	if (shape->type == SPHERE)
		uv = pattern->uv_map_sphere(*point, pattern->sphere_scale);
	else
		uv = pattern->uv_map(*point);
	if (pattern->simple == false)
	{
		color = uv_pattern_at_image((t_pattern *)pattern->uv_pattern,
				uv.u, uv.v);
		return (new_color3(color.r, color.g, color.b));
	}
	uv_pattern = (t_uv *)pattern->uv_pattern;
	color = uv_pattern_at(uv_pattern, uv.u, uv.v);
	return (new_color3(color.r, color.g, color.b));
}

t_color3	pattern_at(t_pattern *pattern, t_point3 *point, t_shape *shape)
{
	t_uv_val			uv;
	t_color3			color;
	t_uv_align_check	*uv_pattern_a;

	if (pattern->type == STRIPE)
		return (stripe_at(*pattern, point));
	if (pattern->type == GRADIENT)
		return (gradient_at(pattern, point));
	if (pattern->type == RING)
		return (ring_at(pattern, point));
	if (pattern->type == CHECKERS)
		return (checkers_at(pattern, point));
	if (pattern->type == TEXTURE_MAP)
		return (handle_texture_map(pattern, point, shape));
	if (pattern->type == ALIGN_CHECK)
	{
		uv = pattern->uv_map(*point);
		uv_pattern_a = (t_uv_align_check *)pattern->uv_pattern;
		color = uv_pattern_at_align_check(uv_pattern_a, uv.u, uv.v);
		return (new_color3(color.r, color.g, color.b));
	}
	if (pattern->type == CUBE_MAP)
		return (pattern_at_cube_map(pattern, *point));
	ft_dprintf(2, "Error: Unsupported pattern type.\n");
	exit(EXIT_FAILURE);
}
