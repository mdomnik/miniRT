/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_transformation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:05:26 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/23 18:59:31 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

// static void	fill_row(t_matrix *orientation, t_tuple input, int row)
// {
// 	orientation->a[row][0] = input.x;
// 	orientation->a[row][1] = input.y;
// 	orientation->a[row][2] = input.z;
// }

t_matrix view_transformation(t_point3 from, t_vec3 orientation)
{
    if (fabs(orientation.x) < 0.0001 && fabs(orientation.y) < 0.0001 && fabs(orientation.z) < 0.0001)
        orientation = new_vec3(0, 0, 1);

    t_vec3 forward = normalize(orientation);
    t_vec3 up = new_vec3(0, 1, 0);

    // Ensure up vector correction when forward is vertical
    if (fabs(forward.x) < 0.0001 && fabs(forward.z) < 0.0001)
        up = new_vec3(0, 0, (forward.y > 0) ? 1 : -1);

    // **FIX: Correct cross product order for left**
    t_vec3 left = normalize(cross_product(forward, up));  // Correct order

    t_vec3 true_up = cross_product(left, forward);

    // Create the orientation matrix
    t_matrix orientation_matrix = init_identity_matrix(4);

    orientation_matrix.a[0][0] = left.x;
    orientation_matrix.a[0][1] = left.y;
    orientation_matrix.a[0][2] = left.z;

    orientation_matrix.a[1][0] = true_up.x;
    orientation_matrix.a[1][1] = true_up.y;
    orientation_matrix.a[1][2] = true_up.z;

    orientation_matrix.a[2][0] = -forward.x;
    orientation_matrix.a[2][1] = -forward.y;
    orientation_matrix.a[2][2] = -forward.z;

    // Apply translation to move the world relative to the camera
    t_matrix translation_matrix = translation(-from.x, -from.y, -from.z);

    return multiply_matrices(orientation_matrix, translation_matrix);
}


