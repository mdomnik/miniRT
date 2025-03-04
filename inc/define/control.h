/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:51:50 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/21 20:22:58 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROL_H
# define CONTROL_H

//control.c
int			program_state(bool set, int variable);
int			tooltip_state(bool set, int variable);
int			quality(bool set, int variable);
int			render_max(bool set, int variable);

//downscale.c
int			downscale_setting(int set, int quality);
// mlx_image_t	*render_downscale(mlx_t *mlx, t_camera *camera, t_world *world);

//hooks_helper.c
// void		movement_hooks(mlx_key_data_t keydata, t_loop *loop);
// void		state_hooks(mlx_key_data_t keydata, t_loop *loop);
// void		downscale_hooks(mlx_key_data_t keydata, t_loop *loop);

//hooks.c
// void		keyhook(mlx_key_data_t keydata, void* param);
void		scrollhook(double xdelta, double ydelta, void *param);
void		rotate_camera_up(t_loop *loop, int direction);
void		cursorhook(double xpos, double ypos, void *param);
// void		mousehook(mouse_key_t button, action_t action,
// 				modifier_key_t mods, void* param);

//super_sampling.c
int			supersampling_setting(int set, int quality);
t_ray		*ray_for_pixel_with_offset(t_camera *camera, float x_offset,
				float y_offset);
// mlx_image_t	*render_supersampling(mlx_t *mlx, t_camera *camera,
// 					t_world *world);

#endif
