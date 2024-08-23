/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:16:16 by astavrop          #+#    #+#             */
/*   Updated: 2024/08/22 21:43:25 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYFT_H
# define RAYFT_H

# include <math.h>
# include "../lib/libft/libft.h"

/* VEC3 */

# define X 0
# define Y 1
# define Z 2

typedef struct s_vec3	t_vec3;
typedef struct s_vec3	t_point3;

struct	s_vec3
{
	double	a[3];
};

t_vec3		*vec3_new(double x, double y, double z);
t_vec3		vec3(double x, double y, double z);
t_point3	point3(double x, double y, double z);

double		vec3_len_sq(t_vec3 *v);
double		vec3_len(t_vec3 *v);
double		dot(t_vec3 *u, t_vec3 *v);
t_vec3		*cross(t_vec3 *u, t_vec3 *v);
void		v_vec3_neg(t_vec3 *v);
void		v_vec3_add(t_vec3 *n, t_vec3 *m);
void		v_vec3_sub(t_vec3 *n, t_vec3 *m);
void		v_vec3_mult(t_vec3 *n, double t);
void		v_vec3_div(t_vec3 *n, double t);

t_vec3		*vec3_neg(t_vec3 *v);
t_vec3		*vec3_add(t_vec3 *n, t_vec3 *m);
t_vec3		*vec3_sub(t_vec3 *n, t_vec3 *m);
t_vec3		*vec3_mult(t_vec3 *n, double t);
t_vec3		*vec3_div(t_vec3 *n, double t);

void		v_vec3_unit(t_vec3 *v);
t_vec3		*vec3_unit(t_vec3 *v);
t_vec3		*vec3_copy(t_vec3 *orig);

int			vec3_print(t_vec3 *v, char *msg);

#endif /* RAYFT_H */
