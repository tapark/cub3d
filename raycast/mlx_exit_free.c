/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_exit_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapark <tapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 20:04:10 by tapark            #+#    #+#             */
/*   Updated: 2021/03/16 21:14:29 by tapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		mlx_exit_free(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->map_height)
		free(g_map[i++]);
	free(g_map);
	i = 0;
	while (i < info->sp_num)
		free(info->sprite[i++]);
	free(info->sprite);
	i = 0;
	while (i < 5)
		free(info->path[i++]);
	i = 0;
	while (i < info->win_h)
		free(info->buffer[i++]);
	free(info->buffer);
	mlx_destroy_image(info->mlx, info->img.img);
	free(info->mlx);
	exit(0);
	return (0);
}
