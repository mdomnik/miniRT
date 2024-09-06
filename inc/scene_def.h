/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_def.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:46:08 by mdomnik           #+#    #+#             */
/*   Updated: 2024/09/06 17:49:00 by mdomnik          ###   ########.fr       */
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
void free_double(char **args);
int pointer_count(char **args);
int ret_message(char *message, char *str);
t_light *append_to_list(t_light *list, t_light *new);

//scene_file/check_data.c
int check_scene_data(t_options *options);
int check_mandatory_objects(t_options *options);
int check_dup_objects(t_options *options, int binary);
int check_object_data(t_options *options, char **args);
int determine_object(t_options *options, char **args);
int check_object_rules(t_options *options, char **args, char **rules);

//scene_file/ruleset.c
int check_color_format(char *str);
int check_ratio_format(char *str, int min, int max);
int check_vector_range_format(char *str);

//scene_file/create_mand.c
int create_objects(t_options *options);
int create_ambient(t_options *options, char **args);
int create_camera(t_options *options, char **args);
int create_light(t_options *options, char **args);

#endif
