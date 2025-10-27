/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_standard2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artem <artem@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 21:25:40 by artem            #+#    #+#             */
/*   Updated: 2025/03/13 21:25:40 by artem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

void	free_render_data(t_render_data *data)
{
	int	i;

	if (!data)
		return ;
	free(data->pixel_order);
	i = 0;
	while (i < data->height)
	{
		free(data->cmped_buf[i]);
		i++;
	}
	free(data->cmped_buf);
	i = 0;
	while (i <= RECURSIVE_DEPTH)
	{
		free(data->ray[i]);
		free(data->comp[i]);
		i++;
	}
	free(data->ray);
	free(data->comp);
	free(data);
}
