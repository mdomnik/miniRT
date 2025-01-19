/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:37:50 by mdomnik           #+#    #+#             */
/*   Updated: 2025/01/19 18:16:33 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

#define EPSILON 0.001


#define RECURSIVE_DEPTH 5

#define LOW 0
#define MEDIUM 1
#define HIGH 2
#define MAX 3

#define MAX_VERTEX_COUNT 300
#define MAX_FACE_COUNT 300
#define MAX_GROUP_COUNT 300

#define GLASS_REFRACTION 1.5
#define AIR_REFRACTION 1.0
#define WATER_REFRACTION 1.333
#define DIAMOND_REFRACTION 2.417

int	quality(bool set, int variable);


#endif
