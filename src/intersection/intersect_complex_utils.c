/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_complex_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-04 17:36:39 by astavrop          #+#    #+#             */
/*   Updated: 2025-03-04 17:36:39 by astavrop         ###   ########:w        */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

void	calculate_t_values(float t[2], float values[2], int bounds[2])
{
	float	tmin_numerator;
	float	tmax_numerator;
	float	temp;

	tmin_numerator = (bounds[MIN] - values[0]);
	tmax_numerator = (bounds[L_MAX] - values[0]);
	if (fabsf(values[1]) >= EPSILON)
	{
		t[TMIN] = tmin_numerator / values[1];
		t[TMAX] = tmax_numerator / values[1];
	}
	else
	{
		t[TMIN] = tmin_numerator * INFINITY;
		t[TMAX] = tmax_numerator * INFINITY;
	}
	if (t[TMIN] > t[TMAX])
	{
		temp = t[TMIN];
		t[TMIN] = t[TMAX];
		t[TMAX] = temp;
	}
}

float	check_axis(float origin, float direction, bool ret, int bounds[2])
{
	float	t[2];
	float	values[2];

	values[0] = origin;
	values[1] = direction;
	calculate_t_values(t, values, bounds);
	if (ret)
		return (t[TMAX]);
	return (t[TMIN]);
}

t_x	*handle_zero_a(float v[8], t_shape *cone, t_ray *ray)
{
	t_x	*xs;

	xs = malloc(sizeof(t_x));
	xs->count = 0;
	xs->i = malloc(sizeof(t_i) * 2);
	if (fabsf(v[LOCAL_B]) < EPSILON)
		return (free(xs->i), free(xs), NULL);
	v[T0] = -v[C] / (2 * v[LOCAL_B]);
	v[Y0] = ray->orig.y + v[T0] * ray->dir.y;
	if (cone->size_cap.min <= v[Y0] && v[Y0] <= cone->size_cap.max)
		xs = add_intersection(xs, v[T0], cone);
	return (xs);
}

t_x	*handle_discriminant(float v[8], t_shape *cone, t_ray *ray)
{
	t_x	*xs;

	xs = malloc(sizeof(t_x));
	xs->count = 0;
	xs->i = malloc(sizeof(t_i) * 2);
	v[T0] = (-v[LOCAL_B] - sqrtf(v[DISC])) / (2 * v[A]);
	v[T1] = (-v[LOCAL_B] + sqrtf(v[DISC])) / (2 * v[A]);
	if (v[T0] > v[T1])
		ft_swap(&v[T0], &v[T1]);
	v[Y0] = ray->orig.y + v[T0] * ray->dir.y;
	v[Y1] = ray->orig.y + v[T1] * ray->dir.y;
	if (cone->size_cap.min <= v[Y0] && v[Y0] <= cone->size_cap.max)
		xs = add_intersection(xs, v[T0], cone);
	if (cone->size_cap.min <= v[Y1] && v[Y1] <= cone->size_cap.max)
		xs = add_intersection(xs, v[T1], cone);
	xs = intersect_caps_cone(cone, ray, xs);
	if (xs->count == 0)
		return (free(xs->i), free(xs), NULL);
	return (xs);
}

t_x	*handle_child_intersection(t_x *xs, t_x *temp_xs)
{
	if (xs == NULL)
		return (temp_xs);
	xs = join_intersections((xs->count + temp_xs->count), xs, temp_xs);
	return (xs);
}
