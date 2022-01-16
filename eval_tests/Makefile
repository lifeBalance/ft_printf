# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/05 13:19:07 by rodrodri          #+#    #+#              #
#    Updated: 2022/01/16 12:42:40 by rodrodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	test_printf

CC		:=	clang

# CFLAGS	=	-Wall -Werror -Wextra -I../includes -I../libft/includes
CFLAGS	=	-I../includes -I../libft/includes

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

char:		CFLAGS	+= -D CHAR_TEST
char:		$(NAME)

address:	CFLAGS	+= -D ADDR_TEST
address:	touch $(NAME)

int:		CFLAGS	+= -D INT_TEST
int:		touch $(NAME)

uint:		CFLAGS	+= -D UINT_TEST
uint:		touch $(NAME)

octal:		CFLAGS	+= -D OCTAL_TEST
octal:		touch $(NAME)

hex:		CFLAGS	+= -D HEX_TEST
hex:		touch $(NAME)

upphex:		CFLAGS	+= -D UPPHEX_TEST
upphex:		touch $(NAME)

touch:
	touch main.c.test

libftprintf.a:
	make -C ../libftprintf.a re

fclean:
	/bin/rm -f $(NAME)
	make -C .. fclean

re:		fclean all

.PHONY:	all fclean re int