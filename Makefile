PUSH_SWAP = push_swap
NAME = $(PUSH_SWAP)

CC = gcc
CFLAGS =  -Wall -Wextra -Werror -g3

RM = rm -f

LIBFTDIR = libft/
OBJ_DIR = obj/
SRC_DIR = srcs/

SRC = srcs/push_swap/push_swap.c \
			srcs/push_swap/move.c \
			srcs/push_swap/utils.c \
			srcs/push_swap/stack_utils.c 
OBJ = $(SRC:.c=.o)

INCLUDE = -L ./libft -lft

.c.o:
	${CC} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ}
	make -C $(LIBFTDIR)
	${CC} ${CFLAGS} ${OBJ} -o ${NAME} ${INCLUDE}

all: $(NAME)

clean:
	${RM} ${OBJ} ${NAME}
	@cd $(LIBFTDIR) && $(MAKE) clean

fclean: clean
	${RM} ${NAME}
	@cd $(LIBFTDIR) && $(MAKE) fclean


re: clean all

.PHONY: all clean fclean re bonus
