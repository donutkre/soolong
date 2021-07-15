# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/20 21:37:04 by ktiong            #+#    #+#              #
#    Updated: 2021/05/20 21:37:04 by ktiong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					= libft.a

SRCS					= ft_atoi.c \
					  ft_bzero.c \
					  ft_calloc.c \
					  ft_isalnum.c \
					  ft_isalpha.c \
					  ft_isascii.c \
					  ft_isdigit.c \
					  ft_isprint.c \
					  ft_itoa.c \
					  ft_memccpy.c \
					  ft_memchr.c \
					  ft_free.c \
					  ft_memcmp.c \
					  ft_memcpy.c \
					  ft_memmove.c \
					  ft_memset.c \
					  ft_putchar_fd.c \
					  ft_putendl_fd.c \
					  ft_putnbr_fd.c \
					  ft_putstr_fd.c \
					  ft_putnbr.c \
					  ft_split.c \
					  ft_strchr.c \
					  ft_strdup.c \
					  ft_strjoin.c \
					  ft_strlcat.c \
					  ft_strlcpy.c \
					  ft_strlen.c \
					  ft_strncmp.c \
					  ft_strnstr.c \
					  ft_substr.c \
					  ft_tern.c \
					  ft_tolower.c \
					  ft_toupper.c \
					  ft_itoa.c \
					  ft_strnew.c \
					  ft_chrstr.c \
					  ft_putchar.c \
					  ft_strcpy.c \
					  ft_open.c \
					  ft_putstr.c \
					  ft_strncpy.c \
					  ft_ishex.c \
	   				  ft_ispunc.c \
					  ft_isspace.c \
					  ft_isxdigit.c \
					  ft_memdel.c \
					  ft_putnstr_fd.c \
					  ft_strrev.c \
					  ft_strndup.c \
					  ft_htoi.c \
					  ft_utoi.c \
					  ft_otoi.c \
					  ft_strcmp.c \
					  get_next_line.c \
					  gnl_util.c

BONUSES				= ft_lstsize.c \
					  ft_lstadd_back.c \
					  ft_lstadd_front.c \
					  ft_lstclear.c \
					  ft_lstdelone.c \
					  ft_lstiter.c \
					  ft_lstlast.c \
					  ft_lstmap.c \
					  ft_lstnew.c 

OBJS = $(SRCS:%.c=%.o)
BOBJS = $(BONUSES:%.c=%.o)
HEADER = libft.h
CFLAGS = -Wall -Wextra -Werror
CC = gcc

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rc $(NAME) $(OBJS)

clean :
	rm -f $(OBJS) $(BOBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

bonus : $(BOBJS)
	ar -rc $(NAME) $(BOBJS)

.PHONY: all clean fclean re bonus