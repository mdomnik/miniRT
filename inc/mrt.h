/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 20:06:22 by astavrop          #+#    #+#             */
/*   Updated: 2024/09/10 16:27:55 by astavrop         ###   ########.fr       */
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

# include "data_types.h"
# include "error.h"

# include "flags.h"
# include "objects.h"
# include "file.h"

# include "def_flags.h"
# include "def_scene.h"

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <MLX42/MLX42.h>
# include "../lib/libft/libft.h"

# include "data_types.h"
# include "error.h"

# include "flags.h"
# include "objects.h"
# include "file.h"

# include "def_flags.h"
# include "def_scene.h"

# define ASPECT_R 1.77777777777
# define IWIDTH 400

# include <stdio.h>

// Define the DEBUG macro
#define DEBUG(fmt, ...) \
    fprintf(stderr, "[DEBUG] %s:%d:%s(): " fmt "\n", __FILE__, __LINE__, __func__, ##__VA_ARGS__)

#endif /* MRT_H */
