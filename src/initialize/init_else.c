/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_else.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:29:09 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/23 16:32:26 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

t_material	default_material(void)
{
	t_material	material;

	material.color = add_tuple(new_color3(0, 0, 0),
			global_color('g', new_color3(0, 0, 0)));
	material.pattern = NULL;
	material.ambient = current_ambient('g', 0);
	material.diffuse = 0.9;
	material.specular = 0.9;
	material.shininess = 200.0;
	material.reflective = 0;
	material.transparency = 0.0;
	material.refractive_index = 1.0;
	material.bump_map = NULL;
	return (material);
}

t_size_cap	default_size_cap(void)
{
	t_size_cap	size_cap;

	size_cap.min = -0.5;
	size_cap.max = 0.5;
	size_cap.cap = 1;
	return (size_cap);
}
