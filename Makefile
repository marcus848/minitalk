# File name
NAME = minitalk

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
SRCS = $(SRC_DIR)/client.c $(SRC_DIR)/server.c
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
LIBFT = $(LIBFT_DIR)/libft.a

# targets
all: $(NAME)

${NAME}: server client

server: $(BIN_DIR)/server

client: $(BIN_DIR)/client

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

$(BIN_DIR)/server: $(OBJ_DIR)/server.o $(LIBFT) | $(BIN_DIR)
	$(CC) $(CFLAGS) $(OBJ_DIR)/server.o -o $(BIN_DIR)/server -L$(LIBFT_DIR) -lft

$(BIN_DIR)/client: $(OBJ_DIR)/client.o $(LIBFT) | $(BIN_DIR)
	$(CC) $(CFLAGS) $(OBJ_DIR)/client.o -o $(BIN_DIR)/client -L$(LIBFT_DIR) -lft

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)


clean:
	@rm -rf $(OBJ_DIR) $(LIBFT_DIR)/obj
	@echo "Object files removed."

fclean: clean
	@rm -rf $(BIN_DIR)/* $(LIBFT)
	@rm -rf $(BIN_DIR)
	@echo "all cleaned"

re: fclean all

.PHONY: all clean fclean re
