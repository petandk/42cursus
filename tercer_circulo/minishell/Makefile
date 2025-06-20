# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpolo <gpolo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/04 11:11:44 by gpolo             #+#    #+#              #
#    Updated: 2025/06/16 18:44:36 by gpolo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:= minishell
 
LIBS			:= minishell.h

SRC_DIR			:= src/

OBJ_DIR			:= obj/

LIBS_DIRS		:= ./libs/libft 
LIBS_A          := ./libs/libft/libft.a
LIBS_COM		:= readline termcap
LIBS_INC		:= $(addprefix -I , $(LIBS_DIRS))
LIBS_COML		:= $(addprefix -l, $(LIBS_COM))


#SRCS_FILES		:= src/expansion/expansion_var src/expansion/expansion_var_utils src/parsing/count_token \
				   src/parsing/split_first src/parsing/token_utils_2 src/parsing/token src/parsing/token_utils \
				   src/parsing/token_utils_3 src/parsing/token_utils_4 src/parsing/token_utils_5 src/parsing/token_utils_6 \
				   src/builtins/cd_utils src/builtins/cd src/builtins/echo src/builtins/export_utils src/builtins/builtins \
				   src/builtins/env src/builtins/exit src/builtins/export src/builtins/pwd src/builtins/unset \
				   src/builtins/export_utils2 src/builtins/export_utils3 src/redirections/handle_redirections \
				   src/redirections/heredoc_utils4helper src/redirections/heredoc_utils src/redirections/heredoc \
				   src/redirections/heredoc_utils4 src/redirections/heredoc_helper src/redirections/heredoc_expansion \
				   src/redirections/handle_redirections_utils src/redirections/heredoc_utils2 src/redirections/heredoc_utils3 \
				   src/execution/ex_child src/execution/prepare_to_execute src/execution/execute_pipeline src/execution/execute_pipeline_utils \
				   src/execution/execute_pipeline_utils1 src/execution/execution src/utils/utils src/utils/free src/utils/ft_putmult_fd \
				   src/utils/child_signals src/utils/signals src/utils/the_files src/utils/the_files_utils src/shell/shell src/errors/errors src/main
 
SRCS_FILES		:= $(shell find $(SRC_DIR) -type f -iname "*.c" | sed 's#[.][^.]*$$##')
SRCS			:= $(addsuffix .c, $(SRCS_FILES))
SRCDIRS			:= $(shell find $(SRC_DIR) -type d)
OBJSDIRS		:= $(patsubst $(SRC_DIR)%,$(OBJ_DIR)%,$(SRCDIRS))
OBJSTEMP		:= $(patsubst $(SRC_DIR)%,$(OBJ_DIR)%,$(SRCS_FILES))
OBJS			:= $(addsuffix .o, $(OBJSTEMP))

CC				:= cc

CFLAGS			:= -Wall -Werror -Wextra -g $(LIBS_INC)

AR				:= ar rcs
RANLIB			:= ranlib
RM				:= rm -rf
MKDIR			:= mkdir -p

all:			makelibs $(NAME)

$(NAME):	    $(OBJSDIRS) $(OBJS) $(LIBS_A) Makefile
				$(CC) $(CFLAGS) $(OBJS) $(LIBS_A) $(LIBS_COML) -o $(NAME)
	
$(OBJ_DIR)%.o:	$(SRC_DIR)%.c $(LIBS) Makefile 
				$(CC) -I . $(CFLAGS) -c $< -o $@

$(OBJSDIRS):
				$(MKDIR) $(OBJSDIRS)
$(LIBS_A):
				for dir in $(LIBS_DIRS); do \
					$(MAKE) -C $$dir; \
				done
makelibs:
				for dir in $(LIBS_DIRS); do \
					$(MAKE) -C $$dir; \
				done

clean:
				$(RM) $(OBJS)
				for dir in $(LIBS_DIRS); do \
					$(MAKE) clean -C $$dir; \
				done

fclean:			clean
				$(RM) $(OBJSDIRS)
				$(RM) $(NAME)
				for dir in $(LIBS_DIRS); do \
					$(MAKE) fclean -C $$dir; \
				done

re:				fclean $(NAME)

normi:
				@clear
				@norminette $(SRCS) $(LIBS)
info:
				$(info $(SRCS_FILES))

.PHONY:			all clean fclean re info normi
