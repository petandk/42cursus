# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 15:32:54 by rmanzana          #+#    #+#              #
#    Updated: 2024/07/01 12:59:20 by rmanzana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#######################################
## APP INFO
#######################################

NAME			:= libft.a
SOURCEFOLDER	:= srcs
HEADERFOLDER	:= includes

FILES		:=	ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint\
		   		ft_strlen ft_memset ft_bzero ft_memcpy ft_memmove ft_strlcpy\
		   		ft_strlcat ft_toupper ft_tolower ft_strchr ft_strrchr ft_strncmp\
		   		ft_memchr ft_memcmp ft_strnstr ft_atoi ft_calloc ft_strdup\
		   		ft_substr ft_strjoin ft_strtrim ft_split ft_itoa ft_strmapi\
		   		ft_striteri ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd

BONUSFILES 	:= 	ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast ft_lstadd_back\
				ft_lstdelone ft_lstclear ft_lstiter ft_lstmap

SOURCEFILES := $(addsuffix .c, $(FILES))
OBJECTFILES	:= $(patsubst %.c,%.o,$(SOURCEFILES))

SOURCEBONUS := $(addsuffix .c, $(BONUSFILES))
OBJECTBONUS := $(patsubst %.c,%.o,$(SOURCEBONUS))

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

bonus: .libft

.libft:	$(OBJECTBONUS) libft.h
	$(AR) $(OBJECTBONUS)
	$(RAN)
	touch .libft


%.o : %.c Makefile libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTFILES) $(OBJECTBONUS)

fclean: clean
	$(RM) $(NAME) .libft

re: fclean all

.PHONY: all bonus clean fclean re
