NAME        = codexion
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -pthread
RM          = rm -rf
OBJ_DIR     = obj

# Source files
SRCS        = main.c \
              main_utils.c \
              coders.c \
              routines.c \
              dongles.c \
              simulation.c \
              simulation_utils.c \
			  scheduler.c

# Object files in separate directory
OBJS        = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: %.c codexion.h
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

run: all
	./$(NAME) 6 800 200 200 200 5 10 edf

.PHONY: all clean fclean re run
