/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_basic_ops.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 21:26:28 by astavrop          #+#    #+#             */
/*   Updated: 2024/08/22 17:41:15 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vec3.h"

void	v_vec3_neg(t_vec3 *v)
{
	v->a[X] = -v->a[X];
	v->a[Y] = -v->a[Y];
	v->a[Z] = -v->a[Z];
}

void	v_vec3_add(t_vec3 *n, t_vec3 *m)
{
	n->a[X] += m->a[X];
	n->a[Y] += m->a[Y];
	n->a[Z] += m->a[Z];
}

void	v_vec3_sub(t_vec3 *n, t_vec3 *m)
{
	n->a[X] -= m->a[X];
	n->a[Y] -= m->a[Y];
	n->a[Z] -= m->a[Z];
}

void	v_vec3_mult(t_vec3 *n, double t)
{
	n->a[X] *= t;
	n->a[Y] *= t;
	n->a[Z] *= t;
}

void	v_vec3_div(t_vec3 *n, double t)
{
	v_vec3_mult(n, 1 / t);
}
