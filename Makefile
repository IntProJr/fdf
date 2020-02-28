# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrosalee <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/22 14:48:08 by lrosalee          #+#    #+#              #
#    Updated: 2020/02/28 16:45:24 by lrosalee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean fclean re

NAME = fdf

CC = gcc

CFLAGS = -g
FRAMEWORKS = -framework OpenGL -framework Appkit

MY_LIB = ./libft/
MLX_LIB = ./minilibx_macos/
INC = ./minilibx_macos/ ./libft/includes/ ./includes
INCLUDES = -I ./minilibx_macos/ -I ./libft/includes/ -I ./includes/

SRC = $(addprefix $(SRC_DIR), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_DIR)/, $(OBJ_NAME))

SRC_DIR = ./src
OBJ_DIR = ./object

SRC_NAME = main.c read_map.c draw_map.c initialize.c give_color.c ft_mouse.c key_hook.c projection.c utilits.c
OBJ_NAME = $(SRC_NAME:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make build_lib
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L $(MLX_LIB) -lmlx -L $(MY_LIB) -lft $(INCLUDES) $(FRAMEWORKS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

build_lib:
	@make -sC $(MY_LIB)
	@make -sC $(MLX_LIB)

clean:
	@/bin/rm -rf $(OBJ_DIR)
	@make clean -C $(MLX_LIB)
	@make clean -C $(MY_LIB)

fclean:	clean
	@make clean
	@/bin/rm -f $(NAME)
	@make fclean -C $(MY_LIB)

re:	fclean all
