/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_reflection.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:46:43 by mdomnik           #+#    #+#             */
/*   Updated: 2024/11/30 18:25:46 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_REFLECTION_H
# define DEF_REFLECTION_H

t_color3	reflected_color(t_world *world, t_comp *comps, int remaining);
t_color3	refracted_color(t_world *world, t_comp *comps, int remaining);

#endif //DEF_REFLECTION_H
