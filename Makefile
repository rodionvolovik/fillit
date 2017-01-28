# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvolovik <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/19 16:20:42 by rvolovik          #+#    #+#              #
#    Updated: 2016/12/19 16:20:49 by rvolovik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = fillit
SRC = src/check_map.c \
      src/coords.c \
      src/create_list.c \
      src/error_exit.c \
      src/filler.c \
      src/free_all.c \
      src/main.c \
      src/print.c \
      src/read_map.c \
      src/solve.c
OBJ        = $(SRC:.c=.o)
CC        = gcc
CFLAGS    = -Wall -Wextra -Werror -I./include/ -Ilibft
LIBFT    = libft.a
all: $(OBJ) $(LIBFT) $(NAME)

$(LIBFT):
	make -C ./libft

$(NAME): $(OBJ) $(LIBFT)
	$(CC) -L./libft -lft -o $(NAME) $(OBJ)

clean:
	make clean -C ./libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C ./libft
	/bin/rm -f $(NAME)

re: fclean all
