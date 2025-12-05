NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -I.

SRC = \
ft_printf.c \
ft_putchar.c \
ft_putnbr_base.c \
ft_putnbr.c \
ft_putstr.c \

OBJ = $(SRC:.c=.o)

TEST_FILE = main.c

TEST_NAME = run_test

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

test: $(NAME) $(TEST_FILE)
	$(CC) $(CFLAGS) $(TEST_FILE) -L. -lftprintf -o $(TEST_NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(TEST_NAME)

re: fclean all

.PHONY: all clean fclean re test
