/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group_objs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:32:53 by mdomnik           #+#    #+#             */
/*   Updated: 2025/01/16 16:19:44 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

t_shape *ice_cream_cone(void)
{
	t_shape *c;
	t_shape *scoop;
	t_shape *scoop2;
	t_shape *scoop3;
	t_shape *cone_scoop;

    t_canvas *waffle = canvas_from_ppm("textures/waffle.ppm");
    t_pattern *waffle_pattern = uv_image(waffle);
    t_pattern *cone_texture = texture_map(waffle_pattern, cylindrical_map);
	
	set_pattern_transform(cone_texture, scaling(2, 2, 2));
	c = cone();
	set_transform(c, multiply_matrices(translation(0, -1, 0), multiply_matrices(rotation_z(M_PI), scaling(0.5, 2, 0.5))));
	c->material.color = new_color3_p(1, 0.5, 0.5);
	c->material.pattern = cone_texture;
	c->material.bump_map = bump_map_from_ppm("textures/waffle_bump.ppm", 2, cylindrical_map);
	c->material.diffuse = 0.7;
	c->material.specular = 0.3;
	c->material.shininess = 200.0;
	c->material.reflective = 0.2;
	c->material.transparency = 0.0;
	c->material.refractive_index = 1.0;


	t_canvas *scoop_look = canvas_from_ppm("textures/choc_scoop.ppm");
    t_pattern *scoop_look_pattern = uv_image(scoop_look);
    t_pattern *scoop_texture = texture_map(scoop_look_pattern, cylindrical_map);
	
	scoop = sphere();
	set_transform(scoop, multiply_matrices(translation(0, 2, 0),scaling(0.5, 0.5, 0.5)));
	scoop->material.color = new_color3_p(0.4, 0.8, 0.4);
	scoop->material.pattern = scoop_texture;
	scoop->material.bump_map = bump_map_from_ppm("textures/choc_scoop_bump.ppm", 1, spherical_map);
	scoop->material.diffuse = 0.7;
	scoop->material.specular = 0.3;
	scoop->material.shininess = 200.0;
	scoop->material.reflective = 0.2;

	scoop2 = sphere();
	set_transform(scoop2, multiply_matrices(translation(0, 2.7, 0),scaling(0.5, 0.5, 0.5)));
	scoop2->material.color = new_color3_p(1, 0.2, 0.9);
	scoop2->material.pattern = scoop_texture;
	scoop2->material.bump_map = bump_map_from_ppm("textures/choc_scoop_bump.ppm", 5, spherical_map);
	scoop2->material.diffuse = 0.7;
	scoop2->material.specular = 0.3;
	scoop2->material.shininess = 200.0;
	scoop2->material.reflective = 0.2;

	scoop3 = sphere();
	set_transform(scoop3, multiply_matrices(translation(0, 3.4, 0),scaling(0.5, 0.5, 0.5)));
	scoop3->material.color = new_color3_p(0.2, 0.6, 0.9);
	scoop3->material.pattern = scoop_texture;
	scoop3->material.bump_map = bump_map_from_ppm("textures/choc_scoop_bump.ppm", 5, spherical_map);
	scoop3->material.diffuse = 0.7;
	scoop3->material.specular = 0.3;
	scoop3->material.shininess = 200.0;
	scoop3->material.reflective = 0.2;

	cone_scoop = group();
	add_child(cone_scoop, c);
	add_child(cone_scoop, scoop);
	add_child(cone_scoop, scoop2);
	add_child(cone_scoop, scoop3);
	return (cone_scoop);	
}
