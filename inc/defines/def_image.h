/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_image.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:44:55 by mdomnik           #+#    #+#             */
/*   Updated: 2025/01/14 00:42:14 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_IMAGE_H
# define DEF_IMAGE_H

t_canvas *canvas_new(int width, int height);
void write_pixel(t_canvas *canvas, int x, int y, t_color3 color);
t_color3 pixel_at(t_canvas *canvas, int x, int y);
void canvas_to_ppm(t_canvas *canvas, char *filename);
t_canvas *canvas_from_ppm(const char *filename);

#endif
