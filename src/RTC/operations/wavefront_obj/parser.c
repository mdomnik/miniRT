/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 22:54:30 by mdomnik           #+#    #+#             */
/*   Updated: 2025/01/17 18:30:11 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

static t_group *create_group(const char *name)
{
	t_group *g = malloc(sizeof(t_group));
	g->name = ft_strdup(name);
	g->group = group();
	g->next = NULL;
	return g;
}

static void add_triangle_to_group(t_group *g, t_triangle *tri)
{
	t_shape *t = triangle(tri->p1, tri->p2, tri->p3);
	add_child(g->group, t);
}

// Add a group to the default group chain
static void add_group_to_default(t_obj_file *obj_file, t_group *group)
{
	if (!obj_file->default_group)
		obj_file->default_group = group;
	else
	{
		t_group *current = obj_file->default_group;
		while (current->next)
			current = current->next;
		current->next = group;
	}
}

static void fan_triangulation(t_group *group, t_obj_file *obj_file, int *indices, int count) {
    // Ensure the face has at least three vertices
    if (count < 3) {
        fprintf(stderr, "Face has fewer than 3 vertices, skipping\n");
        return;
    }

    // Fan triangulation: Always use the first vertex as p1
    for (int i = 1; i < count - 1; i++) {
        int v1 = indices[0];
        int v2 = indices[i];
        int v3 = indices[i + 1];

        // Ensure indices are valid
        if (v1 > 0 && v1 <= obj_file->vertex_count &&
            v2 > 0 && v2 <= obj_file->vertex_count &&
            v3 > 0 && v3 <= obj_file->vertex_count) {

            t_triangle triangle = {
                .p1 = obj_file->vertices[v1],
                .p2 = obj_file->vertices[v2],
                .p3 = obj_file->vertices[v3]
            };

            // Add triangle to the group
            add_triangle_to_group(group, &triangle);
        } else {
            fprintf(stderr, "Face references out-of-bounds vertex indices\n");
        }
    }
}

t_obj_file *parse_obj_file(const char *filename) {
    t_obj_file *obj_file = malloc(sizeof(t_obj_file));
    if (!obj_file) {
        fprintf(stderr, "Memory allocation failed for OBJ file structure\n");
        exit(EXIT_FAILURE);
    }
    obj_file->vertex_count = 0;
    obj_file->face_count = 0;
    obj_file->default_group = create_group("Default");

    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Failed to open file: %s\n", filename);
        free(obj_file);
        exit(EXIT_FAILURE);
    }

    t_group *current_group = obj_file->default_group;
    char *line = NULL;
    size_t len = 0;

    while (getline(&line, &len, file) != -1) {
        if (line[0] == 'v' && isspace(line[1])) {
            // Handle vertex
            if (obj_file->vertex_count >= MAX_VERTEX_COUNT) {
                fprintf(stderr, "Exceeded maximum vertex count: %d\n", MAX_VERTEX_COUNT);
                break;
            }

            float x, y, z;
            if (sscanf(line, "v %f %f %f", &x, &y, &z) == 3) {
                obj_file->vertices[++obj_file->vertex_count] = new_point3(x, y, z);
            } else {
                fprintf(stderr, "Malformed vertex line: %s\n", line);
            }
        } else if (line[0] == 'g' && isspace(line[1])) {
            // Handle group
            char group_name[64];
            if (sscanf(line, "g %63s", group_name) == 1) {
                t_group *new_group = create_group(group_name);
                add_group_to_default(obj_file, new_group);
                current_group = new_group;
            } else {
                fprintf(stderr, "Malformed group line: %s\n", line);
            }
        } else if (line[0] == 'f' && isspace(line[1])) {
            // Handle face
            int indices[64]; // Adjust size based on expected max vertices in a face
            int count = 0;

            // Parse all indices in the face line
            char *token = strtok(line + 2, " \t");
            while (token && count < 64) {
                if (sscanf(token, "%d", &indices[count]) == 1) {
                    count++;
                } else {
                    fprintf(stderr, "Malformed face line: %s\n", line);
                    break;
                }
                token = strtok(NULL, " \t");
            }

            // Perform triangulation
            fan_triangulation(current_group, obj_file, indices, count);
        }
    }

    free(line);
    fclose(file);
    return obj_file;
}



