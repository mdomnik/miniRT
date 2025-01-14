/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 02:18:21 by mdomnik           #+#    #+#             */
/*   Updated: 2024/10/15 21:32:49 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H

//input.c
int	check_args(int argc, char **argv, t_project *project);

//find_scene_file.c
int		validate_file_name(char **argv, t_options *options);
int		scene_file_check(char *filename, char **scene_file, bool *scene_count);
int		check_scene_file(char *args);
int		check_arg_count(char **argv);

//tests.c
void	printf_option_values(t_options *options);
void	printf_objects(t_options *options);

#endif
