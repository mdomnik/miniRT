/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 23:48:37 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/14 00:34:15 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

static void	parse_group_line(t_obj_file *obj_file, char *line,
		t_group **current_group)
{
	t_group	*new_group;
	char	**tokens;

	tokens = ft_split(line + 2, ' ');
	if (tokens && tokens[0])
	{
		new_group = create_group(tokens[0]);
		add_group_to_default(obj_file, new_group);
		*current_group = new_group;
	}
	else
		ft_dprintf(2, "Malformed group line: %s\n", line);
	free_double(tokens);
}

static void	parse_face_line(t_obj_file *obj_file,
		t_group *current_group, char *line)
{
	char	**tokens;
	int		indices[64];
	int		count;
	int		tok_i;

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

t_obj_file	*parse_obj_file(const char *filename)
{
	t_obj_file	*obj_file;
	int			fd;
	t_group		*current_group;
	char		*line;

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
			parse_group_line(obj_file, line, &current_group);
		else if (line[0] == 'f' && ft_isspace(line[1]))
			parse_face_line(obj_file, current_group, line);
		free(line);
		line = gnl(fd);
	}
	close(fd);
	return (obj_file);
}
