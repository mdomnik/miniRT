/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:16:16 by astavrop          #+#    #+#             */
/*   Updated: 2024/08/21 17:06:45 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYFT_H
# define RAYFT_H

# include <math.h>

/* VEC3 */

# define X 0
# define Y 1
# define Z 2

typedef struct s_vec3	t_vec3;

struct	s_vec3
{
	double	a[3];
};

t_vec3		*new_vec3(double x, double y, double z);
double		vec3_len_sq(t_vec3 *v);
double		vec3_len(t_vec3 *v);
double		dot(t_vec3 *u, t_vec3 *v);
t_vec3		*cross(t_vec3 *u, t_vec3 *v);
void		vec3_neg(t_vec3 *v);
void		vec3_add(t_vec3 *n, t_vec3 *m);
void		vec3_sub(t_vec3 *n, t_vec3 *m);
void		vec3_mult(t_vec3 *n, double t);
void		vec3_div(t_vec3 *n, double t);

#endif /* RAYFT_H */
