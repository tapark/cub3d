/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapark <tapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 20:04:07 by tapark            #+#    #+#             */
/*   Updated: 2021/03/03 20:07:01 by tapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_floor_ceiling(t_info *info)
{
	int	x;
	int	y;

	y = 0;
	while (y < info->win_h / 2)
	{
		x = 0;
		while (x < info->win_w)
		{
			info->buffer[y][x] = info->color_c;
			x++;
		}
		y++;
	}
	while (y < info->win_h)
	{
		x = 0;
		while (x < info->win_w)
		{
			info->buffer[y][x] = info->color_f;
			x++;
		}
		y++;
	}
}

void	draw_win(t_info *info)
{
	int	x;
	int	y;

	y = 0;
	while (y < info->win_h)
	{
		x = 0;
		while (x < info->win_w)
		{
			info->img.data[y * info->win_w + x] = info->buffer[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}

int		main_loop(t_info *info)
{
	draw_floor_ceiling(info);
	draw_wall(info);
	draw_sprite(info);
	if (info->save == 0)
		draw_win(info);
	return (0);
}
