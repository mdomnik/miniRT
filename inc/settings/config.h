/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:37:50 by mdomnik           #+#    #+#             */
/*   Updated: 2025/01/20 20:48:09 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

#define EPSILON 0.001

#define LIGHTING 4
#define RECURSIVE_DEPTH 5

#define ON 1
#define OFF 0

#define LOW 0
#define MEDIUM 1
#define HIGH 2
#define MAX 3

//resolution downscaling
#define FULL 0
#define HALF 1
#define QUARTER 2
#define EIGHTH 3
#define SIXTEENTH 4

//supersampling
#define SS_OFF 0
#define SS_2X 1
#define SS_4X 2
#define SS_8X 3
#define SS_16X 4

#define MAX_VERTEX_COUNT 300
#define MAX_FACE_COUNT 300
#define MAX_GROUP_COUNT 300

#define GLASS_REFRACTION 1.5
#define AIR_REFRACTION 1.0
#define WATER_REFRACTION 1.333
#define DIAMOND_REFRACTION 2.417

int	quality(bool set, int variable);


#endif
