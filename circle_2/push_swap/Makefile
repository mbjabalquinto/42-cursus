NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./includes

SRC_DIR = src/
LIBS_DIR = libs/

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

SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES)) \
		$(addprefix $(LIBS_DIR), $(LIB_FILES))

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re