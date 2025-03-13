/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:57:28 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/13 20:36:18 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

//debug_methods.c
void	print_matrix(t_matrix mat);
void	print_tuple(t_tuple tuple);

void	set_window(t_loop *loop);
void	clean_dependencies(t_loop *loop);
int		key_hook(int keycode, void *param);
int		close_window(void *param);
#endif
