/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_info_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapark <tapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 18:48:23 by tapark            #+#    #+#             */
/*   Updated: 2021/03/03 18:55:13 by tapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_info_all(t_info *info)
{
	if (info->win_w < 0 || info->win_h < 0)
		return (-1);
	if (info->color_c < 0 || info->color_f < 0)
		return (-1);
	if (info->path[0] == NULL || info->path[1] == NULL || info->path[2] == NULL
		|| info->path[3] == NULL || info->path[4] == NULL)
		return (-1);
	if (info->map_start == 0)
		return (-1);
	return (0);
}
