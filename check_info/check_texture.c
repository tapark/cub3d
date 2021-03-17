/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapark <tapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 18:48:32 by tapark            #+#    #+#             */
/*   Updated: 2021/03/03 19:10:32 by tapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_xpm(t_info *info, char *texture)
{
	int		fd;
	t_img	img;

	if (check_file_name(texture, ".xpm") == 0)
		return (-1);
	if ((fd = open(texture, O_RDONLY)) == -1)
		return (-2);
	close(fd);
	img.img = mlx_xpm_file_to_image(info->mlx, texture, &img.img_w, &img.img_h);
	if (img.img == NULL)
		return (-8);
	img.data = (int *)mlx_get_data_addr(img.img,
										&img.bpp, &img.size_l, &img.endian);
	mlx_destroy_image(info->mlx, img.img);
	if (img.img_w != 64 || img.img_h != 64)
		return (-8);
	return (0);
}

int	check_texture(t_info *info, char *line, int *i, int path_num)
{
	int		len;
	int		re;
	char	*texture;

	if (info->path[path_num] != NULL)
		return (-7);
	*i = *i + 2;
	ft_skip_space(line, i);
	len = *i;
	while (ft_isspace(line[*i]) == 0 && line[*i] != '\0')
		(*i)++;
	if (!(texture = (char *)malloc(sizeof(char) * (*i - len + 1))))
		return (-6);
	(*i) = len;
	len = 0;
	while (ft_isspace(line[*i]) == 0 && line[*i] != '\0')
		texture[len++] = line[(*i)++];
	texture[len] = '\0';
	if ((re = check_xpm(info, texture)) != 0)
		return (re);
	info->path[path_num] = texture;
	ft_skip_space(line, i);
	if (line[*i] != '\0')
		return (-5);
	return (0);
}
