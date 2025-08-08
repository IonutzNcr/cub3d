# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoyo <yoyo@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/12 16:19:15 by kjullien          #+#    #+#              #
#    Updated: 2025/08/08 16:16:49 by yoyo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

# Compiler and flags
CC = cc

# CFLAGS = -Wall -Wextra -Werror -g
CFLAGS = -Wall -Wextra -g

# Directories
SRC_DIR = src
INC_DIR = includes
OBJ_DIR = obj

# Source files
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
          
# All C files for linting and formatting
C_FILES = $(SRC_FILES)
H_FILES = 	$(INC_DIR)/checker.h \
	
			
			


# Object files
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

# Header files
INC_FILES = -I$(INC_DIR)/

# Readline



# Rules
all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS)  $(OBJ_FILES) -L./libft -lft -I./includes -o $(NAME) -g3

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(H_FILES)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC_FILES) -c $< -o $@

# Linting with norminette
lint:
	@echo "Running norminette on all source files..."
	@norminette $(C_FILES)
	@echo "Running norminette on all header files..."
	@norminette $(H_FILES)

# Formatting with c_formatter_42
format:
	@echo "Formatting source files with c_formatter_42..."
	@c_formatter_42 $(C_FILES)
	@echo "Formatting header files with c_formatter_42..."
	@c_formatter_42 $(H_FILES)

clean:
	$(MAKE) -C ./libft clean
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C ./libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re lint format
