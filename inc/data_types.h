/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_types.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:37:23 by mdomnik           #+#    #+#             */
/*   Updated: 2024/09/09 17:39:08 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_TYPES_H
# define DATA_TYPES_H

// STRING DATA TYPE STRUCT
typedef struct s_string
{
	char	*string_value;
}	t_string;

// FLOAT DATA TYPE STRUCT
typedef struct s_float
{
	double	float_value;
}	t_float;

// VECTOR DATA TYPE STRUCT
typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}	t_vector;

// COLOR DATA TYPE STRUCT
typedef struct s_color
{
	int		r;
	int		g;
	int		b;
}			t_color;

// VALUE TYPE UNION
typedef union u_value_type
{
	t_string	string;
	t_float		float_value;
	t_vector	vector;
}	t_value_type;

// VALUE NODE STRUCT
typedef struct s_value
{
	t_opts_type		type;
	t_value_type	value;
	struct s_value	*next;
}	t_value;

#endif
