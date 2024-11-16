/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:09:58 by mdomnik           #+#    #+#             */
/*   Updated: 2024/11/16 20:28:00 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

//prepare computations
t_comp *prepare_computations(t_i *i, t_ray *ray)
{
	t_comp *comps;

	comps = malloc(sizeof(t_comp));
	comps->t = i->t;
	comps->object = i->object;
	comps->point = ray_position(ray, comps->t);
	comps->eyev = neg_tuple(ray->dir);
	comps->normalv = normal_at(comps->object, comps->point);
	if (dot_product(comps->normalv, comps->eyev) < 0)
	{
		comps->inside = true;
		comps->normalv = neg_tuple(comps->normalv);
	}
	else
		comps->inside = false;
	return (comps);
}

//shade hit
t_color3 shade_hit(t_world *world, t_comp *comps)
{
	t_color3 color = new_color3(0, 0, 0);
	t_light_p *light_temp;
	
	light_temp = world->light;
	if (comps->object->type == SPHERE)
	{
		t_sphere *sphere = (t_sphere *)comps->object->object;	
		while(world->light != NULL)
		{
			color = add_tuples(lighting(sphere->material, world->light, &comps->point, comps->eyev, comps->normalv), color);
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



