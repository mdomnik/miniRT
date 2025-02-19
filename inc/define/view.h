/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view1.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:32:19 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/19 19:03:56 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEW_H
# define VIEW_H

//camera_op.c
void		get_pixel_size(t_camera *camera);
t_camera	*camera_new(int hsize, int vsize, float fov);
t_ray		*ray_for_pixel(t_camera *camera, int px, int py);

//render_loop.c
t_loop 		*loop_init(int ac, char *av[]);
mlx_image_t	*render_tooltip(mlx_t *mlx, t_camera *camera);
void		render_loop(void *param);

//view_transformation.c
t_matrix	view_transformation(t_point3 from, t_point3 to, t_vec3 up);

#endif
