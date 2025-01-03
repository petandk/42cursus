# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/30 18:41:14 by rmanzana          #+#    #+#              #
#    Updated: 2025/01/03 22:55:38 by rmanzana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

#######################################
## APP INFO
#######################################

NAME			:= fractol
SOURCEFOLDER	:= srcs
OBJECTFOLDER	:= obj
DEPFOLDER		:= dep
HEADERFOLDER	:= includes
MINILIBX		:= minilibx-linux

FILES		:= main libft_str libft_num control drawing \
			common_functions mandelbrot julia destroy

SOURCEFILES := $(addprefix $(SOURCEFOLDER)/, $(addsuffix .c, $(FILES)))
OBJECTFILES	:= $(addprefix $(OBJECTFOLDER)/, $(addsuffix .o, $(FILES)))

DEPFILES	:= $(addprefix $(DEPFOLDER)/, $(addsuffix .d, $(FILES)))

#######################################
## COMPILER 
#######################################

CC			:= cc
CFLAGS		:= -Wall -Werror -Wextra -Ofast -ffast-math -march=native
MLX_FLAGS	:= -L./$(MINILIBX) -lmlx -lXext -lX11
INCLUDES	:= -I $(HEADERFOLDER) -I $(MINILIBX)

#######################################
## OTHER TOOLS
#######################################

RM	:= rm -rf

all :
	@clear
	@echo "Building $(NAME)"
	@$(MAKE) -s $(OBJECTFOLDER) $(DEPFOLDER) $(MINILIBX) $(NAME)
	
$(NAME): $(OBJECTFILES) minilibx 
	@echo "Linking $(NAME)"
	$(CC) $(CFLAGS) $(OBJECTFILES) $(MLX_FLAGS) -lm -o $(NAME)

$(OBJECTFOLDER)/%.o : $(SOURCEFOLDER)/%.c Makefile
	@mkdir -p $(OBJECTFOLDER) $(DEPFOLDER)
	@echo "Compiling $<"
	$(CC) $(CFLAGS) $(INCLUDES) -MMD -MP -MF $(DEPFOLDER)/$*.d -c $< -o $@

$(OBJECTFOLDER) $(DEPFOLDER):
	@mkdir -p $@

minilibx:
	@echo "Building $(MINILIBX)"
	@$(MAKE) -s -C $(MINILIBX)

clean:
	@clear
	@echo "Cleaning object files"
	$(RM) $(OBJECTFOLDER) $(DEPFOLDER)
	@$(MAKE) -s -C $(MINILIBX) clean

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

.PHONY: all clean fclean re minilibx normi norminette check

-include $(DEPFILES)
