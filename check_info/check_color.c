/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapark <tapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 18:48:08 by tapark            #+#    #+#             */
/*   Updated: 2021/03/03 19:06:15 by tapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_color(t_info *info, char *line, int *i, int *color)
{
	int	r;
	int	g;
	int	b;

	if (*color != -1)
		return (-7);
	*i = *i + 1;
	r = ft_cub_atoi(line, i);
	if (line[*i] == ',')
		*i = *i + 1;
	g = ft_cub_atoi(line, i);
	if (line[*i] == ',')
		*i = *i + 1;
	b = ft_cub_atoi(line, i);
	if (r > 255 || g > 255 || b > 255 || r < 0 || g < 0 || b < 0)
		return (-9);
	*color = r * 256 * 256 + g * 256 + b;
	if (line[*i] != '\0')
		return (-5);
	if (info->color_c == info->color_f)
		return (-9);
	return (0);
}
