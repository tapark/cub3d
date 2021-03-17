/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapark <tapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 18:48:16 by tapark            #+#    #+#             */
/*   Updated: 2021/03/04 20:37:35 by tapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_file_name(char *file, char *ex)
{
	int	len;

	len = ft_strlen(file);
	if (file == NULL || len < 5)
		return (0);
	if (file[len - 4] == ex[0] && file[len - 3] == ex[1]
		&& file[len - 2] == ex[2] && file[len - 1] == ex[3])
		return (1);
	return (0);
}
