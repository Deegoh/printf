NAME = libftprintf.a
SRC = ft_printf.c ft_printf_utils.c
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

compile:
	$(CC) $(CFLAGS) $(SRC) && ./a.out | cat -e

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re compile
