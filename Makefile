# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsuardi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/25 10:22:58 by lsuardi           #+#    #+#              #
#    Updated: 2020/02/25 10:59:43 by lsuardi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= BSQ

SRCS	= main.c srcs/*

CFLAGS	= -Wall -Wextra -Werror

HEADERS = headers/*

all:
	cc ${CFLAGS} ${SRCS} -o ${NAME}

clean:
	rm -f *.o

fclean:	clean
	rm -f ${NAME}
