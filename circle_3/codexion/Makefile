# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjabalqu <mjabalqu@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/12 14:00:00 by mjabalqu          #+#    #+#              #
#    Updated: 2026/06/12 14:00:00 by mjabalqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = codexion
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror -pthread
RM          = rm -f

# Source files
SRCS        = main.c \
              main_utils.c \
              coders.c \
              routines.c \
              routines_utils.c \
              simulation.c \
              simulation_utils.c

# Object files
OBJS        = $(SRCS:.c=.o)

# Colors for output
GREEN       = \033[0;32m
YELLOW      = \033[0;33m
RESET       = \033[0m

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(YELLOW)Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Compilation successful: $(NAME) ready.$(RESET)"

%.o: %.c
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(YELLOW)Cleaning object files...$(RESET)"
	@$(RM) $(OBJS)
	@echo "$(GREEN)Object files removed.$(RESET)"

fclean: clean
	@echo "$(YELLOW)Removing $(NAME)...$(RESET)"
	@$(RM) $(NAME)
	@echo "$(GREEN)Cleanup complete.$(RESET)"

re: fclean all

.PHONY: all clean fclean re
