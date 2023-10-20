# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seungjyu <seungjyu@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/18 18:56:40 by seungjyu          #+#    #+#              #
#    Updated: 2023/10/19 17:01:34 by seungjyu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS_SV = server.c
SRCS_CL = client.c
SRCS = utils.c ft_atoi.c
OBJS_SRCS = $(SRCS:.c=.o)
OBJS_SV = $(SRCS_SV:.c=.o) $(OBJS_SRCS)
OBJS_CL = $(SRCS_CL:.c=.o) $(OBJS_SRCS)
NAME_SV = server
NAME_CL = client
CFLAGS = -Wall -Wextra -Werror

all: $(NAME_SV) $(NAME_CL)

$(NAME_SV): $(OBJS_SV)
	gcc $(CFLAGS) $(OBJS_SV) -o $(NAME_SV)

$(NAME_CL): $(OBJS_CL)
	gcc $(CFLAGS) $(OBJS_CL) -o $(NAME_CL)

.c.o:
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_SV) $(OBJS_CL) $(OBJS_BSV) $(OBJS_BCL) $(OBJS_SRCS)

fclean: clean
	rm -rf $(NAME_SV) $(NAME_CL) $(NAME_BSV) $(NAME_BCL)

re: fclean all

.PHONY: all clean fclean re
