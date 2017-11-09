#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/01 05:54:49 by dpogrebn          #+#    #+#              #
#    Updated: 2017/11/01 05:54:49 by dpogrebn         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc
FLAGS = -Wall -Wextra -Werror
SRC = ./*.c
HEADER = ../includes/libft.h

all :
	$(CC) $(FLAGS) $(SRC) -I $(HEADER)

w :
	$(CC) $(FLAGS) $(SRC) -I $(HEADER)
	./a.out | cat -e

fclean :
	rm -rf ./*.o
	rm -rf ./a.out