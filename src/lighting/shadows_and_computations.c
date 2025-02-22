/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows_and_computations.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:08:27 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/22 18:38:57 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

//prepare computations
void	prepare_computations(t_i *i, t_ray *ray, t_x *xs, t_comp *comps)
{
	comps->t = i->t;
	comps->shape = i->shape;
	comps->point = ray_position(ray, comps->t);
	comps->eyev = neg_tuple(ray->dir);
	comps->normalv = normal_at(comps->shape, comps->point);
	if (dot_product(comps->normalv, comps->eyev) < 0)
	{
		comps->inside = true;
		comps->normalv = neg_tuple(comps->normalv);
	}
	else
		comps->inside = false;
	comps->over_point = add_tuple(comps->point, mult_tuple(comps->normalv, EPSILON));
	comps->under_point = sub_tuple(comps->point, mult_tuple(comps->normalv, EPSILON));
	comps->reflectv = reflect(ray->dir, comps->normalv);
	// transparency_and_refraction(i, comps, xs); reflection broken
	(void)xs; // needs to stay when we add reflection
}

t_color3	shade_hit(t_world *world, t_comp *comps, t_ray **ray, int remaining)
{
	t_color3	surface;
	t_color3	reflected;
	t_light_p	*light_temp;
	bool		in_shadow;

	light_temp = world->light;
	surface = new_color3(0, 0, 0);
	if (comps->shape->type != NONE)
	{
		while (world->light != NULL)
		{
			in_shadow = is_shadowed(world, &comps->over_point);
			surface = add_tuple(lighting(&comps->shape->material, comps->shape, world->light, &comps->over_point, comps->eyev, comps->normalv, in_shadow), surface);
			world->light = world->light->next;
		}
		world->light = light_temp;
		reflected = reflected_color(world, comps, ray, remaining);
		return (add_tuple(surface, reflected));
	}
	return (new_color3(0, 0, 0));
}

t_color3 color_at(t_world *world, t_ray **ray, t_comp *comp, int remaining)
{
	t_x			*xs;
	t_i			i;
	t_color3	color;

	xs = intersect_world(world, ray[RECURSIVE_DEPTH - remaining]);
	if (!xs) return new_color3(0, 0, 0);

	if (xs->count == 0)
	{
		free(xs->i);
		free(xs);
		return new_color3(0, 0, 0);
	}

	i = hit(xs);
	if (i.shape == NULL)
	{
		free(xs->i);
		free(xs);
		return new_color3(0, 0, 0);
	}

	prepare_computations(&i, ray[RECURSIVE_DEPTH - remaining], xs, comp);
	free(xs->i);
	free(xs);

	color = shade_hit(world, comp, ray, remaining);
	return color;
}


bool	is_shadowed(t_world *world, t_point3 *point)
{
	t_vec3		v;
	float		distance;
	t_vec3		direction;
	t_ray		*r;
	t_x			*xs;
	t_i			h;

	v = sub_tuple_p(&world->light->position, point);
	distance = magnitude(v);
	direction = normalize(v);
	r = ray_new(point, &direction);
	xs = intersect_world(world, r);
	h = hit(xs);
	if (h.t > EPSILON && h.t < distance)
	{
		free(xs->i);
		free(xs);
		free(r);
		return (true);
	}
	else
	{
		free(xs->i);
		free(xs);
		free(r);
		return (false);
	}
}
