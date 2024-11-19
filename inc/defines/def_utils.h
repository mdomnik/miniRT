/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:45:30 by mdomnik           #+#    #+#             */
/*   Updated: 2024/11/19 15:42:42 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_UTILS_H
# define DEF_UTILS_H

//operations/utils/default.c
t_material *default_material(void);
t_world	*default_world(void);
t_world *test_world(void);

//operations/utils/utils_1.c
bool		is_equal(float a, float b);
float		deg_to_rad(float deg);
int			color_to_int(t_color3 color);

#endif
