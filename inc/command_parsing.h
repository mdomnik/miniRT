/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_parsing.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 02:18:21 by mdomnik           #+#    #+#             */
/*   Updated: 2024/09/06 17:39:43 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_PARSING_H
# define COMMAND_PARSING_H

// OPTIONS STRUCT
typedef struct s_options
{
	int		opts_flags;
	t_scene	scene;
	t_value	*values;
	t_obj   objects;
}	t_options;


//file_parser.c
int	check_arg_count(char **argv);

//find_scene_file.c
int	validate_file_name(char **argv, t_options *options);
int	scene_file_check(char *filename, char **scene_file, bool *scene_count);
int	check_scene_file(char *args);

#endif
