/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:32:19 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/10 15:26:36 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEW_H
# define VIEW_H

//camera_op.c
void		get_pixel_size(t_camera *camera);
t_camera	*camera_new(int hsize, int vsize, float fov);
void		ray_for_pixel(t_camera *camera, float px, float py, t_ray *ray);

//view_transformation.c
t_matrix	view_transformation(t_point3 from, t_vec3 orientation);

#endif
