/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 19:33:06 by mdomnik           #+#    #+#             */
/*   Updated: 2024/09/10 18:04:02 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

int	check_args(int argc, char **argv, t_render *render)
{
	(void)argc;
	render->options = gc_malloc(sizeof(t_options));
	if (validate_file_name(argv, render->options) == -1)
		return (1);
	if (check_arg_count(argv) == -1)
		return (1);
	if (option_preferences(argv, render->options) == -1)
		return (1);
	if (get_scene_data(render->options) == -1)
		return (1);
	if (check_scene_data(render->options) == -1)
		return (1);
	return(0);
}
