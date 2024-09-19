/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 20:06:22 by astavrop          #+#    #+#             */
/*   Updated: 2024/09/19 20:50:14 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MRT_H
# define MRT_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <MLX42/MLX42.h>
# include "../lib/libft/libft.h"

typedef struct s_render t_render;

# include "flags.h"
# include "data_types.h"
# include "error.h"

# include "objects.h"
# include "file.h"

# include "def_flags.h"
# include "def_scene.h"
# include "def_mlx.h"


#include "color.h"
#include "vec3.h"
#include "ray.h"

typedef struct s_render
{
    mlx_t       *window;
    mlx_image_t *vp_img;
    t_options   *options;
}   t_render;

# define VP_WIDTH  960
# define VP_HEIGHT 540

# define ASPECT_R 1.77777777777
# define IWIDTH 400

// Define the DEBUG macro
#define DEBUG(fmt, ...) \
    fprintf(stderr, "[DEBUG] %s:%d:%s(): " fmt "\n", __FILE__, __LINE__, __func__, ##__VA_ARGS__)



#endif /* MRT_H */
