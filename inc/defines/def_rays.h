/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_rays.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:43:46 by mdomnik           #+#    #+#             */
/*   Updated: 2024/10/17 07:04:15 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_RAYS_H
# define DEF_RAYS_H

//operations/rays/ray.c
t_ray		*ray_new(t_point3 *orig, t_vec3 *dir);
t_point3	ray_position(t_ray *ray, float t);
t_ray		*ray_transform(t_ray *ray, t_matrix *matrix);

#endif