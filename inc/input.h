/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:11:31 by mdomnik           #+#    #+#             */
/*   Updated: 2024/08/22 19:55:58 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <MLX42/MLX42.h>
# include "../lib/libft/libft.h"

# define OPTS_FULL "--save,--reflection,--test"
# define OPTS_SHORT "-s,-r,-t"

typedef struct s_options
{
	char	*save;
	char	*reflection;
}	t_options;

//file_parser.c
int validate_arg_count(int argc);


//option_arg_parser.c
int get_option_values (int opt_flags, t_options *options, char **argv);

//option_parser.c
int option_preferences(char **argv);
int check_file_format(char **argv, int *opt_flags, char *options, int type);
int args_to_opts(char *str, char *options, int type);
int opt_binary_assignment(int value, int *opt_flags);


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
