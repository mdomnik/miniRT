/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_render.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 20:17:41 by mdomnik           #+#    #+#             */
/*   Updated: 2025/01/20 20:53:10 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_RENDER_H
# define DEF_RENDER_H

t_loop		*loop_init(void);
mlx_image_t	*render(mlx_t *mlx, t_camera *camera, t_world *world);
void	render_loop(void *param);
int	downscale_setting(int set, int quality);
int	supersampling_setting(int set, int quality);

#endif
