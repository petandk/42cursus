NAME        = convert

COMPILER    = c++

CFLAGS      = -Wall -Werror -Wextra -std=c++98 -Wshadow
DEBUG_FLAGS = -DDEBUG -g

SRC_DIR     = src/
OBJ_DIR     = obj/
INCLUDE_DIR = inc/

SOURCE_FILES = ScalarConverter.cpp \
                main.cpp

SRCS		= $(addprefix $(SRC_DIR), $(SOURCE_FILES))
OBJS		= $(patsubst $(SRC_DIR)%.cpp, $(OBJ_DIR)%.o, $(SRCS))
DEPS		= $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(COMPILER) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "\033[1;36m"
	@echo "==================================================="
	@echo "	🍏​🍎 $(NAME) Compiled! 🍎​🍏"
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
	rm -f $(NAME)
	@echo "\033[1;34m"
	@echo "==================================================="
	@echo "	🗑️  Executable removed! 🗑️"
	@echo "==================================================="
	@echo "\033[0m"

re:	fclean all

run: all
	@echo "\033[1;32m"
	@echo "==================================================="
	@echo " ⚰️​  Executing $(NAME)... ⚰️​​​​"
	@echo "==================================================="
	@echo "\033[0m"
	./$(NAME)

debug: CFLAGS += $(DEBUG_FLAGS)
debug: fclean all
	@echo "\033[1;31m"
	@echo "==================================================="
	@echo "	🐛 DEBUG MODE ENABLED 🐛"
	@echo "==================================================="
	@echo "\033[0m"

 #		To show debug info you should do somenthing like this:
 #				#ifdef DEBUG
 #                   std::cout << "debug message" << std::endl;
 #               #endif

-include $(DEPS)
.PHONY: all clean fclean re run
