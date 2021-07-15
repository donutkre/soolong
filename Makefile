# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/08 00:44:23 by ktiong            #+#    #+#              #
#    Updated: 2021/07/14 23:16:03 by ktiong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS	= srcs/main.c \
			srcs/item.c \
			srcs/image.c \
			srcs/map.c \
			srcs/control.c \
			srcs/parse.c \
			srcs/valid.c

OBJS = $(SRCS:.c=.o)

CC = clang

CFLAGS = -Wall -Wextra -Werror -g3

MLX = -L. -lmlx -lm -lbsd -lX11 -lXext

MINILIB = libmlx.a

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS) $(MINILIB) 
	cd libft && make all
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) libft/libft.a

$(MINILIB):
	$(MAKE) -C mlx_linux
	mv mlx_linux/$(MINILIB) .

clean:
	$(MAKE) -C mlx_linux clean
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(MINILIB)

re: fclean all

.PHONY: all clean fclean re
