# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pthorell <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/23 21:25:55 by pthorell          #+#    #+#              #
#    Updated: 2018/08/06 22:15:26 by pthorell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAGS = -Wall -Wextra -Werror -I minilibx_macos -L minilibx_macos -lmlx -framework OpenGL -framework AppKit

LIB1DIR = libft/
LIB1 = $(LIB1DIR)libft.a

LIB2DIR = minilibx_macos/
LIB2 = $(LIB2DIR)libmlx.a

SRC = src/main.c \
	  src/input_handler.c \
	  src/window_events.c \
	  src/draw_line.c \
	  src/fdf.c \
	  src/math.c \
	  src/project.c \
	  src/file_manager.c \
	  src/camera.c \
	  src/math_utilities.c

all: $(NAME)

$(NAME): $(SRC)
	make -C $(LIB1DIR)
	make -C $(LIB2DIR)
	gcc $(FLAGS) $(SRC) -o $(NAME) $(LIB1) $(LIB2)

clean:
	make clean -C $(LIB1DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIB1DIR)
	make clean -C $(LIB2DIR)

re: fclean all
