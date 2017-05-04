# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsolis <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/15 20:09:40 by gsolis            #+#    #+#              #
#    Updated: 2017/02/15 20:09:42 by gsolis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC     = gcc
CFLAGS = -Wall -Wextra -Werror

NAME   = fillit
HEAD   = fillit.h
SRCS   =	./srcs/main.c \
			./srcs/reader.c \
			./srcs/ft_putstr.c \
			./srcs/piece.c \
			./srcs/map.c \
			./srcs/solver.c
OBJS   =	./srcs/main.o \
			./srcs/reader.o \
			./srcs/ft_putstr.o \
			./srcs/piece.o \
			./srcs/map.o \
			./srcs/solver.o \

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(SRCS) -I ./includes$(HEAD) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all