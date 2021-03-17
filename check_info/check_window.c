/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapark <tapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 18:48:35 by tapark            #+#    #+#             */
/*   Updated: 2021/03/03 19:07:09 by tapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx2020/mlx.h"
#include "../cub3d.h"

int	check_window(t_info *info, char *line, int *i)
{
	int	max_w;
	int	max_h;

	if (info->win_w != -1 || info->win_w != -1)
		return (-7);
	mlx_get_screen_size(info->mlx, &max_w, &max_h);
	*i = *i + 1;
	info->win_w = ft_cub_atoi(line, i);
	info->win_h = ft_cub_atoi(line, i);
	if (info->win_w > max_w)
		info->win_w = max_w;
	if (info->win_h > max_h)
		info->win_h = max_h;
	if (info->win_w <= 0 || info->win_h <= 0)
		return (-10);
	if (line[*i] != '\0')
		return (-5);
	return (0);
}
