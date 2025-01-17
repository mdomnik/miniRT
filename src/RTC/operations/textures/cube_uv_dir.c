/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_uv_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:21:41 by mdomnik           #+#    #+#             */
/*   Updated: 2025/01/17 20:08:16 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

static float	clamp_uv(float value)
{
	return (fmod(value + 2.0f, 2.0f) / 2.0f);
}

// UV mapping for the front face
t_uv_val	cube_uv_front(t_point3 point)
{
	t_uv_val	uv;

	uv.u = clamp_uv(point.x + 1.0f);
	uv.v = clamp_uv(point.y + 1.0f);
	return (uv);
}

// UV mapping for the back face
t_uv_val	cube_uv_back(t_point3 point)
{
	t_uv_val	uv;

	uv.u = clamp_uv(-point.x + 1.0f);
	uv.v = clamp_uv(point.y + 1.0f);
	return (uv);
}

// UV mapping for the left face
t_uv_val	cube_uv_left(t_point3 point)
{
	t_uv_val	uv;

	uv.u = clamp_uv(point.z + 1.0f);
	uv.v = clamp_uv(point.y + 1.0f);
	return (uv);
}

// UV mapping for the right face
t_uv_val	cube_uv_right(t_point3 point)
{
	t_uv_val	uv;

	uv.u = clamp_uv(1.0f - point.z);
	uv.v = clamp_uv(point.y + 1.0f);
	return (uv);
}

// UV mapping for the upper face
t_uv_val	cube_uv_up(t_point3 point)
{
	t_uv_val	uv;

	uv.u = clamp_uv(point.x + 1.0f);
	uv.v = clamp_uv(-point.z + 1.0f);
	return (uv);
}

// UV mapping for the lower face
t_uv_val	cube_uv_down(t_point3 point)
{
	t_uv_val	uv;

	uv.u = clamp_uv(point.x + 1.0f);
	uv.v = clamp_uv(point.z + 1.0f);
	return (uv);
}
