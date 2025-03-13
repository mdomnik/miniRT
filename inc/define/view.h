/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artem <artem@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:32:19 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/13 20:12:11 by artem            ###   ########.fr       */
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

//rotate_xyz.c
t_vec3	    rotate_x(t_vec3 v, double angle);
t_vec3	    rotate_y(t_vec3 v, double angle);
t_vec3	    rotate_z(t_vec3 v, double angle);

#endif
