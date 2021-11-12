NAME = libftprintf.a
SRC = ft_printf.c ft_printf_utils.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ)

compile:
	cc -Wall -Wextra -Werror $(SRC) && ./a.out | cat -e

clean:
	rm $(OBJ)

fclean: clean
	rm $(NAME)

re: fclean all

.PHONY: all clean fclean re
