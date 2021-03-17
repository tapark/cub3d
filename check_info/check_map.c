/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapark <tapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 18:48:26 by tapark            #+#    #+#             */
/*   Updated: 2021/03/04 21:17:20 by tapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_map(t_info *info, char *line, int *i)
{
	int		len;
	char	*line_temp;

	info->map_start = 1;
	len = ft_strlen(line);
	if (len > info->map_width)
		info->map_width = len;
	if (!(line_temp = (char *)malloc(sizeof(char) * (len + 2))))
		return (-6);
	*i = len;
	len = -1;
	while (line[++len] != '\0')
		line_temp[len] = line[len];
	line_temp[len] = '\n';
	line_temp[len + 1] = '\0';
	g_temp = ft_strjoin_free(g_temp, line_temp);
	return (0);
}
