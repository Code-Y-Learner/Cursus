# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seungjyu <seungjyu@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 17:03:16 by seungjyu          #+#    #+#              #
#    Updated: 2023/05/11 21:28:21 by seungjyu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_write.c

INCLUDE = ft_printf.h

OBJS = ft_printf.o ft_write.o

AR = ar

ARFLAGS = -rc

all : $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $< -I $(INCLUDE)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re:
	make fclean
	make all

.PHONY: all, clean, fclean, re,
