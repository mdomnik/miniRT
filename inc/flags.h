/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:11:31 by mdomnik           #+#    #+#             */
/*   Updated: 2024/09/09 13:52:27 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGS_H
# define FLAGS_H

// FLAG PARSING

/* Flag parsing is done in a highly modular way.
 * A Flag is created in the header by defining it's FULL and SHORT string
 * as well as their data type (e.g. --save, -s, "STRING").
 * A data type can also have an '*', which signifies an optional argument.
 * A data type can be either "NULL"(takes no arguments),
 * "STRING", "FLOAT", "VECTOR" (all with optional argument setting).*/

// FULL FLAG STRINGS
# define OPTS_FULL "--save,--reflection,--test,--help, \
					--testy,--vector,--noargvector,--added,--skybox,--what" 
// SHORT FLAG STRINGS
# define OPTS_SHORT "-s,-r,-t,-h,-y,-v,-n,-a,-k,-w"

// DATA TYPES
# define OPTS_VALUE "STRING,FLOAT,*STRING,NULL,*FLOAT,VECTOR,*VECTOR,*STRING,STRING,FLOAT"

// FLAGS
typedef enum e_opts_type
{
	OPT_SAVE = 0,
	OPT_REFLECTION = 1,
	OPT_TEST = 2,
	OPT_HELP = 3,
	OPT_TESTY = 4,
	OPT_VECTOR = 5,
	OPT_NOARGVECTOR = 6,
	OPT_ADDED = 7
}	t_opts_type;

// VALUE NODE STRUCT
typedef struct s_value
{
	t_opts_type		type;
	t_value_type	value;
	struct s_value	*next;
}	t_value;

#endif
