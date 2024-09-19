/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2024/09/21 15:15:43 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




#include "../inc/color.h"
#include "../inc/vec3.h"
#include "../inc/ray.h"

#include <stdio.h>
#include <unistd.h>

#ifndef WIDTH
# define WIDTH 900
#endif

#ifndef HEIGHT
# define HEIGHT 600
#endif

#include "../inc/mrt.h"

int main(int argc, char **argv)
{
	t_render	render;
	
	if(check_args(argc, argv, &render) == 1)
		return(1);
	if(start_mlx(&render) == 1)
		return(1);
	mlx_loop(render.window);
}

