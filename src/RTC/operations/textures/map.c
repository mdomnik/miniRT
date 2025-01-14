/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 20:08:24 by mdomnik           #+#    #+#             */
/*   Updated: 2024/12/08 18:24:49 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

t_uv_val spherical_map(t_point3 p)
{
	t_uv_val uv;

	float theta = atan2f(p.x, p.z);
	float radius = sqrtf(p.x * p.x + p.y * p.y + p.z * p.z);
	float phi = acosf(p.y / radius);
	float raw_u = theta / (2.0f * M_PI);
	uv.u = 1.0f - (raw_u + 0.5f);
	uv.v = 1.0f - (phi / M_PI);

	return (uv);
}

t_uv_val planar_map(t_point3 p)
{
	t_uv_val uv;

	uv.u = fmodf(p.x, 1.0f);
	if (uv.u < 0) uv.u += 1.0f;
	uv.v = fmodf(p.z, 1.0f);
	if (uv.v < 0) uv.v += 1.0f;
	return (uv);
}

t_uv_val cylindrical_map(t_point3 p)
{
	t_uv_val uv;

	float theta = atan2f(p.x, p.z);
	float raw_u = theta / (2.0f * M_PI);

	uv.u = 1.0f - (raw_u + 0.5f);
	uv.v = fmodf(p.y, 1.0f);
	if (uv.v < 0.0f) uv.v += 1.0f;
	return (uv);
}

