/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_boundary_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapark <tapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 19:42:51 by tapark            #+#    #+#             */
/*   Updated: 2021/03/04 21:30:39 by tapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	map_top_bottom_check(int y)
{
	int	i;

	i = 0;
	while (g_map[0][i] == '1')
		i++;
	while (g_map[0][i] == ' ')
		i++;
	if (g_map[0][i] != '\0')
		return (-1);
	i = 0;
	while (g_map[y - 1][i] == '1')
		i++;
	while (g_map[y - 1][i] == ' ')
		i++;
	if (g_map[y - 1][i] != '\0')
		return (-1);
	return (0);
}

int	map_left_right_check(int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < y)
	{
		if (g_map[i][0] != '1')
			return (-1);
		i++;
	}
	i = 0;
	while (i < y)
	{
		j = x;
		while (g_map[i][j - 1] == ' ')
			j--;
		if (g_map[i][j - 1] != '1')
			return (-1);
		i++;
	}
	return (0);
}

int	map_boundary_check(int x, int y)
{
	if (map_top_bottom_check(y) != 0)
		return (-1);
	if (map_left_right_check(x, y) != 0)
		return (-1);
	return (0);
}
