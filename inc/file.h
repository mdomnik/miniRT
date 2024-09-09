/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 02:18:21 by mdomnik           #+#    #+#             */
/*   Updated: 2024/09/09 17:23:35 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H

typedef struct s_scene
{
	char	*scene_file;
	char	***scene_objects;
}	t_scene;

// OPTIONS STRUCT
typedef struct s_options
{
	int		opts_flags;
	t_scene	scene;
	t_value	*values;
	t_obj	objects;
}	t_options;

//input.c

//find_scene_file.c
int		validate_file_name(char **argv, t_options *options);
int		scene_file_check(char *filename, char **scene_file, bool *scene_count);
int		check_scene_file(char *args);
int		check_arg_count(char **argv);

//tests.c
void	printf_option_values(t_options *options);
void	printf_objects(t_options *options);

#endif
