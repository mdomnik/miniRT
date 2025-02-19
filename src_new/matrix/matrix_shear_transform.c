/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_shear_transform.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 03:08:40 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/19 13:08:18 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

//stretches the object on the x axis
t_matrix	*shearing_x(float y, float z)
{
	t_matrix	*transform;

	transform = init_identity_matrix(4);
	transform->a[0][1] = y;
	transform->a[0][2] = z;
	return (transform);
}

//stretches the object on the y axis
t_matrix	*shearing_y(float x, float z)
{
	t_matrix	*transform;

	transform = init_identity_matrix(4);
	transform->a[1][0] = x;
	transform->a[1][2] = z;
	return (transform);
}

//stretches the object on the z axis
t_matrix	*shearing_z(float x, float y)
{
	t_matrix	*transform;

	transform = init_identity_matrix(4);
	transform->a[2][0] = x;
	transform->a[2][1] = y;
	return (transform);
}

//sets the transformation to the object
void	set_transform(t_shape *shape, t_matrix *new_transform)
{
	int			i;
	int			j;
	t_matrix	*transform;

	transform = &shape->transform;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			transform->a[i][j] = new_transform->a[i][j];
			j++;
		}
		i++;
	}
	if (shape->type == CONE || shape->type == CYLINDER)
		shape->transform.a[1][3] += 1;
}
