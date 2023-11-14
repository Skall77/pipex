# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 11:43:24 by aaudevar          #+#    #+#              #
#    Updated: 2022/11/10 19:55:45 by aaudevar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =  ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_memmove.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_itoa.c \
		ft_split.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_printf.c \
		ft_printf_utils.c \
		conversions.c \
		more_conversions.c \
		hexadecimals_functions.c \
		get_next_line.c \
		get_next_line_utils.c \

OBJ = ${SRC:.c=.o}

BNS =  	ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c \

BNS_OBJ = ${BNS:.c=.o}

INCS = libft.h
NAME = libft.a
LIB = ar rc
RANL = ranlib
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ} ${INCS}
	${LIB} ${NAME} ${OBJ}
	${RANL} ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJ} ${BNS_OBJ}

fclean: clean
	${RM} ${NAME}

re : fclean all

bonus : ${OBJ} ${BNS_OBJ} ${INCS}
	${LIB} ${NAME} ${OBJ} ${BNS_OBJ}
	${RANL} ${NAME}
