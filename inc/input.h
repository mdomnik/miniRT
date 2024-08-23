/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:11:31 by mdomnik           #+#    #+#             */
/*   Updated: 2024/08/23 20:16:27 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <MLX42/MLX42.h>
# include "../lib/libft/libft.h"

# define OPTS_FULL "--save,--reflection,--test,--help,--testy,--vector,--noargvector,--added"
# define OPTS_SHORT "-s,-r,-t,-h,-y,-v,-n,-a"
# define OPTS_VALUE "STRING,FLOAT,*STRING,NULL,*FLOAT,VECTOR,*VECTOR,*STRING"
typedef enum e_opts_type
{
	OPT_SAVE = 0,
	OPT_REFLECTION = 1,
	OPT_TEST = 2,
	OPT_HELP = 3,
}	t_opts_type;




typedef struct s_string
{
	char *string_value;
}	t_string;

typedef struct s_float
{
	double float_value;
}	t_float;

typedef struct s_vector
{
	double x;
	double y;
	double z;
}	t_vector;

typedef union u_value_type
{
	t_string	string;
	t_float		float_value;
	t_vector	vector;
}	t_value_type;

typedef struct s_value
{
	t_opts_type		type;
	t_value_type	value;
	struct s_value	*next;
}	t_value;

typedef struct s_options
{
	int		opts_flags;
	t_value	*values;
	
}	t_options;

//file_parser.c
int validate_arg_count(int argc);

//option_arg_parser.c
int get_option_values (t_options *options, char **argv);

//option_parser.c
int option_preferences(char **argv, t_options *options);
int check_file_format(char **argv, t_options *options, char *flag, int type);
int args_to_opts(char *str, char *options, int type);
int opt_binary_assignment(int value, t_options *options);
int value_containers(int value, t_options *options, char *str, char *flag);
int create_option(t_options *options, int value, char **flag_junction);
char *check_if_option(char *str);
t_value *create_value_node(t_opts_type type, char *value_type, char *data);
int check_string_format(char *str);
int check_float_format(char *str);
double ft_atob(char *str);
void append_value_node(t_options *options, t_value *new_value_node);
int	is_number(char *str);

//ft_atob.c
double ft_atob(char *str);


// typedef enum e_opt_type
// {
// 	OPT_SAVE = 0,
// 	OPT_S = 0,
// }	t_opt_type;

// typedef struct s_options
// {
// 	t_opt_type  type;
// 	char		*value;
// 	t_options	*next;

// }	t_options;

// typedef struct s_input
// {
// 	char		*scene_file;
// 	t_options	options;

// }	t_input;

#endif /* input_H */
