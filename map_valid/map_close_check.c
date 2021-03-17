/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_close_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapark <tapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 19:43:00 by tapark            #+#    #+#             */
/*   Updated: 2021/03/04 21:57:08 by tapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	land_dir_close_check(t_info *info, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			if (g_map[i][j] == info->pos_dir)
			{
				info->posx = i + 0.5;
				info->posy = j + 0.5;
				g_map[i][j] = '0';
			}
			if (g_map[i][j] == '0' && g_map[i][j + 1] == ' ')
				return (-1);
			if (g_map[i][j] == ' ' && g_map[i][j + 1] == '0')
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ver_dir_close_check(int x, int y)
{
	int i;
	int j;

	i = 0;
	while (i < y - 1)
	{
		j = 0;
		while (j < x)
		{
			if (g_map[i][j] == '0' && g_map[i + 1][j] == ' ')
				return (-1);
			if (g_map[i][j] == ' ' && g_map[i + 1][j] == '0')
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	map_close_check(t_info *info, int x, int y)
{
	if (land_dir_close_check(info, x, y) != 0)
		return (-1);
	if (ver_dir_close_check(x, y) != 0)
		return (-1);
	return (0);
}
