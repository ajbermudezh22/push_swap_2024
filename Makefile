
CC := gcc
CFLAGS := -Wall -Wextra -Werror
LIBFT_PATH := libft
LIBFT_ARCHIVE := $(LIBFT_PATH)/libft.a
SRC := main.c check_input.c push.c sorting.c stack_helpers.c stack_initialization.c stack_memory.c swap_rotate_rrotate.c
NAME := push_swap
HEADER := push_swap.h

NAME := push_swap
HEADER := push_swap.h

# ANSI escape codes for colors
GREEN = \033[0;32m
YELLOW = \033[0;33m
RESET = \033[0m

all: $(NAME)

$(NAME): $(SRC) $(LIBFT_ARCHIVE) $(HEADER)
	$(CC) $(CFLAGS) -o $@ $(SRC) -I$(LIBFT_PATH) -L$(LIBFT_PATH) -lft
	@echo "$(GREEN)Push_swap compiled successfully.$(RESET)"

$(LIBFT_ARCHIVE):
	$(MAKE) -C $(LIBFT_PATH)
	@echo "$(GREEN)Libft compiled successfully.$(RESET)"

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	@echo "$(YELLOW)Cleaned object files.$(RESET)"

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	rm -f $(NAME)
	@echo "$(YELLOW)Cleaned all files.$(RESET)"

re: fclean all

.PHONY: all clean fclean re

