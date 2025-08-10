# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/30 18:41:14 by rmanzana          #+#    #+#              #
#    Updated: 2024/12/17 21:05:37 by rmanzana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

#######################################
## APP INFO
#######################################

NAME			:= pipex
SOURCEFOLDER	:= srcs
OBJECTFOLDER	:= obj
DEPFOLDER		:= dep
HEADERFOLDER	:= includes
LIBFT			:= libft
PRINTF			:= printf

FILES		:= main args path execution execution_utils errors

SOURCEFILES := $(addprefix $(SOURCEFOLDER)/, $(addsuffix .c, $(FILES)))
OBJECTFILES	:= $(addprefix $(OBJECTFOLDER)/, $(addsuffix .o, $(FILES)))

DEPFILES	:= $(addprefix $(DEPFOLDER)/, $(addsuffix .d, $(FILES)))

#######################################
## COMPILER 
#######################################

CC		:= cc
CFLAGS	:= -Wall -Werror -Wextra
INCLUDES:= -I $(HEADERFOLDER) -I $(LIBFT) -I $(PRINTF)

#######################################
## OTHER TOOLS
#######################################

RM	:= rm -rf

all :
	@clear
	@$(MAKE) -s $(OBJECTFOLDER) $(DEPFOLDER) libft printf $(NAME)
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
	@echo "Building $(NAME)"
	@$(MAKE) -s -C $(LIBFT)

printf:
	@echo "Building $(NAME)"
	@$(MAKE) -s -C $(PRINTF)

clean:
	@clear
	@echo "Cleaning object files"
	$(RM) $(OBJECTFOLDER) $(DEPFOLDER)
	@$(MAKE) -s -C $(LIBFT) clean
	@$(MAKE) -s -C $(PRINTF) clean

fclean:
	@clear
	@$(MAKE) -s clean
	@echo "Cleaning executable"
	$(RM) $(NAME)
	@$(MAKE) -s -C $(LIBFT) fclean
	@$(MAKE) -s -C $(PRINTF) fclean

re: 
	@clear
	@$(MAKE) -s fclean
	@$(MAKE) -s all

normi norminette check:
	@clear
	@echo "Running Norminette for $(NAME) $(SOURCEFOLDER) and $(HEADERFOLDER) files"
	norminette $(SOURCEFOLDER) $(HEADERFOLDER)

.PHONY: all clean fclean re libft printf normi norminette check

-include $(DEPFILES)
