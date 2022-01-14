# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/05 13:19:07 by rodrodri          #+#    #+#              #
#    Updated: 2022/01/13 17:48:44 by rodrodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	test_printf

CC		:=	clang

CFLAGS	=	-Wall -Werror -Wextra -I../includes -I../libft/includes
# CFLAGS	=	-I../includes -I../libft/includes

LDFLAGS	:=	-L../

LDLIBS	:=	-lftprintf

SRCS	:=	main.c.test

all: $(NAME)

$(NAME):	$(SRCS)
	make -C ../
	$(CC) $(CFLAGS) -x c $(SRCS) -o $(NAME) $(LDFLAGS) $(LDLIBS)

debug:	CFLAGS	+=	-g -D LEAKS
debug:	$(NAME)

percent:	CFLAGS	+= -D PERCENT_TEST
percent:	$(NAME)

strings:	CFLAGS	+= -D STRINGS_TEST
strings:	$(NAME)

char:	CFLAGS	+= -D CHAR_TEST
char:	$(NAME)

int:	CFLAGS	+= -D INT_TEST
int:	touch $(NAME)

touch:
	touch main.c.test

libft.a:
	make -C ../libft re

fclean:
	/bin/rm -f $(NAME)
	make -C .. fclean

re:		fclean all

.PHONY:	all fclean re int