/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:12:52 by astavrop          #+#    #+#             */
/*   Updated: 2024/08/26 17:22:21 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "vec3.h"
# include "ray.h"

# include <stdbool.h>

typedef struct s_sphere	t_sphere;

/* SPHERE */

struct	s_sphere
{
	t_point3	center;
	float		radius;
};

t_sphere			sphere(t_point3 c, float r);
bool				hit_sphere(const t_sphere *s, t_ray *r);

#endif /* OBJECTS_H */
