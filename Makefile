# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/14 14:53:50 by ldufour           #+#    #+#              #
#    Updated: 2023/05/19 11:37:25 by ldufour          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP = push_swap
NAME = $(PUSH_SWAP)

CC = gcc
CFLAGS =  -Wall -Wextra -Werror -g

RM = rm -f

OBJ_DIR = obj/
SRC_DIR = srcs/
SHR_DIR = shared/

SRC = srcs/push_swap/push_swap.c \
			srcs/push_swap/move_swap.c \
			srcs/push_swap/move_push.c \
			srcs/push_swap/move_rotate.c \
			srcs/push_swap/move_reverse_rotate.c \
			srcs/push_swap/sort_utils.c \
			srcs/push_swap/sort_utils2.c \
			srcs/push_swap/tiny_sort.c \
			srcs/push_swap/medium_sort.c \
			srcs/push_swap/parsing.c \
			srcs/push_swap/parsing2.c \
			srcs/push_swap/struct.c

SHR = shared/ft_split.c \
			shared/libft_utils.c \
			shared/ft_lst.c

OBJ = $(SRC:.c=.o) $(SHR:.c=.o)
# OBJ = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o) $(SHR:$(SHR_DIR)%.c=$(OBJ_DIR)%.o)

.c.o:
	${CC} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ}
	${CC} ${CFLAGS} ${OBJ} -o ${NAME}

all: $(NAME)

clean:
	${RM} ${OBJ} ${NAME}

fclean: clean
	${RM} ${NAME}


re: clean all

.PHONY: all clean fclean re bonus
