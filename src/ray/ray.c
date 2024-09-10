/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:44:11 by astavrop          #+#    #+#             */
/*   Updated: 2024/08/22 19:40:36 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ray.h"

t_ray	*ray_new(t_point3 *orig, t_vec3 *dir)
{
	t_ray	*ray;

	if (!orig || !dir)
	{
		ft_dprintf(2, "Error [%s:%d] dir or orig == NULL\n",
				(char *) __func__, __LINE__);
		return (NULL);
	}
	ray = gc_malloc(sizeof(*ray));
	if (!ray)
		return (ray);
	ray->orig = orig;
	ray->dir = dir;
	return (ray);
}

t_point3	*ray_at(t_ray *ray, double t)
{
	t_vec3		*dir;
	t_point3	*orig;

	dir = vec3_copy(ray->dir);
	if (!dir)
		return (NULL);
	orig = vec3_copy(ray->orig);
	if (!orig)
		return (NULL);
	v_vec3_mult(dir, t);
	v_vec3_add(orig, dir);
	gc_free_ptr((void **) &dir);
	return (orig);
}
