/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_image.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:44:55 by mdomnik           #+#    #+#             */
/*   Updated: 2025/01/14 22:24:16 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_IMAGE_H
# define DEF_IMAGE_H

t_canvas *canvas_new(int width, int height);
void write_pixel(t_canvas *canvas, int x, int y, t_color3 color);
t_color3 pixel_at(t_canvas *canvas, int x, int y);
void canvas_to_ppm(t_canvas *canvas, char *filename);
t_canvas *canvas_from_ppm(const char *filename);

t_bump_map *bump_map_from_ppm(const char *filename, double scale, t_uv_val (*uv_maps)(t_point3));
t_vec3 perturb_normal(t_shape *shape, t_point3 *local_point, t_vec3 local_normal);


#endif
