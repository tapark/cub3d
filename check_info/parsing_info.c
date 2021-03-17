/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapark <tapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 18:48:43 by tapark            #+#    #+#             */
/*   Updated: 2021/03/05 01:49:46 by tapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_information(t_info *info, char *line)
{
	int i;

	i = 0;
	info->err_n = 0;
	if (line[i] == ' ' || line[i] == '1' || info->map_start == 1)
		info->err_n = check_map(info, line, &i);
	else if (line[i] == 'R' && line[i + 1] == ' ')
		info->err_n = check_window(info, line, &i);
	else if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
		info->err_n = check_texture(info, line, &i, 0);
	else if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
		info->err_n = check_texture(info, line, &i, 1);
	else if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
		info->err_n = check_texture(info, line, &i, 2);
	else if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
		info->err_n = check_texture(info, line, &i, 3);
	else if (line[i] == 'S' && line[i + 1] == ' ')
		info->err_n = check_texture(info, line, &i, 4);
	else if (line[i] == 'F' && line[i + 1] == ' ')
		info->err_n = check_color(info, line, &i, &info->color_f);
	else if (line[i] == 'C' && line[i + 1] == ' ')
		info->err_n = check_color(info, line, &i, &info->color_c);
	return (error(info->err_n));
}

int	check_map_valid(t_info *info)
{
	if (map_valid_temp(info) != 0)
		return (error(-3));
	else
	{
		if (map_valid_map(info) != 0)
			return (error(-3));
	}
	return (0);
}

int	parsing_info(t_info *info, char *file)
{
	int		fd;
	int		ret;
	char	*line;
	int		err;

	err = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		return (error(-4));
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (check_information(info, line) != 0)
			err = -1;
		free(line);
	}
	check_map(info, line, &ret);
	free(line);
	close(fd);
	if (check_map_valid(info) != 0)
		return (-1);
	return (err);
}
