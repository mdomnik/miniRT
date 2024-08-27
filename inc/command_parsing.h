/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_parsing.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 02:18:21 by mdomnik           #+#    #+#             */
/*   Updated: 2024/08/27 02:19:35 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_PARSING_H
# define COMMAND_PARSING_H

//file_parser.c
int validate_arg_count(int argc);

//option_arg_parser.c
int get_option_values (t_options *options, char **argv);

#endif