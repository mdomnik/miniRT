/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:17:29 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/26 15:59:45 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

static int	check_mat_args(char *str, t_material *mat, char **params);
static int check_value_bound(char *param, char *arg);
static void allocate_mat(char *param, float value, t_material *mat);

int	get_material(char *str, t_material *mat)
{
	int		fd;
	int		i;
	char	*line;
	char	**params;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		perror(ERR_OPEN_FILE);
		return (-1);
	}
	line = gnl(fd);
	if (line == NULL)
	{
		perror(ERR_EMPTY_FILE);
		close(fd);
		return (-1);
	}
	params = ft_split(PARAM_LIST, ',');
	while (line != NULL)
	{
		i = 0;
		i = omit_whitespaces(line, i);
		if (line[i] != '#')
		{
			i = 0;
			line = ft_substr(line, 0, ft_strlen(line) - 1);
			if (check_mat_args(line, mat, params) == -1 || check_texture_args(line, mat) == -1)
			{
				close(fd);
				free_double(params);
				return (-1);
			}
		}
		free(line);
		line = gnl(fd);
	}
	close(fd);
	free_double(params);
	return (0);
}

static int	check_mat_args(char *str, t_material *mat, char **params)
{
	char **args;
	int i;

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
			break;
		i++;
	}
	if (params[i] == NULL)
	{
		free_double(args);
		return (-1);
	}
	if (check_value_bound(params[i], args[1]) == -1)
	{
		free_double(args);
		return (-1);
	}
	else if (check_value_bound(params[i], args[1]) == 0)
		allocate_mat(args[0], ft_atof(args[1]), mat);
	free_double(args);
	return (0);
}


static int check_value_bound(char *param, char *arg)
{
	int i;
	float value;
	char *bounds;
	char **limits;

	i = 0;
	while(arg[i] != '\0')
	{
		if ((arg[i] < '0' || arg[i] > '9') && arg[i] != '-' && arg[i] != '+' && arg[i] != '.')
			return(2);
		i++;
	}
	value = ft_atof(arg);
	i = 0;
	while (param[i] != ':' && param[i] != '\0')
		i++;
	if (param[i] == '\0')
	{
		ft_dprintf(2, "Problem parsing: %s", param);
		return (-1);
	}
	i++;
	bounds = ft_substr(param, i, ft_strlen(param) - i);
	limits = ft_split(bounds, '-');
	i = 0;
	while (limits[i] != NULL)
		i++;
	if (i != 2)
	{
		ft_dprintf(2, "Problem parsing: %s", param);
		free_double(limits);
		free(bounds);
		return (-1);
	}
	if (value < ft_atof(limits[0]) || value > ft_atof(limits[1]))
	{
		free_double(limits);
		free(bounds);
		return (2);
	}
	free_double(limits);
	free(bounds);
	return (0);
}

static void allocate_mat(char *param, float value, t_material *mat)
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
	{
		if (mat->bump_map)
			mat->bump_map->scale = value;
	}
}
