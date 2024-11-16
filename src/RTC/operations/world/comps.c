/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:09:58 by mdomnik           #+#    #+#             */
/*   Updated: 2024/11/16 16:54:43 by mdomnik          ###   ########.fr       */
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
	t_color3 color;
	
	if (comps->object->type == SPHERE)
	{
		t_sphere *sphere = (t_sphere *)comps->object->object;			
		while(world->light != NULL)
		{
			printf("light->position: %f, %f, %f\n", world->light->position->x, world->light->position->y, world->light->position->z);
			color = add_tuples(lighting(sphere->material, world->light, &comps->point, comps->eyev, comps->normalv), color);
			printf("here\n");
			print_tuple(color);
			world->light = world->light->next;
			printf("light is not NULL\n");
		}
		printf("returning color\n");
		return (color);
	}
	return(new_color3(0, 0, 0));
}
