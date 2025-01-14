/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patterns.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:11:21 by mdomnik           #+#    #+#             */
/*   Updated: 2025/01/14 21:17:48 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

t_pattern *test_pattern(void)
{
	t_pattern *pattern;

	pattern = malloc(sizeof(t_pattern));
	pattern->type = STRIPE;
	pattern->a = new_color3_p(0, 1, 0);
	pattern->b = new_color3_p(1, 0, 0);
	pattern->transform = *init_identity_matrix(4);
	return (pattern);
}


t_pattern *new_pattern(t_pattern_type pattern, t_color3 *a, t_color3 *b)
{
	t_pattern *p;

	p = malloc(sizeof(t_pattern));
	p->type = pattern;
	p->a = a;
	p->b = b;
	p->transform = *init_identity_matrix(4);
	return (p);
}

void	set_pattern_transform(t_pattern *pattern, t_matrix *new_transform)
{
	int	i;
	int	j;
	t_matrix *transform;

	transform = &pattern->transform;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			transform->a[i][j] = new_transform->a[i][j];
			j++;
		}
		i++;
	}
}

//pattern at object
t_color3 *pattern_at_object(t_pattern *pattern, t_shape *shape, t_point3 *point)
{
	t_point3 object_space;
	t_point3 pattern_space;
	t_color3 *c;

	object_space = multiply_matrix_tuple(inverse(shape->transform), point);
	pattern_space = multiply_matrix_tuple(inverse(pattern->transform), &object_space);
	c = pattern_at(pattern, &pattern_space);
	return (c);
}

//pattern at
t_color3 *pattern_at(t_pattern *pattern, t_point3 *point)
{
	if (pattern->type == STRIPE)
		return stripe_at(pattern, point);
	if (pattern->type == GRADIENT)
		return gradient_at(pattern, point);
	if (pattern->type == RING)
		return ring_at(pattern, point);
	if (pattern->type == CHECKERS)
		return checkers_at(pattern, point);
	if (pattern->type == TEXTURE_MAP)
	{
        t_uv_val uv = pattern->uv_map(*point);
        
        // Check if uv_pattern is of type UV_IMAGE
        if (((t_pattern *)pattern->uv_pattern)->type == UV_IMAGE)
        {
            t_color3 color = uv_pattern_at_image((t_pattern *)pattern->uv_pattern, uv.u, uv.v);
            return new_color3_p(color.r, color.g, color.b);
        }
        else
        {
            t_uv *uv_pattern = (t_uv *)pattern->uv_pattern;
            t_color3 color = uv_pattern_at(uv_pattern, uv.u, uv.v);
            return new_color3_p(color.r, color.g, color.b);
        }
    }
	if (pattern->type == ALIGN_CHECK)
	{
        t_uv_val uv = pattern->uv_map(*point);
        t_uv_align_check *uv_pattern = (t_uv_align_check *)pattern->uv_pattern;
        t_color3 color = uv_pattern_at_align_check(uv_pattern, uv.u, uv.v);
        return new_color3_p(color.r, color.g, color.b);
    }
	if (pattern->type == CUBE_MAP)
	{
        t_color3 color = pattern_at_cube_map(pattern, *point);
        return new_color3_p(color.r, color.g, color.b);
    }
    fprintf(stderr, "Error: Unsupported pattern type.\n");
    exit(EXIT_FAILURE);
}

