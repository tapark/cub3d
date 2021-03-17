/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapark <tapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 21:06:32 by tapark            #+#    #+#             */
/*   Updated: 2021/03/16 21:16:32 by tapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>

# define BUFFER_SIZE 5
# define MAX 32

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_EXIT 17

# define K_W 13
# define K_S 1
# define K_A 0
# define K_D 2
# define K_UP 126
# define K_DOWN 125
# define K_LEFT 123
# define K_RIGHT 124
# define K_ESC 53

# define TEX_W 64
# define TEX_H 64

typedef struct	s_img
{
	void		*img;
	int			*data;
	int			bpp;
	int			size_l;
	int			endian;
	int			img_w;
	int			img_h;
}				t_img;

typedef	struct	s_ray
{
	int			mapx;
	int			mapy;
	double		rayx;
	double		rayy;
	double		deltax;
	double		deltay;
	double		sidex;
	double		sidey;
	int			stepx;
	int			stepy;
	int			side;
}				t_ray;

typedef	struct	s_wall
{
	double		distance;
	double		distx;
	double		disty;
	int			height;
	int			start;
	int			end;
	int			color;
}				t_wall;

typedef struct	s_tex
{
	double		wallx;
	int			tex_num;
	int			texx;
	int			texy;
	double		step;
	double		pos;
}				t_tex;

typedef struct	s_sp
{
	double		sx;
	double		sy;
	double		tx;
	double		ty;
	int			screenx;
	int			screeny;
	int			sp_w;
	int			sp_h;
	int			startx;
	int			endx;
	int			starty;
	int			endy;
	int			sp_texx;
	int			sp_texy;
	int			sp_color;
}				t_sp;

typedef struct	s_info
{
	int			win_w;
	int			win_h;
	int			color_f;
	int			color_c;
	int			err_n;
	int			map_width;
	int			map_height;
	char		pos_dir;
	void		*mlx;
	void		*win;
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	double		move;
	double		rot;
	int			map_start;
	int			sp_num;
	char		*path[5];
	double		**sprite;
	int			texture[5][TEX_H * TEX_H];
	int			**buffer;
	double		*zbuffer;
	int			save;
	t_img		img;
	t_ray		ray;
	t_wall		wall;
	t_tex		tex;
	t_sp		sp;
}				t_info;

char *g_temp;
char **g_map;

int				ft_strlen(char *s1);
char			*ft_strdup(char *s1);
char			**ft_split(char const *s, char c);
char			*ft_strjoin_free(char *s1, char *s2);
char			*ft_strjoin_gnl(char *s1, char *s2);
int				get_next_line(int fd, char **line);
int				ft_isspace(char c);
int				ft_skip_space(char *line, int *i);
int				ft_cub_atoi(char *line, int *i);
int				check_file_name(char *file, char *ex);
int				check_save(char *save);
int				check_window(t_info *info, char *line, int *i);
int				check_color(t_info *info, char *line, int *i, int *color);
int				check_texture(t_info *info, char *line, int *i, int path_num);
int				check_map(t_info *info, char *line, int *i);
int				check_info_all(t_info *info);
int				map_valid_temp(t_info *info);
int				split_temp_to_map(int x, int y);
int				map_boundary_check(int x, int y);
int				map_close_check(t_info *info, int x, int y);
int				map_valid_map(t_info *info);
int				error(int n);
int				key_press(int keycode, t_info *info);
int				main_loop(t_info *info);
int				mlx_raycasting(t_info *info);
void			draw_wall(t_info *info);
void			draw_wall_init(t_info *info, int x);
int				mlx_exit_free(t_info *info);
void			draw_sprite_init(t_info *info);
void			draw_sprite(t_info *info);
int				get_sprite_buffer(t_info *info);
void			bitmap(t_info *info);
int				parsing_info(t_info *info, char *file);
int				main(int argc, char **argv);

#endif
