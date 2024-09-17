/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:35:40 by mdomnik           #+#    #+#             */
/*   Updated: 2024/09/17 18:59:15 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

/**
 * Appends a new light to the end of the light list.
 *
 * @param list The current light list.
 * @param new The new light to be appended.
 * @return The updated light list with the new light appended.
 */
t_light	*append_light_list(t_light *list, t_light *new)
{
	t_light	*current;

	if (list == NULL)
		return (new);
	current = list;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
	return (list);
}

/**
 * Appends a new sphere to the end of the sphere list.
 *
 * @param sphere The current sphere list.
 * @param new The new sphere to be appended.
 * @return The updated sphere list with the new sphere appended.
 */
t_sphere	*append_sphere_list(t_sphere *sphere, t_sphere *new)
{
	t_sphere	*current;

	if (sphere == NULL)
		return (new);
	current = sphere;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
	return (sphere);
}

/**
 * Appends a new plane to the end of the plane list.
 *
 * @param plane The head of the plane list.
 * @param new The plane to be appended.
 * @return The updated head of the plane list.
 */
t_plane	*append_plane_list(t_plane *plane, t_plane *new)
{
	t_plane	*current;

	if (plane == NULL)
		return (new);
	current = plane;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
	return (plane);
}

/**
 * Appends a new cylinder to the end of the cylinder list.
 *
 * @param cylinder The current cylinder list.
 * @param new The new cylinder to be appended.
 * @return The updated cylinder list with the new cylinder appended.
 */
t_cylinder	*append_cylinder_list(t_cylinder *cylinder, t_cylinder *new)
{
	t_cylinder	*current;

	if (cylinder == NULL)
		return (new);
	current = cylinder;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
	return (cylinder);
}
