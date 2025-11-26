# **************************************************************************** #
#                                 1. VARIABLES                                 #
# **************************************************************************** #

# Nombre de la librería estática
NAME = libft.a
CC = cc

# Flags de compilación: -I. para encontrar libft.h
CFLAGS = -Wall -Wextra -Werror -g -I.


# ---------------------------------------------------------------------------- #
#                              Parte Obligatoria (All)                         #
# ---------------------------------------------------------------------------- #
SRC = ft_isalnum.c ft_isprint.c ft_memmove.c ft_strjoin.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c ft_memchr.c ft_memset.c ft_strlcat.c ft_strnstr.c ft_tolower.c ft_bzero.c ft_isascii.c ft_memcmp.c ft_strchr.c ft_strlcpy.c ft_strrchr.c ft_toupper.c ft_calloc.c ft_isdigit.c ft_memcpy.c ft_strdup.c ft_strlen.c ft_strtrim.c ft_split.c ft_split_utils.c ft_free_matrix.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
OBJ = $(SRC:.c=.o)


# ---------------------------------------------------------------------------- #
#                               Parte Bonus (Listas)                           #
# ---------------------------------------------------------------------------- #
# Nota: Los archivos .c deben llamarse *_bonus.c para cumplir la Norma.
BONUS_SRC = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
BONUS_OBJ = $(BONUS_SRC:.c=.o)

# Conjunto total de objetos (Base + Bonus)
ALL_OBJ = $(OBJ) $(BONUS_OBJ)


# ---------------------------------------------------------------------------- #
#                              Variables de Prueba                             #
# ---------------------------------------------------------------------------- #
TEST_FILE = main.c
TEST_NAME = run_test


# **************************************************************************** #
#                                 2. REGLAS                                    #
# **************************************************************************** #

# Regla principal: Construye la librería solo con la parte obligatoria.
all: $(NAME)

# -------------------------- Construcción de la Librería ------------------------- #

# Regla para el objetivo 'all' (Crea/Actualiza libft.a solo con OBJ base)
$(NAME): $(OBJ)
	ar rcs $@ $^

# Regla bonus: Compila los bonus y enlaza la librería con todo.
# Depende de todos los objetos (.o) y crea/actualiza la librería con ellos.
bonus: $(ALL_OBJ)
	ar rcs $(NAME) $^

# ------------------------------ Regla de Compilación ---------------------------- #

# Regla de sufijo (Implícita): Cómo compilar cualquier .c a su respectivo .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# ----------------------------------- Regla Test --------------------------------- #

test: $(NAME) $(TEST_FILE)
	$(CC) $(CFLAGS) $(TEST_FILE) -L. -lft -o $(TEST_NAME)

# ---------------------------------- Limpieza ------------------------------------ #

# Limpia los objetos (.o) de la parte obligatoria y bonus.
clean:
	rm -f $(OBJ) $(BONUS_OBJ)

# Limpia todo: objetos y la librería final.
fclean: clean
	rm -f $(NAME) $(TEST_NAME)

# Recompila todo: Limpia y luego construye la parte obligatoria.
re: fclean all

# ------------------------------- Objetivos Falsos ------------------------------- #

.PHONY: all clean fclean re test bonus
