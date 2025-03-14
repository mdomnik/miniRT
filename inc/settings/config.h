/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:37:50 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/14 16:12:51 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# define EPSILON 0.001

# define ESCAPE 65307
# define LIGHTING 4
# define RECURSIVE_DEPTH 5

//PROGRAM STATES
# define EDIT_MODE 0
# define CAMERA_MODE 1
# define RENDER_MODE 2

//TOOLTIP STATES
# define TOOLTIP_OFF 0
# define TOOLTIP_ON 1

# define ON 1
# define OFF 0

# define LOW 0
# define MEDIUM 1
# define HIGH 2
# define MAX 3

//resolution downscaling
# define FULL 4
# define HALF 3
# define QUARTER 2
# define EIGHTH 1
# define SIXTEENTH 0

//supersampling
# define SS_OFF 0
# define SS_2X 1
# define SS_4X 2
# define SS_8X 3
# define SS_16X 4

# define MAX_VERTEX_COUNT 20000
# define MAX_FACE_COUNT 5000
# define MAX_GROUP_COUNT 300

# define GLASS_REFRACTION 1.5
# define AIR_REFRACTION 1.0
# define WATER_REFRACTION 1.333
# define DIAMOND_REFRACTION 2.417

int	program_state(bool set, int variable);
int	tooltip_state(bool set, int variable);

int	quality(bool set, int variable);
int	render_max(bool set, int variable);

#endif
