/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_objects.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:52:07 by mdomnik           #+#    #+#             */
/*   Updated: 2024/11/13 13:54:09 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_OBJECTS_H
# define DEF_OBJECTS_H


t_object	*object_new(void *object, t_object_type type);
void 		add_object(t_object **objects, t_object *new_object);

#endif
