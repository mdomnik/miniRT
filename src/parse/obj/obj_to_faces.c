/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_to_faces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:21:30 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/12 13:04:31 by mdomnik          ###   ########.fr       */
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
	void	*t;

	t = triangle(tri->p1, tri->p2, tri->p3);
	add_child(g->group, t);
}

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

static void	fan_triangulation(t_group *group, t_obj_file *obj_file,
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

static void	parse_vertex_line(t_obj_file *obj_file, char *line)
{
	char	**tokens;
	float	coords[3];

	if (obj_file->vertex_count >= MAX_VERTEX_COUNT)
	{
		ft_dprintf(2, "Exceeded maximum vertex count: %d\n", MAX_VERTEX_COUNT);
		return ;
	}
	tokens = ft_split(line + 2, ' ');
	if (!tokens || !tokens[0] || !tokens[1] || !tokens[2])
	{
		ft_dprintf(2, "Malformed vertex line: %s\n", line);
		return ;
	}
	coords[0] = ft_atof(tokens[0]);
	coords[1] = ft_atof(tokens[1]);
	coords[2] = ft_atof(tokens[2]);
	obj_file->vertices[++obj_file->vertex_count] = new_point3(coords[0],
			coords[1], coords[2]);
	free_double(tokens);
}

static t_obj_file	*init_obj_file(const char *filename, int *fd)
{
	t_obj_file	*obj_file;
	char		*path;

	obj_file = malloc(sizeof(t_obj_file));
	if (!obj_file)
		return (NULL);
	obj_file->vertex_count = 0;
	obj_file->face_count = 0;
	obj_file->vertices = malloc(MAX_VERTEX_COUNT * sizeof(t_point3));
	obj_file->faces = malloc(MAX_VERTEX_COUNT * sizeof(t_triangle));
	obj_file->default_group = create_group("Default");
	path = ft_strjoin("objects/", filename);
	*fd = open(path, O_RDONLY);
	free(path);
	if (!*fd)
	{
		ft_dprintf(2, "Failed to open file: %s\n", filename);
		free(obj_file->vertices);
		free(obj_file->faces);
		free(obj_file);
		return (NULL);
	}
	return (obj_file);
}

t_obj_file	*parse_obj_file(const char *filename)
{
	t_obj_file	*obj_file;
	int			fd;
	t_group		*current_group;
	char		*line;
	t_group		*new_group;
	char		**tokens;
	int			indices[64];
	int			count;
	int			tok_i;

	obj_file = init_obj_file(filename, &fd);
	if (!obj_file)
		return (NULL);
	current_group = obj_file->default_group;
	line = gnl(fd);
	while (line != NULL)
	{
		if (line[0] == 'v' && ft_isspace(line[1]))
			parse_vertex_line(obj_file, line);
		else if (line[0] == 'g' && ft_isspace(line[1]))
		{
			tokens = ft_split(line + 2, ' ');
			if (tokens && tokens[0])
			{
				new_group = create_group(tokens[0]);
				add_group_to_default(obj_file, new_group);
				current_group = new_group;
			}
			else
				ft_dprintf(2, "Malformed group line: %s\n", line);
			free_double(tokens);
		}
		else if (line[0] == 'f' && ft_isspace(line[1]))
		{
			count = 0;
			tokens = ft_split(line + 2, ' ');
			tok_i = 0;
			while (tokens[tok_i] && count < 64)
			{
				indices[count] = ft_atoi(tokens[tok_i]);
				if (indices[count] != 0)
					count++;
				else
				{
					ft_dprintf(2, "Malformed face line: %s\n", line);
					break ;
				}
				tok_i++;
			}
			fan_triangulation(current_group, obj_file, indices, count);
			free_double(tokens);
		}
		free(line);
		line = gnl(fd);
	}
	close(fd);
	return (obj_file);
}
