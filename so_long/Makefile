CC 			= cc

NAME		= so_long

SRCS		= so_long.c \
			  image.c \
			  key.c \
			  map.c \
			  map_dfs.c\
			  utils.c \
			  get_next_line.c \
			  get_next_line_utils.c \


OBJS		= $(SRCS:%.c=%.o)

LIBC		= ar rc

CFLAGS 		= -Wall -Wextra -Werror 

CLIB		= -lmlx -framework OpenGl -framework AppKit -Imlx

all			:	$(NAME)

$(NAME)		:	$(OBJS)
		make -C mlx
		$(CC) $(CFLAGS) $(CLIB) $^ -o $@ ./mlx/libmlx.a

%.o			:	%.c
		$(CC) $(CFLAGS) -c $^ -o $@

clean		:
		make clean -C mlx
		rm -f $(OBJS)

fclean		:	clean
		make clean -C mlx
		rm -f $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re bonus
