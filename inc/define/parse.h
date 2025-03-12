/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:29:54 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/12 12:51:40 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

//obj/obj_to_faces.c
t_obj_file	*parse_obj_file(const char *filename);

//ppm/canvas_from_ppm.c
void		canvas_from_ppm_pixels(FILE *file, t_canvas *canvas, int color_max);
int			check_ppm_magic_number(char *line);
int			canvas_from_ppm_dimensions(t_canvas *canvas, char *line);
t_canvas	*canvas_from_ppm(const char *filename);
// t_canvas	*process_ppm_header(FILE *file, int *color_max);

//ppm/canvas_utils.c
void		canvas_write_pixel(t_canvas *canvas, int x, int y, t_color3 color);
char		*skip_comments(FILE *file);

//ppm/write_to_ppm.c
t_canvas	*canvas_new(int width, int height);
t_color3	pixel_at(t_canvas *canvas, int x, int y);
void		save_image(t_image *img, char *filename);

//rt/flags/check_value_format.c
int			check_string_format(char *str);
int			check_float_format(char *str);
int			check_vector_format(char *str);

//rt/flags/create_flag_nodes.c
int			value_containers(int value, t_options *options, char *str,
				char *flag);
int			process_flag(char *f_type, t_options *options, int value,
				char **flag_join);
int			create_option(t_options *options, int value, char **flag_junction);

//rt/flags/flag_formatting.c
int			option_preferences(char **argv, t_options *options);
int			check_file_format(char **argv, t_options *options, char *flag,
				int type);
int			args_to_opts(char *str, char *options, int type);
int			opt_binary_assignment(int value, t_options *options);

//rt/flags/flag_utils.c
char		*check_if_option(char *str);
int			is_number(char *str);
float		ft_atof(char *str);

//rt/scene_file/append.c
t_light		*append_light_list(t_light *list, t_light *new);
t_sphere	*append_sphere_list(t_sphere *list, t_sphere *new);
t_plane		*append_plane_list(t_plane *list, t_plane *new);
t_cylinder	*append_cylinder_list(t_cylinder *list, t_cylinder *new);

//rt/scene_file/check_data.c
int			check_scene_data(t_options *options);
int			check_mandatory_objects(t_options *options);
int			check_dup_objects(t_options *options, int binary);
int			check_object_data(char **args);
int			determine_object(char **args);

//rt/scene_file/check_objects.c
int			create_objects(t_options *options, t_world *world);
int			check_objects_helper(t_scene *scene, t_world *world, int i);

//rt/scene_file/create_mand.c
int			create_ambient(t_options *options, char **args);
int			create_camera(t_camera **camera, char **args);
int			create_light(t_light_p **lights, char **args);

//rt/scene_file/create_bonus.c
int			check_bonus_objects(t_scene *scene, t_world *world, int i);
int			create_cone(t_world *world, char **args);
int			create_hourglass(t_world *world, char **args);
int			create_cube(t_world *world, char **args);
int			create_obj(t_world *world, char **args);
int			create_skybox(t_world *world, char **args);

//rt/scene_file/create_obj.c
int			create_sphere(t_world *world, char **args);
int			create_plane(t_world *world, char **args);

//rt/scene_file/create_cylinder.c
int			create_cylinder(t_world *world, char **args);
void		set_cylinder_pattern(t_shape *cy);
//rt/scene_file/file_data.c
int			get_scene_data(t_options *options);
int			append_object_nodes(t_options *options, char *line);
char		**append_to_double(char **args, char *temp);
int			append_to_triple(t_options *options, char **args);
int			check_file_open_format(char *str);

//rt/scene_file/file_utils.c
int			omit_whitespaces(char *str, int i);
void		free_double(char **args);
int			pointer_count(char **args);
int			ret_message(char *message, char *str);
char		**double_dup(char **src);

//rt/scene_file/ruleset.c
int			check_object_rules(char **args, char **rules);
int			check_color_format(char *str);
int			check_ratio_format(char *str, int min, int max);
int			check_vector_range_format(char *str);

//rt/scene_file/to_object.c
t_toremove	*populate_object_struct(t_obj *obj);

//rt/input.c
int			check_args(int argc, char **argv, t_options *options);
int			make_world(t_options *options, t_world *world);

//rt/find_scene_file.c
int			validate_file_name(char **argv, t_options *options);
int			scene_file_check(char *filename, char **scene_file,
				bool *scene_count);
int			check_scene_file(char *args);
int			check_arg_count(char **argv);

//mat/mat_format_utils.c
int			validate_arg_chars(char *arg);
int			check_limits(char *limits, float value);

//rt/tests.c
void		printf_option_values(t_options *options);
void		printf_objects(t_options *options);

//utils/error_handler.c
void		*error_handler(char *error_msg, FILE *file);
int			error_handler_int(char *error_msg, FILE *file);

#endif
