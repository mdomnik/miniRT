/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:12:52 by astavrop          #+#    #+#             */
/*   Updated: 2024/09/15 14:02:17 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "vec3.h"
# include "ray.h"

# include <stdbool.h>

typedef struct s_sphere		t_sphere;
typedef struct s_plane		t_plane;
typedef struct s_cylinder	t_cylinder;

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

/* CYLINDER */

struct	s_cylinder
{
	t_vec3		center;
	t_vec3		axis;
	t_vec3		btop;
	t_vec3		bbottom;
	float		radius;
	float		height;
};

t_cylinder	cylinder(t_vec3 center, t_vec3 axis, float radius, float height);
bool		hit_cylinder(t_cylinder *cy, t_ray *r);

#endif /* OBJECTS_H */
