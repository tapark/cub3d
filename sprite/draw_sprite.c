/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapark <tapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 20:24:45 by tapark            #+#    #+#             */
/*   Updated: 2021/03/04 21:58:51 by tapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_sprite_init(t_info *info, int n)
{
	info->sp.sx = info->sprite[n][0] - info->posx;
	info->sp.sy = info->sprite[n][1] - info->posy;
	info->sp.tx = (info->diry * info->sp.sx - info->dirx * info->sp.sy)
					/ (info->planex * info->diry - info->planey * info->dirx);
	info->sp.ty = (-info->planey * info->sp.sx + info->planex * info->sp.sy)
					/ (info->planex * info->diry - info->planey * info->dirx);
	info->sp.screenx = (int)(info->win_w / 2 * (1 + info->sp.tx / info->sp.ty));
	info->sp.screeny = (int)(info->win_h / 2);
	info->sp.sp_w = abs((int)(info->win_h / info->sp.ty));
	info->sp.sp_h = abs((int)(info->win_h / info->sp.ty));
}

void	get_sprite_range(t_info *info)
{
	info->sp.startx = (int)(info->sp.screenx - info->sp.sp_w / 2);
	info->sp.endx = (int)(info->sp.screenx + info->sp.sp_w / 2);
	if (info->sp.startx < 0)
		info->sp.startx = 0;
	if (info->sp.endx > info->win_w - 1)
		info->sp.endx = info->win_w - 1;
	info->sp.starty = (int)(info->sp.screeny - info->sp.sp_h / 2);
	info->sp.endy = (int)(info->sp.screeny + info->sp.sp_h / 2);
	if (info->sp.starty < 0)
		info->sp.starty = 0;
	if (info->sp.endy > info->win_h - 1)
		info->sp.endy = info->win_h - 1;
}

void	sprite_to_buffer(t_info *info, int sp_x, int sp_y)
{
	if (0 < info->sp.ty && info->sp.ty < info->zbuffer[sp_x])
	{
		info->sp.sp_color = info->texture[4]
							[info->sp.sp_texy * TEX_W + info->sp.sp_texx];
		if (info->sp.sp_color != 0)
			info->buffer[sp_y][sp_x] = info->sp.sp_color;
	}
}

void	draw_sprite(t_info *info)
{
	int n;
	int sp_x;
	int sp_y;

	n = -1;
	draw_sprite_init(info);
	while (++n < info->sp_num)
	{
		get_sprite_init(info, n);
		get_sprite_range(info);
		sp_x = info->sp.startx - 1;
		while (++sp_x < info->sp.endx)
		{
			info->sp.sp_texx = (sp_x - (info->sp.screenx -
								info->sp.sp_w / 2)) * TEX_W / info->sp.sp_w;
			sp_y = info->sp.starty - 1;
			while (++sp_y < info->sp.endy)
			{
				info->sp.sp_texy = (sp_y - (info->sp.screeny -
									info->sp.sp_h / 2)) * TEX_H / info->sp.sp_h;
				sprite_to_buffer(info, sp_x, sp_y);
			}
		}
	}
}
