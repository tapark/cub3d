/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_save.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapark <tapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 18:48:29 by tapark            #+#    #+#             */
/*   Updated: 2021/03/04 20:41:44 by tapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_save(char *save)
{
	int	len;

	len = ft_strlen(save);
	if (save == NULL || len != 6)
		return (0);
	if (save[0] == '-' && save[1] == '-' && save[2] == 's'
		&& save[3] == 'a' && save[4] == 'v' && save[5] == 'e')
		return (1);
	return (0);
}
