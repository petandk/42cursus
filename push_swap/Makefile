# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/30 18:41:14 by rmanzana          #+#    #+#              #
#    Updated: 2024/10/01 18:26:39 by rmanzana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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
				list swap push rotate reverse

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

all : $(OBJECTFOLDER) $(DEPFOLDER) libft printf $(NAME)

$(NAME): $(OBJECTFILES) libft printf
	$(CC) $(CFLAGS) $(OBJECTFILES) -L $(LIBFT) -lft -L $(PRINTF) -lftprintf -o $(NAME)

$(OBJECTFOLDER)/%.o : $(SOURCEFOLDER)/%.c Makefile
	@mkdir -p $(OBJECTFOLDER) $(DEPFOLDER)
	$(CC) $(CFLAGS) $(INCLUDES) -MMD -MP -MF $(DEPFOLDER)/$*.d -c $< -o $@

$(OBJECTFOLDER) $(DEPFOLDER):
	@mkdir -p $@

libft:
	@$(MAKE) -C $(LIBFT)

printf:
	@$(MAKE) -C $(PRINTF)

clean:
	$(RM) $(OBJECTFOLDER) $(DEPFOLDER)
	@$(MAKE) -C $(LIBFT) clean
	@$(MAKE) -C $(PRINTF) clean

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT) fclean
	@$(MAKE) -C $(PRINTF) fclean

re: fclean all

.PHONY: all clean fclean re libft printf

-include $(DEPFILES)
