/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:58:36 by astavrop          #+#    #+#             */
/*   Updated: 2024/09/17 18:49:34 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "vec3.h"
# include "ray.h"
# include "data_types.h"

# define R 0
# define G 1
# define B 2

typedef struct s_color	t_color;

struct s_color
{
	union {
		int		a[3];
		struct {
			int	r;
			int	g;
			int	b;
		};
	};
};

t_color		ray_color(t_ray *r);
int			write_color(int fd, t_color *pixel_color);

#endif /* COLOR_H */
