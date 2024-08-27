/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:12:52 by astavrop          #+#    #+#             */
/*   Updated: 2024/08/27 20:54:57 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "vec3.h"
# include "ray.h"

# include <stdbool.h>

typedef struct s_sphere	t_sphere;
typedef struct s_plane	t_plane;

/* SPHERE */

struct	s_sphere
{
	t_point3	center;
	float		radius;
};

t_sphere			sphere(t_point3 c, float r);
bool				hit_sphere(const t_sphere *s, t_ray *r);

/* PLANE */

struct	s_plane
{
	t_point3	center;
	t_vec3		norm;
};

t_plane				plane(t_point3 center, t_vec3 norm);
bool				hit_plane(t_plane *p, t_ray *r);

#endif /* OBJECTS_H */
