# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 15:32:54 by rmanzana          #+#    #+#              #
#    Updated: 2024/06/20 16:19:21 by rmanzana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#######################################
## APP INFO
#######################################
NAME		:= libft.a
SOURCEFOLDER	:= srcs
HEADERFOLDER	:= includes

FILES	:= ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint ft_strlen ft_memset ft_bzero ft_memcpy ft_memmove ft_strlcpy ft_strlcat ft_toupper ft_tolower ft_strchr ft_strrchr ft_strncmp ft_memchr ft_memcmp ft_strnstr ft_atoi
SOURCEFILES := $(addsuffix .c, $(FILES))
OBJECTFILES	:= $(patsubst %.c, %.o, $(SOURCEFILES))

#######################################
## COMPILER 
#######################################
CC	:= cc
CFLAGS	:= -Wall -Werror -Wextra
AR	:= ar rcs

#######################################
## OTHER TOOLS
#######################################

RM	:= rm -f

all : $(NAME)

$(NAME): $(OBJECTFILES)
	$(AR) $(NAME) $(OBJECTFILES)
	ranlib $(NAME)

%.o : %.c Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTFILES)

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: clean fclean re

