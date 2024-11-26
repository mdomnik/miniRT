/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_patterns.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:12:10 by mdomnik           #+#    #+#             */
/*   Updated: 2024/11/26 18:12:05 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_PATTERNS_H	
# define DEF_PATTERNS_H

t_pattern *stripe_pattern(t_color3 *a, t_color3 *b);
t_color3 *stripe_at(t_pattern *pattern, t_point3 *point);
t_color3 *stripe_at_object(t_pattern *pattern, t_shape *shape, t_point3 *point);
void	set_pattern_transform(t_pattern *pattern, t_matrix *new_transform);


#endif //DEF_PATTERNS_H
