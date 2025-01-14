/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_flags.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:44:58 by mdomnik           #+#    #+#             */
/*   Updated: 2024/10/16 03:28:28 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_FLAGS_H
# define DEF_FLAGS_H

// FUNCTION DEFINITIONS

//flags/check_value_format.c
int		check_string_format(char *str);
int		check_float_format(char *str);
int		check_vector_format(char *str);

//flags/create_flag_nodes.c
int		value_containers(int value, t_options *options, char *str, char *flag);
int		process_flag(char *f_type, t_options *options, int value,
			char **flag_join);
int		create_option(t_options *options, int value, char **flag_junction);
t_flags	*create_value_node(t_opts_type type, char *value_type, char *data);
void	append_value_node(t_options *options, t_flags *new_value_node);

//flags/flag_formatting.c
int		option_preferences(char **argv, t_options *options);
int		check_file_format(char **argv, t_options *options, char *flag,
			int type);
int		args_to_opts(char *str, char *options, int type);
int		opt_binary_assignment(int value, t_options *options);

//flags/flag_utils.c
char	*check_if_option(char *str);
int		is_number(char *str);
float	ft_atof(char *str);

//flags/handle_values.c
int		handle_null_value(char *str);
int		handle_string_value(t_flags *new_value_node, char *data);
int		handle_float_value(t_flags *new_value_node, char *data);
int		handle_vector_value(t_flags *new_value_node, char *data);
void	set_vector_values(t_flags *new_value_node, char **vector);

#endif
