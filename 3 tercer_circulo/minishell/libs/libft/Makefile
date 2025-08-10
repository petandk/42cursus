# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/15 11:26:21 by gpolo             #+#    #+#              #
#    Updated: 2025/02/26 12:00:40 by rmanzana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME						:= libft.a

BONUS						:= .bonus

LIBS						:= libft.h

SOURCES 					:= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strcmp.c

OBJECTS 					:= ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o ft_strlen.o ft_memset.o ft_bzero.o ft_memcpy.o ft_memmove.o ft_strlcpy.o ft_strlcat.o ft_toupper.o ft_tolower.o ft_strchr.o ft_strrchr.o ft_strncmp.o ft_memchr.o ft_memcmp.o ft_strnstr.o ft_atoi.o ft_calloc.o ft_strdup.o ft_substr.o ft_strjoin.o ft_strtrim.o ft_split.o ft_itoa.o ft_strmapi.o ft_striteri.o ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o ft_putnbr_fd.o ft_strcmp.o

SOURCES_BONUS				:= ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJECTS_BONUS				:= ft_lstnew_bonus.o ft_lstadd_front_bonus.o ft_lstsize_bonus.o ft_lstlast_bonus.o ft_lstadd_back_bonus.o ft_lstdelone_bonus.o ft_lstclear_bonus.o ft_lstiter_bonus.o ft_lstmap_bonus.o

CC							:= gcc

FLAGS						:= -Wall -Werror -Wextra

AR							:= ar rcs

RAN							:= ranlib

all :						$(NAME) $(BONUS)

$(NAME) : 					$(OBJECTS) $(LIBS) Makefile
							$(AR) $(NAME) $(OBJECTS)

%.o: %.c					$(LIBS) Makefile
							$(CC) $(FLAGS) -c $< -o $@

bonus :						$(BONUS)

$(BONUS) :					$(OBJECTS_BONUS) $(OBJECTS)
							$(AR) $(NAME) $(OBJECTS_BONUS) $(OBJECTS)
							@touch $(BONUS)
clean :
							rm -f $(OBJECTS) $(OBJECTS_BONUS)

fclean : 					clean
							rm -f $(NAME)
							rm -f $(BONUS)
		
re : 						fclean all

rebonus :					fclean bonus

.PHONY: all clean fclean re bonus rebonus
