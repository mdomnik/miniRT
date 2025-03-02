/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ice_cream.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:11:52 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/19 18:58:21 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

#define CONE 0
#define SCOOP1 1
#define SCOOP2 2
#define SCOOP3 3

static t_pattern	*create_cone_texture(void)
{
	t_canvas	*waffle;
	t_pattern	*waffle_pattern;
	t_pattern	*cone_texture;

	waffle = canvas_from_ppm("textures/waffle.ppm");
	waffle_pattern = uv_image(waffle);
	cone_texture = texture_map(waffle_pattern, cylindrical_map);
	set_pattern_transform(cone_texture, scaling(2, 2, 2));
	return (cone_texture);
}

static void	setup_cone_material(t_shape *c, t_pattern *cone_texture)
{
	c->material.color = new_color3(1, 0.5, 0.5);
	c->material.pattern = cone_texture;
	c->material.bump_map = bump_map_from_ppm("textures/waffle_bump.ppm",
			2, cylindrical_map);
	c->material.diffuse = 0.7;
	c->material.specular = 0.3;
	c->material.shininess = 200.0;
	c->material.reflective = 0.2;
	c->material.transparency = 0.0;
	c->material.refractive_index = 1.0;
}

static t_pattern	*create_scoop_texture(void)
{
	t_canvas	*scoop_look;
	t_pattern	*pattern;
	t_pattern	*texture;

	scoop_look = canvas_from_ppm("textures/choc_scoop.ppm");
	pattern = uv_image(scoop_look);
	texture = texture_map(pattern, cylindrical_map);
	return (texture);
}

static void	setup_scoop(t_shape *scoop, t_pattern *texture,
		float y_pos, t_color3 color)
{
	set_transform(scoop, multiply_matrices(translation(0, y_pos, 0),
			scaling(0.5, 0.5, 0.5)));
	scoop->material.color = color;
	scoop->material.pattern = texture;
	scoop->material.bump_map = bump_map_from_ppm(
			"textures/choc_scoop_bump.ppm", 5, spherical_map);
	scoop->material.diffuse = 0.7;
	scoop->material.specular = 0.3;
	scoop->material.shininess = 200.0;
	scoop->material.reflective = 0.2;
}

t_shape	*ice_cream_cone(void)
{
	t_shape		*shapes[4];
	t_shape		*gr;
	t_pattern	*texture;

	shapes[CONE] = cone();
	set_transform(shapes[CONE], multiply_matrices(translation(0, -1, 0),
			multiply_matrices(rotation_z(M_PI), scaling(0.5, 2, 0.5))));
	setup_cone_material(shapes[CONE], create_cone_texture());
	texture = create_scoop_texture();
	shapes[SCOOP1] = sphere();
	shapes[SCOOP2] = sphere();
	shapes[SCOOP3] = sphere();
	setup_scoop(shapes[SCOOP1], texture, 2.0, new_color3(0.4, 0.8, 0.4));
	setup_scoop(shapes[SCOOP2], texture, 2.7, new_color3(1, 0.2, 0.9));
	setup_scoop(shapes[SCOOP3], texture, 3.4, new_color3(0.2, 0.6, 0.9));
	gr = group();
	add_child(gr, shapes[CONE]);
	add_child(gr, shapes[SCOOP1]);
	add_child(gr, shapes[SCOOP2]);
	add_child(gr, shapes[SCOOP3]);
	return (gr);
}
