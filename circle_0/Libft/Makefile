# 1. Configuración General
NAME = libft.a
SRC = ft_isalnum.c ft_isprint.c ft_memmove.c ft_strjoin.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c ft_memchr.c ft_memset.c ft_strlcat.c ft_strnstr.c ft_tolower.c ft_bzero.c ft_isascii.c ft_memcmp.c ft_strchr.c ft_strlcpy.c ft_strrchr.c ft_toupper.c ft_calloc.c ft_isdigit.c ft_memcpy.c ft_strdup.c ft_strlen.c ft_strtrim.c ft_split.c ft_split_utils.c ft_free_matrix.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

# 2. Regla principal
all: $(NAME)

# 3. Crear la librería estática
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

# 3.1. Regla para pruebas con main.
TEST_FILE = main.c
TEST_NAME = run_test

test: $(NAME) $(TEST_FILE)
	# 1. Compila el archivo de prueba (main.c)
	# 2. Lo enlaza contra tu librería estática (-lft)
	# 3. Crea el ejecutable 'run_test'
	$(CC) $(CFLAGS) $(TEST_FILE) -L. -lft -o $(TEST_NAME)

# 3.2. Regla para los bonus de libft.
# Archivos bonus
BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
ft_lstiter.c ft_lstmap.c 
BONUS_OBJ = $(BONUS:.c=.o)
# Regla bonus
bonus: $(OBJ) $(BONUS_OBJ)
	ar rcs $(NAME) $(OBJ) $(BONUS_OBJ)

# 4. Compilar cada archivo fuente
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# 5. Limpiar archivos objeto
clean:
	rm -f $(OBJ) $(BONUS_OBJ)

# 6. Limpiar todo
fclean: clean
	rm -f $(NAME) $(TEST_NAME)

# 7. Recompilar todo
re: fclean all

# 8. Objetivos falsos
.PHONY: all clean fclean re test
