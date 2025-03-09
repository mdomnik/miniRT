/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_from_ppm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:18:27 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/09 12:18:22 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

static int ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r');
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
            while (ft_isspace(*ptr)) ptr++;

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

// static t_canvas	*process_ppm_header(FILE *file, int *color_max)
// {
// 	char		*line;
// 	t_canvas	*canvas;

// 	line = skip_comments(file);
// 	if (!line || check_ppm_magic_number(line) == -1)
// 		return (free(line), ft_dprintf(2, "Error: %s\n", ERR_PPM_FORMAT), NULL);
// 	free(line);
// 	canvas = malloc(sizeof(t_canvas));
// 	if (!canvas)
// 		return (ft_dprintf(2, "Error: %s\n", ERR_MEMORY), NULL);
// 	line = skip_comments(file);
// 	if (canvas_from_ppm_dimensions(canvas, line) != 0)
// 		return (free(line), ft_dprintf(2, "Error: %s\n", ERR_PPM_FORMAT), NULL);
// 	free(line);
// 	line = skip_comments(file);
// 	*color_max = atoi(line);
// 	free(line);
// 	return (canvas);
// }

// t_canvas	*canvas_from_ppm(const char *filename)
// {
// 	FILE		*file;
// 	t_canvas	*canvas;
// 	int			color_max;

// 	file = fopen(filename, "r");
// 	if (!file)
// 		return (ft_dprintf(2, "Error: %s\n", ERR_OPEN_FILE), NULL);
// 	canvas = process_ppm_header(file, &color_max);
// 	if (!canvas)
// 		return (fclose(file), NULL);
// 	if (color_max > 255)
// 		return (ft_dprintf(2, "Error:%s\n", ERR_COLOR_MAX), fclose(file), NULL);
// 	canvas = canvas_new(canvas->width, canvas->height);
// 	canvas_from_ppm_pixels(file, canvas, color_max);
// 	return (fclose(file), canvas);
// }
