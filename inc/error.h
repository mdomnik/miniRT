/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:30:43 by mdomnik           #+#    #+#             */
/*   Updated: 2024/08/27 16:24:26 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

//FLAGS
# define ERR_SCENE_FILE "Error: No scene file provided"
# define ERR_INVALID_OPT "Error: Invalid option"
# define ERR_DOUBLE_OPT "Error: Option already set"
# define ERR_INVALID_CHAR "Error: Option value contains invalid characters"
# define ERR_DOT_COUNT "Error: Option value contains multiple '.'"
# define ERR_NO_ARG "does not take any arguments"
# define ERR_REQ_ARG "requires an argument"
# define ERR_VEC_ARG "Error: Vector flags require exactly 3 arguments 'x,y,z'"
# define ERR_INVALID_ATOB "Error: Invalid character of "

//FILE PARSER
# define ERR_MULTIPLE_SCENE "Error: Multiple scene files provided"
# define ERR_NO_SCENE "Error: No scene file provided"
# define ERR_ARGS "Error: Invalid number of arguments"
# define ERR_NO_NAME "Error: No file name provided with '.rt' extension"
#endif /* ERROR_H */
