# 1. Configuración General
NAME = libft.a
#SRC_DIR = srcs
#INC_DIR = includes
SRC = ft_isalnum.c ft_isprint.c ft_memmove.c ft_strjoin.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c ft_memchr.c ft_memset.c ft_strlcat.c ft_strnstr.c ft_tolower.c ft_bzero.c ft_isascii.c ft_memcmp.c ft_strchr.c ft_strlcpy.c ft_strrchr.c ft_toupper.c ft_calloc.c ft_isdigit.c ft_memcpy.c ft_strdup.c ft_strlen.c ft_strtrim.c ft_split.c ft_split_utils.c ft_free_matrix.c ft_itoa.c ft_strmapi.c
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
