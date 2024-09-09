/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:35:40 by mdomnik           #+#    #+#             */
/*   Updated: 2024/09/09 15:11:40 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

t_light *append_light_list(t_light *list, t_light *new)
{
	t_light *current;

	if (list == NULL)
		return (new);
	current = list;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
	return (list);
}

t_sphere *append_sphere_list(t_sphere *sphere, t_sphere *new)
{
	t_sphere *current;

	if (sphere == NULL)
		return (new);
	current = sphere;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
	return (sphere);
}

t_plane *append_plane_list(t_plane *plane, t_plane *new)
{
	t_plane *current;

	if (plane == NULL)
		return (new);
	current = plane;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
	return (plane);
}
t_cylinder *append_cylinder_list(t_cylinder *cylinder, t_cylinder *new)
{
	t_cylinder *current;

	if (cylinder == NULL)
		return (new);
	current = cylinder;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
	return (cylinder);
}
