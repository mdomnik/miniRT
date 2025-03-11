/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_basic_obj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:23:46 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/11 21:07:44 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

t_uv_val	spherical_map(t_point3 p)
{
	t_uv_val	uv;
	float		theta;
	float		radius;
	float		phi;
	float		raw_u;

	theta = atan2f(p.x, p.z);
	radius = sqrtf(p.x * p.x + p.y * p.y + p.z * p.z);
	phi = acosf(p.y / radius);
	raw_u = theta / (2.0f * M_PI);
	uv.u = 1.0f - (raw_u + 0.5f);
	uv.v = 1.0f - (phi / M_PI);
	return (uv);
}

t_uv_val	planar_map(t_point3 p)
{
	t_uv_val	uv;

	uv.u = fmodf(p.x, 1.0f);
	if (uv.u < 0)
		uv.u += 1.0f;
	uv.v = fmodf(p.z, 1.0f);
	if (uv.v < 0)
		uv.v += 1.0f;
	return (uv);
}

t_uv_val	cylindrical_map(t_point3 p)
{
	t_uv_val	uv;
	float		theta;
	float		raw_u;

	theta = atan2f(p.x, p.z);
	raw_u = theta / (2.0f * M_PI);
	uv.u = 1.0f - (raw_u + 0.5f);
	uv.v = fmodf(p.y, 1.0f);
	if (uv.v < 0.0f)
		uv.v += 1.0f;
	return (uv);
}
