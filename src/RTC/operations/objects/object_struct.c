/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:47:10 by mdomnik           #+#    #+#             */
/*   Updated: 2024/11/19 20:09:56 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

void add_light(t_light_p **lights, t_light_p *new_light)
{
	t_light_p	*tmp;

	if(!*lights)
	{
		*lights = new_light;
		return ;
	}
	tmp = *lights;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_light;
}
