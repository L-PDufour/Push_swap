NAME = push_swap.a

RM = rm -f

CFLAGS =  -Wall -Wextra -Werror -g

.PHONY: all clean fclean re bonus

SRC = main.c \

OBJ = $(SRC:.c=.o)

libft:
	cd libft && $(MAKE)

all: $(NAME) $(LIBFT)

$(NAME) : $(OBJ)
	@ar -rcs $(NAME) $(OBJ) $(LIBFT)

clean:
	@$(RM) $(OBJ) $(LIBFT)

fclean: clean
	@$(RM) $(NAME) $(LIBFT)


re: fclean all
