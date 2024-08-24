/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 21:06:12 by astavrop          #+#    #+#             */
/*   Updated: 2024/08/23 13:52:58 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "vec3.h"

# define AR_WIDTH 16.0
# define AR_HEIGHT 9.0
# define IMG_WIDTH 720
# define MAX_DEPTH 5
# define PI 3.141592653589793238462643383279502884197

typedef struct s_camera	t_camera;

struct	s_camera
{
	t_point3	origin;
	t_point3	dir;
	t_point3	center;
	t_vec3		pix_du; // horizontal pixel offest
	t_vec3		pix_dv; // vertical pixel offest
	float		aspect_ration;
	float		FOV;
	float		focal_dist;
	int			img_width;
	int			img_height;
	int			max_depth;
};

/* Utility functions */

double			deg_to_rad(double deg);

#endif /* CAMERA_H */
