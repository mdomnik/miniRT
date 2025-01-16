/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:36:39 by mdomnik           #+#    #+#             */
/*   Updated: 2025/01/16 17:32:34 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

void add_child(t_shape *group, t_shape *child)
{
	t_shape *temp;

	if (!child)
		return ;
	if (!group->children)
	{
		group->children = child;
		child->parent = group;
		group->children_count++;
		return ;
	}
	temp = group->children;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = child;
	child->parent = group;
	group->children_count++;
}

void add_shape_to_group(t_shape *group, t_shape *child) {
    if (!group->children) {
        group->children = child;
    } else {
        t_shape *current = group->children;
        while (current->next) {
            current = current->next;
        }
        current->next = child;
    }
    child->parent = group; // Set the child's parent
}

t_point3 world_to_object(t_shape *shape, t_point3 *point)
{
    t_point3 transformed_point = *point;
    if (shape->parent)
        transformed_point = world_to_object(shape->parent, &transformed_point);
    return multiply_matrix_tuple(inverse(shape->transform), &transformed_point);
}


t_vec3 normal_to_world(t_shape *shape, t_vec3 *normal)
{
    t_vec3 transformed_normal = multiply_matrix_tuple(transpose_matrix(inverse(shape->transform)), normal);
    transformed_normal.w = 0;
    transformed_normal = normalize(transformed_normal);

    if (shape->parent)
        transformed_normal = normal_to_world(shape->parent, &transformed_normal);

    return transformed_normal;
}
