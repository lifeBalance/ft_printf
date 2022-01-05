# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/05 12:16:57 by rodrodri          #+#    #+#              #
#    Updated: 2022/01/05 13:27:58 by rodrodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	libftprintf.a

CC		:=	clang

CFLAGS	:=	-Wall -Werror -Wextra -Iincludes -Ilibft/includes

SRCS	:=	ft_printf.c

vpath	%.c ./srcs

OBJS_DIR	:= ./objs

OBJS		:=	$(patsubst %,$(OBJS_DIR)/%,$(SRCS:.c=.o))

all:		$(NAME)

$(NAME):	$(OBJS)
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

$(OBJS_DIR)/%.o: %.c
	make -sC libft
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	/bin/rm -rf $(OBJS_DIR)
	make -sC libft clean

fclean:	clean
	/bin/rm -f $(NAME)
	make -sC libft fclean

re:	fclean all

.PHONY:	all clean fclean re