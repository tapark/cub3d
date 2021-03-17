/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sprite_buffer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapark <tapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 20:24:49 by tapark            #+#    #+#             */
/*   Updated: 2021/03/04 21:58:51 by tapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_sprite_buffer(t_info *info)
{
	int	i;

	i = 0;
	if (!(info->sprite = (double **)malloc(sizeof(double *) * info->sp_num)))
		return (-1);
	while (i < info->sp_num)
	{
		if (!(info->sprite[i++] = (double *)malloc(sizeof(double) * 3)))
			return (-1);
	}
	i = 0;
	if (!(info->buffer = (int **)malloc(sizeof(int *) * info->win_h)))
		return (-1);
	while (i < info->win_h)
	{
		if (!(info->buffer[i++] = (int *)malloc(sizeof(int) * info->win_w)))
			return (-1);
	}
	if (!(info->zbuffer = (double *)malloc(sizeof(double) * info->win_w)))
		return (-1);
	return (0);
}
