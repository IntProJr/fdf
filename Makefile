# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrosalee <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/22 14:48:08 by lrosalee          #+#    #+#              #
#    Updated: 2019/11/22 14:48:18 by lrosalee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIBFT = ./libft/libft.a

LIBDIR = ./libft

SRC = main.c fdf.h

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Wextra -Werror

INCLUDE = -I ./

all: $(NAME)

$(NAME): $(OBJ)
	@make -sC $(LIBDIR)
	@gcc $(FLAG) $(OBJ) $(INCLUDE) $(LIBFT) -o $(NAME)

%.o:%.c
	@gcc $(FLAG) $(INCLUDE) -c $< -o $@

clean:
	@make -sC $(LIBDIR) clean

fclean: clean
	@make -sC $(LIBDIR) fclean
	@rm -rf $(NAME)

re: fclean all