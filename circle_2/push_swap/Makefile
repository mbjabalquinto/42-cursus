NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
# Esto le dice al compilador dónde buscar el .h
INCLUDES = -I./includes

# --- RUTAS ---
SRC_DIR = src/
LIBS_DIR = libs/

# --- ARCHIVOS FUENTE ---
# Solo los nombres, las rutas se añaden abajo automáticamente
SRC_FILES = main.c \
			push_swap.c \
			stack_utils.c \
			set_nodes.c \
			return_to_stack_a.c \
			parse_and_node_utils.c \
			swap.c \
			swap_push_and_swap.c \
			swap_rotate.c \
			swap_rrotate.c

LIB_FILES = ft_atol.c \
			ft_split.c \
			ft_substr.c \
			ft_strdup.c \
			ft_strlen.c \
			ft_strlcpy.c

# --- COMBINACIÓN DE RUTAS Y ARCHIVOS ---
# addprefix añade "src/" o "libs/" delante de cada archivo
SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES)) \
       $(addprefix $(LIBS_DIR), $(LIB_FILES))

# Convierte los .c en .o (manteniendo la ruta)
OBJS = $(SRCS:.c=.o)

# --- REGLAS ---

all: $(NAME)

# Crea el ejecutable linkeando los objetos
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Compila cada .c a .o individualmente
# $< es el archivo .c (input)
# $@ es el archivo .o (output)
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re