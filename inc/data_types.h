/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_types.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:37:23 by mdomnik           #+#    #+#             */
/*   Updated: 2024/08/30 18:29:51 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

#ifndef DATA_TYPES_H
# define DATA_TYPES_H

// STRING DATA TYPE STRUCT | 1
typedef struct s_string
{
	char	*string_value;
}	t_string;

// FLOAT DATA TYPE STRUCT | 2
typedef struct s_float
{
	double	float_value;
}	t_float;

// VECTOR DATA TYPE STRUCT | 4
typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}	t_vector;

// COLOR DATA TYPE STRUCT | 8
typedef struct s_color
{
	int		r;
	int		g;
	int		b;
}			t_color;

// RATIO DATA TYPE STRUCT | 16
typedef struct s_ratio
{
	double	range;
}			t_ratio;

// VECTOR RANGE DATA TYPE STRUCT | 32
typedef struct s_vector_range
{
	t_ratio		x;
	t_ratio		y;
	t_ratio		z;
}	t_vector_range;


// VALUE TYPE UNION
typedef union u_value_type
{
	t_string	string;
	t_float		float_value;
	t_vector	vector;
}	t_value_type;

// OBJECT TYPE UNION
typedef union u_data_type
{
	t_string	string;
	t_float		float_value;
	t_vector	vector;
	t_color		color;
	t_ratio		ratio;
	t_vector_range	vector_range;
}	t_data_type;

#endif
