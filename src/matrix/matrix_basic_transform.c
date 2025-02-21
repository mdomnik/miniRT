/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_basic_transform.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 00:08:24 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/21 18:08:08 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"


//moves the unit object to a point in the scene
t_matrix	*translation(float x, float y, float z)
{
	t_matrix	*transform;

	transform = init_identity_matrix_p(4);
	transform->a[0][3] = x;
	transform->a[1][3] = y;
	transform->a[2][3] = z;
	return (transform);
}

//scales unit object by a factor
t_matrix	*scaling(float x, float y, float z)
{
	t_matrix	*transform;

	transform = init_identity_matrix_p(4);
	transform->a[0][0] = x;
	transform->a[1][1] = y;
	transform->a[2][2] = z;
	return (transform);
}

//rotates object on x axis
t_matrix	*rotation_x(float rad)
{
	t_matrix	*transform;

	transform = init_identity_matrix_p(4);
	transform->a[1][1] = cos(rad);
	transform->a[1][2] = -sin(rad);
	transform->a[2][1] = sin(rad);
	transform->a[2][2] = cos(rad);
	return (transform);
}

//rotates object on y axis
t_matrix	*rotation_y(float rad)
{
	t_matrix	*transform;

	transform = init_identity_matrix_p(4);
	transform->a[0][0] = cos(rad);
	transform->a[0][2] = sin(rad);
	transform->a[2][0] = -sin(rad);
	transform->a[2][2] = cos(rad);
	return (transform);
}

//rotates object on z axis
t_matrix	*rotation_z(float rad)
{
	t_matrix	*transform;

	transform = init_identity_matrix_p(4);
	transform->a[0][0] = cos(rad);
	transform->a[0][1] = -sin(rad);
	transform->a[1][0] = sin(rad);
	transform->a[1][1] = cos(rad);
	return (transform);
}
