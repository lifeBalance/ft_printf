# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/29 11:09:58 by rodrodri          #+#    #+#              #
#    Updated: 2022/01/04 18:15:44 by rodrodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

CC		=	clang

CFLAGS	=	-Wall -Werror -Wextra -Iincludes

PART1_LIBC	=	ft_memset.c		ft_bzero.c		ft_memcpy.c		ft_memccpy.c\
				ft_memmove.c	ft_memchr.c		ft_memcmp.c		ft_strlen.c	\
				ft_strdup.c		ft_strcpy.c		ft_strncpy.c	ft_strcat.c	\
				ft_strncat.c	ft_strlcat.c	ft_strchr.c		ft_strrchr.c\
				ft_strstr.c		ft_strnstr.c	ft_strcmp.c		ft_strncmp.c\
				ft_atoi.c		ft_isalpha.c	ft_isdigit.c	ft_isalnum.c\
				ft_isascii.c	ft_isprint.c	ft_toupper.c	ft_tolower.c

PART2_ADDIT	=	ft_memalloc.c	ft_memdel.c		ft_strnew.c		ft_strdel.c	\
				ft_strclr.c		ft_striter.c	ft_striteri.c	ft_strmap.c	\
				ft_strmapi.c	ft_strequ.c		ft_strnequ.c	ft_strsub.c	\
				ft_strjoin.c	ft_strtrim.c	ft_strsplit.c	ft_itoa.c	\
				ft_putchar.c	ft_putstr.c		ft_putendl.c	ft_putnbr.c	\
				ft_putchar_fd.c	ft_putstr_fd.c	ft_putendl_fd.c	ft_putnbr_fd.c

BONUS_LISTS	=	ft_lstnew.c		ft_lstdelone.c	ft_lstdel.c		ft_lstadd.c	\
				ft_lstiter.c	ft_lstmap.c

EXTRA_BONUS	=	ft_strrev.c		ft_isspace.c

MORE_LISTS	=	ft_lstprepend.c	ft_lstappend.c	ft_lstcount.c	\
				ft_lstdelnode.c	ft_lstdelcont.c

CIRC_LISTS	=	ft_clst_add.c	ft_clst_del.c	ft_clst_cnt.c	ft_clst_iter.c

BITWISE		=	bitwise.c	uint8_tobin.c		uint16_tobin.c

MORE_LIBC	=	get_next_line.c

SRCS	:=	$(PART1_LIBC)
SRCS	+=	$(PART2_ADDIT)
SRCS	+=	$(BONUS_LISTS)
SRCS	+=	$(MORE_LISTS)
SRCS	+=	$(CIRC_LISTS)
SRCS	+=	$(EXTRA_BONUS)
SRCS	+=	$(BITWISE)
SRCS	+=	$(MORE_LIBC)

vpath	%.c ./srcs/part1_libc
vpath	%.c	./srcs/part2_addit
vpath	%.c	./srcs/more_libc
vpath	%.c ./srcs/linked_lists
vpath	%.c ./srcs/circ_lists
vpath	%.c	./srcs/extra_bonus
vpath	%.c	./srcs/bitwise

OBJS_DIR = ./objs

OBJS	=	$(patsubst %,$(OBJS_DIR)/%,$(SRCS:.c=.o))

all:		$(NAME)

$(NAME):	$(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJS_DIR)/%.o: %.c
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	/bin/rm -rf $(OBJS_DIR)

fclean:	clean
	/bin/rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re