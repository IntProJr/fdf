cmake_minimum_required(VERSION 3.15)
project(fdf C)

set(CMAKE_C_STANDARD 99)

include_directories(.)

include_directories(./minilibx_mms)

find_library(MLX mlx ./includes/minilibx_mms)

link_directories(./minilibx_mms)

add_executable(fdf
		src/main.c
		includes/fdf.h
		src/exit.c
		src/initialize.c
		src/read_map.c
		src/check_color.c
		libft/src/ft_atoi.c
		libft/src/ft_atoi_base.c
		libft/src/ft_isdigit.c
		libft/src/ft_memalloc.c
		libft/src/ft_putendl_fd.c
		libft/src/ft_strsplit.c
		libft/src/get_next_line.c
		libft/src/ft_bzero.c
		libft/src/ft_putchar_fd.c
		libft/src/ft_putstr_fd.c
		libft/src/ft_strchr.c
		libft/src/ft_strdup.c
		libft/src/ft_strjoin.c
		libft/src/ft_strdup.c
		libft/src/ft_strndup.c
		libft/src/ft_strnew.c
		libft/src/ft_strsub.c
		libft/src/ft_strlen.c
		libft/src/ft_strdel.c
		src/draw_map.c
		src/projection.c
		src/give_color.c
		libft/src/ft_wordcount.c
		libft/src/ft_clear_mass.c
		src/utilits.c
		includes/for_utilits.h
		src/key_hook.c
		src/ft_mouse.c)

target_link_libraries(fdf PUBLIC "-framework AppKit" "-framework OpenGL")

target_link_libraries(fdf PUBLIC ${MLX})




