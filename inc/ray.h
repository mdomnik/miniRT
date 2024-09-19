/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:37:28 by astavrop          #+#    #+#             */
/*   Updated: 2024/08/24 18:53:39 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "vec3.h"

typedef struct s_ray	t_ray;

struct	s_ray
{
	t_point3	orig;
	t_vec3		dir;
};

t_ray		*ray_new(t_point3 *orig, t_vec3 *dir);
t_point3	*ray_at(t_ray *ray, double t);

#endif /* RAY_H */
