# Executable name
NAME        = so_long

# Compilers and flags
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror 

# Directories
SRC_DIR     = src
INCLUDE_DIR = include
LIBFT_DIR   = Libft
MLX_DIR     = minilibx-linux

# Paths
INCLUDES    = -I$(INCLUDE_DIR) -I$(LIBFT_DIR)/includes -I$(MLX_DIR)

# Sources and objects
SRC         = $(shell find $(SRC_DIR) -type f -name "*.c")
OBJ         = $(SRC:.c=.o)

# Libraries
LIBFT       = $(LIBFT_DIR)/libft.a

MLX         = $(MLX_DIR)/libmlx_Linux.a
MLX_FLAGS   = $(MLX) -lXext -lX11


# Default target
all: $(NAME)

# Build libft
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

# Build mlx
$(MLX):
	@$(MAKE) -C $(MLX_DIR)

# Link the executable
$(NAME): $(LIBFT) $(MLX) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(MLX_FLAGS) $(LIBFT) -no-pie

# Compile .c to .o
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean objects
clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean
	rm -f $(OBJ)

# Full clean including binary
fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(MLX_DIR) clean
	rm -f $(NAME)

val:
	valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes ./so_long maps/map_0.ber
# Rebuild all
re: fclean all

# Phony targets
.PHONY: all clean fclean re

