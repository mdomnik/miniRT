/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:35:59 by mdomnik           #+#    #+#             */
/*   Updated: 2024/11/13 13:38:53 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

t_material *default_material()
{
	t_material *material;

	material = malloc(sizeof(t_material));
	material->color = new_color3_p(1, 1, 1);
	material->ambient = 0.1;
	material->diffuse = 0.9;
	material->specular = 0.9;
	material->shininess = 200.0;
	return (material);
}
//default world
t_world	*default_world()
{
	t_world	*world;

	world = malloc(sizeof(t_world));
	world->objects = NULL;
	world->light = NULL;
	return (world);
}
