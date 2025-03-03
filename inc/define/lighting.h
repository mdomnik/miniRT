/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:07:30 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/25 20:41:13 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHTING_H
# define LIGHTING_H

//ambient.c
float		current_ambient(int flag, float value);
t_color3	global_color(int flag, t_color3 color);

//find_normal.c
t_vec3		normal_at(t_shape *shape, t_point3 point);

//light_and_reflect.c
t_vec3		reflect(t_vec3 in, t_vec3 normal);
t_color3	lighting(t_material *m, t_shape *shape, t_light_p *light,
				t_point3 *point, t_vec3 eyev, t_vec3 normalv, bool in_shadow);

//ray_op.c
t_ray		*ray_new(t_point3 *orig, t_vec3 *dir);
t_point3	ray_position(t_ray *ray, float t);
t_ray		*ray_transform(t_ray *ray, t_matrix matrix);

//reflection_and_refraction.c
t_color3	reflected_color(t_world *world, t_comp **comps,
				t_ray **ray, int remaining);
t_color3	refracted_color(t_world *world, t_comp *comps,
				int remaining);

//shadows_and_computations.c
void		prepare_computations(t_i *i, t_ray *ray, t_x *xs, t_comp *comps);
t_color3	shade_hit(t_world *world, t_comp **comps, t_ray **ray,
				int remaining);
t_color3	color_at(t_world *world, t_ray **ray, t_comp **comp, int remaining);
bool		is_shadowed(t_world *world, t_point3 *point);

//transparency.c
void		transparency_and_refraction(t_i *hit, t_comp *comp, t_x *xs);

#endif
