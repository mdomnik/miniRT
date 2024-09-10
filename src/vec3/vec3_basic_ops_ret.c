/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_basic_ops_ret.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:42:02 by astavrop          #+#    #+#             */
/*   Updated: 2024/08/22 19:34:04 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vec3.h"

t_vec3	*vec3_neg(t_vec3 *v)
{
	t_vec3	*ret;

	ret = vec3_new(-v->a[X], -v->a[Y], -v->a[Z]);
	return (ret);
}

t_vec3	*vec3_add(t_vec3 *n, t_vec3 *m)
{
	t_vec3	*ret;

	ret = vec3_new(n->a[X] + m->a[X], n->a[Y] + m->a[Y], n->a[Z] + m->a[Z]);
	return (ret);
}

t_vec3	*vec3_sub(t_vec3 *n, t_vec3 *m)
{
	t_vec3	*ret;

	ret = vec3_new(n->a[X] - m->a[X], n->a[Y] - m->a[Y], n->a[Z] - m->a[Z]);
	return (ret);
}

t_vec3	*vec3_mult(t_vec3 *n, double t)
{
	t_vec3	*ret;

	ret = vec3_new(n->a[X] * t, n->a[Y] * t, n->a[Z] * t);
	return (ret);
}

t_vec3	*vec3_div(t_vec3 *n, double t)
{
	return (vec3_mult(n, 1 / t));
}
