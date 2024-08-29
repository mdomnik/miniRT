/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_def.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:46:08 by mdomnik           #+#    #+#             */
/*   Updated: 2024/08/29 17:59:25 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_DEF_H
# define SCENE_DEF_H

//scene_file/scene_file.c
int get_scene_data(t_options *options);
int append_object_nodes(t_options *options, char *line);
char **append_to_double(char **args, char *temp);
int		append_to_triple(t_options *options, char **args);

//scene_file/file_utils.c
int omit_whitespaces(char *str, int i);

//scene_file/check_data.c
int check_scene_data(t_options *options);
int check_object_data(t_options *options, char **args);

#endif