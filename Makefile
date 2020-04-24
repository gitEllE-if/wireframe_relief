NAME = fdf
FLAGS = -Wall -Wextra -Werror
SOURCE = main.c fdf_initialize.c fdf_get_check_in.c fdf_list.c fdf_render.c\
		fdf_projection.c fdf_menu.c fdf_handle_in.c fdf_color.c\
		fdf_control1.c fdf_control2.c fdf_rotate.c fdf_event.c fdf_setpixel.c\
		fdf_bresenham.c
INCLUDES = -I$(LIBFT_INCLUDE) -I$(LIBMLX_INCLUDE) -Iincludes 
HEADER = fdf.h fdf_control.h fdf_menu.h fdf_projection.h fdf_color.h
LIBRARIES_DIR = -L$(LIBFT_DIR) -L$(LIBMLX_DIR)
LIBRARIES = -lft -lmlx -lm -framework OpenGL -framework AppKit
VPATH = srcs includes

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a
LIBFT_INCLUDE = $(LIBFT_DIR)includes

LIBMLX_DIR = minilibx_macos/
LIBMLX = minilibx_macos/libmlx.a
LIBMLX_INCLUDE = $(LIBMLX_DIR)

LIB = -lft -lmlx -lm

OBJ = $(SOURCE:.c=.o)
OBJ_DIR = obj/
OBJECT = $(patsubst %.o, $(OBJ_DIR)%.o, $(OBJ))

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(LIBFT) $(LIBMLX) $(OBJECT)
	@echo "\033[1;3;34m"
	@gcc -g  $(OBJECT) $(INCLUDES) $(LIBRARIES_DIR) $(LIBRARIES) -o $@
	@echo "\033[23;32m--[ "$(NAME) ]-- successfully compiled"\033[0m"

$(LIBFT) :
	@echo "\033[33;3m"
	@make -C $(LIBFT_DIR)
	@echo "\033[0m"

$(LIBMLX) :
	@echo "\033[0m"
	@make -C $(LIBMLX_DIR)
	@echo "\033[0m"

$(OBJ_DIR)%.o : %.c $(HEADER)
	@echo "\033[36;3m\c"
	gcc -g $(FLAGS) $(INCLUDES) -c $< -o $@
	@echo "\033[0m\c"

clean :
	@make -C $(LIBFT_DIR) clean
	@make -C $(LIBMLX_DIR) clean
	@find $(OBJ_DIR) -type f -not -name '.gitkeep' -delete

fclean : clean
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)

re : fclean all
