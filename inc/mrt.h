/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 20:06:22 by astavrop          #+#    #+#             */
/*   Updated: 2024/11/27 12:47:04 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MRT_H
# define MRT_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdarg.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <math.h>
# include <MLX42/MLX42.h>
# include "../lib/libft/libft.h"

# include "settings/config.h"
# include "settings/error.h"

# include "types.h"
# include "objects.h"
# include "flags.h"
# include "rtc.h"

# include "defines/def_file.h"
# include "defines/def_flags.h"
# include "defines/def_matrix.h"
# include "defines/def_rays.h"
# include "defines/def_scene.h"
# include "defines/def_tuples.h"
# include "defines/def_utils.h"
# include "defines/def_intersection.h"
# include "defines/def_world.h"
# include "defines/def_objects.h"
# include "defines/def_patterns.h"
# include "defines/def_reflection.h"

# define VP_WIDTH  960
# define VP_HEIGHT 540

# define ASPECT_R 1.77777777777
# define IWIDTH 400

// Define the DEBUG macro
// Define the DEBUG macro
#define DEBUG(fmt, ...) \
    fprintf(stderr, "[DEBUG] %s:%d:%s(): " fmt "\n", __FILE__, __LINE__, __func__, ##__VA_ARGS__)



#endif /* MRT_H */
