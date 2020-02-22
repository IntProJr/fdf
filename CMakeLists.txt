cmake_minimum_required(VERSION 3.15)
project(fdf C)

set(CMAKE_C_STANDARD 99)

include_directories(.)

include_directories(./minilibx_macos)

find_library(MLX mlx ./includes/minilibx_macos)

link_directories(./minilibx_macos)

add_executable(fdf
		main.c
		fdf.h
		exit.c
		initialize.c
		read_map.c
		check_color.c
		./libft/sources/ft_atoi.c
		./libft/sources/ft_atoi_base.c
		./libft/sources/ft_isdigit.c
		./libft/sources/ft_memalloc.c
		./libft/sources/ft_putendl_fd.c
		./libft/sources/ft_strsplit.c
		./libft/sources/get_next_line.c
		./libft/sources/ft_bzero.c
		./libft/sources/ft_putchar_fd.c
		./libft/sources/ft_putstr_fd.c
		./libft/sources/ft_strchr.c
		./libft/sources/ft_strdup.c
		./libft/sources/ft_strjoin.c
		./libft/sources/ft_strdup.c
		./libft/sources/ft_strndup.c
		./libft/sources/ft_strnew.c
		./libft/sources/ft_strsub.c
		./libft/sources/ft_strlen.c
		./libft/sources/ft_strdel.c
		draw_map.c
		projection.c
		give_color.c libft/sources/ft_wordcount.c libft/sources/ft_clear_mass.c)

target_link_libraries(fdf PUBLIC "-framework AppKit" "-framework OpenGL")

target_link_libraries(fdf PUBLIC ${MLX})




