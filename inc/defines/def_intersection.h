/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_intersection.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 05:13:40 by mdomnik           #+#    #+#             */
/*   Updated: 2025/01/15 16:04:51 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_INTERSECTION_H
# define DEF_INTERSECTION_H


float check_axis(float origin, float direction, bool ret);
t_x *intersect_caps(t_shape *cylinder, t_ray *ray, t_x *xs);
t_x *intersect_caps_cone(t_shape *cone, t_ray *ray, t_x *xs);
t_x *add_intersection(t_x *xs, float t, t_shape *shape);

t_x *intersect_sphere(t_shape *sphere, t_ray *ray);
t_x *intersect_plane(t_shape *plane, t_ray *ray);
t_x *intersect_cube(t_shape *cube, t_ray *ray);
t_x *intersect_cylinder(t_shape *cylinder, t_ray *ray);
t_x *intersect_cone(t_shape *cone, t_ray *ray);
t_x *intersect_group(t_shape *group, t_ray *ray);

t_x	*intersect(t_shape *shape, t_ray *ray);
t_x *local_intersect(t_shape *shape, t_ray *ray);
t_i	intersection(float t, t_shape *shape);
// t_x *intersections(int num_x, t_i i1, t_i i2, ...);
t_x *intersections(int num_x, t_x *xs, t_x *temp_xs);
t_i hit(t_x *xs);

#endif
