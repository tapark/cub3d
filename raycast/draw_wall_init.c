/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapark <tapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 20:03:58 by tapark            #+#    #+#             */
/*   Updated: 2021/03/04 21:58:51 by tapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_ray_init(t_info *info, int x)
{
	double	index;

	info->ray.mapx = (int)info->posx;
	info->ray.mapy = (int)info->posy;
	index = 2 * x / (double)info->win_w - 1;
	info->ray.rayx = info->dirx + info->planex * index;
	info->ray.rayy = info->diry + info->planey * index;
	info->ray.deltax = fabs(1 / info->ray.rayx);
	info->ray.deltay = fabs(1 / info->ray.rayy);
}

void	get_ray_side_step(t_info *info)
{
	if (info->ray.rayx < 0)
	{
		info->ray.stepx = -1;
		info->ray.sidex = (info->posx - info->ray.mapx) * info->ray.deltax;
	}
	else
	{
		info->ray.stepx = 1;
		info->ray.sidex = (info->ray.mapx + 1.0 - info->posx)
													* info->ray.deltax;
	}
	if (info->ray.rayy < 0)
	{
		info->ray.stepy = -1;
		info->ray.sidey = (info->posy - info->ray.mapy) * info->ray.deltay;
	}
	else
	{
		info->ray.stepy = 1;
		info->ray.sidey = (info->ray.mapy + 1.0 - info->posy)
													* info->ray.deltay;
	}
}

void	get_wall_dist(t_info *info, int x)
{
	while (g_map[info->ray.mapx][info->ray.mapy] != '1')
	{
		if (info->ray.sidex < info->ray.sidey)
		{
			info->ray.sidex = info->ray.sidex + info->ray.deltax;
			info->ray.mapx = info->ray.mapx + info->ray.stepx;
			info->ray.side = 'x';
		}
		else
		{
			info->ray.sidey = info->ray.sidey + info->ray.deltay;
			info->ray.mapy = info->ray.mapy + info->ray.stepy;
			info->ray.side = 'y';
		}
	}
	info->wall.distx = info->ray.mapx - info->posx + (1 - info->ray.stepx) / 2;
	info->wall.disty = info->ray.mapy - info->posy + (1 - info->ray.stepy) / 2;
	if (info->ray.side == 'x')
		info->wall.distance = info->wall.distx / info->ray.rayx;
	else
		info->wall.distance = info->wall.disty / info->ray.rayy;
	info->zbuffer[x] = info->wall.distance;
}

void	draw_wall_init(t_info *info, int x)
{
	get_ray_init(info, x);
	get_ray_side_step(info);
	get_wall_dist(info, x);
}
