/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapark <tapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 18:48:40 by tapark            #+#    #+#             */
/*   Updated: 2021/03/05 01:52:39 by tapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	error(int n)
{
	if (n == 0)
		return (0);
	(n == -1) ? write(1, "Error(-1)\nfile name : *.xpm\n", 28) : 0;
	(n == -2) ? write(1, "Error(-2)\n*.xpm : file open fail\n", 33) : 0;
	(n == -3) ? write(1, "Error(-3)\ninvalid map\n", 22) : 0;
	(n == -4) ? write(1, "Error(-4)\n*.cub : file open fail\n", 33) : 0;
	(n == -5) ? write(1, "Error(-5)\nunknown character(.cub)\n", 34) : 0;
	(n == -6) ? write(1, "Error(-6)\nmalloc fail\n", 22) : 0;
	(n == -7) ? write(1, "Error(-7)\nfactor overlap\n", 25) : 0;
	(n == -8) ? write(1, "Error(-8)\ntexture(.xpm) : 64 * 64\n", 34) : 0;
	(n == -9) ? write(1, "Error(-9)\ncolor : 0~255\ncolor : F!=C\n", 37) : 0;
	(n == -10) ? write(1, "Error(-10)\ncheck screen size\n", 29) : 0;
	(n == -12) ? write(1, "Error(0)\n*.cub : lack of information\n", 37) : 0;
	return (-1);
}
