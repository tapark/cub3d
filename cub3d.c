/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapark <tapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 17:42:04 by tapark            #+#    #+#             */
/*   Updated: 2021/03/16 15:56:17 by tapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	default_value(t_info *info)
{
	info->win_w = -1;
	info->win_h = -1;
	info->color_c = -1;
	info->color_f = -1;
	info->path[0] = NULL;
	info->path[1] = NULL;
	info->path[2] = NULL;
	info->path[3] = NULL;
	info->path[4] = NULL;
	info->map_start = 0;
	info->dirx = 0;
	info->diry = 0;
	info->planex = 0;
	info->planey = 0;
	g_temp = ft_strdup("");
}

int		parse_n_raycast(t_info *info, char *file, int save)
{
	int		i;

	info->save = save;
	if ((i = open(file, O_RDONLY)) == -1)
		return (error(-4));
	default_value(info);
	if (parsing_info(info, file) != 0 || check_info_all(info) != 0)
	{
		i = 0;
		while (i < info->map_height)
			free(g_map[i++]);
		free(g_map);
		i = 0;
		while (i < 5)
			free(info->path[i++]);
		free(info->mlx);
		return (error(-12));
	}
	mlx_raycasting(info);
	return (0);
}

int		main(int argc, char **argv)
{
	t_info	info;

	if (argc == 2 && check_file_name(argv[1], ".cub"))
	{
		info.mlx = mlx_init();
		parse_n_raycast(&info, argv[1], 0);
	}
	else if (argc == 3 && check_file_name(argv[1], ".cub")
				&& check_save(argv[2]))
	{
		info.mlx = mlx_init();
		parse_n_raycast(&info, argv[1], 1);
	}
	else
		write(1, "Error\nfile : *.cub\nflag : --save\n", 33);
	return (0);
}
