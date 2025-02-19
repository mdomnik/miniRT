/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_to_faces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:21:30 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/19 17:21:36 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

static t_group	*create_group(const char *name)
{
	t_group	*g;

	g = malloc(sizeof(t_group));
	g->name = ft_strdup(name);
	g->group = group();
	g->next = NULL;
	return (g);
}

static void	add_triangle_to_group(t_group *g, t_triangle *tri)
{
	t_shape	*t;

	t = triangle(tri->p1, tri->p2, tri->p3);
	add_child(g->group, t);
}

// Add a group to the default group chain
static void	add_group_to_default(t_obj_file *obj_file, t_group *group)
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

static void	fan_triangulation(t_group *group,
	t_obj_file *obj_file, int *indices, int count)
{
	int			i;
	int			v1;
	int			v2;
	int			v3;

	if (count < 3)
	{
		fprintf(stderr, "Face has fewer than 3 vertices, skipping\n");
		return ;
	}
	i = 0;
	while (i < count - 1)
	{
		v1 = indices[0];
		v2 = indices[i];
		v3 = indices[i + 1];
		if (v1 > 0 && v1 <= obj_file->vertex_count
			&& v2 > 0 && v2 <= obj_file->vertex_count
			&& v3 > 0 && v3 <= obj_file->vertex_count)
		{
				t_triangle	triangle = {
				.p1 = obj_file->vertices[v1],
				.p2 = obj_file->vertices[v2],
				.p3 = obj_file->vertices[v3]
			};
			add_triangle_to_group(group, &triangle);
		}
		else
			fprintf(stderr, "Face references out-of-bounds vertex indices\n");
		i++;
	}
}

t_obj_file	*parse_obj_file(const char *filename)
{
	t_obj_file	*obj_file;
	FILE		*file;
	t_group		*current_group;
	char		*line;
	size_t		len;
	float		x;
	float		y;
	float		z;
	char		group_name[64];
	t_group		*new_group;
	int			indices[64];
	int			count;
	char		*token;

	obj_file = malloc(sizeof(t_obj_file));
	obj_file->vertex_count = 0;
	obj_file->face_count = 0;
	obj_file->default_group = create_group("Default");
	file = fopen(filename, "r");
	if (!file)
	{
		fprintf(stderr, "Failed to open file: %s\n", filename);
		free(obj_file);
		exit(EXIT_FAILURE);
	}
	current_group = obj_file->default_group;
	line = NULL;
	len = 0;
	while (getline(&line, &len, file) != -1)
	{
		if (line[0] == 'v' && isspace(line[1]))
		{
			if (obj_file->vertex_count >= MAX_VERTEX_COUNT)
			{
				fprintf(stderr, "Exceeded maximum vertex count: %d\n",
					MAX_VERTEX_COUNT);
				break ;
			}
			if (sscanf(line, "v %f %f %f", &x, &y, &z) == 3)
			{
				obj_file->vertices[++obj_file->vertex_count] = new_point3
					(x, y, z);
			}
			else
				fprintf(stderr, "Malformed vertex line: %s\n", line);
		}
		else if (line[0] == 'g' && isspace(line[1]))
		{
			if (sscanf(line, "g %63s", group_name) == 1)
			{
				new_group = create_group(group_name);
				add_group_to_default(obj_file, new_group);
				current_group = new_group;
			}
			else
				fprintf(stderr, "Malformed group line: %s\n", line);
		}
		else if (line[0] == 'f' && isspace(line[1]))
		{
			count = 0;
			token = strtok(line + 2, " \t");
			while (token && count < 64)
			{
				if (sscanf(token, "%d", &indices[count]) == 1)
					count++;
				else
				{
					fprintf(stderr, "Malformed face line: %s\n", line);
					break ;
				}
				token = strtok(NULL, " \t");
			}
			fan_triangulation(current_group, obj_file, indices, count);
		}
	}
	free(line);
	fclose(file);
	return (obj_file);
}
