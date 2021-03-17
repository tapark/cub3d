/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid_temp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapark <tapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 19:43:10 by tapark            #+#    #+#             */
/*   Updated: 2021/03/04 21:17:22 by tapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	temp_check(void)
{
	int		len;
	int		i;
	char	*backup;

	len = ft_strlen(g_temp);
	i = 1;
	while (g_temp[len - i] == '\n')
		i++;
	len = len - i;
	if (!(backup = (char *)malloc(sizeof(char) * (len + 1))))
		return (-1);
	i = -1;
	while (++i < len)
		backup[i] = g_temp[i];
	backup[len] = '\0';
	free(g_temp);
	g_temp = backup;
	return (0);
}

int	is_map_char(int i)
{
	if (g_temp[i] == '0' || g_temp[i] == '1' || g_temp[i] == '2' ||
			g_temp[i] == ' ' || g_temp[i] == 'W' || g_temp[i] == 'S' ||
			g_temp[i] == 'N' || g_temp[i] == 'E' || g_temp[i] == '\n')
		return (1);
	else
		return (0);
}

int	map_valid_temp(t_info *info)
{
	int	i;
	int	pos_index;

	i = 0;
	pos_index = 0;
	temp_check();
	while (is_map_char(i))
	{
		if (g_temp[i] == '2')
			info->sp_num++;
		if (g_temp[i] == ' ')
			g_temp[i] = '1';
		if (g_temp[i] == '\n' && g_temp[i + 1] == '\n')
			return (-3);
		if (g_temp[i] == 'W' || g_temp[i] == 'S' ||
			g_temp[i] == 'N' || g_temp[i] == 'E')
		{
			info->pos_dir = g_temp[i];
			pos_index++;
		}
		i++;
	}
	if (g_temp[i] != '\0' || pos_index != 1)
		return (-3);
	return (0);
}
