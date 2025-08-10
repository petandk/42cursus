# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/11 14:40:42 by pamanzan          #+#    #+#              #
#    Updated: 2025/07/16 14:58:34 by rmanzana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
BONUS		= .bonus
LIBS		= libft.h

SRCS		= ft_isalnum.c ft_isprint.c ft_memmove.c ft_strlcat.c ft_strnstr.c ft_atoi.c ft_isalpha.c ft_memchr.c ft_memset.c ft_strlcpy.c ft_strrchr.c ft_bzero.c ft_isascii.c ft_memcmp.c ft_strchr.c ft_strlen.c ft_tolower.c ft_calloc.c ft_isdigit.c ft_memcpy.c ft_strdup.c ft_strncmp.c ft_toupper.c ft_split.c ft_strjoin.c ft_strtrim.c ft_substr.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_str_isalpha.c ft_str_isdigit.c ft_strcmp.c ft_strcpy.c

OBJS		= ft_isalnum.o ft_isprint.o ft_memmove.o ft_strlcat.o ft_strnstr.o ft_atoi.o ft_isalpha.o ft_memchr.o ft_memset.o ft_strlcpy.o ft_strrchr.o ft_bzero.o ft_isascii.o ft_memcmp.o ft_strchr.o ft_strlen.o ft_tolower.o ft_calloc.o ft_isdigit.o ft_memcpy.o ft_strdup.o ft_strncmp.o ft_toupper.o ft_split.o ft_strjoin.o ft_strtrim.o ft_substr.o ft_itoa.o ft_strmapi.o ft_striteri.o ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o ft_putnbr_fd.o ft_str_isalpha.o ft_str_isdigit.o ft_strcmp.o ft_strcpy.o

BONUS_SRCS	= ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

BONUS_OBJS	= ft_lstnew_bonus.o ft_lstadd_front_bonus.o ft_lstsize_bonus.o ft_lstlast_bonus.o ft_lstadd_back_bonus.o ft_lstdelone_bonus.o ft_lstclear_bonus.o ft_lstiter_bonus.o ft_lstmap_bonus.o

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rcs
RANLIB		= ranlib

RM			= rm -f
MKDIR		= mkdir -p
TOUCH		= touch

all:		$(NAME)

$(NAME):	$(OBJS) $(BONUS_OBJS) $(LIBS)
			$(AR) $(NAME) $(OBJS) $(BONUS_OBJS)
			$(RANLIB) $(NAME)

%.o : %.c $(LIBS)
			$(CC) $(CFLAGS) -c $< -o $@

bonus:		$(BONUS)

$(BONUS):	$(BONUS_OBJS) $(OBJS)
			$(AR) $(NAME) $(BONUS_OBJS) $(OBJS)
			$(RANLIB) $(NAME)
			@$(TOUCH) $(BONUS)		

%.o : $(BONUS_SRC)%.c $(LIBS)
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			$(RM) $(OBJS) $(BONUS_OBJS)

fclean:		clean
			$(RM) $(OBJS)
			$(RM) $(NAME)
			$(RM) $(BONUS_OBJS)

re:			fclean $(NAME)

rebonus:	fclean $(BONUS)


.PHONY:		all clean fclean re rebonus
