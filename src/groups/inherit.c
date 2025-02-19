/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inherit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 20:32:30 by mdomnik           #+#    #+#             */
/*   Updated: 2025/01/16 20:55:24 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

void inherit_material(t_shape *group)
{
	t_material	material;
	t_shape		*child;
	
	material = group->material;
	material.pattern = NULL;
	material.bump_map = NULL;
	child = group->children;
	while (child)
	{
		child->material = material;
		if(child->type == GROUP)
			inherit_material(child);
		child = child->next;
	}
}
