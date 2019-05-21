# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amarcel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/21 01:08:46 by amarcel           #+#    #+#              #
#    Updated: 2019/05/21 03:23:41 by abelkhay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= fdf
CC= gcc
CFLAGS = -Wall -Werror -Wextra
MLX= -lmlx -framework OpenGL -framework Appkit

SRC=    ./src/draw_lines.c\
        ./src/fdf.c\
        ./src/fill_tab.c\
        ./src/ft_init.c\
        ./src/main.c\
        ./src/params.c\
        ./src/read_file.c\
		./src/key_function.c\

OBJ= $(SRC:.c=.o)
LIBFT= ./libft/libft.a

all: $(NAME)

$(NAME): $(SRC)
		make -C ./libft/
		$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(LIBFT) $(MLX)

clean:
		/bin/rm -rf $(OBJ)
		make -C libft fclean

fclean: clean
		/bin/rm -rf $(NAME)
		/bin/rm -rf ./libft/libft.a

re: fclean all

.PHONY: all, clean, fclean, re
