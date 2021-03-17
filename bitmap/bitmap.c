/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapark <tapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 18:46:01 by tapark            #+#    #+#             */
/*   Updated: 2021/03/16 21:14:56 by tapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	bmp_file_header(t_info *info, int fd)
{
	int				i;
	unsigned char	bmp_file[14];

	i = 0;
	while (i < 14)
		bmp_file[i++] = 0;
	bmp_file[0] = 66;
	bmp_file[1] = 77;
	i = info->win_w * info->win_h * 4 + 54;
	bmp_file[2] = i % 256;
	bmp_file[3] = i / 256 % 256;
	bmp_file[4] = i / 256 / 256 % 256;
	bmp_file[5] = i / 256 / 256 / 256;
	bmp_file[10] = 54;
	write(fd, bmp_file, 14);
}

void	bmp_info_header(t_info *info, int fd)
{
	int				i;
	unsigned char	bmp_info[40];

	i = 0;
	while (i < 40)
		bmp_info[i++] = 0;
	bmp_info[0] = 40;
	bmp_info[4] = info->win_w % 256;
	bmp_info[5] = info->win_w / 256 % 256;
	bmp_info[6] = info->win_w / 256 / 256 % 256;
	bmp_info[7] = info->win_w / 256 / 256 / 256;
	bmp_info[8] = info->win_h % 256;
	bmp_info[9] = info->win_h / 256 % 256;
	bmp_info[10] = info->win_h / 256 / 256 % 256;
	bmp_info[11] = info->win_h / 256 / 256 / 256;
	bmp_info[12] = 1;
	bmp_info[14] = 32;
	write(fd, bmp_info, 40);
}

void	bmp_pixel_data(t_info *info, int fd)
{
	int				x;
	int				y;
	unsigned char	bmp_pix[4];

	y = info->win_h - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < info->win_w)
		{
			bmp_pix[0] = info->buffer[y][x] % 256;
			bmp_pix[1] = info->buffer[y][x] / 256 % 256;
			bmp_pix[2] = info->buffer[y][x] / 256 / 256;
			bmp_pix[3] = 0;
			write(fd, bmp_pix, 4);
			x++;
		}
		y--;
	}
}

void	bitmap(t_info *info)
{
	int fd;

	main_loop(info);
	fd = open("ScreenShot.bmp", O_CREAT | O_RDWR | O_TRUNC, S_IRWXU);
	bmp_file_header(info, fd);
	bmp_info_header(info, fd);
	bmp_pixel_data(info, fd);
	close(fd);
	mlx_exit_free(info);
}
