# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inicoara <inicoara@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 13:41:50 by inicoara          #+#    #+#              #
#    Updated: 2025/04/25 11:32:19 by inicoara         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC=ft_striteri.c \
	ft_putnbr_fd.c \
	ft_putendl_fd.c \
	ft_putstr_fd.c \
	ft_putchar_fd.c \
	ft_strmapi.c \
	ft_itoa.c \
	ft_split.c \
	ft_strtrim.c \
	ft_strjoin.c \
	ft_substr.c \
	ft_strrchr.c \
	ft_strnstr.c \
	ft_strncmp.c \
	ft_strlen.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_strdup.c \
	ft_strchr.c \
	ft_memset.c \
	ft_memmove.c \
	ft_memcpy.c \
	ft_memcmp.c \
	ft_memchr.c \
	ft_isprint.c \
	ft_isascii.c \
	ft_isalpha.c \
	ft_calloc.c \
	ft_bzero.c \
	ft_atoi.c \
	ft_isalnum.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_isdigit.c \
	gnl/get_next_line.c\
	gnl/get_next_line_utils.c\
	printf/ft_fds.c\
	printf/ft_printf.c\
   	printf/ft_utils.c\
	ft_strncpy.c\
	ft_strncat.c\
	ft_strnulify.c\
	ft_strcmp.c

BONUS = ft_lstadd_back_bonus.c\
		ft_lstadd_front_bonus.c\
		ft_lstclear_bonus.c\
		ft_lstdelone_bonus.c\
		ft_lstiter_bonus.c\
		ft_lstlast_bonus.c \
		ft_lstnew_bonus.c\
		ft_lstsize_bonus.c\
		ft_lstmap_bonus.c

OBJS = ${SRC:.c=.o}
OBJSBONUS = ${BONUS:.c=.o}
NAME = libft.a
COMPILER = cc
CFLAGS = -Wall -Werror -Wextra -I ./

${NAME}: ${OBJS}
	ar -rsc ${NAME} ${OBJS}

.tmp: ${NAME} ${OBJSBONUS}
	ar -rsc ${NAME} ${OBJSBONUS}
	touch .tmp

all: ${NAME}

bonus: .tmp

clean:
	rm -f ${OBJS} ${OBJSBONUS} .tmp

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: clean flclean re 
