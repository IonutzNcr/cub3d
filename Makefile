# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoyo <yoyo@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/12 16:19:15 by kjullien          #+#    #+#              #
#    Updated: 2025/11/05 12:58:26 by yoyo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D


CC = cc
CFLAGS = -Wall -Wextra -Werror -g


SRC_DIR = src
INC_DIR = includes
OBJ_DIR = obj
MLX_DIR = minilibx-linux
LIBFT_DIR = libft


MLX_FLAGS = -I$(MLX_DIR) -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

SRC_FILES = $(SRC_DIR)/main.c \
			$(SRC_DIR)/parser/controller/asset_checker.c \
			$(SRC_DIR)/parser/controller/asset_parser.c \
			$(SRC_DIR)/parser/controller/checked_list.c \
			$(SRC_DIR)/parser/controller/check_characters.c \
			$(SRC_DIR)/parser/controller/map_fixer.c \
			$(SRC_DIR)/parser/controller/map_parser.c \
			$(SRC_DIR)/parser/controller/map_checker.c \
			$(SRC_DIR)/parser/controller/map_checker_2.c \
			$(SRC_DIR)/parser/controller/map_checker_3.c \
			$(SRC_DIR)/parser/controller/map_checker_4.c \
			$(SRC_DIR)/parser/controller/mapper.c \
			$(SRC_DIR)/parser/controller/parse_assets.func.c \
			$(SRC_DIR)/parser/controller/parse_cf.func.c \
			$(SRC_DIR)/parser/controller/parser.c \
			$(SRC_DIR)/parser/controller/get_player_info.c \
			$(SRC_DIR)/parser/controller/utils.c \
			$(SRC_DIR)/parser/controller/utility.c \
			$(SRC_DIR)/parser/controller/hard_verif.c \
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
			


OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))


INC_FLAGS = -I$(INC_DIR) -I$(MLX_DIR)


all: $(NAME)


$(NAME): $(OBJ_FILES)
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJ_FILES) -L$(LIBFT_DIR) -lft $(MLX_FLAGS) -I$(INC_DIR) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC_FLAGS) -c $< -o $@


clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(MLX_DIR) clean
	rm -f $(NAME)

re: fclean all



.PHONY: all clean fclean re
