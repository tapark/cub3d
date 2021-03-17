/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapark <tapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 20:04:02 by tapark            #+#    #+#             */
/*   Updated: 2021/03/04 21:57:21 by tapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_tex_x(t_info *info)
{
	info->wall.height = (int)(info->win_h / info->wall.distance);
	info->wall.start = info->win_h / 2 - info->wall.height / 2;
	info->wall.end = info->win_h / 2 + info->wall.height / 2;
	if (info->wall.start < 0)
		info->wall.start = 0;
	if (info->wall.end > info->win_h - 1)
		info->wall.end = info->win_h - 1;
	if (info->ray.side == 'x')
		info->tex.wallx = info->posy + info->ray.rayy
							/ info->ray.rayx * info->wall.distx;
	else
		info->tex.wallx = info->posx + info->ray.rayx
							/ info->ray.rayy * info->wall.disty;
	info->tex.wallx = info->tex.wallx - floor(info->tex.wallx);
	info->tex.texx = (int)(info->tex.wallx * (double)TEX_W);
	if (info->ray.side == 'x' && info->ray.rayx > 0)
		info->tex.texx = TEX_W - info->tex.texx - 1;
	if (info->ray.side == 'y' && info->ray.rayy < 0)
		info->tex.texx = TEX_W - info->tex.texx - 1;
	info->tex.step = 1.0 * TEX_H / info->wall.height;
	info->tex.pos = (info->wall.start - info->win_h / 2
						+ info->wall.height / 2) * info->tex.step;
}

void	get_tex_num(t_info *info)
{
	if (info->ray.side == 'x')
	{
		if (info->ray.rayx > 0)
			info->tex.tex_num = 1;
		else
			info->tex.tex_num = 0;
	}
	else
	{
		if (info->ray.rayy > 0)
			info->tex.tex_num = 3;
		else
			info->tex.tex_num = 2;
	}
}

void	get_tex_y(t_info *info, int x, int y)
{
	info->tex.texy = (int)info->tex.pos & (TEX_H - 1);
	info->wall.color = info->texture[info->tex.tex_num]
						[info->tex.texy * TEX_W + info->tex.texx];
	if (info->ray.side == 'y')
		info->wall.color = (info->wall.color >> 1) & 8355711;
	info->buffer[y][x] = info->wall.color;
	info->tex.pos = info->tex.pos + info->tex.step;
}

void	draw_wall(t_info *info)
{
	int	x;
	int	y;

	x = 0;
	while (x < info->win_w)
	{
		draw_wall_init(info, x);
		get_tex_x(info);
		get_tex_num(info);
		y = info->wall.start;
		while (y <= info->wall.end)
		{
			get_tex_y(info, x, y);
			y++;
		}
		x++;
	}
}
