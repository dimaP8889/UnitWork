#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/20 14:30:37 by dpogrebn          #+#    #+#              #
#    Updated: 2017/11/20 14:30:38 by dpogrebn         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRC = getmap.c main.c check_sharps.c
HEADER = header.h 
FLAGS = -Wall -Wextra -Werror
NAME = fillit
CC = gcc
LIB = -L./libft -lft

all: $(NAME)

$(NAME):
	cd libft && make re
	cd ..
	$(CC) $(FLAGS) -o $(NAME) $(LIB) $(SRC)

clean:
	rm -rf ./*.o

fclean:
	rm -rf ./*.o
	rm -rf $(NAME)

re: fclean all
