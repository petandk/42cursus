# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/30 18:41:14 by rmanzana          #+#    #+#              #
#    Updated: 2025/06/02 18:12:59 by rmanzana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

#######################################
## APP INFO
#######################################

NAME			:= philo 
SOURCEFOLDER	:= srcs
OBJECTFOLDER	:= obj
DEPFOLDER		:= dep
HEADERFOLDER	:= includes

FILES		:= philo inits inits2 eat croupier\
			   lunchtime lunchtime_utils\
			   maths strings error

SOURCEFILES := $(addprefix $(SOURCEFOLDER)/, $(addsuffix .c, $(FILES)))
OBJECTFILES	:= $(addprefix $(OBJECTFOLDER)/, $(addsuffix .o, $(FILES)))
DEPFILES	:= $(addprefix $(DEPFOLDER)/, $(addsuffix .d, $(FILES)))

#######################################
## COMPILER 
#######################################

CC		:= gcc
CFLAGS	:= -Wall -Werror -Wextra -g -fsanitize=thread  

# -g -fsanitize=thread
# -g -fsanitize=address -lpthread 

INCLUDES:= -I $(HEADERFOLDER)

#######################################
## OTHER TOOLS
#######################################

RM	:= rm -rf

all :
	@clear
	@$(MAKE) -s $(OBJECTFOLDER) $(DEPFOLDER) $(NAME)
	@echo "Building $(NAME)"

$(NAME): $(OBJECTFILES)
	@echo "Linking $(NAME)"
	$(CC) $(CFLAGS) $(OBJECTFILES) -o $(NAME)

$(OBJECTFOLDER)/%.o : $(SOURCEFOLDER)/%.c
	@mkdir -p $(OBJECTFOLDER) $(DEPFOLDER)
	@echo "Compiling $<"
	$(CC) $(CFLAGS) $(INCLUDES) -MMD -MP -MF $(DEPFOLDER)/$*.d -c $< -o $@

$(OBJECTFOLDER) $(DEPFOLDER):
	@mkdir -p $@

clean:
	@clear
	@echo "Cleaning object files"
	$(RM) $(OBJECTFOLDER) $(DEPFOLDER)

fclean:
	@clear
	@$(MAKE) -s clean
	@echo "Cleaning executable"
	$(RM) $(NAME)

re: 
	@clear
	@$(MAKE) -s fclean
	@$(MAKE) -s all

normi norminette check:
	@clear
	@echo "Running Norminette for $(NAME) $(SOURCEFOLDER) and $(HEADERFOLDER) files"
	norminette $(SOURCEFOLDER) $(HEADERFOLDER)

leak: $(NAME)
	valgrind --leak-check=full ./$(NAME) $(ARGS)

.PHONY: all clean fclean re normi norminette check leak

-include $(DEPFILES)
