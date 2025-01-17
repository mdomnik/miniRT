/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_ppm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 22:14:06 by mdomnik           #+#    #+#             */
/*   Updated: 2025/01/17 22:12:45 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

int	isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}
// canvas_write_pixel function remains unchanged
void canvas_write_pixel(t_canvas *canvas, int x, int y, t_color3 color) {
    if (x < 0 || x >= canvas->width || y < 0 || y >= canvas->height) {
        fprintf(stderr, "Error: %s\n", ERR_WRITE_PIXEL);
        exit(EXIT_FAILURE);
    }
    canvas->pixels[y][x] = color;
}

char *skip_comments(FILE *file) {
    char *line = NULL;
    size_t len = 0;

    while (getline(&line, &len, file) != -1) {
        // Trim leading whitespace
        char *ptr = line;
        while (isspace(*ptr)) ptr++;

        // Skip empty lines or lines starting with '#'
        if (*ptr == '\0' || *ptr == '#') {
            free(line);
            line = NULL;
            continue;
        }

        return line; // Valid line found
    }

    free(line); // Cleanup if EOF is reached
    return NULL;
}

void canvas_from_ppm_pixels(FILE *file, t_canvas *canvas, int color_max) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    float scale_factor = 1.0f / color_max;
    int x = 0, y = 0;

    // Temporary storage for RGB values
    int r = -1, g = -1, b = -1;

    while ((read = getline(&line, &len, file)) != -1) {
        char *ptr = line;

        while (*ptr) {
            // Skip leading whitespace
            while (isspace(*ptr)) ptr++;

            // Parse RGB values
            int read_count = sscanf(ptr, "%d %d %d", &r, &g, &b);
            if (read_count == 3) {
                t_color3 color = new_color3(
                    r * scale_factor,
                    g * scale_factor,
                    b * scale_factor
                );
                canvas_write_pixel(canvas, x, y, color);

                // Move to the next pixel
                x++;
                if (x >= canvas->width) {
                    x = 0;
                    y++;
                    if (y >= canvas->height)
                        break;
                }

                // Advance the pointer past the parsed values
                ptr = strchr(ptr, ' ');
                if (ptr) ptr = strchr(ptr + 1, ' ');
                if (ptr) ptr = strchr(ptr + 1, ' ');
            } else {
                break; // Stop parsing this line if we can't read 3 integers
            }
        }

        free(line);
        line = NULL;

        if (y >= canvas->height)
            break;
    }

    free(line);

    if (r == -1 || g == -1 || b == -1) {
        fprintf(stderr, "Error: %s\n", ERR_INCOMPLETE_RGB);
        exit(EXIT_FAILURE);
    }
}


int check_ppm_magic_number(char *line) {
    int i = 0, j = 0;

    if (strncmp(line, "P3", 2) != 0)
        return -1;

    while (line[i] != '\0') {
        if (!isspace(line[i]))
            j++;
        i++;
    }

    return (j == 2) ? 0 : -1;
}

int canvas_from_ppm_dimensions(t_canvas *canvas, char *line) {
    int width, height;
    if (sscanf(line, "%d %d", &width, &height) != 2)
        return -1;

    canvas->width = width;
    canvas->height = height;
    return 0;
}

t_canvas *canvas_from_ppm(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: %s\n", ERR_OPEN_FILE);
        return NULL;
    }

    char *line = skip_comments(file);
    if (!line || check_ppm_magic_number(line) == -1) {
        fprintf(stderr, "Error: %s\n", ERR_PPM_FORMAT);
        free(line);
        fclose(file);
        return NULL;
    }
    free(line);

    t_canvas *canvas = malloc(sizeof(t_canvas));
    if (!canvas) {
        fprintf(stderr, "Error: %s\n", ERR_MEMORY);
        fclose(file);
        return NULL;
    }

    line = skip_comments(file);
    if (canvas_from_ppm_dimensions(canvas, line) != 0) {
        fprintf(stderr, "Error: %s\n", ERR_PPM_FORMAT);
        free(line);
        fclose(file);
        return NULL;
    }
    free(line);

    line = skip_comments(file);
    int color_max = atoi(line);
    free(line);

    if (color_max > 255) {
        fprintf(stderr, "Error: %s\n", ERR_COLOR_MAX);
        fclose(file);
        return NULL;
    }

    canvas = canvas_new(canvas->width, canvas->height);
    canvas_from_ppm_pixels(file, canvas, color_max);

    fclose(file);
    return canvas;
}
