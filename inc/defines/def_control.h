/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_control.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:28:44 by mdomnik           #+#    #+#             */
/*   Updated: 2025/01/20 22:32:45 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_CONTROL_H
# define DEF_CONTROL_H

void my_keyhook(mlx_key_data_t keydata, void* param);
void my_scrollhook(double xdelta, double ydelta, void* param);
void my_cursorhook(double xpos, double ypos, void* param);
void my_mousehook(mouse_key_t button, action_t action, modifier_key_t mods, void* param);

void	get_pixel_size(t_camera *camera);


#endif
