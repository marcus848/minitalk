# File name
NAME = project_name

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -Iinclude

# Directories
SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = libft
BIN_DIR = bin
TEST_DIR = tests

# Source and object files
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
LIBFT = $(LIBFT_DIR)/libft.a

# targets
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) -lft

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR) $(LIBFT_DIR)/obj
	@echo "Object files removed."

fclean: clean
	@rm -f $(NAME) $(LIBFT)
	@echo "fcleaned"

re: fclean all

.PHONY: all clean fclean re

#Tests
TEST_SRCS = $(wildcard $(TEST_DIR)/*.c)
TEST_BINS = $(TEST_SRCS:$(TEST_DIR)/%.c=$(BIN_DIR)/%)

tests: $(TEST_BINS)

$(BIN_DIR)/%: $(TEST_DIR)/%.c $(LIBFT)
	$(CC) $(CFLAGS) $< -o $@_tester -L$(LIBFT_DIR) -lft
