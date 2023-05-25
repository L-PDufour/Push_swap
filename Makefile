# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/14 14:53:50 by ldufour           #+#    #+#              #
#    Updated: 2023/05/19 14:14:35by ldufour          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP = push_swap
NAME = $(PUSH_SWAP)

CC = gcc
CFLAGS =  -g

RM = rm -f

OBJS_DIR = obj
SRCS_DIR = srcs
SHR_DIR = shared

SRCS = srcs/push_swap.c \
			srcs/move_swap.c \
			srcs/move_push.c \
			srcs/move_rotate.c \
			srcs/move_reverse_rotate.c \
			srcs/sort_utils.c \
			srcs/sort_utils2.c \
			srcs/tiny_sort.c \
			srcs/medium_sort.c \
			srcs/parsing.c \
			srcs/parsing2.c \
			srcs/struct.c \
			srcs/big_sort.c \
			srcs/big_sort_utils.c

SHR = shared/ft_split.c \
			shared/libft_utils.c \
			shared/ft_lst.c

OBJS = $(patsubst $(SRCS_DIR)/%.c,$(OBJS_DIR)/%.o,$(SRCS))

.c.o:
	${CC} -c $< -o ${OBJS_DIR}/${<F:.c=.o}

all: $(NAME)

${NAME}: ${OBJS} ${SHR}
	${CC} ${CFLAGS} $^ -o $@

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	mkdir -p $(OBJS_DIR)
	${CC} ${CFLAGS} -c $< -o $@

clean:
	${RM} ${OBJS_DIR} ${NAME}

fclean: clean
	${RM} ${NAME}


re: clean all

.PHONY: all clean fclean re bonus
