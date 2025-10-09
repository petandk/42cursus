# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/10 20:46:57 by rmanzana          #+#    #+#              #
#    Updated: 2025/10/09 20:53:03 by rmanzana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = ocf
TEST_NAME   = testall

COMPILER    = c++

CFLAGS      = -Wall -Werror -Wextra -std=c++98

SRC_DIR     = src/
OBJ_DIR     = obj/
INCLUDE_DIR = inc/

# Main program files
SOURCE_FILES = main.cpp \
				fixed.cpp

# Test program files  
TEST_SOURCE_FILES = testall.cpp \
					fixed.cpp

SRCS		= $(addprefix $(SRC_DIR), $(SOURCE_FILES))
OBJS		= $(patsubst $(SRC_DIR)%.cpp, $(OBJ_DIR)%.o, $(SRCS))
DEPS		= $(OBJS:.o=.d)

TEST_SRCS	= $(addprefix $(SRC_DIR), $(TEST_SOURCE_FILES))
TEST_OBJS	= $(patsubst $(SRC_DIR)%.cpp, $(OBJ_DIR)%.o, $(TEST_SRCS))
TEST_DEPS	= $(TEST_OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(COMPILER) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "\033[1;36m"
	@echo "==================================================="
	@echo "	🍏​🍎 $(NAME) Compiled! 🍎​🍏"
	@echo "==================================================="
	@echo "\033[0m"

testall: $(TEST_NAME)

$(TEST_NAME): $(TEST_OBJS)
	$(COMPILER) $(CFLAGS) $(TEST_OBJS) -o $(TEST_NAME)
	@echo "\033[1;32m"
	@echo "==================================================="
	@echo "	🧪​🔬 $(TEST_NAME) Compiled! 🔬​🧪"
	@echo "==================================================="
	@echo "\033[0m"

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(OBJ_DIR)
	$(COMPILER) $(CFLAGS) -I $(INCLUDE_DIR) -MMD -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	@echo "\033[1;33m"
	@echo "==================================================="
	@echo "	🧹 Object files cleaned! 🧹"
	@echo "==================================================="
	@echo "\033[0m"

fclean: clean
	rm -f $(NAME) $(TEST_NAME)
	@echo "\033[1;34m"
	@echo "==================================================="
	@echo "	🗑️  Executables removed! 🗑️"
	@echo "==================================================="
	@echo "\033[0m"

re:	fclean all

retestall: fclean testall

-include $(DEPS) $(TEST_DEPS)
.PHONY: all clean fclean re testall retestall
