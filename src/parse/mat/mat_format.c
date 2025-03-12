/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:17:29 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/12 12:33:48 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

static int	check_mat_args(char *str, t_material *mat, char **params);
static int	check_value_bound(char *param, char *arg);
static void	allocate_mat(char *param, float value, t_material *mat);
static int	process_line(char *line, t_material *mat, char **params, t_shape *shape);

int	get_material(char *str, t_material *mat, t_shape *shape)
{
	int		fd;
	char	*line;
	char	**params;
	char	*filename;

	filename = ft_strjoin("materials/", str);
	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == -1)
		return (perror(ERR_OPEN_FILE), -1);
	line = gnl(fd);
	if (line == NULL)
		return (perror(ERR_EMPTY_FILE), close(fd), -1);
	params = ft_split(PARAM_LIST, ',');
	while (line != NULL)
	{
		if (process_line(line, mat, params, shape) == -1)
			return (close(fd), free_double(params), -1);
		free(line);
		line = gnl(fd);
	}
	close(fd);
	free_double(params);
	return (0);
}

static int	process_line(char *line, t_material *mat, char **params, t_shape *shape)
{
	int		i;
	char	*trimmed;

	i = omit_whitespaces(line, 0);
	if (line[i] != '#')
	{
		trimmed = ft_substr(line, 0, ft_strlen(line) - 1);
		if (check_mat_args(trimmed, mat, params) == -1
			|| check_texture_args(trimmed, mat, shape) == -1)
		{
			return (-1);
		}
		free(trimmed);
	}
	return (0);
}

static int	check_mat_args(char *str, t_material *mat, char **params)
{
	char	**args;
	int		i;

	i = 0;
	args = ft_split(str, ' ');
	while (args[i] != NULL)
		i++;
	if (i != 2)
	{
		free_double(args);
		return (0);
	}
	i = 0;
	while (params[i] != NULL)
	{
		if (ft_strncmp(args[0], params[i], ft_strlen(args[0])) == 0)
			break ;
		i++;
	}
	if (params[i] == NULL || check_value_bound(params[i], args[1]) == -1)
		return (free_double(args), -1);
	else if (check_value_bound(params[i], args[1]) == 0)
		allocate_mat(args[0], ft_atof(args[1]), mat);
	free_double(args);
	return (0);
}

static int	check_value_bound(char *param, char *arg)
{
	int		i;
	float	value;

	i = validate_arg_chars(arg);
	if (i == 2)
		return (2);
	value = ft_atof(arg);
	i = 0;
	while (param[i] != ':' && param[i] != '\0')
		i++;
	if (param[i] == '\0')
	{
		ft_dprintf(2, "Problem parsing: %s", param);
		return (-1);
	}
	if (check_limits(param + i + 1, value) == -1)
		return (-1);
	return (0);
}

static void	allocate_mat(char *param, float value, t_material *mat)
{
	if (ft_strncmp(param, "ambient:", ft_strlen(param)) == 0)
		mat->ambient = value;
	else if (ft_strncmp(param, "diffuse:", ft_strlen(param)) == 0)
		mat->diffuse = value;
	else if (ft_strncmp(param, "specular:", ft_strlen(param)) == 0)
		mat->specular = value;
	else if (ft_strncmp(param, "shininess:", ft_strlen(param)) == 0)
		mat->shininess = value;
	else if (ft_strncmp(param, "reflection:", ft_strlen(param)) == 0)
		mat->reflective = value;
	else if (ft_strncmp(param, "transparency:", ft_strlen(param)) == 0)
		mat->transparency = value;
	else if (ft_strncmp(param, "refraction:", ft_strlen(param)) == 0)
		mat->refractive_index = value;
	else if (ft_strncmp(param, "bump_intensity:", ft_strlen(param)) == 0)
		mat->bump_map_scale = value;
}
