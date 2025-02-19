/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexagon.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:12:22 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/19 18:58:18 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

static t_shape *hexagon_corner(void)
{
	t_shape *corner;

	corner = sphere();
	set_transform(corner, multiply_matrices(translation(0, 0, -1), scaling(0.25, 0.25, 0.25)));
	return (corner);
}

static t_shape *hexagon_edge(void)
{
	t_shape *edge;

	edge = cylinder();
	edge->size_cap.min = 0;
	edge->size_cap.max = 1;
	set_transform(edge, multiply_matrices(multiply_matrices(translation(0, -1, -1), rotation_y(-M_PI / 6)), multiply_matrices(rotation_z(-M_PI / 2), scaling(0.25, 1, 0.25))));
	return (edge);
}

static t_shape *hexagon_side(void)
{
	t_shape *side;

	side = group();
	add_child(side, hexagon_corner());
	add_child(side, hexagon_edge());
	return (side);
}

t_shape *hexagon(void)
{
	t_shape *hex;
	int n;

	hex = group();
	n = 6;
	while(n > 0)
	{
		t_shape *side = hexagon_side();
		set_transform(side, rotation_y(n * M_PI / 3));
		add_child(hex, side);
		n--;
	}
	return (hex);
}
