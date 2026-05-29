NAME        = webserv

COMPILER    = c++

CFLAGS      = -Wall -Werror -Wextra -std=c++98 -Wshadow #-g -fsanitize=address,leak
DEBUG_FLAGS = -DDEBUG -g

SRC_DIR     = src/
OBJ_DIR     = obj/
INCLUDE_DIR = inc/

CGI_DIR   = CGI/
MIME_DIR   = mime/
PARSER_DIR   = parser/
REQUEST_DIR  = request/
RESPONSE_DIR  = response/
SERVER_DIR  = server/
UTILS_DIR   = utils/

CGI_FILES   =   CGIHandler.cpp

MIME_FILES   =  MimeTypes.cpp

PARSER_FILES =  ServerConfig.cpp \
                ConfigParser.cpp \
                LocationConfig.cpp \
                RequestParser.cpp \
				ConfigPreflight.cpp

REQUEST_FILES   =   HTTPRequest.cpp

RESPONSE_FILES   =  HTTPResponse.cpp \
                    ResponseBuilder.cpp


SERVER_FILES =  Server.cpp \
                Client.cpp

UTILS_FILES =   Utils.cpp \
                Debug.cpp \
                HTTPStatus.cpp \
				BuilderUtils.cpp \
				CGIUtils.cpp

MAIN_FILE   = main.cpp

SOURCE_FILES =  $(addprefix $(CGI_DIR), $(CGI_FILES)) \
                $(addprefix $(MIME_DIR), $(MIME_FILES)) \
                $(addprefix $(PARSER_DIR), $(PARSER_FILES)) \
                $(addprefix $(REQUEST_DIR), $(REQUEST_FILES)) \
                $(addprefix $(RESPONSE_DIR), $(RESPONSE_FILES)) \
                $(addprefix $(SERVER_DIR), $(SERVER_FILES)) \
                $(addprefix $(UTILS_DIR), $(UTILS_FILES)) \
                $(MAIN_FILE)

SRCS        = $(addprefix $(SRC_DIR), $(SOURCE_FILES))
OBJS        = $(patsubst $(SRC_DIR)%.cpp,$(OBJ_DIR)%.o,$(SRCS))
DEPS        = $(OBJS:.o=.d)

INCLUDES    =   -I $(INCLUDE_DIR) \
                -I $(INCLUDE_DIR)$(CGI_DIR) \
                -I $(INCLUDE_DIR)$(MIME_DIR) \
                -I $(INCLUDE_DIR)$(PARSER_DIR) \
                -I $(INCLUDE_DIR)$(REQUEST_DIR) \
                -I $(INCLUDE_DIR)$(RESPONSE_DIR) \
                -I $(INCLUDE_DIR)$(SERVER_DIR) \
                -I $(INCLUDE_DIR)$(UTILS_DIR)


all: $(NAME)

$(NAME): $(OBJS)
	$(COMPILER) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "\033[1;36m"
	@echo "==================================================="
	@echo "\t🍏​🍎 $(NAME) Compiled! 🍎​🍏"
	@echo "==================================================="
	@echo "\033[0m"

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(@D)
	$(COMPILER) $(CFLAGS) $(INCLUDES) -MMD -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	@echo "\033[1;33m"
	@echo "==================================================="
	@echo "\t🧹 Object files cleaned! 🧹"
	@echo "==================================================="
	@echo "\033[0m"

fclean: clean
	rm -f $(NAME)
	@echo "\033[1;34m"
	@echo "==================================================="
	@echo "\t🗑️  Executable removed! 🗑️"
	@echo "==================================================="
	@echo "\033[0m"

re: fclean all

run: all
	@echo "\033[1;32m"
	@echo "==================================================="
	@echo " ⚰️​  Executing $(NAME)... ⚰️​​​​"
	@echo "==================================================="
	@echo "\033[0m"
	./$(NAME)

debug:
	$(MAKE) --no-print-directory fclean
	$(MAKE) --no-print-directory all CFLAGS="$(CFLAGS) $(DEBUG_FLAGS)"
	@echo "\033[1;31m"
	@echo "==================================================="
	@echo "\t🐛 DEBUG MODE ENABLED 🐛"
	@echo "==================================================="
	@echo "\033[0m"

#		To show debug info you should do something like this:
#				#ifdef DEBUG
#                   std::cout << "debug message" << std::endl;
#               #endif

-include $(DEPS)
.PHONY: all clean fclean re run debug
