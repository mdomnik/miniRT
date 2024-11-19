/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_intersection.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 05:13:40 by mdomnik           #+#    #+#             */
/*   Updated: 2024/11/19 21:08:13 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_INTERSECTION_H
# define DEF_INTERSECTION_H

t_x	*intersect(t_shape *shape, t_ray *ray);
t_x *local_intersect(t_shape *shape, t_ray *ray);
t_i	intersection(float t, t_shape *shape);
// t_x *intersections(int num_x, t_i i1, t_i i2, ...);
t_x *intersections(int num_x, t_x *xs, t_x *temp_xs);
t_i hit(t_x *xs);

#endif
