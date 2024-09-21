/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:58:36 by astavrop          #+#    #+#             */
/*   Updated: 2024/09/21 19:09:36 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

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

t_color		ray_color(t_ray *r, t_render *render);
int			write_color(int fd, t_color *pixel_color);

#endif /* COLOR_H */
