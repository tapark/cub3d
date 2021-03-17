/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapark <tapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 19:43:05 by tapark            #+#    #+#             */
/*   Updated: 2021/03/04 21:17:21 by tapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_map_height(char const *s, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			n++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (n);
}

int	map_valid_map(t_info *info)
{
	int	x;
	int	y;

	x = info->map_width;
	info->map_height = get_map_height(g_temp, '\n');
	y = info->map_height;
	if (split_temp_to_map(x, y) != 0)
		return (-1);
	if (map_boundary_check(x, y) != 0)
		return (-1);
	if (map_close_check(info, x, y) != 0)
		return (-1);
	return (0);
}
