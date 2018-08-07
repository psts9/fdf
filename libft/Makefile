# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edehmlow <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/18 16:46:18 by edehmlow          #+#    #+#              #
#    Updated: 2018/08/02 18:37:43 by pthorell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

FLAGS = -c -Wall -Wextra -Werror

ARCHIVE = ar rc

INDEX = ranlib

OBJ = *.o

SRCS = free_strjoin.c ft_memalloc.c ft_strcat.c ft_strncmp.c \
	   free_strnjoin.c ft_memccpy.c ft_strchr.c ft_strncpy.c \
	   ft_atoi.c ft_memchr.c ft_strclr.c ft_strnequ.c \
	   ft_bzero.c ft_memcmp.c ft_strcmp.c ft_strnew.c \
	   ft_isalnum.c ft_memcpy.c ft_strcpy.c ft_strnjoin.c \
	   ft_isalpha.c ft_memdel.c ft_strdel.c ft_strnstr.c \
	   ft_isascii.c ft_memmove.c ft_strdup.c ft_strrchr.c \
	   ft_isdigit.c ft_memset.c ft_strequ.c ft_strsplit.c \
	   ft_isprint.c ft_putchar.c ft_striter.c ft_strstr.c \
	   ft_itoa.c ft_putchar_fd.c ft_striteri.c ft_strsub.c \
	   ft_lstadd.c ft_putendl.c ft_strjoin.c ft_strtrim.c \
	   ft_lstdel.c ft_putendl_fd.c ft_strlcat.c ft_tolower.c \
	   ft_lstdelone.c ft_putnbr.c ft_strlen.c ft_toupper.c \
	   ft_lstiter.c ft_putnbr_fd.c ft_strmap.c ft_lstmap.c \
	   ft_putstr.c ft_strmapi.c ft_lstnew.c ft_putstr_fd.c \
	   ft_strncat.c get_next_line.c

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(SRCS)
	$(ARCHIVE) $(NAME) $(OBJ)
	$(INDEX) $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
