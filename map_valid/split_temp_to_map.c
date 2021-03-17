/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_temp_to_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapark <tapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 19:43:13 by tapark            #+#    #+#             */
/*   Updated: 2021/03/05 01:12:21 by tapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	malloc_map(int x, int y)
{
	int	i;
	int	j;

	if (!(g_map = (char **)malloc(sizeof(char *) * y)))
		return (-1);
	i = 0;
	while (i < y)
	{
		if (!(g_map[i++] = (char *)malloc(sizeof(char) * (x + 1))))
			return (-1);
	}
	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
			g_map[i][j++] = ' ';
		g_map[i][j] = '\0';
		i++;
	}
	return (0);
}

int	split_map(int y)
{
	char	**split;
	int		i;
	int		j;

	split = ft_split(g_temp, '\n');
	i = -1;
	while (++i < y)
	{
		j = -1;
		while (++j < ft_strlen(split[i]))
			g_map[i][j] = split[i][j];
	}
	free(g_temp);
	i = -1;
	while (++i < y)
		free(split[i]);
	free(split);
	return (0);
}

int	split_temp_to_map(int x, int y)
{
	if (malloc_map(x, y) != 0)
		return (-1);
	if (split_map(y) != 0)
		return (-1);
	return (0);
}
