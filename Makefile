SRCS	=	./cub3d.c \
			./check_info/check_color.c \
			./check_info/check_file_name.c \
			./check_info/check_map.c \
			./check_info/check_save.c \
			./check_info/check_texture.c \
			./check_info/check_window.c \
			./check_info/error.c \
			./check_info/parsing_info.c \
			./check_info//check_info_all.c \
			./map_valid/map_boundary_check.c \
			./map_valid/map_close_check.c \
			./map_valid/map_valid_temp.c \
			./map_valid/split_temp_to_map.c \
			./map_valid/map_valid_map.c \
			./utils/ft_cub_atoi.c \
			./utils/ft_isspace.c \
			./utils/ft_skip_space.c \
			./utils/ft_split.c \
			./utils/ft_strdup.c \
			./utils/ft_strjoin_free.c \
			./utils/ft_strjoin_gnl.c \
			./utils/ft_strlen.c \
			./utils/get_next_line.c \
			./raycast/key_press.c \
			./raycast/main_loop.c \
			./raycast/mlx_raycasting.c \
			./raycast/draw_wall.c \
			./raycast/draw_wall_init.c \
			./raycast/mlx_exit_free.c \
			./sprite/draw_sprite_init.c \
			./sprite/draw_sprite.c \
			./sprite/get_sprite_buffer.c \
			./bitmap/bitmap.c \

NAME	= cub3D
OBJS	= $(SRCS:.c=.o)
INCS	= .
RM		= rm -f
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
LIBC	= -Lmlx -lmlxgl -L. -lmlx -framework OpenGL -framework AppKit -lm
MLX		= libmlxgl.a
MLX_B	= libmlx.dylib
BMP		= ScreenShot.bmp

$(NAME) : $(MLX) $(MLX_B) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -I $(INCS) $(LIBC)

$(MLX) :
	$(MAKE) -C mlx
	mv mlx/libmlx.a mlx/$(MLX)

$(MLX_B) :
	$(MAKE) -C mlx2020
	mv mlx2020/$(MLX_B) ./$(MLX_B)

all : $(NAME)

clean :
	$(RM) $(OBJS) $(MLX_B) $(BMP)

fclean : clean
	$(RM) $(NAME)

re : fclean all