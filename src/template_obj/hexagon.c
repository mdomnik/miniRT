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

static t_shape	*hexagon_corner(void)
{
	t_shape	*corner;

	corner = sphere();
	set_transform(corner, multiply_matrices(
			translation(0, 0, -1), scaling(0.25, 0.25, 0.25)));
	return (corner);
}

static t_shape	*hexagon_edge(void)
{
	t_shape		*edge;
	t_matrix	transform;
	t_matrix	rotation;
	t_matrix	temp;

	edge = cylinder();
	edge->size_cap.min = 0;
	edge->size_cap.max = 1;
	rotation = multiply_matrices(rotation_y(-M_PI / 6), rotation_z(-M_PI / 2));
	temp = multiply_matrices(translation(0, -1, -1), rotation);
	transform = multiply_matrices(temp, scaling(0.25, 1, 0.25));
	set_transform(edge, transform);
	return (edge);
}

static t_shape	*hexagon_side(void)
{
	t_shape	*side;

	side = group();
	add_child(side, hexagon_corner());
	add_child(side, hexagon_edge());
	return (side);
}

t_shape	*hexagon(void)
{
	t_shape	*hex;
	t_shape	*side;
	int		n;

	hex = group();
	n = 6;
	while (n > 0)
	{
		side = hexagon_side();
		set_transform(side, rotation_y(n * M_PI / 3));
		add_child(hex, side);
		n--;
	}
	return (hex);
}
