/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 19:32:44 by mdomnik           #+#    #+#             */
/*   Updated: 2024/08/23 20:15:52 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

int	option_preferences(char **argv, t_options *options)
{

	if (check_file_format(argv, options, ft_strdup(OPTS_FULL), 0) == -1)
		return (-1);
	if (check_file_format(argv, options, ft_strdup(OPTS_SHORT), 1) == -1)
		return (-1);
	return (0);
}

int	check_file_format(char **argv, t_options *options, char *flag, int type)
{
	int	i;
	int	ato_ret;

	i = 1;
	while (argv[i])
	{
		ato_ret = args_to_opts(argv[i], ft_strdup(flag), type);
		if (ato_ret == -2)
			return (-1);
		else
			if (opt_binary_assignment(ato_ret, options) == -1)
				return (-1);
			if (value_containers(ato_ret, options, argv[i + 1], argv[i]) == -1)
				return (-1);
		i++;
	}
	return (0);
}

int	args_to_opts(char *str, char *flag, int type)
{
	char	**opts;
	int		i;

	opts = ft_split(flag, ',');
	i = 0;
	while (opts[i])
	{
		if (ft_strcmp(opts[i], str) == 0)
			return (i);
		i++;
	}
	if (is_number(str) == 1)
	{
		if ((type == 0 && str[0] == '-' && str[1] == '-' )
			|| (type == 1 && str[0] == '-' && str[1] != '-'))
		{
			ft_dprintf(2, "%s\n", ERR_INVALID_OPT);
			return (-2);
		}
	}
	return (-1);
}

int	opt_binary_assignment(int value, t_options *options)
{
	if (value < 0)
		return (0);
	if (options->opts_flags & (1 << value))
	{
		ft_dprintf(2, "%s\n", ERR_DOUBLE_OPT);
		return (-1);
	}
	options->opts_flags |= (1 << value);
	return (0);
}

int value_containers(int value, t_options *options, char *str, char *flag)
{
	char **flag_types;
	char **flag_junction;
	char *opts_value = ft_strdup(OPTS_VALUE);

	if (value < 0)
		return (0);
	flag_types = ft_split(opts_value, ',');
	flag_junction = gc_malloc(sizeof(char *) * 4);
	flag_junction[0] = ft_strdup(flag);
	flag_junction[1] = ft_strdup(flag_types[value]);
	if (str)
		flag_junction[2] = ft_strdup(str);
	else
		flag_junction[2] = NULL;
	flag_junction[3] = NULL;
	if (ft_strnstr(flag_junction[1], "STRING", ft_strlen(flag_junction[1])))
		if (create_option(options, value, flag_junction) == -1)
			return (-1);
	if (ft_strnstr(flag_junction[1], "FLOAT", ft_strlen(flag_junction[1])))
		if (create_option(options, value, flag_junction) == -1)
			return (-1);
	if (ft_strnstr(flag_junction[1], "VECTOR", ft_strlen(flag_junction[1])))
		if (create_option(options, value, flag_junction) == -1)
			return (-1);
	return (0);
}

int create_option(t_options *options, int value, char **flag_junction)
{
	t_value *new_value_node;
	char *arg;

	
	arg = check_if_option(flag_junction[2]);
	if (flag_junction[1][0] == '*' && arg == NULL)
		new_value_node = create_value_node(value, flag_junction[1], NULL);
	else if (arg == NULL)
	{
		ft_dprintf(2, "Error: Option '%s' requires an argument\n", flag_junction[0]);
		return (-1);
	}
	else
		new_value_node = create_value_node(value, flag_junction[1], arg);
	if (new_value_node == NULL)
		return (-1);
	append_value_node(options, new_value_node);
	return (0);
}

char *check_if_option(char *str)
{
	char *ret;
	
	if (!str)
		return (NULL);
	if ((is_number(str) == 1) && str[0] == '-')
			return (NULL);
	ret = ft_strdup(str);
	return (str);
}

t_value *create_value_node(t_opts_type type, char *value_type, char *data)
{
	t_value *new_value_node;
	
	new_value_node = (t_value *)gc_malloc(sizeof(t_value));	
	new_value_node->type = type;
	
	if (ft_strnstr(value_type, "STRING", ft_strlen(value_type)) && data == NULL)
		new_value_node->value.string.string_value = NULL;
	else if (ft_strnstr(value_type, "STRING", ft_strlen(value_type)))
		if (check_string_format(data) == -1)
			return (NULL);
		else
			new_value_node->value.string.string_value = ft_strdup(data);
	else if (ft_strnstr(value_type, "FLOAT", ft_strlen(value_type)) && data == NULL)
		new_value_node->value.float_value.float_value = 0;
	else if (ft_strnstr(value_type, "FLOAT", ft_strlen(value_type)))
	{
		if (check_float_format(data) == -1)
			return (NULL);
		else
			new_value_node->value.float_value.float_value = ft_atob(data);
	}
	new_value_node->next = NULL;
	return (new_value_node);
}

int	check_string_format(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < 65 || str[i] > 90) && (str[i] < 97 || str[i] > 122) && str[i] != '_')
		{
			if (str[i] != '_')
				ft_dprintf(2, "Error: Option value contains invalid characters '%c'\n", str[i]);
			return (-1);
		}
		i++;
	}
	return (0);
}

int check_float_format(char *str)
{
	int i;
	int dot_count;

	i = 0;
	dot_count = 0;
	while (str[i])
	{
		if ((str[i] < 48 || str[i] > 57) && str[i] != '.' && str[i] != '-')
		{
			ft_dprintf(2, "Error: Option value contains invalid characters '%c'\n", str[i]);
			return (-1);
		}
		if (str[i] == '.')
			dot_count++;
		i++;
	}
	if (dot_count > 1)
	{
		ft_dprintf(2, "Error: Option value contains multiple '.'\n");
		return (-1);
	}
	return (0);
}

void append_value_node(t_options *options, t_value *new_value_node)
{
	t_value *last;

	if (options->values == NULL)
	{
		options->values = new_value_node;
		return ;
	}
	last = options->values;
	while (last->next != NULL)
		last = last->next;
	last->next = new_value_node;
}
int	is_number(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < 48 || str[i] > 57) && str[i] != '.' && str[i] != '-')
			return (1);
		i++;
	}
	return (0);
}
