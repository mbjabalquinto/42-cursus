NAME		= push_swap
BONUS_NAME	= checker

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

INCLUDES = -I ./includes -I ./bonus/includes

LIBS_SRC =	libs/ft_atol.c libs/ft_split.c libs/ft_strdup.c \
			libs/ft_strlcpy.c libs/ft_strlen.c libs/ft_substr.c

COMMON_SRC =	src/node_utils.c \
				src/parse_utils.c \
				src/stack_utils.c \
				src/swap.c \
				src/swap_push_and_swap.c \
				src/swap_rotate.c \
				src/swap_rrotate.c

MAND_SRC =	src/main.c \
			src/push_swap.c \
			src/sort_stacks.c \
			src/set_nodes.c \
			src/return_to_stack_a.c

BONUS_SRC =	bonus/checker.c \
			bonus/libs/get_next_line.c \
			bonus/libs/get_next_line_utils.c \
			bonus/libs/ft_strcmp.c \
			bonus/libs/ft_strncmp.c \

LIBS_OBJ	= $(LIBS_SRC:.c=.o)
COMMON_OBJ	= $(COMMON_SRC:.c=.o)
MAND_OBJ	= $(MAND_SRC:.c=.o)
BONUS_OBJ	= $(BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBS_OBJ) $(COMMON_OBJ) $(MAND_OBJ)
	$(CC) $(CFLAGS) $(LIBS_OBJ) $(COMMON_OBJ) $(MAND_OBJ) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(LIBS_OBJ) $(COMMON_OBJ) $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(LIBS_OBJ) $(COMMON_OBJ) $(BONUS_OBJ) -o $(BONUS_NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(LIBS_OBJ) $(COMMON_OBJ) $(MAND_OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus