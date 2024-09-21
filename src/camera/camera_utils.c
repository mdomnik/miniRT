/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 13:46:12 by astavrop          #+#    #+#             */
/*   Updated: 2024/09/21 18:49:28 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

// Convert degrees to radians (conversion of degrees into radians)
inline double	deg_to_rad(double deg)
{
	return (deg * PI / 180.0);
}
