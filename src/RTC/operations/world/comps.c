/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:09:58 by mdomnik           #+#    #+#             */
/*   Updated: 2024/11/19 20:18:09 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

//prepare computations
t_comp *prepare_computations(t_i *i, t_ray *ray)
{
	t_comp *comps;

	comps = malloc(sizeof(t_comp));
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
	comps->over_point = add_tuples(comps->point, mult_tuple(comps->normalv, EPSILON));
	return (comps);
}

//shade hit
t_color3 shade_hit(t_world *world, t_comp *comps)
{
	t_color3 color = new_color3(0, 0, 0);
	t_light_p *light_temp;
	
	light_temp = world->light;
	bool in_shadow;
	if (comps->shape->type == SPHERE)
	{
		while(world->light != NULL)
		{
			in_shadow = is_shadowed(world, world->light->position, &comps->over_point);
			color = add_tuples(lighting(&comps->shape->material, world->light, &comps->over_point, comps->eyev, comps->normalv, in_shadow), color);
			world->light = world->light->next;
		}
		world->light = light_temp;
		return (color);
	}
	return(new_color3(0, 0, 0));
}

t_color3 color_at(t_world *world, t_ray *ray)
{
	t_x *xs;
	t_i i;
	t_comp *comps;
	t_color3 color;
	
	xs = intersect_world(world, ray);
	if (xs->count == 0)
	{
		free(xs->i);
		free(xs);
		return (new_color3(0, 0, 0));
	}
	i = hit(xs);
	comps = prepare_computations(&i, ray);
	color = shade_hit(world, comps);
	free(xs->i);
	free(xs);
	free(comps);
	return (color);	
}

bool is_shadowed(t_world *world, t_point3 *light_pos, t_point3 *point)
{
	t_vec3 v = sub_tuple_p(light_pos, point);
	float distance = magnitude(v);
	t_vec3 direction = normalize(v);

	t_ray *r = ray_new(point, &direction);
	t_x *xs = intersect_world(world, r);
	t_i h = hit(xs);
	if (h.t > 0 && h.t < distance)
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



