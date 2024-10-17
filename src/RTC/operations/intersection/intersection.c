/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 05:02:00 by mdomnik           #+#    #+#             */
/*   Updated: 2024/10/17 15:57:31 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"


static t_x *intersect_sphere(t_object *object, t_sphere *sphere, t_ray *ray)
{
	t_x	*xs;
	t_vec3	sphere_to_ray;
	float	a;
	float	b;
	float	c;
	float	discriminant;
	t_ray	*ray_t;

	ray_t = ray_transform(ray, inverse(sphere->transform));
	xs = malloc(sizeof(t_x));
	xs->count = 0;
	xs->i = malloc(sizeof(t_i) * 2);
	sphere_to_ray = sub_tuple(ray_t->orig, sphere->coords);
	a = dot_product(ray_t->dir, ray_t->dir);
	b = 2 * dot_product(ray->dir, sphere_to_ray);
	c = dot_product(sphere_to_ray, sphere_to_ray) - 1;
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
	{
		xs->i[0].t = 0;
		xs->i[1].t = 0;
		xs->i[0].object = NULL;
		xs->i[1].object = NULL;
	}
	else
	{
		xs->count = 2;
		xs->i[0].t = (-b - sqrt(discriminant)) / (2 * a);
		xs->i[1].t = (-b + sqrt(discriminant)) / (2 * a);
		xs->i[0].object = object;
		xs->i[1].object = object;
	}
	return (xs);
}

// Intersect a ray with a sphere
t_x	*intersect(t_object *object, t_ray *ray)
{
	if (object->type == SPHERE)
		return (intersect_sphere(object, (t_sphere *)object->object, ray));
	return (NULL);
}

//intersect a ray with an object
t_i	intersection(float t, t_object *object)
{
	t_i	i;

	i.t = t;
	i.object = object;
	return (i);
}

t_x *intersections(int num_x, t_i i1, t_i i2, ...)
{
	t_x		*xs;
	va_list	args;
	t_i		i;

	xs = malloc(sizeof(t_x));
	xs->count = num_x;
	xs->i = malloc(sizeof(t_i) * num_x);
	xs->i[0].t = i1.t;
	xs->i[1].t = i2.t;
	xs->i[0].object = i1.object;
	xs->i[1].object = i2.object;
	va_start(args, i2);
	for (int j = 2; j < num_x; j++) {
		i = va_arg(args, t_i);
		xs->i[j].t = i.t;
		xs->i[j].object = i.object;
	}
	va_end(args);
	return (xs);
}

t_i hit(t_x *xs)
{
	t_i	i;
	int j;
	int		count;

	count = xs->count;
	i.t = 0;
	i.object = NULL;
	j = 0;
	while (j < count)
	{
		if (xs->i[j].t > 0)
		{
			if (i.object == NULL || xs->i[j].t < i.t)
				i = xs->i[j];
		}
		j++;
	}
	return (i);
}