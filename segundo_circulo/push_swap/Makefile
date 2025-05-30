# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/30 18:41:14 by rmanzana          #+#    #+#              #
#    Updated: 2025/01/07 22:44:26 by rmanzana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

#######################################
## APP INFO
#######################################

NAME			:= push_swap
SOURCEFOLDER	:= srcs
OBJECTFOLDER	:= obj
DEPFOLDER		:= dep
HEADERFOLDER	:= includes
LIBFT			:= libft
PRINTF			:= printf

FILES		:=	push_swap push_swap_utils\
				list swap push rotate reverse\
				errors args sort\
				turk turk_utils turk_help turk_rotate\
				turk_fixes

SOURCEFILES := $(addprefix $(SOURCEFOLDER)/, $(addsuffix .c, $(FILES)))
OBJECTFILES	:= $(addprefix $(OBJECTFOLDER)/, $(addsuffix .o, $(FILES)))

DEPFILES	:= $(addprefix $(DEPFOLDER)/, $(addsuffix .d, $(FILES)))

#######################################
## COMPILER 
#######################################

CC		:= cc
CFLAGS	:= -Wall -Werror -Wextra -g
INCLUDES:= -I $(HEADERFOLDER) -I $(LIBFT) -I $(PRINTF)

#######################################
## OTHER TOOLS
#######################################

RM	:= rm -rf

all : $(OBJECTFOLDER) $(DEPFOLDER) libft printf $(NAME)
	@echo "Building $(NAME)"

$(NAME): $(OBJECTFILES) libft printf
	@echo "Linking $(NAME)"
	$(CC) $(CFLAGS) $(OBJECTFILES) -L $(LIBFT) -lft -L $(PRINTF) -lftprintf -o $(NAME)

$(OBJECTFOLDER)/%.o : $(SOURCEFOLDER)/%.c Makefile
	@mkdir -p $(OBJECTFOLDER) $(DEPFOLDER)
	@echo "Compiling $<"
	$(CC) $(CFLAGS) $(INCLUDES) -MMD -MP -MF $(DEPFOLDER)/$*.d -c $< -o $@

$(OBJECTFOLDER) $(DEPFOLDER):
	@mkdir -p $@

libft:
	@echo "Building libft"
	@$(MAKE) -s -C $(LIBFT)

printf:
	@echo "Building printf"
	@$(MAKE) -s -C $(PRINTF)

clean:
	@echo "Cleaning object files"
	$(RM) $(OBJECTFOLDER) $(DEPFOLDER)
	@$(MAKE) -s -C $(LIBFT) clean
	@$(MAKE) -s -C $(PRINTF) clean

fclean: clean
	@echo "Cleaning executable"
	$(RM) $(NAME)
	@$(MAKE) -s -C $(LIBFT) fclean
	@$(MAKE) -s -C $(PRINTF) fclean

test:
	@NUM_QTY=500; \
    MAX_MOVES=5500; \
    ARG=$$(shuf -i 0-5000000 -n $$NUM_QTY); \
    RESULT=$$(./$(NAME) $$ARG | ./checker_linux $$ARG); \
    if [ "$$RESULT" = "OK" ]; then \
        COLOR="\033[0;32m"; \
    else \
        COLOR="\033[0;31m"; \
    fi; \
    echo "󱝿⚙️ Checker verify: $$COLOR$$RESULT\033[0m"; \
    echo -n "🔢 Num of moves:    "; \
    NUM_MOVES=$$(./$(NAME) $$ARG | wc -l); \
    if [ $$NUM_MOVES -lt $$MAX_MOVES ]; then \
        COLOR="\033[0;32m"; \
    else \
        COLOR="\033[0;31m"; \
    fi; \
    echo "$$COLOR$$NUM_MOVES\033[0m"

re: fclean all

normi norminette check:
	@clear
	@echo "Running Norminette for $(NAME) $(SOURCEFOLDER) and $(HEADERFOLDER) files"
	norminette $(SOURCEFOLDER) $(HEADERFOLDER)

.PHONY: all clean fclean re libft printf test normi norminette check

-include $(DEPFILES)
