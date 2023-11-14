# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/20 19:04:49 by aaudevar          #+#    #+#              #
#    Updated: 2022/11/20 19:04:49 by aaudevar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIRSRC = ./srcs/

BNSSRC = ./bonus/

DIRCINC = ./includes/

DIRLIB = ./libft/

SRC = 	pipex \
		utils \
		first_child \
		second_child \
		free \

BNS =	pipex_bonus \
		utils_bonus \
		first_child_bonus \
		free_bonus \
		extra_bonus \
	   
SRCS = $(addprefix ${DIRSRC}, $(addsuffix .c, ${SRC}))
BNSS = $(addprefix ${BNSSRC}, $(addsuffix .c, ${BNS}))

OBJS = ${SRCS:.c=.o}
OBJS_BNS = ${BNSS:.c=.o}

NAME = pipex
LFT = libft.a
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c -I${DIRCINC} -I${DIRLIB} $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	cd ${DIRLIB} && ${MAKE}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} -L./libft -lft

all: ${NAME}

bonus: ${OBJS_BNS}
	cd ${DIRLIB} && ${MAKE}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS_BNS} -L./libft -lft

clean:
	${RM} ${OBJS} ${OBJS_BNS}
	cd ${DIRLIB} && ${MAKE} clean

fclean: clean
	${RM} ${NAME}
	cd ${DIRLIB} && ${MAKE} fclean

re : fclean all

.PHONY : all clean fclean re