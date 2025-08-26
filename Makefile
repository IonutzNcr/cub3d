NAME = cub3d

CC       = cc
CFLAGS   = -Wall -Wextra -Iincludes -Imlx_linux -Ilibft -g 

SRC_DIR = src
INC_DIR = includes
OBJ_DIR = obj

SRC_FILES = $(SRC_DIR)/main.c\
			$(SRC_DIR)/parser/controller/asset_checker.c\
			$(SRC_DIR)/parser/controller/asset_parser.c\
			$(SRC_DIR)/parser/controller/checked_list.c\
			$(SRC_DIR)/parser/controller/check_characters.c\
			$(SRC_DIR)/parser/controller/map_fixer.c\
			$(SRC_DIR)/parser/controller/map_parser.c\
			$(SRC_DIR)/parser/controller/map_checker.c\
			$(SRC_DIR)/parser/controller/mapper.c\
			$(SRC_DIR)/parser/controller/parse_assets.func.c\
			$(SRC_DIR)/parser/controller/parse_cf.func.c\
			$(SRC_DIR)/parser/controller/parser.c\
			$(SRC_DIR)/parser/controller/utils.c\
			$(SRC_DIR)/parser/controller/utility.c\
			$(SRC_DIR)/parser/controller/verif.c\
			$(SRC_DIR)/parser/rules/is_cf_format.c\
			$(SRC_DIR)/parser/rules/is_extension.c\
			$(SRC_DIR)/parser/rules/is_file_empty.c\
			$(SRC_DIR)/parser/rules/is_invalid_space.c\
			$(SRC_DIR)/parser/rules/is_texture_format.c\
			$(SRC_DIR)/singleton/sgt_assets.c\
			$(SRC_DIR)/singleton/sgt_error.c\
			$(SRC_DIR)/singleton/sgt_line.c\
			$(SRC_DIR)/singleton/sgt_map.c\
			$(SRC_DIR)/minimap/init_mini_map.c


OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

H_FILES = $(INC_DIR)/checker.h $(INC_DIR)/minimap.h 

all: $(NAME)

# Single canonical rule: creates obj subdirs and compiles
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(H_FILES)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS)  -c $< -o $@

$(NAME): $(OBJ_FILES)
	$(MAKE) -C libft
	$(MAKE) -C mlx_linux
	$(CC) $(OBJ_FILES) -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -Llibft -lft -o $(NAME) -g3
	
	

clean:
	$(MAKE) -C libft clean
	$(MAKE) -C mlx_linux clean
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
