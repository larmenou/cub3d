# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mferracc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/01 14:41:16 by bahommer          #+#    #+#              #
#    Updated: 2023/05/01 17:44:06 by mferracc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
			ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
			ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
			ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
			ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			get_next_line.c \
			ft_printf/ft_c.c ft_printf/ft_s.c ft_printf/ft_p.c \
			ft_printf/ft_di.c ft_printf/ft_u.c ft_printf/ft_x.c \
			ft_printf/ft_count.c ft_printf/ft_flags.c ft_printf/ft_printf.c \
			ft_printf/ft_putnbr_mod.c ft_printf/ft_s_null.c \
			ft_printf/ft_write.c ft_printf/ft_s_fd.c ft_printf/ft_fprintf.c
SRCSB	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_list_sort.c \
			ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
			ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_list_remove_if.c

INCDIR	= inc

OBJS	= ${SRCS:.c=.o}

OBJSB	= ${SRCSB:.c=.o}

CC		= cc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror -I ${INCDIR}

AR		= ar rc

RAN		= ranlib

NAME	= libft.a

%.o: %.c
		@${CC} -c $< ${CFLAGS} -o $@ 

${NAME}:	${OBJS} ${OBJSB}
		@${AR} ${NAME} ${OBJS} ${OBJSB}
		@${RAN} ${NAME}

all:	${NAME}

bonus:		${OBJSB} ${OBJS}
		@${AR} ${NAME} ${OBJSB} ${OBJS}
		@${RAN} ${NAME}

clean:
		@${RM} ${OBJS} ${OBJSB}

fclean:	clean
		@${RM} ${NAME}

re:		fclean all

.PHONY: all clean fclean re
