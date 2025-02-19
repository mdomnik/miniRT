/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:33:02 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/19 18:59:52 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTION_H
# define INTERSECTION_H

//intersect_and_hit.c
t_x		*intersect(t_shape *shape, t_ray *ray);
t_x		*local_intersect(t_shape *shape, t_ray *ray);
t_i		hit(t_x *xs);
t_x		*intersect_world(t_world *world, t_ray *ray);

//intersect_basic_obj.c
t_x		*intersect_sphere(t_shape *sphere, t_ray *ray);
t_x		*intersect_plane(t_shape *plane, t_ray *ray);
t_x		*intersect_cylinder(t_shape *cylinder, t_ray *ray);

//intersect_cap_obj.c
t_x		*intersect_caps(t_shape *cylinder, t_ray *ray, t_x *xs);
t_x		*intersect_caps_cone(t_shape *cone, t_ray *ray, t_x *xs);
void	apply_cap_transformation(t_shape *cone, t_matrix *transform);

//intersect_complex_obj.c
t_x		*intersect_cone(t_shape *cone, t_ray *ray);
t_x		*intersect_cube(t_shape *cube, t_ray *ray);
t_x		*intersect_group(t_shape *group, t_ray *ray);
t_x		*intersect_triangle(t_shape *shape, t_ray *ray);

//intersect_op.c
t_i		create_intersection(float t, t_shape *shape);
t_x		*add_intersection(t_x *xs, float t, t_shape *shape);
t_x		*join_intersections(int num_x, t_x *xs, t_x *temp_xs);
void	sort_intersections(t_x *xs);

#endif

