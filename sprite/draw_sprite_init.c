/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapark <tapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 20:24:41 by tapark            #+#    #+#             */
/*   Updated: 2021/03/04 21:57:08 by tapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_sprite_coord(t_info *info)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (i < info->map_height)
	{
		j = 0;
		while (j < info->map_width)
		{
			if (g_map[i][j] == '2')
			{
				info->sprite[k][0] = i + 0.5;
				info->sprite[k][1] = j + 0.5;
				info->sprite[k][2] = pow(info->sprite[k][0] - info->posx, 2)
									+ pow(info->sprite[k][1] - info->posy, 2);
				k++;
			}
			j++;
		}
		i++;
	}
}

void	sort_sprite(t_info *info)
{
	int		i;
	int		j;
	double	*tmp;

	i = 0;
	while (i < info->sp_num)
	{
		j = i;
		while (j < info->sp_num - 1)
		{
			if (info->sprite[i][2] < info->sprite[j + 1][2])
			{
				tmp = info->sprite[i];
				info->sprite[i] = info->sprite[j + 1];
				info->sprite[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	draw_sprite_init(t_info *info)
{
	get_sprite_coord(info);
	sort_sprite(info);
}
