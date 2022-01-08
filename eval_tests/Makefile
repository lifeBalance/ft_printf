# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/05 13:19:07 by rodrodri          #+#    #+#              #
#    Updated: 2022/01/08 19:27:57 by rodrodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	test_printf

CC		:=	clang

CFLAGS	=	-Wall -Werror -Wextra -I../includes -I../libft/includes

LDFLAGS	:=	-L../

LDLIBS	:=	-lftprintf

SRCS	:=	main.c.test

all: $(NAME)

$(NAME):	$(SRCS)
	make -C ../
	$(CC) $(CFLAGS) -x c $(SRCS) -o $(NAME) $(LDFLAGS) $(LDLIBS)

debug:	CFLAGS	+=	-g -D DEBUG
debug:	$(NAME)

libft.a:
	make -C ../libft re

fclean:
	/bin/rm -f $(NAME)

re:		fclean all

.PHONY:	all fclean re