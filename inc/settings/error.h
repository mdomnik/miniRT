/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:30:43 by mdomnik           #+#    #+#             */
/*   Updated: 2025/01/13 23:39:35 by mdomnik          ###   ########.fr       */
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
# define ERR_EMPTY_FILE "Error: Empty file"

//FILE READING
# define ERR_OPEN_FILE "Error: Failed to open file"
# define ERR_READ_FILE "Error: Failed to read file"
# define ERR_FAIL_LINE "Error: Failed to read line"

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

#define ERR_SPLIT "Error: Failed to split string"

//IMAGE
# define ERR_PPM_FORMAT "Error: Invalid PPM format"
# define ERR_MEMORY "Error: Could not allocate memory for canvas"
# define ERR_WRITE_PIXEL "Error: Attempted to write pixel outside of canvas bounds"
# define ERR_COLOR_MAX "Error: Invalid color max value"
# define ERR_INCOMPLETE_RGB "Error: Incomplete RGB values"
#endif
