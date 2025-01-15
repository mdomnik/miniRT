/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:47:10 by mdomnik           #+#    #+#             */
/*   Updated: 2025/01/15 22:53:30 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

void add_light(t_light_p **lights, t_light_p *new_light)
{
	t_light_p	*tmp;

	if(!*lights)
	{
		*lights = new_light;
		return ;
	}
	tmp = *lights;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_light;
}

void apply_cap_transformation(t_shape *cone, t_matrix *transform)
{
    // Extract translation and scaling from the transformation matrix
    float translate_y = transform->a[1][3];
    float scale_y = transform->a[1][1];

    // Apply scaling and translation to the min and max
    cone->size_cap.min = translate_y - 1;
    cone->size_cap.max = translate_y + (1.0 * scale_y) - 1;

    // Debug output
    printf("Updated cone min: %f\n", cone->size_cap.min);
    printf("Updated cone max: %f\n", cone->size_cap.max);
}




