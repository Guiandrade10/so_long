# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gude-and <gude-and@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/10 20:00:59 by gude-and          #+#    #+#              #
#    Updated: 2025/07/11 17:00:35 by gude-and         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nome do executável
NAME = test_mlx

# Arquivos fonte
SRC = main.c

# Diretório da minilibx
MLX_DIR = ./minilibx

# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Includes e flags da MiniLibX (Linux)
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -I$(MLX_DIR)

# Regra padrão
all: $(NAME)

$(NAME): $(SRC)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(SRC) $(CFLAGS) $(MLX_FLAGS) -o $(NAME)

clean:
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

