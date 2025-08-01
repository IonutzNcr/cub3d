# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoyo <yoyo@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/12 16:19:15 by kjullien          #+#    #+#              #
#    Updated: 2025/07/28 20:41:27 by yoyo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

# Directories
SRC_DIR = src
INC_DIR = includes
OBJ_DIR = obj

# Source files
SRC_FILES = $(SRC_DIR)/main.c\
			$(SRC_DIR)/checker.c\
			$(SRC_DIR)/checks/is_extension.c
          
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
