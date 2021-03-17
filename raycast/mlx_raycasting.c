/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_raycasting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapark <tapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 20:04:13 by tapark            #+#    #+#             */
/*   Updated: 2021/03/16 21:14:46 by tapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_posdir(t_info *info)
{
	if (info->pos_dir == 'N')
	{
		info->dirx = -1;
		info->planey = 0.66;
	}
	else if (info->pos_dir == 'S')
	{
		info->dirx = 1;
		info->planey = -0.66;
	}
	else if (info->pos_dir == 'E')
	{
		info->diry = 1;
		info->planex = 0.66;
	}
	else if (info->pos_dir == 'W')
	{
		info->diry = -1;
		info->planex = -0.66;
	}
}

void	load_texture(t_info *info, char *file, int *texture)
{
	t_img	img;
	int		x;
	int		y;

	img.img = mlx_xpm_file_to_image(info->mlx, file, &img.img_w, &img.img_h);
	img.data = (int *)mlx_get_data_addr(img.img,
										&img.bpp, &img.size_l, &img.endian);
	y = 0;
	while (y < img.img_h)
	{
		x = 0;
		while (x < img.img_w)
		{
			texture[y * img.img_w + x] = img.data[y * img.img_w + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(info->mlx, img.img);
}

void	load_all_texture(t_info *info)
{
	int		i;

	i = 0;
	while (i < 5)
	{
		load_texture(info, info->path[i], info->texture[i]);
		i++;
	}
}

int		mlx_raycasting(t_info *info)
{
	set_posdir(info);
	get_sprite_buffer(info);
	info->move = 0.1;
	info->rot = 0.1;
	if (info->save == 0)
		info->win = mlx_new_window(info->mlx, info->win_w, info->win_h,
																"cub3d");
	load_all_texture(info);
	info->img.img = mlx_new_image(info->mlx, info->win_w, info->win_h);
	info->img.data = (int *)mlx_get_data_addr(info->img.img,
						&info->img.bpp, &info->img.size_l, &info->img.endian);
	if (info->save == 1)
		bitmap(info);
	mlx_loop_hook(info->mlx, &main_loop, info);
	mlx_hook(info->win, X_EVENT_KEY_PRESS, 0, &key_press, info);
	mlx_hook(info->win, X_EVENT_KEY_EXIT, 0, &mlx_exit_free, info);
	mlx_loop(info->mlx);
	return (0);
}
