/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapark <tapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 20:04:05 by tapark            #+#    #+#             */
/*   Updated: 2021/03/16 21:15:54 by tapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	key_ws(int keycode, t_info *info)
{
	if (keycode == K_W || keycode == K_UP)
	{
		if (g_map[(int)(info->posx + 2 * info->dirx * info->move)]
				[(int)info->posy] == '0')
			info->posx = info->posx + info->dirx * info->move;
		if (g_map[(int)info->posx]
				[(int)(info->posy + 2 * info->diry * info->move)] == '0')
			info->posy = info->posy + info->diry * info->move;
	}
	if (keycode == K_S || keycode == K_DOWN)
	{
		if (g_map[(int)(info->posx - 2 * info->dirx * info->move)]
				[(int)info->posy] == '0')
			info->posx = info->posx - info->dirx * info->move;
		if (g_map[(int)info->posx]
				[(int)(info->posy - 2 * info->diry * info->move)] == '0')
			info->posy = info->posy - info->diry * info->move;
	}
}

void	key_ad(int keycode, t_info *info)
{
	if (keycode == K_A)
	{
		if (g_map[(int)(info->posx - 2 * info->diry * info->move)]
				[(int)info->posy] == '0')
			info->posx = info->posx - info->diry * info->move;
		if (g_map[(int)info->posx]
				[(int)(info->posy + 2 * info->dirx * info->move)] == '0')
			info->posy = info->posy + info->dirx * info->move;
	}
	if (keycode == K_D)
	{
		if (g_map[(int)(info->posx + 2 * info->diry * info->move)]
				[(int)info->posy] == '0')
			info->posx = info->posx + info->diry * info->move;
		if (g_map[(int)info->posx]
				[(int)(info->posy - 2 * info->dirx * info->move)] == '0')
			info->posy = info->posy - info->dirx * info->move;
	}
}

void	key_left_right(int keycode, t_info *info)
{
	double old_dx;
	double old_px;

	if (keycode == K_RIGHT)
	{
		old_dx = info->dirx;
		info->dirx = info->dirx * cos(-info->rot)
									- info->diry * sin(-info->rot);
		info->diry = old_dx * sin(-info->rot) + info->diry * cos(-info->rot);
		old_px = info->planex;
		info->planex = info->planex * cos(-info->rot)
									- info->planey * sin(-info->rot);
		info->planey = old_px * sin(-info->rot)
									+ info->planey * cos(-info->rot);
	}
	if (keycode == K_LEFT)
	{
		old_dx = info->dirx;
		info->dirx = info->dirx * cos(info->rot) - info->diry * sin(info->rot);
		info->diry = old_dx * sin(info->rot) + info->diry * cos(info->rot);
		old_px = info->planex;
		info->planex = info->planex * cos(info->rot)
									- info->planey * sin(info->rot);
		info->planey = old_px * sin(info->rot) + info->planey * cos(info->rot);
	}
}

int		key_press(int keycode, t_info *info)
{
	if (keycode == K_W || keycode == K_S
		|| keycode == K_UP || keycode == K_DOWN)
		key_ws(keycode, info);
	if (keycode == K_A || keycode == K_D)
		key_ad(keycode, info);
	if (keycode == K_LEFT || keycode == K_RIGHT)
		key_left_right(keycode, info);
	if (keycode == K_ESC)
		mlx_exit_free(info);
	return (0);
}
