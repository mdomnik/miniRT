/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:30:43 by mdomnik           #+#    #+#             */
/*   Updated: 2024/09/06 17:23:40 by mdomnik          ###   ########.fr       */
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

//FILE READING
# define ERR_OPEN_FILE "Error: Failed to open file"

//FILE CHECKING
# define ERR_INV_OBJ "Error: Invalid object type"
# define ERR_DUP_OBJ "Error: Duplicate object"
# define ERR_RULES "Error: Invalid object rules for object"
# define ERR_MISS_OBJ "Error: Missing object; required"
//DATA TYPES
# define ERR_COLOR_NUM "ERROR: Colors take 3 arguments 'r,g,b'"
# define ERR_COLOR_RANGE "ERROR: Color values must be between 0 and 255"
# define ERR_INV_CHAR "ERROR: Invalid character in value"
# define ERR_RANGE "ERROR: Value out of range"
# define ERR_VEC_NUM "ERROR: Vector range takes 3 float arguments"


#endif /* ERROR_H */
