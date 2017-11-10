#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/01 05:35:42 by dpogrebn          #+#    #+#              #
#    Updated: 2017/11/01 05:35:44 by dpogrebn         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc
FLAGS = -Wall -Wextra -Werror
SRC = ./sources/*.c
HEADER =./includes/libft.h
NAME = libft.a

all: (NAME)

(NAME):
	$(CC) -c $(FLAGS) $(SRC) -I $(HEADER)
	ar rsc $(NAME) ./*.o

clean:
	rm -rf ./*.o

fclean :
	rm -rf ./*.o
	rm -rf $(NAME)
	
re: clean (NAME)
