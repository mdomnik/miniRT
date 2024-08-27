/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:11:31 by mdomnik           #+#    #+#             */
/*   Updated: 2024/08/27 02:50:21 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGS_H
# define FLAGS_H

// FLAG PARSING

/* Flag parsing is done in a highly modular way.
 * A Flag is created in the header by defining it's FULL and SHORT string
 * as well as their data type (e.g. --save, -s, "STRING").
 * A data type can also have an '*', which signifies an optional argument.
 * A data type can be either "NULL"(takes no arguments),
 * "STRING", "FLOAT", "VECTOR" (all with optional argument setting).*/

// FULL FLAG STRINGS
# define OPTS_FULL "--save,--reflection,--test,--help, \
					--testy,--vector,--noargvector,--added"
// SHORT FLAG STRINGS
# define OPTS_SHORT "-s,-r,-t,-h,-y,-v,-n,-a"

// DATA TYPES
# define OPTS_VALUE "STRING,FLOAT,*STRING,NULL,*FLOAT,VECTOR,*VECTOR,*STRING"

// FLAGS
typedef enum e_opts_type
{
	OPT_SAVE = 0,
	OPT_REFLECTION = 1,
	OPT_TEST = 2,
	OPT_HELP = 3,
	OPT_TESTY = 4,
	OPT_VECTOR = 5,
	OPT_NOARGVECTOR = 6,
	OPT_ADDED = 7
}	t_opts_type;

// STRING DATA TYPE STRUCT
typedef struct s_string
{
	char	*string_value;
}	t_string;

// FLOAT DATA TYPE STRUCT
typedef struct s_float
{
	double	float_value;
}	t_float;

// VECTOR DATA TYPE STRUCT
typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}	t_vector;

// VALUE TYPE UNION
typedef union u_value_type
{
	t_string	string;
	t_float		float_value;
	t_vector	vector;
}	t_value_type;

// VALUE NODE STRUCT
typedef struct s_value
{
	t_opts_type		type;
	t_value_type	value;
	struct s_value	*next;
}	t_value;

// OPTIONS STRUCT
typedef struct s_options
{
	int		opts_flags;
	char	*scene_file;
	t_value	*values;
}	t_options;

// FUNCTION DEFINITIONS

//flags/flag_formatting.c
int		option_preferences(char **argv, t_options *options);
int		check_file_format(char **argv, t_options *options, char *flag,
			int type);
int		args_to_opts(char *str, char *options, int type);
int		opt_binary_assignment(int value, t_options *options);

//flags/flag_utils.c
char	*check_if_option(char *str);
int		is_number(char *str);
double	ft_atob(char *str);

//flags/create_flag_nodes.c
int		value_containers(int value, t_options *options, char *str, char *flag);
int		process_flag(char *f_type, t_options *options, int value,
			char **flag_join);
int		create_option(t_options *options, int value, char **flag_junction);
t_value	*create_value_node(t_opts_type type, char *value_type, char *data);
void	append_value_node(t_options *options, t_value *new_value_node);

//flags/handle_values.c
int		handle_null_value(char *str);
int		handle_string_value(t_value *new_value_node, char *data);
int		handle_float_value(t_value *new_value_node, char *data);
int		handle_vector_value(t_value *new_value_node, char *data);
void	set_vector_values(t_value *new_value_node, char **vector);

//flags/handle_value_format.c
int		check_string_format(char *str);
int		check_float_format(char *str);
int		check_vector_format(char *str);

#endif
