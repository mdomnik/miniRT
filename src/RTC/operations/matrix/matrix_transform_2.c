/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transform_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 03:08:40 by mdomnik           #+#    #+#             */
/*   Updated: 2024/10/17 14:31:28 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

t_matrix *shearing_x(float y, float z)
{
	t_matrix	*transform;

	transform = init_identity_matrix(4);
	transform->a[0][1] = y;
	transform->a[0][2] = z;
	return (transform);
}
t_matrix *shearing_y(float x, float z)
{
	t_matrix	*transform;

	transform = init_identity_matrix(4);
	transform->a[1][0] = x;
	transform->a[1][2] = z;
	return (transform);
}

t_matrix *shearing_z(float x, float y)
{
	t_matrix	*transform;

	transform = init_identity_matrix(4);
	transform->a[2][0] = x;
	transform->a[2][1] = y;
	return (transform);
}

//set transform
void	set_transform(t_matrix *transform, t_matrix *new_transform)
{
	int	i;
	int	j;

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
}