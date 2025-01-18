/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_patterns.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:12:10 by mdomnik           #+#    #+#             */
/*   Updated: 2024/11/30 18:50:26 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_PATTERNS_H	
# define DEF_PATTERNS_H

//operations/patterns/patterns.c
t_pattern *test_pattern(void);
t_pattern *new_pattern(t_pattern_type pattern, t_color3 a, t_color3 b);
void	set_pattern_transform(t_pattern *pattern, t_matrix *new_transform);
t_color3 pattern_at_object(t_pattern *pattern, t_shape *shape, t_point3 *point);
t_color3 pattern_at(t_pattern *pattern, t_point3 *point);

//operations/patterns/pattern_types.c
t_color3	stripe_at(t_pattern pattern, t_point3 *point);
t_color3	gradient_at(t_pattern *pattern, t_point3 *point);
t_color3	ring_at(t_pattern *pattern, t_point3 *point);
t_color3	checkers_at(t_pattern *pattern, t_point3 *point);

#endif //DEF_PATTERNS_H
