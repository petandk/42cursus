NAME		= cub3d
LIBFT_DIR	= include/42_Libft/

LIBFT		= $(LIBFT_DIR)libft.a
CUBE_3D	    = cube_3d.h

INCLUDES	= -Iinclude -Iinclude/42_Libft -Iinclude/mlx_linux
MLX_DIR		= include/mlx_linux/
MLX			= $(MLX_DIR)libmlx_Linux.a
MLX_FLAGS	= -lXext -lX11 -lm

SRC_DIR		= src/
OBJ_DIR		= obj/

SRCS_FILES	= main.c \
				map/math_functions.c \
				map/map_functions.c \
				map/mini_map.c \
				map/mini_map_utils.c\
				map/perform_dda.c \
				moves/interactive_functions.c \
				moves/interactive_mouse_functions.c \
				moves/move_functions.c \
				moves/cardinal_moves.c \
				moves/loop.c \
				board/draw_elements.c \
				board/draw_line.c \
				board/draw_utils.c \
				board/game.c \
				image/calc_tex_x.c \
				image/img_functions.c \
				image/init_textures.c \
				image/texture_pixel.c \
				error.c \
				get_next_line/get_next_line.c \
				map_parsing/color_utils.c \
				map_parsing/map_validate.c \
				map_parsing/header_validate.c \
				map_parsing/list_array_utils.c \
				map_parsing/map_parser.c \
				map_parsing/map_utils.c \
				map_parsing/string_utils.c \
				map_parsing/int_utils.c \
				get_next_line/get_next_line_utils.c

SRCS 		= $(sort $(addprefix src/, $(SRCS_FILES)))
SRCDIRS		= $(dir $(SRCS))

OBJSDIRS	= $(sort $(patsubst $(SRC_DIR)%,$(OBJ_DIR)%,$(SRCDIRS)))
OBJSTEMP	= $(addprefix obj/, $(SRCS_FILES))
OBJS		= $(OBJSTEMP:%.c=%.o)

DEP		    = $(OBJS:.o=.d)

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -O3
AR			= ar rcs
RANLIB		= ranlib

RM			= rm -f
TOUCH		= touch

all:	libft mlx $(NAME)	

$(NAME):	$(OBJS) $(LIBFT) $(MLX)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(MLX) $(MLX_FLAGS)
			@echo "\033[0;31m     ,--./,-.   \033[0;32m    ,--./,-.   \033[0;31m    ,--./,-.   \033[0;32m    ,--./,-.   "
			@echo "\033[0;31m    / #      \ \033[0;32m    / #      \ \033[0;31m    / #      \ \033[0;32m    / #      \\" 
			@echo "\033[0;31m   |          |\033[0;32m   |          |\033[0;31m   |          |\033[0;32m   |          |"
			@echo "\033[0;31m    \        / \033[0;32m    \        / \033[0;31m    \        / \033[0;32m    \        /"
			@echo "\033[0;31m     '._,._,'  \033[0;32m     '._,._,'  \033[0;31m     '._,._,'  \033[0;32m     '._,._,' "
			@echo "\033[0m"
			@echo "\033[1;32m​🍏​🍎Compilación exitosa finalizada!!!!!🍎​🍏​\033[0m"

obj/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -MMD -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(RM) $(DEP)
	$(RM) -r $(OBJ_DIR)

fclean:		clean
			$(RM) $(NAME)
			make fclean -C $(LIBFT_DIR)
			make clean -C $(MLX_DIR)

re:			fclean all

submodule:
	git submodule init
	git submodule update

libft: submodule
	make -C $(LIBFT_DIR)

mlx: submodule
	make -C $(MLX_DIR)

.PHONY:		all clean fclean re libft submodule mlx
-include $(DEP)
