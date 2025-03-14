/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:25:55 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/14 14:36:09 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

//free.c
void		free_world(t_world *world);
void		free_triple_ptr(char ***str);
void		free_canvas(t_canvas *canvas);
void		free_pattern(t_pattern *pattern, t_shape *shape);
void		free_bump_map(t_bump_map *bump_map);

//process_pixel.c
void		process_pixel_aa(t_world *world, t_pixel *px, int samples);
t_color3	ray_shooter(int grid_size, float a[],
				t_pixel *px, t_world *world);
void		process_pixel_color(t_world *world, t_ray **ray,
				t_comp **comp, t_pixel *px);

//render_loop_init.c
bool		init_loop_img(t_loop *loop);
bool		init_loop_opts(t_loop *loop);

//render_loop.c
t_loop		*loop_init(void);
void		render(t_loop *loop);

//render_mt.c
void		render_multithreaded(t_loop *loop);
void		join_threads(pthread_t *threads, int thread_count);
void		*render_worker(void *arg);
void		assign_loop_locks(t_loop *loop);

//render_standard.c
void		render_single(t_loop *loop);

//render_standard2.c
void		free_render_data(t_render_data *data);

//render_utils.c
void		put_pixel_to_img(t_image *img, int x, int y, int color);
void		update_display(t_loop *loop);
bool		init_worker_memory(t_ray **ray, t_comp **comp);
void		free_worker_memory(t_ray **ray, t_comp **comp);
t_world		*init_local_world(t_thread_data *data);

//render_rand.c
int			ft_srand(int seed);
int			ft_rand(void);

#endif