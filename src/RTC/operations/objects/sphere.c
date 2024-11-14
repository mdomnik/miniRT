/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:17:22 by mdomnik           #+#    #+#             */
/*   Updated: 2024/11/14 17:44:53 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

// Create a new sphere object
t_sphere	*sphere_new(void)
{
	t_sphere	*sphere;
	static int	id = 0;

	sphere = malloc(sizeof(t_sphere));
	sphere->id = id++;
	sphere->coords = new_point3(0, 0, 0);
	sphere->radius = 1;
	sphere->color = new_tuple(0, 0, 0, 0);
	sphere->transform = *init_identity_matrix(4);
	sphere->material = default_material();
	return (sphere);
}
