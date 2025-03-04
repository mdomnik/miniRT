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

#define T0 0
#define T1 1
#define Y0 2
#define Y1 3
#define A 4
#define LOCAL_B 5
#define C 6
#define DISC 7
#define TMIN 0
#define TMAX 1
#define X 0
#define Y 1
#define Z 2
#define MIN 0
#define L_MAX 1
#define DIR_CROSS_E2 0
#define P1_TO_ORIGIN 1
#define ORIGIN_CROSS_E1 2
#define DET 0
#define F 1
#define U 2
#define V 3
#define T 4

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

//ico_utils.c
void	ft_swap(float *a, float *b);

//intersect_complex_utils.c
void	calculate_t_values(float t[2], float values[2], int bounds[2]);
float	check_axis(float origin, float direction, bool ret, int bounds[2]);
t_x 	*handle_zero_a(float v[8], t_shape *cone, t_ray *ray);
t_x	    *handle_discriminant(float v[8], t_shape *cone, t_ray *ray);
t_x	    *handle_child_intersection(t_x *xs, t_x *temp_xs);

#endif
