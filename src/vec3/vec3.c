/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:22:28 by astavrop          #+#    #+#             */
/*   Updated: 2024/08/22 19:33:56 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vec3.h"
#include "../../lib/libft/libft.h"

t_vec3	*vec3_new(double x, double y, double z)
{
	t_vec3	*v;

	v = gc_malloc(sizeof(*v));
	if (!v)
		return (NULL);
	v->a[X] = x;
	v->a[Y] = y;
	v->a[Z] = z;
	return (v);
}

double	vec3_len_sq(t_vec3 *v)
{
	return (
		v->a[X] * v->a[X]
		+ v->a[Y] * v->a[Y]
		+ v->a[Z] * v->a[Z]
	);
}

double	vec3_len(t_vec3 *v)
{
	return (sqrt(vec3_len_sq(v)));
}

double	dot(t_vec3 *u, t_vec3 *v)
{
	return (
		u->a[X] * v->a[X]
		+ u->a[Y] * v->a[Y]
		+ u->a[Z] * v->a[Z]
	);
}

t_vec3	*cross(t_vec3 *u, t_vec3 *v)
{
	t_vec3	*ret;

	ret = vec3_new(0, 0, 0);
	if (!ret)
		return (NULL);
	ret->a[X] = u->a[Y] * v->a[Z] - u->a[Z] * v->a[Y];
	ret->a[Y] = u->a[Z] * v->a[X] - u->a[X] * v->a[Z];
	ret->a[Z] = u->a[X] * v->a[Y] - u->a[Y] * v->a[X];
	return (ret);
}
