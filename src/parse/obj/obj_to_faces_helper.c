/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_to_faces_helper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 20:10:37 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/15 14:09:43 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

void	parse_vertex_line(t_obj_file *obj_file, char *line)
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

t_obj_file	*init_obj_file(const char *filename, int *fd)
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
	path = ft_strjoin("assets/objects/", filename);
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
