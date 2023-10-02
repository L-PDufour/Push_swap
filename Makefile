# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/14 14:53:50 by ldufour           #+#    #+#              #
#    Updated: 2023/10/02 14:54:50 by ldufour          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

RM = rm -f

OBJS_DIR = obj
SRCS_DIR = srcs
SHR_DIR = shared
BONUS_DIR = bonus

SRCS = srcs/push_swap.c \
			srcs/move_swap.c \
			srcs/move_push.c \
			srcs/move_rotate.c \
			srcs/move_reverse_rotate.c \
			srcs/sort_utils.c \
			srcs/tiny_sort.c \
			srcs/medium_sort.c \
			srcs/parsing.c \
			srcs/struct.c \
			srcs/big_sort.c \
			srcs/big_sort_utils.c

SHR = shared/ft_split.c \
			shared/libft_utils.c \
			shared/get_next_line_utils.c \
			shared/get_next_line.c \
			shared/ft_lst.c

BONUS = bonus/checker_bonus.c \
			bonus/move_bonus.c \
			shared/ft_lst.c \
			shared/get_next_line.c \
			shared/get_next_line_utils.c \
			shared/libft_utils.c \
			shared/ft_split.c \
			srcs/move_push.c \
			srcs/move_reverse_rotate.c \
			srcs/move_rotate.c \
			srcs/move_swap.c \
			srcs/struct.c \
			srcs/parsing.c


OBJS = $(patsubst $(SRCS_DIR)/%.c,$(OBJS_DIR)/%.o,$(SRCS))

.c.o:
	${CC} -c $< -o ${OBJS_DIR}/${<F:.c=.o}

all: $(NAME)

${NAME}: ${OBJS} ${SHR}
	${CC} ${CFLAGS} $^ -o $@

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	${CC} ${CFLAGS} -c $< -o $@

clean: 
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

bonus: $(NAME_BONUS)

${NAME_BONUS}: $(BONUS)
		${CC} ${CFLAGS} $^ -o $@
cleanbonus:
	$(RM) $(OBJS)

fcleanbonus:
	${RM} ${NAME_BONUS}

re: clean all

.PHONY: all clean fclean re bonus
