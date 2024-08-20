/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:16:16 by astavrop          #+#    #+#             */
/*   Updated: 2024/08/20 21:25:53 by astavrop         ###   ########.fr       */
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

#endif /* RAYFT_H */
