/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 20:06:22 by astavrop          #+#    #+#             */
/*   Updated: 2025/02/26 14:40:01 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MRT_H
# define MRT_H

// System includes first
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdarg.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <pthread.h>
# include <errno.h>
# include <math.h>

// External libraries
# include "../lib/minilibx-linux/mlx.h"
# include "../lib/libft/libft.h"

// Project settings
# include "settings/config.h"
# include "settings/error.h"

// Forward declarations
# include "forward.h"

// Basic types and structures
# include "types.h"
# include "objects.h"

// Feature-specific headers
# include "flags.h"
# include "rtc.h"
# include "materials.h"

// Implementation headers
# include "define/control.h"
# include "define/debug.h"
# include "define/groups.h"
# include "define/initialize.h"
# include "define/intersection.h"
# include "define/lighting.h"
# include "define/matrix.h"
# include "define/parse.h"
# include "define/template_obj.h"
# include "define/textures.h"
# include "define/tuple.h"
# include "define/view.h"

# define VP_WIDTH  960
# define VP_HEIGHT 540

# define ASPECT_R 1.77777777777
# define IWIDTH 400

# define NUM_THREADS 1

#endif /* MRT_H */
