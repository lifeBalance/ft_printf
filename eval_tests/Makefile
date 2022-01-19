# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/05 13:19:07 by rodrodri          #+#    #+#              #
#    Updated: 2022/01/19 14:25:25 by rodrodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	test_printf

CC		:=	clang

# CFLAGS	=	-Wall -Werror -Wextra -I../includes -I../libft/includes -I.
CFLAGS	=	-I../includes -I../libft/includes -I.

LDFLAGS	:=	-L../

LDLIBS	:=	-lftprintf

HDRS	:=	test_printf.h
SRCS	=	main.c.test percent.c.test char.c.test string.c.test int.c.test
SRCS	+=	uint.c.test hex.c.test upper_hex.c.test
SRCS	+=	address.c.test octal.c.test float.c.test

all: $(NAME)

$(NAME):	$(SRCS) $(HDRS) lib
	$(CC) $(CFLAGS) -x c $(SRCS) -o $(NAME) $(LDFLAGS) $(LDLIBS)

lib:
	make -C .. re

fclean:
	/bin/rm -f $(NAME)

re:		fclean all

.PHONY:	all fclean re int