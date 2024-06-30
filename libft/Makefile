# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 15:32:54 by rmanzana          #+#    #+#              #
#    Updated: 2024/06/30 20:43:52 by rmanzana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#######################################
## APP INFO
#######################################
NAME			:= libft.a
SOURCEFOLDER	:= srcs
HEADERFOLDER	:= includes

FILES		:= ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint\
			   ft_strlen ft_memset ft_bzero ft_memcpy ft_memmove ft_strlcpy\
			   ft_strlcat ft_toupper ft_tolower ft_strchr ft_strrchr ft_strncmp\
			   ft_memchr ft_memcmp ft_strnstr ft_atoi ft_calloc ft_strdup\
			   ft_substr ft_strjoin ft_strtrim ft_split ft_itoa ft_strmapi\
			   ft_striteri ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd

BONUSFILES	:= ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast ft_lstadd_back

SOURCEFILES := $(addsuffix .c, $(FILES))
OBJECTFILES	:= $(patsubst %.c, %.o, $(SOURCEFILES))

SOURCEBONUS := $(addsuffix .c, $(BONUSFILES))
OBJECTBONUS := $(patsubst %.c, %.o, $(SOURCEBONUS))

#######################################
## COMPILER 
#######################################

CC	:= cc
CFLAGS	:= -Wall -Werror -Wextra
AR	:= ar rcs $(NAME)
RAN	:= ranlib $(NAME)

#######################################
## OTHER TOOLS
#######################################

RM	:= rm -f

all : $(NAME)

$(NAME): $(OBJECTFILES)
	$(AR) $(OBJECTFILES)
	 $(RAN)

bonus: $(OBJECTBONUS)
	$(AR) $(OBJECTBONUS)
	$(RAN)

%.o : %.c Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTFILES) $(OBJECTBONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re

