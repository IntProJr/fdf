# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrosalee <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/11 19:57:51 by lrosalee          #+#    #+#              #
#    Updated: 2020/02/10 20:04:42 by lrosalee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

INC = -I ./includes
INC_FILE = ./includes/libft.h ./includes/get_next_line.h
SRC_DIR = src
OBJ_DIR = object

SRC = ft_atoi.c \
      	ft_memset.c\
      	ft_atoi_base.c \
      	ft_strlen.c \
      	ft_strcmp.c \
      	ft_strncmp.c \
      	ft_strstr.c \
      	ft_strnstr.c \
      	ft_memset.c \
      	ft_bzero.c \
      	ft_memcpy.c \
      	ft_memccpy.c \
      	ft_memmove.c \
      	ft_memchr.c \
      	ft_memcmp.c \
      	ft_strdup.c \
      	ft_strndup.c \
      	ft_strcpy.c \
      	ft_strncpy.c \
      	ft_strcat.c \
      	ft_strncat.c \
      	ft_strlcat.c \
      	ft_strchr.c \
      	ft_strrchr.c \
      	ft_isalpha.c \
      	ft_isdigit.c \
      	ft_isalnum.c \
      	ft_isascii.c \
      	ft_isprint.c \
      	ft_toupper.c \
      	ft_tolower.c \
      	ft_memalloc.c \
      	ft_memdel.c \
      	ft_strnew.c \
      	ft_strdel.c \
      	ft_strclr.c \
      	ft_striter.c \
      	ft_striteri.c \
      	ft_strmap.c \
      	ft_strmapi.c \
      	ft_strequ.c \
      	ft_strnequ.c \
      	ft_strsub.c \
      	ft_strjoin.c \
      	ft_strtrim.c \
      	ft_putchar.c \
      	ft_putchar_fd.c \
      	ft_strsplit.c \
      	ft_itoa.c \
      	ft_putstr.c \
      	ft_putstr_fd.c \
      	ft_putendl_fd.c \
      	ft_putendl.c \
      	ft_putnbr.c \
      	ft_putnbr_fd.c \
      	ft_abs.c \
      	ft_min.c \
      	ft_pow.c \
      	ft_fact.c \
      	ft_sqrt.c \
      	ft_lstnew.c \
      	ft_lstdelone.c \
      	ft_lstdel.c \
      	ft_lstadd.c \
      	ft_lstiter.c \
      	ft_lstmap.c \
      	ft_realloc.c \
      	ft_wordcount.c \
      	get_next_line.c

FLAGS = -Wall -Wextra -Werror

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_FILE)
		@mkdir -p $(OBJ_DIR)
		$(CC) $(FLAG) $(INC) -c $< -o $@

clean:
		@/bin/rm -rf $(OBJ_DIR)

fclean: clean
		@/bin/rm -f $(OBJ)
		@/bin/rm -f $(NAME)

re: fclean $(NAME)