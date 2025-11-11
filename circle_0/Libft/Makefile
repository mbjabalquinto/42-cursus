# 1. Configuración General
NAME = libft.a
#SRC_DIR = srcs
#INC_DIR = includes
SRC =	ft_putchar.c ft_putstr.c ft_strcmp.c ft_strlen.c ft_swap.c
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -g 

# 2. Regla principal
all: $(NAME)

# 3. Crear la librería estática
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

# 4. Compilar cada archivo fuente
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# 5. Limpiar archivos objeto
clean:
	rm -f $(OBJ)

# 6. Limpiar todo
fclean: clean
	rm -f $(NAME)

# 7. Recompilar todo
re: fclean all

# 8. Objetivos falsos
.PHONY: all clean fclean re
