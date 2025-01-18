/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_rays.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:43:46 by mdomnik           #+#    #+#             */
/*   Updated: 2024/11/26 18:11:01 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_RAYS_H
# define DEF_RAYS_H

//operations/rays/ray_normal.c
t_vec3	normal_at(t_shape *shape, t_point3 point);
t_vec3	local_normal_at(t_shape *shape, t_point3 *local_point);

//operations/rays/ray_reflect.c
t_vec3 reflect(t_vec3 in, t_vec3 normal);
t_light_p *new_light(t_point3 position, t_color3 intensity);
t_color3 lighting(t_material *m, t_shape *shape, t_light_p *light, t_point3 *point, t_vec3 eyev, t_vec3 normalv, bool in_shadow);

//operations/rays/ray.c
t_ray		*ray_new(t_point3 *orig, t_vec3 *dir);
t_point3	ray_position(t_ray *ray, float t);
t_ray		*ray_transform(t_ray *ray, t_matrix matrix);


#endif
