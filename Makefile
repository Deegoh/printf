NAME = libftprintf.a
SRC = ft_printf.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	ar -rc $(NAME) $(OBJ)

clean:
	rm $(OBJ)

fclean: clean
	rm $(NAME)

re: fclean all

.PHONY: all clean fclean re
