/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_basic_obj.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:54:28 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/22 18:10:23 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

#define IBO_A 0
#define IBO_B 1
#define IBO_C 2
#define IBO_DISC 3
#define IBO_T0 4
#define IBO_T1 5
#define IBO_Y0 6
#define IBO_Y1 7

static void	set_sphere_intersections(t_x *xs, float v[4], t_shape *sphere)
{
	if (v[IBO_DISC] < 0)
	{
		xs->i[0].t = 0;
		xs->i[1].t = 0;
		xs->i[0].shape = NULL;
		xs->i[1].shape = NULL;
	}
	else
	{
		xs->count = 2;
		xs->i[0].t = (-v[IBO_B] - sqrt(v[IBO_DISC])) / (2 * v[IBO_A]);
		xs->i[1].t = (-v[IBO_B] + sqrt(v[IBO_DISC])) / (2 * v[IBO_A]);
		xs->i[0].shape = sphere;
		xs->i[1].shape = sphere;
	}
}

// Determines if given ray hit a sphere object
t_x	*intersect_sphere(t_shape *sphere, t_ray *ray)
{
	t_x		*xs;
	t_vec3	sphere_to_ray;
	float	v[4];

	xs = malloc(sizeof(t_x));
	xs->count = 0;
	xs->i = malloc(sizeof(t_i) * 2);
	sphere_to_ray = sub_tuple(ray->orig, new_point3(0, 0, 0));
	v[IBO_A] = dot_product(ray->dir, ray->dir);
	v[IBO_B] = 2 * dot_product(ray->dir, sphere_to_ray);
	v[IBO_C] = dot_product(sphere_to_ray, sphere_to_ray) - 1;
	v[IBO_DISC] = v[IBO_B] * v[IBO_B] - 4 * v[IBO_A] * v[IBO_C];
	set_sphere_intersections(xs, v, sphere);
	return (xs);
}

// Determines if given ray hit a plane object
t_x	*intersect_plane(t_shape *plane, t_ray *ray)
{
	t_x	*xs;

	xs = malloc(sizeof(t_x));
	if (!xs)
		return (NULL);
	xs->i = malloc(sizeof(t_i));
	if (!xs->i)
	{
		free(xs);
		return (NULL);
	}
	xs->count = 0;
	if (fabs(ray->dir.y) < EPSILON)
	{
		free(xs->i);
		free(xs);
		return (NULL);
	}
	xs->count = 1;
	xs->i[0].t = -ray->orig.y / ray->dir.y;
	xs->i[0].shape = plane;
	return (xs);
}

static t_x	*setup_cylinder_intersections(float v[8], t_shape *cylinder,
		t_ray *ray)
{
	t_x	*xs;

	xs = malloc(sizeof(t_x));
	xs->count = 0;
	xs->i = malloc(sizeof(t_i) * 2);
	v[IBO_Y0] = ray->orig.y + v[IBO_T0] * ray->dir.y;
	v[IBO_Y1] = ray->orig.y + v[IBO_T1] * ray->dir.y;
	if (cylinder->size_cap.min <= v[IBO_Y0] && v[IBO_Y0]
		<= cylinder->size_cap.max)
		xs = add_intersection(xs, v[IBO_T0], cylinder);
	if (cylinder->size_cap.min <= v[IBO_Y1] && v[IBO_Y1]
		<= cylinder->size_cap.max)
		xs = add_intersection(xs, v[IBO_T1], cylinder);
	xs = intersect_caps(cylinder, ray, xs);
	return (xs);
}

// Determines if given ray hit a cylinder object
t_x	*intersect_cylinder(t_shape *cylinder, t_ray *ray)
{
	float	v[8];

	v[IBO_A] = ray->dir.x * ray->dir.x + ray->dir.z * ray->dir.z;
	if (fabsf(v[IBO_A]) < EPSILON && cylinder->size_cap.cap == false)
		return (NULL);
	v[IBO_B] = 2 * (ray->orig.x * ray->dir.x + ray->orig.z * ray->dir.z);
	v[IBO_C] = ray->orig.x * ray->orig.x + ray->orig.z * ray->orig.z - 1;
	v[IBO_DISC] = v[IBO_B] * v[IBO_B] - 4 * v[IBO_A] * v[IBO_C];
	if (v[IBO_DISC] < 0)
		return (NULL);
	v[IBO_T0] = (-v[IBO_B] - sqrtf(v[IBO_DISC])) / (2 * v[IBO_A]);
	v[IBO_T1] = (-v[IBO_B] + sqrtf(v[IBO_DISC])) / (2 * v[IBO_A]);
	if (v[IBO_T0] > v[IBO_T1])
		ft_swap(&v[IBO_T0], &v[IBO_T1]);
	return (setup_cylinder_intersections(v, cylinder, ray));
}
