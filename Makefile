# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inicoara <inicoara@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/12 16:19:15 by kjullien          #+#    #+#              #
#    Updated: 2025/09/30 18:24:39 by inicoara         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -g

# Directories
SRC_DIR = src
INC_DIR = includes
OBJ_DIR = obj
MLX_DIR = minilibx-linux
LIBFT_DIR = libft

# MiniLibX flags (Linux)
MLX_FLAGS = -I$(MLX_DIR) -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

# Source files
SRC_FILES = $(SRC_DIR)/main.c \
			$(SRC_DIR)/parser/controller/asset_checker.c \
			$(SRC_DIR)/parser/controller/asset_parser.c \
			$(SRC_DIR)/parser/controller/checked_list.c \
			$(SRC_DIR)/parser/controller/check_characters.c \
			$(SRC_DIR)/parser/controller/map_fixer.c \
			$(SRC_DIR)/parser/controller/map_parser.c \
			$(SRC_DIR)/parser/controller/map_checker.c \
			$(SRC_DIR)/parser/controller/mapper.c \
			$(SRC_DIR)/parser/controller/parse_assets.func.c \
			$(SRC_DIR)/parser/controller/parse_cf.func.c \
			$(SRC_DIR)/parser/controller/parser.c \
			$(SRC_DIR)/parser/controller/get_player_info.c \
			$(SRC_DIR)/parser/controller/utils.c \
			$(SRC_DIR)/parser/controller/utility.c \
			$(SRC_DIR)/parser/controller/verif.c \
			$(SRC_DIR)/parser/rules/is_cf_format.c \
			$(SRC_DIR)/parser/rules/is_extension.c \
			$(SRC_DIR)/parser/rules/is_file_empty.c \
			$(SRC_DIR)/parser/rules/is_invalid_space.c \
			$(SRC_DIR)/parser/rules/is_texture_format.c \
			$(SRC_DIR)/singleton/sgt_assets.c \
			$(SRC_DIR)/singleton/sgt_error.c \
			$(SRC_DIR)/singleton/sgt_line.c \
			$(SRC_DIR)/singleton/sgt_map.c \
			$(SRC_DIR)/singleton/sgt_player.c \
			$(SRC_DIR)/graphics/render_single_frame.c \
			$(SRC_DIR)/graphics/temp.c\
			$(SRC_DIR)/graphics/utils_compute.c\
			$(SRC_DIR)/graphics/utils_compute2.c\
			$(SRC_DIR)/graphics/moves.c\
			$(SRC_DIR)/graphics/utils_moves.c\
			$(SRC_DIR)/graphics/utils_moves2.c\
			$(SRC_DIR)/graphics/dda.c\
			$(SRC_DIR)/graphics/events.c\
			$(SRC_DIR)/graphics/draw_utils.c\
			$(SRC_DIR)/graphics/memory_management.c\
			$(SRC_DIR)/graphics/misc.c\
			$(SRC_DIR)/graphics/init.c\
			$(SRC_DIR)/graphics/walls_misc.c\
			$(SRC_DIR)/graphics/walls.c\
			$(SRC_DIR)/graphics/textures.c\
			

# Object files
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

# Include paths
INC_FLAGS = -I$(INC_DIR) -I$(MLX_DIR)

# Default rule
all: $(NAME)

# Build executable
$(NAME): $(OBJ_FILES)
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJ_FILES) -L$(LIBFT_DIR) -lft $(MLX_FLAGS) -I$(INC_DIR) -o $(NAME)

# Build object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC_FLAGS) -c $< -o $@

# Cleaning rules
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

# Extra rules
lint:
	@echo "Running norminette..."
	@norminette $(SRC_FILES) $(INC_DIR)/*.h

format:
	@echo "Formatting..."
	@c_formatter_42 $(SRC_FILES) $(INC_DIR)/*.h

.PHONY: all clean fclean re lint format
