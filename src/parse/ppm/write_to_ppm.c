/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_to_ppm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:39:02 by mdomnik           #+#    #+#             */
/*   Updated: 2025/03/14 17:29:53 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

#define FD 0
#define OFFSET 2

static void	write_number(int fd, int num)
{
	char	buffer[12];
	int		i;
	int		temp;

	if (num == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	i = 0;
	temp = num;
	while (temp > 0)
	{
		buffer[i++] = (temp % 10) + '0';
		temp /= 10;
	}
	while (--i >= 0)
		write(fd, &buffer[i], 1);
}

static void	write_ppm_header(int fd, t_image *img)
{
	write(fd, "P3\n", 3);
	write_number(fd, img->width);
	write(fd, " ", 1);
	write_number(fd, img->height);
	write(fd, "\n255\n", 5);
}

static void	extract_pixel_data(t_image *img, int offset, unsigned char *c)
{
	if (img->endian == 0)
	{
		c[B] = (unsigned char)img->buffer[offset];
		c[G] = (unsigned char)img->buffer[offset + 1];
		c[R] = (unsigned char)img->buffer[offset + 2];
	}
	else
	{
		c[R] = (unsigned char)img->buffer[offset];
		c[G] = (unsigned char)img->buffer[offset + 1];
		c[B] = (unsigned char)img->buffer[offset + 2];
	}
}

static void	write_ppm_pixels(int fd, t_image *img)
{
	int				a[3];
	unsigned char	c[3];

	a[Y] = 0;
	while (a[Y] < img->height)
	{
		a[X] = 0;
		while (a[X] < img->width)
		{
			a[OFFSET] = (a[Y] * img->size_line)
				+ (a[X] * (img->bits_per_pixel / 8));
			extract_pixel_data(img, a[OFFSET], c);
			write_number(fd, c[R]);
			write(fd, " ", 1);
			write_number(fd, c[G]);
			write(fd, " ", 1);
			write_number(fd, c[B]);
			write(fd, "\n", 1);
			a[X]++;
		}
		a[Y]++;
	}
}

void	save_image(t_image *img, char *filename)
{
	int	fd;

	if (!img || !img->buffer)
	{
		ft_dprintf(2, "Error: Invalid image data.\n");
		return ;
	}
	fd = open_ppm_file(filename);
	if (fd < 0)
		return ;
	write_ppm_header(fd, img);
	write_ppm_pixels(fd, img);
	close(fd);
}
