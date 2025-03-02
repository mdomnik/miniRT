/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:32:19 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/24 21:40:21 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEW_H
# define VIEW_H

//camera_op.c
void		get_pixel_size(t_camera *camera);
t_camera	*camera_new(int hsize, int vsize, float fov);
void		ray_for_pixel(t_camera *camera, int px, int py, t_ray *ray);

//render_loop.c
t_loop		*loop_init(void);
void		put_pixel_to_img(t_image *img, int x, int y, int color);
void		render(t_loop *loop, int ac, char *av[]);

//render_loop_init.c
bool		init_loop_img(t_loop *loop);
bool		init_loop_opts(t_loop *loop);

//render_worker.c
void		*render_worker(void *arg);
void		process_pixel(t_thread_data *data, t_world *world,
			int coords[2], t_ray **ray, t_comp **comp);
void		process_pixel_color(t_world *world, t_ray **ray,
			t_comp **comp, t_pixel *px);

//render_worker_utils.c
t_world		*init_local_world(t_thread_data *data);
void		process_row(t_thread_data *data, t_world *world, 
				int y, t_ray **ray, t_comp **comp);
void		update_display(t_loop *loop);
void		join_threads(pthread_t *threads);

//view_transformation.c
t_matrix	view_transformation(t_point3 from, t_vec3 orientation);

#endif
