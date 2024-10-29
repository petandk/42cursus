# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmanzana <rmanzana@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/03 19:48:45 by rmanzana          #+#    #+#              #
#    Updated: 2024/07/04 15:48:20 by rmanzana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#######################################
## APP INFO
#######################################

NAME			:= libftprintf.a
SOURCEFOLDER	:= srcs
HEADERFOLDER	:= includes

FILES		:=	ft_printf ft_strings ft_numbers ft_hex

SOURCEFILES := $(addsuffix .c, $(FILES))
OBJECTFILES	:= $(patsubst %.c,%.o,$(SOURCEFILES))

DEPFILES	:= $(addsuffix .d, $(FILES))

#######################################
## COMPILER 
#######################################

CC		:= cc
CFLAGS	:= -Wall -Werror -Wextra
AR		:= ar rcs $(NAME)
RAN		:= ranlib $(NAME)

#######################################
## OTHER TOOLS
#######################################

RM	:= rm -f

all : $(NAME)

$(NAME): $(OBJECTFILES)
	$(AR) $(OBJECTFILES)
	$(RAN)

%.o : %.c Makefile
	$(CC) $(CFLAGS) -MMD -c $< -o $@

clean:
	$(RM) $(OBJECTFILES) $(DEPFILES)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEPFILES)
