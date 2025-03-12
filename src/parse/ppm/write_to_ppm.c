/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_to_ppm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:39:02 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/12 21:56:44 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

t_canvas	*canvas_new(t_canvas *canv, int width, int height)
{
	int			i;
	int			j;

	canv->pixels = malloc(sizeof(t_color3 *) * height);
	i = 0;
	while (i < height)
	{
		j = -1;
		canv->pixels[i] = malloc(sizeof(t_color3) * width);
		while (++j < width)
			canv->pixels[i][j] = new_color3(0, 0, 0);
		i++;
	}
	return (canvas);
}

static void	create_directory(const char *path)
{
	struct stat	st = {0};
	if (stat(path, &st) == -1)
		mkdir(path, 0700);
}

void	save_image(t_image *img, char *filename)
{
	int				fd;
	int				x;
	int				y;
	int				offset;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	char 			*file_name;

	if (!img || !img->buffer)
	{
		 ft_dprintf(2, "Error: Invalid image data.\n");
		return ;
	}
	file_name = ft_strjoin(filename, ".ppm");
	fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	free(file_name);
	if (!fd)
	{
		ft_dprintf(2, "Error: Could not open file for writing.\n");
		return ;
	}
	ft_dprintf(fd, "P3\n%d %d\n255\n", img->width, img->height);
	for (y = 0; y < img->height; y++)
	{
		for (x = 0; x < img->width; x++)
		{
			offset = (y * img->size_line) + (x * (img->bits_per_pixel / 8));
			if (img->endian == 0)
			{
				b = (unsigned char)img->buffer[offset];
				g = (unsigned char)img->buffer[offset + 1];
				r = (unsigned char)img->buffer[offset + 2];
			}
			else
			{
				r = (unsigned char)img->buffer[offset];
				g = (unsigned char)img->buffer[offset + 1];
				b = (unsigned char)img->buffer[offset + 2];
			}
			 ft_dprintf(fd, "%d %d %d\n", r, g, b);
		}
	}
	close(fd);
	printf("\033[1;35mImage saved as %s\033[0m\n", filename);
}
