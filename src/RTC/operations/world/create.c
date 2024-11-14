/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:40:23 by mdomnik           #+#    #+#             */
/*   Updated: 2024/11/13 13:55:41 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

t_world *create_world(t_object *objects, t_light_p *light)
{
	t_world *world;

	world = malloc(sizeof(t_world));
	world->objects = objects;
	world->light = light;
	return (world);
}
