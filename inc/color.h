/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:58:36 by astavrop          #+#    #+#             */
/*   Updated: 2024/09/10 17:27:57 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "vec3.h"
# include "ray.h"

# define R 0
# define G 1
# define B 2

typedef struct s_vec3	t_colors;

t_colors		*ray_color(t_ray *r);
int			write_color(int fd, t_colors *pixel_color);

#endif /* COLOR_H */
