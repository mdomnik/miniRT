/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_to_faces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:21:30 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/13 21:42:36 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

int	isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

t_group	*create_group(const char *name)
{
	t_group	*g;

	g = malloc(sizeof(t_group));
	g->name = ft_strdup(name);
	g->group = group();
	g->next = NULL;
	return (g);
}

void	add_triangle_to_group(t_group *g, t_triangle *tri)
{
	void	*t;

	t = triangle(tri->p1, tri->p2, tri->p3);
	add_child(g->group, t);
}

void	add_group_to_default(t_obj_file *obj_file, t_group *group)
{
	t_group	*current;

	if (!obj_file->default_group)
		obj_file->default_group = group;
	else
	{
		current = obj_file->default_group;
		while (current->next)
			current = current->next;
		current->next = group;
	}
}

void	fan_triangulation(t_group *group, t_obj_file *obj_file,
		int *indices, int count)
{
	t_triangle	triangle;
	int			i;
	int			v1;
	int			v2;
	int			v3;

	if (count < 3)
	{
		ft_dprintf(2, "Face has fewer than 3 vertices, skipping\n");
		return ;
	}
	i = 0;
	while (i < count - 1)
	{
		v1 = indices[0];
		v2 = indices[i];
		v3 = indices[i + 1];
		if (v1 > 0 && v1 <= obj_file->vertex_count && v2 > 0
			&& v2 <= obj_file->vertex_count && v3 > 0
			&& v3 <= obj_file->vertex_count)
		{
			triangle.p1 = obj_file->vertices[v1];
			triangle.p2 = obj_file->vertices[v2];
			triangle.p3 = obj_file->vertices[v3];
			add_triangle_to_group(group, &triangle);
		}
		else
			ft_dprintf(2, "Face references out-of-bounds vertex indices\n");
		i++;
	}
}
