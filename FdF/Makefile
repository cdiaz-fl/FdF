### EXECUTABLE ###

NAME = fdf



### SOURCE FILES ###

FILES = main.c \
								mlx_aux.c \
								dots.c \
								utils.c \
								events.c \



### INCLUDES ###

AR				= 	libft.a
LIBFT			= 	libft
SRC_PATH  = 	src
OBJ_PATH  = 	obj
MLX				=		minilibx



### COMPILATION ###

CC    = clang
FLAGS = -Wall -Werror -Wextra -g#-fsanitize=address -g3
CSANITIZE = -fsanitize=address -g3
MINILIBX	=	 -lmlx -framework OpenGL -framework Appkit



### OBJECTS ###

SRCS = $(addprefix $(SRC_PATH)/,$(FILES))
OBJS = $(addprefix $(OBJ_PATH)/,$(FILES:.c=.o))



### COLORS ###
NOC         = \033[0m
BOLD        = \033[1m
UNDERLINE   = \033[4m
BLACK       = \033[1;30m
RED         = \033[1;31m
GREEN       = \033[1;32m
YELLOW      = \033[1;33m
BLUE        = \033[1;34m
VIOLET      = \033[1;35m
CYAN        = \033[1;36m
WHITE       = \033[1;37m



### RULES ###

all: lib tmp $(NAME)

lib: 
	@make -s -C $(LIBFT)
	@make -s -C $(MLX)

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) $(LIBFT)/$(AR) -L $(MLX) $(MINILIBX) -o $(NAME) 

tmp:
	mkdir -p obj

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c fdf.h
	@$(CC) $(FLAGS) -c -o $@ $<
		
clean:
	@make clean -C $(LIBFT)
	@make clean -C $(MLX)
	@rm -rf $(OBJ_PATH)

fclean: clean
	@rm -rf $(OBJ_PATH)
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re : fclean all

.PHONY: all lib tmp clean fclean re
